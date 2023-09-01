#pragma once

namespace game
{
	// Functions
	WEAK symbol<void(con_channel_e channel, const char* fmt, ...)> Com_Printf{ 0x0, 0x59A2C0 };
	WEAK symbol<void(con_channel_e a1, const char* Source, int a3)>Com_PrintMessage{ 0x0, 0x59A170 };
	WEAK symbol<void(con_channel_e a1, const char* Format, ...)>Com_PrintWarning{ 0x0, 0x59A440 };
	WEAK symbol<void(con_channel_e a1, const char* Format, ...)>Com_PrintError{ 0x0, 0x59A380 };
	WEAK symbol<void(errorParm_t a1, const char* Format, ...)>Com_Error{ 0x0, 0x59AC50 };
	WEAK symbol<void(const char* Format, ...)>Sys_Error{ 0x0, 0x5FE8C0 };

	WEAK symbol<void(HunkUser *user)>Hunk_UserDestroy{ 0x0, 0x5E4940 };
	WEAK symbol<void *(HunkUser *user, int size, int alignment)> Hunk_UserAlloc{ 0x0, 0x5E47B0 };
	WEAK symbol<void()> Hunk_ClearTempMemoryHigh{ 0x0, 0x5E4300 };

	WEAK symbol<int(const char* filename, int* file)>FS_FOpenFileRead{ 0x0, 0x5DBD20 };
	WEAK symbol<int(char* Buffer, size_t ElementCount, int a3)>FS_Read{ 0x0, 0x5DBDF0 };
	WEAK symbol<int(const char* filename, int* file, fsMode_t mode)>FS_FOpenFileByMode{ 0x0, 0x5DB630 };

	WEAK symbol<const char*(const char* Format, ...)>va{ 0x0, 0x5F6D80 };

	WEAK symbol<parseInfo_t* (const char* ArgList)>Com_BeginParseSession{ 0x0, 0x5F5830 };
	WEAK symbol<void()> Com_EndParseSession{ 0x0, 0x5F5910 };
	WEAK symbol<int()> Sys_Milliseconds{ 0x0, 0x603D40 };

	WEAK symbol<void(char* Destination, const char* Source, size_t Count)>I_strncpyz{ 0x0, 0x7AA9C0 };

	inline void* I_strncmp_ADDR() { return CALL_ADDR(0x0, 0x5F6A40); }
	int I_strncmp(const char* str1, const char* str2, int len, void* call_addr = I_strncmp_ADDR());

	inline void* Hunk_UserCreate_ADDR() { return CALL_ADDR(0x0, 0x5E46E0); }
	HunkUser* Hunk_UserCreate(signed int maxSize, const char* name, int fixed, int tempMem, int debugMem, int type, void* call_addr = Hunk_UserCreate_ADDR());
	inline void* Hunk_AllocateTempMemoryHigh_ADDR() { return CALL_ADDR(0x0, 0x5E4220); }
	unsigned int Hunk_AllocateTempMemoryHigh(int size_, void* call_addr = Hunk_AllocateTempMemoryHigh_ADDR());

	inline void* FS_FCloseFile_ADDR() { return CALL_ADDR(0x0, 0x5DB060); }
	void FS_FCloseFile(int h, void* call_addr = FS_FCloseFile_ADDR());
	inline void* FS_ListFilteredFiles_ADDR() { return CALL_ADDR(0x0, 0x5DC720); }
	const char** FS_ListFilteredFiles(searchpath_s* searchPath, const char* path, const char* extension, const char* filter, FsListBehavior_e behavior, int* numFiles, void* call_addr = FS_ListFilteredFiles_ADDR());

	inline void* Z_TryVirtualAlloc_ADDR() { return CALL_ADDR(0x0, 0x5E39D0); }
	void* Z_TryVirtualAlloc(signed int size_, void* call_addr = Z_TryVirtualAlloc_ADDR());
	inline void* I_stricmp_ADDR() { return CALL_ADDR(0x0, 0x5F69E0); }
	int I_stricmp(int len, const char* s0, const char* s1, void* call_addr = I_stricmp_ADDR());

	inline void* Com_Parse_ADDR() { return CALL_ADDR(0x0, 0x5F61B0); }
	parseInfo_t* Com_Parse(const char** buffer, void* call_addr = Com_Parse_ADDR());

	inline void* Dvar_RegisterBool_ADDR() { return CALL_ADDR(0x0, 0x5EEE20); }
	dvar_s * Dvar_RegisterBool(unsigned __int8 val, const char * name, int flags, const char * desc, void* call_addr = Dvar_RegisterBool_ADDR());

	inline void* XAnimGetAnimDebugName_ADDR() { return CALL_ADDR(0x0, 0x60F850); }
	const char * XAnimGetAnimDebugName(unsigned int animIndex, XAnim_s * anims, void* call_addr = XAnimGetAnimDebugName_ADDR());

	void Sys_EnterCriticalSection(CriticalSection critSect);
	void Sys_LeaveCriticalSection(CriticalSection critSect);

	// Variables
	WEAK symbol<CRITICAL_SECTION> s_criticalSection{ 0x0, 0x2298D08 };
	WEAK symbol<HunkUser*> g_DebugHunkUser{ 0x0, 0x212B2EC };
	WEAK symbol<dvar_s*> useFastFile{ 0x0, 0x1F552FC };
	WEAK symbol<fileHandleData_t> fsh{ 0x0, 0x2126E20 };
	WEAK symbol<dvar_s*> fs_game{ 0x0, 0x2122B00 };
	WEAK symbol<dvar_s*> com_developer{ 0x0, 0x1F55288 };
	WEAK symbol<int> statmon_related_bool{ 0x0, 0x2122B04 };
	WEAK symbol<HunkUser*> g_allocNodeUser{ 0x0, 0x3882B20 };
	WEAK symbol<struct HunkUser *> g_user{ 0x0, 0x3882B48 };
	WEAK symbol<searchpath_s*> fs_searchpaths{ 0x0, 0x46E5044 };

	namespace plutonium
	{
		WEAK symbol<int(const char* fmt, ...)> printf{0x0, 0x0};

		WEAK symbol<void(scriptInstance_t)> load_custom_script_func{0x0, 0x0};
		WEAK symbol<void(char*, game::scriptInstance_t, sval_u*)> script_preprocess{0x0, 0x0};
		WEAK symbol<void(game::scriptInstance_t)> vm_execute_update_codepos{0x0, 0x0};
		WEAK symbol<void(game::scriptInstance_t, game::scriptInstance_t, unsigned int*, unsigned int*)> scr_execthread_update_codepos_func{0x0, 0x0};
		WEAK symbol<void(game::scriptInstance_t, unsigned int*)> scr_execentthread_update_codepos_func{ 0x0, 0x0 };
		WEAK symbol<void(game::scriptInstance_t, unsigned int*)> scr_addexecthread_update_codepos_func{ 0x0, 0x0 };
	}
}
