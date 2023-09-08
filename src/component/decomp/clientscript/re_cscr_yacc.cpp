#include <stdinc.hpp>
#include "loader/component_loader.hpp"
#include "utils/hook.hpp"
//#include "codsrc/clientscript/cscr_yacc.hpp"

#define RE_CSCR_YACC_USE_WRAPPERS

namespace re_cscr_yacc
{
	utils::hook::detour LowerCase_hook;
	utils::hook::detour yyparse_hook;
	utils::hook::detour StringValue_hook;
	utils::hook::detour yylex_hook;
	utils::hook::detour yy_get_next_buffer_hook;
	utils::hook::detour yy_get_previous_state_hook;
	utils::hook::detour yy_try_NUL_trans_hook;
	utils::hook::detour yyrestart_hook;
	utils::hook::detour yy_create_buffer_hook;
	utils::hook::detour yy_flush_buffer_hook;
	utils::hook::detour ScriptParse_hook;

	void* LowerCase_original;
	void* yyparse_original;
	void* StringValue_original;
	void* yylex_original;
	void* yy_get_next_buffer_original;
	void* yy_get_previous_state_original;
	void* yy_try_NUL_trans_original;
	void* yyrestart_original;
	void* yy_create_buffer_original;
	void* yy_flush_buffer_original;
	void* ScriptParse_original;

	namespace
	{

		unsigned int LowerCase_call(unsigned int strVal, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_YACC_USE_WRAPPERS
			return game::LowerCase(strVal, LowerCase_original);
#else
			return cscr_yacc::LowerCase(strVal);
#endif
		}

		// unsigned int __usercall LowerCase@<eax>(unsigned int strVal@<ecx>)
		NAKED unsigned int LowerCase_stub()
		{
			_asm
			{
				push ecx;
				call LowerCase_call;
				add esp, 0x4;
				ret;
			}
		}

		int yyparse_stub()
		{
#ifdef RE_CSCR_YACC_USE_WRAPPERS
			return yyparse_hook.invoke<int>();
#else
			return cscr_yacc::yyparse();
#endif
		}

		int StringValue_call(int len, const char * str_, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_YACC_USE_WRAPPERS
			return game::StringValue(len, str_, StringValue_original);
#else
			return cscr_yacc::StringValue(len, str_);
#endif
		}

		// int __usercall StringValue@<eax>(int len@<ecx>, const char *str@<edx>)
		NAKED int StringValue_stub()
		{
			_asm
			{
				push edx;
				push ecx;
				call StringValue_call;
				add esp, 0x8;
				ret;
			}
		}

		int yylex_stub()
		{
#ifdef RE_CSCR_YACC_USE_WRAPPERS
			return yylex_hook.invoke<int>();
#else
			return cscr_yacc::yylex();
#endif
		}

		int yy_get_next_buffer_stub()
		{
#ifdef RE_CSCR_YACC_USE_WRAPPERS
			return yy_get_next_buffer_hook.invoke<int>();
#else
			return cscr_yacc::yy_get_next_buffer();
#endif
		}

		int yy_get_previous_state_stub()
		{
#ifdef RE_CSCR_YACC_USE_WRAPPERS
			return yy_get_previous_state_hook.invoke<int>();
#else
			return cscr_yacc::yy_get_previous_state();
#endif
		}

		int yy_try_NUL_trans_call(int yy_current_state, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_YACC_USE_WRAPPERS
			return game::yy_try_NUL_trans(yy_current_state, yy_try_NUL_trans_original);
#else
			return cscr_yacc::yy_try_NUL_trans(yy_current_state);
#endif
		}

		// int __usercall yy_try_NUL_trans@<eax>(int yy_current_state@<eax>)
		NAKED int yy_try_NUL_trans_stub()
		{
			_asm
			{
				push eax;
				call yy_try_NUL_trans_call;
				add esp, 0x4;
				ret;
			}
		}

		void yyrestart_stub()
		{
#ifdef RE_CSCR_YACC_USE_WRAPPERS
			yyrestart_hook.invoke<void>();
#else
			cscr_yacc::yyrestart();
#endif
		}

		game::yy_buffer_state * yy_create_buffer_stub()
		{
#ifdef RE_CSCR_YACC_USE_WRAPPERS
			return yy_create_buffer_hook.invoke<game::yy_buffer_state *>();
#else
			return cscr_yacc::yy_create_buffer();
#endif
		}

		void yy_flush_buffer_call(game::yy_buffer_state * result, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_YACC_USE_WRAPPERS
			game::yy_flush_buffer(result, yy_flush_buffer_original);
#else
			cscr_yacc::yy_flush_buffer(result);
#endif
		}

		// void __usercall yy_flush_buffer(game::yy_buffer_state *result@<eax>)
		NAKED void yy_flush_buffer_stub()
		{
			_asm
			{
				push eax;
				call yy_flush_buffer_call;
				add esp, 0x4;
				ret;
			}
		}

		void ScriptParse_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr, game::sval_u * parseData)
		{
#ifdef RE_CSCR_YACC_USE_WRAPPERS
			game::ScriptParse(a1, parseData, ScriptParse_original);
#else
			cscr_yacc::ScriptParse(a1, parseData);
#endif
		}

		// void __usercall ScriptParse(game::scriptInstance_t a1@<eax>, game::sval_u *parseData)
		NAKED void ScriptParse_stub()
		{
			_asm
			{
				push eax;
				call ScriptParse_call;
				add esp, 0x4;
				ret;
			}
		}
	}

	class component final : public component_interface
	{
	public:
		void post_unpack() override
		{
			LowerCase_hook.create(game::LowerCase(), LowerCase_stub);
			yyparse_hook.create(game::yyparse.get(), yyparse_stub);
			StringValue_hook.create(game::StringValue(), StringValue_stub);
			yylex_hook.create(game::yylex.get(), yylex_stub);
			yy_get_next_buffer_hook.create(game::yy_get_next_buffer.get(), yy_get_next_buffer_stub);
			yy_get_previous_state_hook.create(game::yy_get_previous_state.get(), yy_get_previous_state_stub);
			yy_try_NUL_trans_hook.create(game::yy_try_NUL_trans(), yy_try_NUL_trans_stub);
			yyrestart_hook.create(game::yyrestart.get(), yyrestart_stub);
			yy_create_buffer_hook.create(game::yy_create_buffer.get(), yy_create_buffer_stub);
			yy_flush_buffer_hook.create(game::yy_flush_buffer(), yy_flush_buffer_stub);
			ScriptParse_hook.create(game::ScriptParse(), ScriptParse_stub);

			//Original hook function addresses
			LowerCase_original = LowerCase_hook.get_original();
			yyparse_original = yyparse_hook.get_original();
			StringValue_original = StringValue_hook.get_original();
			yylex_original = yylex_hook.get_original();
			yy_get_next_buffer_original = yy_get_next_buffer_hook.get_original();
			yy_get_previous_state_original = yy_get_previous_state_hook.get_original();
			yy_try_NUL_trans_original = yy_try_NUL_trans_hook.get_original();
			yyrestart_original = yyrestart_hook.get_original();
			yy_create_buffer_original = yy_create_buffer_hook.get_original();
			yy_flush_buffer_original = yy_flush_buffer_hook.get_original();
			ScriptParse_original = ScriptParse_hook.get_original();
		}

	private:
	};
}
REGISTER_COMPONENT(re_cscr_yacc::component)
