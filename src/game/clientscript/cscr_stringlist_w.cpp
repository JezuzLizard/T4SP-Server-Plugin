#include <stdinc.hpp>

namespace game
{
	// char *__usercall SL_ConvertToString@<eax>(unsigned int id@<eax>, scriptInstance_t inst@<ecx>)
	char* SL_ConvertToString(unsigned int id, scriptInstance_t inst, void* call_addr)
	{
		char* answer;

		__asm
		{
			mov eax, id;
			mov ecx, inst;
			call call_addr;
			mov answer, eax;
		}

		return answer;
	}

	// int __usercall SL_GetStringLen@<eax>(unsigned int a1@<eax>, scriptInstance_t a2@<ecx>)
	int SL_GetStringLen(unsigned int a1, scriptInstance_t a2, void* call_addr)
	{
		int answer;

		__asm
		{
			mov eax, a1;
			mov ecx, a2;
			call call_addr;
			mov answer, eax;
		}

		return answer;
	}

	// unsigned int __usercall GetHashCode@<eax>(unsigned int a1@<eax>, char *a2@<edx>)
	unsigned int GetHashCode(unsigned int a1, const char* a2, void* call_addr)
	{
		unsigned int answer;

		__asm
		{
			mov eax, a1;
			mov edx, a2;
			call call_addr;
			mov answer, eax;
		}

		return answer;
	}

	// void __usercall SL_Init(scriptInstance_t a1@<eax>)
	void SL_Init(scriptInstance_t a1, void* call_addr)
	{
		__asm
		{
			mov eax, a1;
			call call_addr;
		}
	}

	// unsigned int __usercall SL_FindStringOfSize@<eax>(scriptInstance_t inst@<eax>, const char *str, unsigned int len)
	unsigned int SL_FindStringOfSize(scriptInstance_t inst, const char* str_, unsigned int len, void* call_addr)
	{
		unsigned int answer;

		__asm
		{
			push len;
			push str_;
			mov eax, inst;
			call call_addr;
			mov answer, eax;
			add esp, 0x8;
		}

		return answer;
	}

	// unsigned int __usercall SL_FindString@<eax>(char *a1@<edx>, scriptInstance_t a2)
	unsigned int SL_FindString(const char* a1, scriptInstance_t a2, void* call_addr)
	{
#if 0
	cscr_stringlist::SL_FindString
#endif

		unsigned int answer;

		__asm
		{
			push a2;
			mov edx, a1;
			call call_addr;
			mov answer, eax;
			add esp, 0x4;
		}

		return answer;
	}

	// signed __int32 __usercall SL_AddUserInternal@<eax>(int user@<eax>, volatile signed __int32 *a2@<edx>)
	signed __int32 SL_AddUserInternal(unsigned int user, RefString* a2, void* call_addr)
	{
		signed __int32 answer;

		__asm
		{
			mov eax, user;
			mov edx, a2;
			call call_addr;
			mov answer, eax;
		}

		return answer;
	}

	// int __usercall Mark_ScriptStringCustom@<eax>(int a1@<eax>)
	int Mark_ScriptStringCustom(unsigned int a1, void* call_addr)
	{
		int answer;

		__asm
		{
			mov eax, a1;
			call call_addr;
			mov answer, eax;
		}

		return answer;
	}

	// unsigned int __usercall SL_GetString_@<eax>(char *a1@<edx>, scriptInstance_t a2, int user)
	unsigned int SL_GetString_(const char* a1, scriptInstance_t a2, unsigned int user, void* call_addr)
	{
		unsigned int answer;

		__asm
		{
			push user;
			push a2;
			mov edx, a1;
			call call_addr;
			mov answer, eax;
			add esp, 0x8;
		}

		return answer;
	}

	// unsigned int __usercall SL_GetString__0@<eax>(char *a1@<edx>, int user, scriptInstance_t a3)
	unsigned int SL_GetString__0(const char* a1, unsigned int user, scriptInstance_t a3, void* call_addr)
	{
		unsigned int answer;

		__asm
		{
			push a3;
			push user;
			mov edx, a1;
			call call_addr;
			mov answer, eax;
			add esp, 0x8;
		}

		return answer;
	}

	// unsigned int __usercall SL_GetLowercaseString@<eax>(const char *a2@<edx>)
	unsigned int SL_GetLowercaseString(const char* a2, void* call_addr)
	{
		unsigned int answer;

		__asm
		{
			mov edx, a2;
			call call_addr;
			mov answer, eax;
		}

		return answer;
	}

