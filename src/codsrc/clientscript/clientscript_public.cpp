#include <stdinc.hpp>
#include "clientscript_public.hpp"
#include <dbghelp.h>

namespace game
{
#define QUICK_TO_JSON_FIELD(j, v, membername) j[#membername] = v.membername

#define QUICK_TO_JSON_FIELD_SAFE_CSTR(j, v, membername) \
	if (v.membername) \
		j[#membername] = v.membername; \
	else \
		j[#membername] = "(NULL)"

#define QUICK_TO_JSON_FIELD_PTR_ADDR(j, v, membername) j[#membername] = reinterpret_cast<size_t>(&v.membername)

#define QUICK_TO_JSON_FIELD_ARRAY(j, v, membername) \
	for (auto i = 0; i < ARRAY_COUNT(v.membername); i++) \
	{ \
		j[#membername][i] = v.membername[i]; \
	}

#define QUICK_TO_JSON_FIELD_SL_STRING(j, v, membername) j[#membername "Str"] = SL_ConvertToStringSafe(v.membername, *gInst)

	void to_json(nlohmann::json& j, const scrVarPub_t& v)
	{
		QUICK_TO_JSON_FIELD_SAFE_CSTR(j, v, fieldBuffer);
		QUICK_TO_JSON_FIELD(j, v, canonicalStrCount);
		QUICK_TO_JSON_FIELD(j, v, developer);
		QUICK_TO_JSON_FIELD(j, v, developer_script);
		QUICK_TO_JSON_FIELD(j, v, evaluate);
		QUICK_TO_JSON_FIELD_SAFE_CSTR(j, v, error_message);
		QUICK_TO_JSON_FIELD(j, v, error_index);
		QUICK_TO_JSON_FIELD(j, v, time);
		QUICK_TO_JSON_FIELD(j, v, timeArrayId);
		QUICK_TO_JSON_FIELD(j, v, pauseArrayId);
		QUICK_TO_JSON_FIELD(j, v, levelId);
		QUICK_TO_JSON_FIELD(j, v, gameId);
		QUICK_TO_JSON_FIELD(j, v, animId);
		QUICK_TO_JSON_FIELD(j, v, freeEntList);
		QUICK_TO_JSON_FIELD(j, v, tempVariable);
		QUICK_TO_JSON_FIELD(j, v, bInited);
		QUICK_TO_JSON_FIELD(j, v, savecount);
		QUICK_TO_JSON_FIELD(j, v, checksum);
		QUICK_TO_JSON_FIELD(j, v, entId);
		QUICK_TO_JSON_FIELD(j, v, entFieldName);
		QUICK_TO_JSON_FIELD_SL_STRING(j, v, entFieldName);
		QUICK_TO_JSON_FIELD_PTR_ADDR(j, v, programHunkUser);
		QUICK_TO_JSON_FIELD_PTR_ADDR(j, v, programBuffer);
		QUICK_TO_JSON_FIELD_PTR_ADDR(j, v, endScriptBuffer);
		QUICK_TO_JSON_FIELD_ARRAY(j, v, saveIdMap);
		QUICK_TO_JSON_FIELD_ARRAY(j, v, saveIdMapRev);
	}
}

// https://stackoverflow.com/questions/5693192/win32-backtrace-from-c-code
std::string printStack()
{
	unsigned int   i;
	void         * stack[ 100 ];
	unsigned short frames;
	SYMBOL_INFO  * symbol;
	HANDLE         process;
	std::string answer;

	process = GetCurrentProcess();

	SymInitialize( process, NULL, TRUE );

	frames               = CaptureStackBackTrace( 0, 100, stack, NULL );
	symbol               = ( SYMBOL_INFO * )calloc( sizeof( SYMBOL_INFO ) + 256 * sizeof( char ), 1 );
	symbol->MaxNameLen   = 255;
	symbol->SizeOfStruct = sizeof( SYMBOL_INFO );

	for( i = 0; i < frames; i++ )
	{
		SymFromAddr( process, ( DWORD64 )( stack[ i ] ), 0, symbol );

		answer += std::format("{}: {} - {:06x}\n", frames - i - 1, symbol->Name, symbol->Address);
	}

	free( symbol );

	return answer;
}

std::string get_full_gsc_state_str(game::scriptInstance_t inst)
{
	nlohmann::json answer;
	auto t = *game::gInst;
	*game::gInst = inst;

	answer["inst"] = inst;
	answer["gScrVarPub"] = game::gScrVarPub[inst];
	answer["stack"] = printStack();

	*game::gInst = t;

	return answer.dump(2);
}
