#pragma once

namespace game
{
	WEAK symbol<int()>yyparse{ 0x0, 0x69AEC0 };
	WEAK symbol<int()>yylex{ 0x0, 0x69C0D0 };
	WEAK symbol<int()>yy_get_next_buffer{ 0x0, 0x69D300 };
	WEAK symbol<int()>yy_get_previous_state{ 0x0, 0x69D450 };
	WEAK symbol<void()>yyrestart{ 0x0, 0x69D5C0 };
	WEAK symbol<yy_buffer_state* ()>yy_create_buffer{ 0x0, 0x69D620 };

	inline void* LowerCase() { return CALL_ADDR(0x0, 0x69AEA0); }
	unsigned int LowerCase(unsigned int strVal, void* call_addr = LowerCase());
	inline void* StringValue() { return CALL_ADDR(0x0, 0x69BFF0); }
	int StringValue(int len, const char* str_, void* call_addr = StringValue());
	inline void* yy_try_NUL_trans() { return CALL_ADDR(0x0, 0x69D520); }
	int yy_try_NUL_trans(int yy_current_state, void* call_addr = yy_try_NUL_trans());
	inline void* yy_flush_buffer() { return CALL_ADDR(0x0, 0x69D690); }
	void yy_flush_buffer(yy_buffer_state* result, void* call_addr = yy_flush_buffer());
	inline void* ScriptParse() { return CALL_ADDR(0x0, 0x69D710); }
	void ScriptParse(scriptInstance_t a1, sval_u* parseData, void* call_addr = ScriptParse());
}