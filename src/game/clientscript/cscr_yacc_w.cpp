#include <stdinc.hpp>

namespace game
{
	// unsigned int __usercall LowerCase@<eax>(unsigned int strVal@<ecx>)
	unsigned int LowerCase(unsigned int strVal, void* call_addr)
	{
		unsigned int answer;

		__asm
		{
			mov ecx, strVal;
			call call_addr;
			mov answer, eax;
		}

		return answer;
	}

	// int __usercall StringValue@<eax>(int len@<ecx>, const char *str@<edx>)
	int StringValue(int len, const char* str_, void* call_addr)
	{
		int answer;

		__asm
		{
			mov ecx, len;
			mov edx, str_;
			call call_addr;
			mov answer, eax;
		}

		return answer;
	}

	// int __usercall yy_try_NUL_trans@<eax>(int yy_current_state@<eax>)
	int yy_try_NUL_trans(int yy_current_state, void* call_addr)
	{
		int answer;

		__asm
		{
			mov eax, yy_current_state;
			call call_addr;
			mov answer, eax;
		}

		return answer;
	}

	// void __usercall yy_flush_buffer(yy_buffer_state *result@<eax>)
	void yy_flush_buffer(yy_buffer_state* result, void* call_addr)
	{
		__asm
		{
			mov eax, result;
			call call_addr;
		}
	}

	// void __usercall ScriptParse(scriptInstance_t a1@<eax>, sval_u *parseData)
	void ScriptParse(scriptInstance_t a1, sval_u* parseData, void* call_addr)
	{
		__asm
		{
			push parseData;
			mov eax, a1;
			call call_addr;
			add esp, 0x4;
		}
	}

	FILE* yy_load_buffer_state()
	{
		FILE* result;

		*game::yy_n_chars = (*game::yy_current_buffer)->yy_n_chars;
		*game::yy_c_buf_p = (*game::yy_current_buffer)->yy_buf_pos;
		*game::yytext = *game::yy_c_buf_p;
		result = (*game::yy_current_buffer)->yy_input_file;
		*game::yyin = (*game::yy_current_buffer)->yy_input_file;
		*game::yy_hold_char = *(*game::yy_c_buf_p);
		return result;
	}

	void yy_fatal_error(const char* err)
	{
		game::_fprintf(game::__iob_func() + 2, "%s\n", err);
		game::_exit(2);
	}

	void* yy_flex_realloc(void* ptr, unsigned int size)
	{
		return game::_realloc(ptr, size);
	}

	void yy_init_buffer(yy_buffer_state* b, FILE* file)
	{
		game::yy_flush_buffer(b);
		b->yy_input_file = file;
		b->yy_fill_buffer = 1;
		b->yy_is_interactive = 0;
	}
}