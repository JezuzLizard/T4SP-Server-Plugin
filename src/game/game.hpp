#pragma once

#define WEAK __declspec(selectany)
#define NAKED __declspec(naked)

#define SELECT(mp, sp) (game::environment::t4mp() ? mp : sp)
#define ASSIGN(type, mp, sp) reinterpret_cast<type>(SELECT(mp, sp))
#define CALL_ADDR(mp, sp) ASSIGN(void*, mp, sp)

#define ARRAY_COUNT(arrayn) \
	((sizeof(arrayn)) / (sizeof(arrayn[0])))

#ifndef NDEBUG
#undef assert
#define assert(expr) \
	if (!!!(expr)) \
	{ \
		utils::io::write_file("t4sp-server-plugin/gsc_state_assert.json", build_gsc_dump(game::SCRIPTINSTANCE_SERVER)); \
		_wassert(_CRT_WIDE(#expr), _CRT_WIDE(__FILE__), (unsigned)(__LINE__)); \
	}
#endif


#define RE_CSCR_ANIMTREE_USE_WRAPPERS
//#define RE_CSCR_COMPILER_USE_WRAPPERS
//#define RE_CSCR_MAIN_USE_WRAPPERS
//#define RE_CSCR_MEMORYTREE_USE_WRAPPERS
//#define RE_CSCR_PARSER_USE_WRAPPERS
//#define RE_CSCR_PARSETREE_USE_WRAPPERS
//#define RE_CSCR_READWRITE_USE_WRAPPERS
//#define RE_CSCR_STRINGLIST_USE_WRAPPERS
//#define RE_CSCR_VARIABLE_USE_WRAPPERS
//#define RE_CSCR_VM_USE_WRAPPERS
//#define RE_CSCR_YACC_USE_WRAPPERS

//#define DISABLE_RE_CSCR_ANIMTREE
//#define DISABLE_RE_CSCR_COMPILER
//#define DISABLE_RE_CSCR_MAIN
//#define DISABLE_RE_CSCR_MEMORYTREE
//#define DISABLE_RE_CSCR_PARSER
//#define DISABLE_RE_CSCR_PARSETREE
//#define DISABLE_RE_CSCR_READWRITE
//#define DISABLE_RE_CSCR_STRINGLIST
//#define DISABLE_RE_CSCR_VARIABLE
//#define DISABLE_RE_CSCR_VM
//#define DISABLE_RE_CSCR_YACC


namespace game
{
	enum gamemode
	{
		multiplayer,
		singleplayer,
		none
	};

	extern gamemode current;

	namespace environment
	{
		bool t4mp();
		bool t4sp();
	}

	template <typename T>
	class symbol
	{
	public:
		symbol(const size_t t4mp, const size_t t4sp)
			: t4mp_(reinterpret_cast<T*>(t4mp))
			, t4sp_(reinterpret_cast<T*>(t4sp))
		{
		}

		T* get() const
		{
			if (environment::t4mp())
			{
				return t4mp_;
			}

			return t4sp_;
		}

		void set(const size_t ptr)
		{
			this->t4mp_ = reinterpret_cast<T*>(ptr);
			this->t4sp_ = reinterpret_cast<T*>(ptr);
		}

		operator T* () const
		{
			return this->get();
		}

		T* operator->() const
		{
			return this->get();
		}

	private:
		T* t4mp_;
		T* t4sp_;
	};
}
