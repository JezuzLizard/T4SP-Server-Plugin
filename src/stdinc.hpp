#pragma once

#pragma warning(disable: 6011)
#pragma warning(disable: 6054)
#pragma warning(disable: 6387)
#pragma warning(disable: 26451)
#pragma warning(disable: 26812)
#pragma warning(disable: 28182)

#pragma warning(disable: 4324)
#pragma warning(disable: 4459)
#pragma warning(disable: 4611)
#pragma warning(error: 4409)

#define DLL_EXPORT extern "C" __declspec(dllexport)
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <vector>
#include <cassert>
#include <mutex>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <regex>
#include <queue>
#include <unordered_set>
#include <filesystem>
#include <map>
#include <csetjmp>
#include <atlcomcli.h>
#include <variant>
#include <optional>
#include <Psapi.h>
#include <timeapi.h>

#ifdef max
#undef max
#endif

#ifdef min
#undef min
#endif

#include <MinHook.h>
#include <gsl/gsl>

#include <json.hpp>

#include <asmjit/core/jitruntime.h>
#include <asmjit/x86/x86assembler.h>

#pragma comment(lib, "ntdll.lib")
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "urlmon.lib" )
#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "Crypt32.lib")
#pragma comment(lib, "Winmm.lib")

#include "utils/hexrays_defs.h"
#include "utils/io.hpp"

#undef GetObject

#include "game/game.hpp"
#include "game/enums.hpp"
#include "game/structs.hpp"
#include "game/symbols.hpp"

std::string build_gsc_dump(game::scriptInstance_t inst);
void push_opcode_history(game::scriptInstance_t inst, game::OpcodeVM op);
void push_builtin_history(game::scriptInstance_t inst, int idx);
void push_codepos_history(game::scriptInstance_t inst, const char* pos);
void print_ast(game::scriptInstance_t inst, game::sval_u node);

using namespace std::literals;