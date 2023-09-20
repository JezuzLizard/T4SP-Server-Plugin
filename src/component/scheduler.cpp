#include <stdinc.hpp>
#include "loader/component_loader.hpp"

#include "scheduler.hpp"

#include <utils/concurrency.hpp>
#include <utils/hook.hpp>

namespace scheduler
{
	namespace
	{
		struct task
		{
			std::function<bool()> handler{};
			std::chrono::milliseconds interval{};
			std::chrono::high_resolution_clock::time_point last_call{};
		};

		using task_list = std::vector<task>;

		class task_pipeline
		{
		public:
			void add(task&& task)
			{
				new_callbacks_.access([&task](task_list& tasks)
				{
					tasks.emplace_back(std::move(task));
				});
			}

			void execute()
			{
				callbacks_.access([&](task_list& tasks)
				{
					this->merge_callbacks();

					for (auto i = tasks.begin(); i != tasks.end();)
					{
						const auto now = std::chrono::high_resolution_clock::now();
						const auto diff = now - i->last_call;

						if (diff < i->interval)
						{
							++i;
							continue;
						}

						i->last_call = now;

						const auto res = i->handler();
						if (res == cond_end)
						{
							i = tasks.erase(i);
						}
						else
						{
							++i;
						}
					}
				});
			}

		private:
			utils::concurrency::container<task_list> new_callbacks_;
			utils::concurrency::container<task_list, std::recursive_mutex> callbacks_;

			void merge_callbacks()
			{
				callbacks_.access([&](task_list& tasks)
				{
					new_callbacks_.access([&](task_list& new_tasks)
					{
						tasks.insert(tasks.end(), std::move_iterator<task_list::iterator>(new_tasks.begin()), std::move_iterator<task_list::iterator>(new_tasks.end()));
						new_tasks = {};
					});
				});
			}
		};

		std::thread thread;
		task_pipeline pipelines[pipeline::count];

		void execute(const pipeline type)
		{
			assert(type >= 0 && type < pipeline::count);
			pipelines[type].execute();
		}

		void execute_server()
		{
			execute(pipeline::server);
		}

		void execute_main()
		{
			execute(pipeline::main);
		}

		utils::hook::detour com_init_hook;
		utils::hook::detour gscr_postloadscripts_hook;

		std::vector<std::function<void()>> post_init_funcs;
		bool com_inited = false;

		void on_post_init_hook()
		{
			if (com_inited)
			{
				return;
			}
			com_inited = true;
			for (const auto& func : post_init_funcs)
			{
				func();
			}

			post_init_funcs.clear();
		}

		void com_init_stub()
		{
			com_init_hook.invoke<void>();
			on_post_init_hook();
		}

		std::vector<std::function<void(game::scriptInstance_t)>> pre_scr_init_funcs;
		std::vector<std::function<void(game::scriptInstance_t)>> post_scr_init_funcs;

		utils::hook::detour pre_scr_init_system_hook;
		utils::hook::detour post_scr_init_system_hook;

		void* pre_scr_init_system_original;
		void* post_scr_init_system_original;

		NAKED void pre_scr_init_system_stub()
		{
			__asm
			{
				pushad;
				push eax;
				call exec_pre_scr_init_funcs;
				add esp, 4;
				popad;

				push pre_scr_init_system_original;
				ret;
			}
		}

		NAKED void post_scr_init_system_stub()
		{
			__asm
			{
				pushad;
				push eax;
				call exec_post_scr_init_funcs;
				add esp, 4;
				popad;

				push post_scr_init_system_original;
				ret;
			}
		}
	}

	void schedule(const std::function<bool()>& callback, const pipeline type,
		const std::chrono::milliseconds delay)
	{
		assert(type >= 0 && type < pipeline::count);

		task task;
		task.handler = callback;
		task.interval = delay;
		task.last_call = std::chrono::high_resolution_clock::now();

		pipelines[type].add(std::move(task));
	}

	void loop(const std::function<void()>& callback, const pipeline type,
		const std::chrono::milliseconds delay)
	{
		schedule([callback]()
		{
			callback();
			return cond_continue;
		}, type, delay);
	}

	void once(const std::function<void()>& callback, const pipeline type,
		const std::chrono::milliseconds delay)
	{
		schedule([callback]()
		{
			callback();
			return cond_end;
		}, type, delay);
	}

	void on_init(const std::function<void()>& callback)
	{
		if (com_inited)
		{
			once(callback, pipeline::main);
		}
		else
		{
			post_init_funcs.push_back(callback);
		}
	}

	void on_pre_scr_init_system(const std::function<void(game::scriptInstance_t)>& callback)
	{
		pre_scr_init_funcs.push_back(callback);
	}

	void on_post_scr_init_system(const std::function<void(game::scriptInstance_t)>& callback)
	{
		post_scr_init_funcs.push_back(callback);
	}

	void exec_pre_scr_init_funcs(game::scriptInstance_t inst)
	{
		for (const auto& func : pre_scr_init_funcs)
		{
			func(inst);
		}
	}

	void exec_post_scr_init_funcs(game::scriptInstance_t inst)
	{
		for (const auto& func : post_scr_init_funcs)
		{
			func(inst);
		}
	}

	class component final : public component_interface
	{
	public:
		void post_unpack() override
		{
			thread = std::thread([]()
			{
				while (true)
				{
					execute(pipeline::async);
					std::this_thread::sleep_for(10ms);
				}
			});

			com_init_hook.create(SELECT(0x0, 0x59D710), com_init_stub);
			utils::hook::call(SELECT(0x0, 0x503B5D), execute_server);
			utils::hook::call(SELECT(0x0, 0x59DCFD), execute_main);

			// for when we dont use decomp
			pre_scr_init_system_hook.create(0x699865, pre_scr_init_system_stub);
			pre_scr_init_system_original = pre_scr_init_system_hook.get_original();
			post_scr_init_system_hook.create(0x699924, post_scr_init_system_stub);
			post_scr_init_system_original = post_scr_init_system_hook.get_original();
		}
	};
}

REGISTER_COMPONENT(scheduler::component)
