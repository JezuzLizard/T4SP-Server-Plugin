#pragma once

#define CalculateRelativeJMPAddress(X, Y) (((std::uintptr_t)Y - (std::uintptr_t)X) - 5)

#include <asmjit/core/jitruntime.h>
#include <asmjit/x86/x86assembler.h>

using namespace asmjit::x86;

namespace utils::hook
{
	class signature final
	{
	public:
		struct container final
		{
			std::string signature;
			std::string mask;
			std::function<void(char*)> callback;
		};

		signature(void* start, const size_t length) : start_(start), length_(length)
		{
		}

		signature(const DWORD start, const size_t length) : signature(reinterpret_cast<void*>(start), length)
		{
		}

		signature() : signature(0x400000, 0x800000)
		{
		}

		void process();
		void add(const container& container);

	private:
		void* start_;
		size_t length_;
		std::vector<container> signatures_;
	};

	class assembler : public Assembler
	{
	public:
		using Assembler::Assembler;
		using Assembler::call;
		using Assembler::jmp;

		asmjit::Error call(void* target);
		asmjit::Error jmp(void* target);
	};

	class detour
	{
	public:
		detour() = default;
		detour(void* place, void* target);
		detour(size_t place, void* target);
		~detour();

		detour(detour&& other) noexcept
		{
			this->operator=(std::move(other));
		}

		detour& operator= (detour&& other) noexcept
		{
			if (this != &other)
			{
				this->~detour();

				this->place_ = other.place_;
				this->original_ = other.original_;

				other.place_ = nullptr;
				other.original_ = nullptr;
			}

			return *this;
		}

		detour(const detour&) = delete;
		detour& operator= (const detour&) = delete;

		void enable() const;
		void disable() const;

		void create(void* place, void* target);
		void create(size_t place, void* target);
		void clear();

		template <typename T>
		T* get() const
		{
			return static_cast<T*>(this->get_original());
		}

		template <typename T, typename... Args>
		T invoke(Args... args)
		{
			return static_cast<T(__cdecl*)(Args ...)>(this->get_original())(args...);
		}

		template <typename T, typename... Args>
		T invoke_pascal(Args... args)
		{
			return static_cast<T(__stdcall*)(Args ...)>(this->get_original())(args...);
		}

		template <typename T, typename... Args>
		T invoke_this(Args... args)
		{
			return static_cast<T(__thiscall*)(Args ...)>(this->get_original())(args...);
		}

		template <typename T, typename... Args>
		T invoke_fast(Args... args)
		{
			return static_cast<T(__fastcall*)(Args ...)>(this->get_original())(args...);
		}

		[[nodiscard]] void* get_original() const;

	private:
		void* place_{};
		void* original_{};
	};

	void nop(void* place, size_t length);
	void nop(size_t place, size_t length);

	void copy(void* place, const void* data, size_t length);
	void copy(size_t place, const void* data, size_t length);

	bool is_relatively_far(const void* pointer, const void* data, int offset = 5);

	void call(void* pointer, void* data);
	void call(size_t pointer, void* data);
	void call(size_t pointer, size_t data);

	void jump(std::uintptr_t address, void* destination);

	void* assemble(const std::function<void(assembler&)>& asm_function);

	void* get_displacement_addr(int original);

	template <typename T>
	T extract(void* address)
	{
		const auto data = static_cast<uint8_t*>(address);
		const auto offset = *reinterpret_cast<int32_t*>(data);
		return  reinterpret_cast<T>(data + offset + 4);
	}

	template <typename T>
	static void set(void* place, T value)
	{
		DWORD old_protect;
		VirtualProtect(place, sizeof(T), PAGE_EXECUTE_READWRITE, &old_protect);

		*static_cast<T*>(place) = value;

		VirtualProtect(place, sizeof(T), old_protect, &old_protect);
		FlushInstructionCache(GetCurrentProcess(), place, sizeof(T));
	}

	template <typename T>
	static void set(const size_t place, T value)
	{
		return set<T>(reinterpret_cast<void*>(place), value);
	}

	template <typename T>
	static T get(void* place)
	{
		return *static_cast<T*>(place);
	}

	template <typename T>
	static T get(const size_t place)
	{
		return get<T>(reinterpret_cast<void*>(place));
	}

	template <typename T, typename... Args>
	static T invoke(size_t func, Args... args)
	{
		return reinterpret_cast<T(__cdecl*)(Args ...)>(func)(args...);
	}

	template <typename T, typename... Args>
	static T invoke(void* func, Args... args)
	{
		return static_cast<T(__cdecl*)(Args ...)>(func)(args...);
	}

	template <typename T, typename... Args>
	static T invoke_pascal(size_t func, Args... args)
	{
		return reinterpret_cast<T(__stdcall*)(Args ...)>(func)(args...);
	}

	template <typename T, typename... Args>
	static T invoke_pascal(void* func, Args... args)
	{
		return static_cast<T(__stdcall*)(Args ...)>(func)(args...);
	}

	template <typename T, typename... Args>
	static T invoke_this(size_t func, Args... args)
	{
		return reinterpret_cast<T(__thiscall*)(Args ...)>(func)(args...);
	}

	template <typename T, typename... Args>
	static T invoke_this(void* func, Args... args)
	{
		return static_cast<T(__thiscall*)(Args ...)>(func)(args...);
	}

	template <typename T, typename... Args>
	static T invoke_fast(size_t func, Args... args)
	{
		return reinterpret_cast<T(__fastcall*)(Args ...)>(func)(args...);
	}

	template <typename T, typename... Args>
	static T invoke_fast(void* func, Args... args)
	{
		return static_cast<T(__fastcall*)(Args ...)>(func)(args...);
	}
}