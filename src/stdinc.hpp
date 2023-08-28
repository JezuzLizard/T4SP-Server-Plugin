#pragma once

#pragma warning(disable: 6011)
#pragma warning(disable: 6054)
#pragma warning(disable: 6387)
#pragma warning(disable: 26451)
#pragma warning(disable: 26812)
#pragma warning(disable: 28182)

#pragma warning(disable: 4324)

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

#include "utils/hexrays_defs.h"
#include "game/structs.hpp"
#include "game/game.hpp"

#define printf(__fmt__, ...) \
	game::Com_Printf(game::CON_CHANNEL_SERVER, __fmt__, __VA_ARGS__)

using namespace std::literals;