	// void __usercall SL_TransferRefToUser(unsigned int stringValue@<eax>, int user@<ecx>, scriptInstance_t inst)
	void SL_TransferRefToUser(unsigned int stringValue, int user, scriptInstance_t inst, void* call_addr)
	{
		__asm
		{
			push inst;
			mov eax, stringValue;
			mov ecx, user;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall SL_RemoveRefToString(unsigned int stringVal@<edx>, scriptInstance_t inst@<esi>)
	void SL_RemoveRefToString(unsigned int stringVal/*@<edx>*/, scriptInstance_t inst/*@<esi>*/, void* call_addr)
	{
		__asm
		{
			mov edx, stringVal;
			mov esi, inst;
			call call_addr;
		}
	}

	// void __usercall Scr_SetString(scriptInstance_t inst@<eax>, unsigned int from@<edi>, unsigned __int16 *to)
	void Scr_SetString(scriptInstance_t inst, unsigned int from, unsigned __int16* to, void* call_addr)
	{
		__asm
		{
			push to;
			mov eax, inst;
			mov edi, from;
			call call_addr;
			add esp, 0x4;
		}
	}

	// unsigned int __usercall Scr_SetStringFromCharString@<eax>(char *a1@<edi>, _WORD *a2)
	void Scr_SetStringFromCharString(const char* a1, unsigned short* a2, void* call_addr)
	{
		__asm
		{
			push a2;
			mov edi, a1;
			call call_addr;
			add esp, 0x4;
		}
	}

	// unsigned int __usercall GScr_AllocString@<eax>(char *a1@<edx>, scriptInstance_t inst)
	unsigned int GScr_AllocString(const char* a1, scriptInstance_t inst, void* call_addr)
	{
		unsigned int answer;

		__asm
		{
			push inst;
			mov edx, a1;
			call call_addr;
			mov answer, eax;
			add esp, 0x4;
		}

		return answer;
	}

	// unsigned int __usercall SL_GetStringForFloat@<eax>(float a1@<xmm0>, scriptInstance_t a2)
	unsigned int SL_GetStringForFloat(float a1, scriptInstance_t a2, void* call_addr)
	{
		unsigned int answer;

		__asm
		{
			push a2;
			movsd xmm0, a1;
			call call_addr;
			mov answer, eax;
			add esp, 0x4;
		}

		return answer;
	}

	// unsigned int __usercall SL_GetStringForInt@<eax>(int a1@<eax>, scriptInstance_t a2)
	unsigned int SL_GetStringForInt(int a1, scriptInstance_t a2, void* call_addr)
	{
		unsigned int answer;

		__asm
		{
			push a2;
			mov eax, a1;
			call call_addr;
			mov answer, eax;
			add esp, 0x4;
		}

		return answer;
	}

	// unsigned int __usercall SL_GetStringForVector@<eax>(float *a1@<eax>, scriptInstance_t a2)
	unsigned int SL_GetStringForVector(float* a1, scriptInstance_t a2, void* call_addr)
	{
		unsigned int answer;

		__asm
		{
			push a2;
			mov eax, a1;
			call call_addr;
			mov answer, eax;
			add esp, 0x4;
		}

		return answer;
	}

	// void __usercall SL_ShutdownSystem(scriptInstance_t a1@<edi>, unsigned int a2)
	void SL_ShutdownSystem(scriptInstance_t a1, unsigned int a2, void* call_addr)
	{
		__asm
		{
			push a2;
			mov edi, a1;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall CreateCanonicalFilename(const char *a1@<eax>, char *a2)
	void SL_CreateCanonicalFilename(const char* a1, char* a2, void* call_addr)
	{
		__asm
		{
			push a2;
			mov eax, a1;
			call call_addr;
			add esp, 0x4;
		}
	}

	RefString* GetRefString(scriptInstance_t inst, unsigned int id)
	{
		//return cscr_stringlist::GetRefString(inst, id);
		return nullptr;
	}

	void SL_AddRefToString(scriptInstance_t inst, unsigned int stringValue)
	{
		//cscr_stringlist::SL_AddRefToString(inst, stringValue);
	}

	void SL_RemoveRefToStringOfSize(scriptInstance_t inst, unsigned int stringValue, unsigned int len)
	{
		//cscr_stringlist::SL_RemoveRefToStringOfSize(inst, stringValue, len);
	}

	int SL_GetRefStringLen(RefString* refString)
	{
		//return cscr_stringlist::SL_GetRefStringLen(refString);
		return 0;
	}

	void SL_AddUser(unsigned int stringValue, unsigned int user, scriptInstance_t inst)
	{
		//cscr_stringlist::SL_AddUser(stringValue, user, inst);
	}

	int SL_ConvertFromString(scriptInstance_t inst, const char* str)
	{
		//return cscr_stringlist::SL_ConvertFromString(inst, str);
		return 0;
	}

	int SL_ConvertFromRefString(scriptInstance_t inst, RefString* refString)
	{
		//return cscr_stringlist::SL_ConvertFromRefString(inst, refString);
		return 0;
	}

	RefString* GetRefString_0(scriptInstance_t inst, const char* str)
	{
		//return cscr_stringlist::GetRefString_0(inst, str);
		return nullptr;
	}

	const char* SL_DebugConvertToString(unsigned int stringValue, scriptInstance_t inst)
	{
		//return cscr_stringlist::SL_DebugConvertToString(stringValue, inst);
		return nullptr;
	}
}