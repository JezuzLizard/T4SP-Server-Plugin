#include <stdinc.hpp>

#include <utils/hook.hpp>
#include <utils/memory.hpp>
#include <utils/string.hpp>

namespace game
{
	gamemode current = reinterpret_cast<const char*>(0x88A5DC) != "CoDWaW.exe"s
		? gamemode::multiplayer
		: gamemode::singleplayer;

	namespace environment
	{
		bool t4mp()
		{
			return current == gamemode::multiplayer;
		}

		bool t4sp()
		{
			return current == gamemode::singleplayer;
		}
	}

	// HunkUser* __usercall Hunk_UserCreate@<eax>(signed int maxSize@<edi>, char* name, char fixed, char tempMem, char debugMem, int type);
	HunkUser* Hunk_UserCreate(signed int maxSize, const char* name, int fixed, int tempMem, int debugMem, int typ, void* call_addr)
	{
		HunkUser* answer;

		__asm
		{
			push typ;
			push debugMem;
			push tempMem;
			push fixed;
			push name;
			mov edi, maxSize;
			call call_addr;
			add esp, 0x14;
			mov answer, eax;
		}

		return answer;
	}

	// unsigned int __usercall Hunk_AllocateTempMemoryHigh@<eax>(int a1@<eax>)
	unsigned int Hunk_AllocateTempMemoryHigh(int size_, void* call_addr)
	{
		unsigned int answer;

		__asm
		{
			mov eax, size_;
			call call_addr;
			mov answer, eax;
		}

		return answer;
	}

	// void __usercall FS_FCloseFile(int h@<eax>)
	void FS_FCloseFile(int h, void* call_addr)
	{
		__asm
		{
			mov eax, h;
			call call_addr;
		}
	}

	// void *__usercall Z_TryVirtualAlloc@<eax>(signed int a1@<edi>)
	void* Z_TryVirtualAlloc(signed int size_, void* call_addr)
	{
		void* answer;

		__asm
		{
			mov edi, size_;
			call call_addr;
			mov answer, eax;
		}

		return answer;
	}

	// int __usercall I_stricmp@<eax>(int a1@<eax>, CHAR *a2@<edx>, const char *a3)
	int I_stricmp(int len, const char* s0, const char* s1, void* call_addr)
	{
		int answer;

		__asm
		{
			push s1;
			mov eax, len;
			mov edx, s0;
			call call_addr;
			mov answer, eax;
			add esp, 0x4;
		}

		return answer;
	}

	//parseInfo_t* __usercall Com_Parse@<eax>(const char** a1@<esi>)
	parseInfo_t* Com_Parse(const char** buffer, void* call_addr)
	{
		parseInfo_t* answer;

		__asm
		{
			mov esi, buffer;
			call call_addr;
			mov answer, eax;
		}

		return answer;
	}

	//int __usercall I_strncmp@<eax>(char *str1@<edx>, char *str2@<ecx>, int len)
	int I_strncmp(const char* str1, const char* str2, int len, void* call_addr)
	{
		int answer;

		__asm
		{
			push len;
			mov ecx, str2;
			mov edx, str1;
			call call_addr;
			mov answer, eax;
		}

		return answer;
	}

	// const char **__usercall FS_ListFilteredFiles@<eax>(searchpath_s *searchPath@<eax>, const char *path@<edx>, const char *extension, const char *filter, FsListBehavior_e behavior, int *numFiles)
	const char** FS_ListFilteredFiles(searchpath_s* searchPath, const char* path, const char* extension, const char* filter, FsListBehavior_e behavior, int* numFiles, void* call_addr)
	{
		const char** answer;

		__asm
		{
			push numFiles;
			push behavior;
			push filter;
			push extension;
			mov eax, searchPath;
			mov edx, path;
			call call_addr;
			mov answer, eax;
			add esp, 0x10;
		}

		return answer;
	}

	dvar_s * Dvar_RegisterBool/*@<eax>*/(unsigned __int8 val/*@<al>*/, const char * name/*@<edi>*/, int flags, const char * desc, void* call_addr)
	{
		dvar_s * answer;

		__asm
		{
			push desc;
			push flags;
			mov al, val;
			mov edi, name;
			call call_addr;
			mov answer, eax;
			add esp, 0x8;
		}

		return answer;
	}

	const char * XAnimGetAnimDebugName/*@<eax>*/(unsigned int animIndex/*@<ecx>*/, XAnim_s * anims/*@<edx>*/, void* call_addr)
	{
		const char * answer;

		__asm
		{
			mov ecx, animIndex;
			mov edx, anims;
			call call_addr;
			mov answer, eax;
		}

		return answer;
	}

	// restored
	void Sys_EnterCriticalSection(CriticalSection critSect)
	{
		EnterCriticalSection(&s_criticalSection[critSect]);
	}

	// restored
	void Sys_LeaveCriticalSection(CriticalSection critSect)
	{
		LeaveCriticalSection(&s_criticalSection[critSect]);
	}

	namespace plutonium
	{
	}
}
