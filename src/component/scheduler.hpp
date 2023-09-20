#pragma once

namespace scheduler
{
	enum pipeline
	{
		server,
		async,
		main,
		count,
	};

	static const bool cond_continue = false;
	static const bool cond_end = true;

	void schedule(const std::function<bool()>& callback, pipeline type = pipeline::main,
		std::chrono::milliseconds delay = 0ms);
	void loop(const std::function<void()>& callback, pipeline type = pipeline::main,
		std::chrono::milliseconds delay = 0ms);
	void once(const std::function<void()>& callback, pipeline type = pipeline::main,
		std::chrono::milliseconds delay = 0ms);

	void on_init(const std::function<void()>& callback);

	void on_pre_scr_init_system(const std::function<void(game::scriptInstance_t)>& callback);
	void on_post_scr_init_system(const std::function<void(game::scriptInstance_t)>& callback);
	void exec_pre_scr_init_funcs(game::scriptInstance_t inst);
	void exec_post_scr_init_funcs(game::scriptInstance_t inst);
}
