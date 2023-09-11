#pragma once

namespace codsrc
{
	unsigned int LowerCase(unsigned int strVal);
	int yyparse();
	int StringValue(int len, const char* str);
	int yylex();
	int yy_get_next_buffer();
	int yy_get_previous_state();
	int yy_try_NUL_trans(int yy_current_state);
	void yyrestart();
	game::yy_buffer_state* yy_create_buffer();
	void yy_flush_buffer(game::yy_buffer_state* result);
	void ScriptParse(game::scriptInstance_t a1, game::sval_u* parseData);

	FILE* yy_load_buffer_state();
	void yy_fatal_error(const char* err);
	void* yy_flex_realloc(void* ptr, unsigned int size);
	void yy_init_buffer(game::yy_buffer_state* b, FILE* file);
}
