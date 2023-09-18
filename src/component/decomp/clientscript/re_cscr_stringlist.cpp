#include <stdinc.hpp>
#include "loader/component_loader.hpp"
#include "utils/hook.hpp"
#include "codsrc/clientscript/cscr_stringlist.hpp"

#ifndef DISABLE_RE_CSCR_STRINGLIST
namespace re_cscr_stringlist
{
	utils::hook::detour SL_ConvertToString_hook;
	utils::hook::detour SL_GetStringLen_hook;
	utils::hook::detour GetHashCode_hook;
	utils::hook::detour SL_Init_hook;
	utils::hook::detour SL_FindStringOfSize_hook;
	utils::hook::detour SL_FindString_hook;
	utils::hook::detour SL_FindLowercaseString_hook;
	utils::hook::detour SL_AddUserInternal_hook;
	utils::hook::detour Mark_ScriptStringCustom_hook;
	utils::hook::detour SL_GetStringOfSize_hook;
	utils::hook::detour SL_GetString__hook;
	utils::hook::detour SL_GetString__0_hook;
	utils::hook::detour SL_GetLowercaseStringOfLen_hook;
	utils::hook::detour SL_GetLowercaseString_hook;
	utils::hook::detour SL_ConvertToLowercase_hook;
	utils::hook::detour SL_TransferRefToUser_hook;
	utils::hook::detour SL_FreeString_hook;
	utils::hook::detour SL_RemoveRefToString_hook;
	utils::hook::detour Scr_SetString_hook;
	utils::hook::detour Scr_SetStringFromCharString_hook;
	utils::hook::detour GScr_AllocString_hook;
	utils::hook::detour SL_GetStringForFloat_hook;
	utils::hook::detour SL_GetStringForInt_hook;
	utils::hook::detour SL_GetStringForVector_hook;
	utils::hook::detour SL_ShutdownSystem_hook;
	utils::hook::detour SL_TransferSystem_hook;
	utils::hook::detour SL_CreateCanonicalFilename_hook;
	utils::hook::detour Scr_CreateCanonicalFilename_hook;

	void* SL_ConvertToString_original;
	void* SL_GetStringLen_original;
	void* GetHashCode_original;
	void* SL_Init_original;
	void* SL_FindStringOfSize_original;
	void* SL_FindString_original;
	void* SL_FindLowercaseString_original;
	void* SL_AddUserInternal_original;
	void* Mark_ScriptStringCustom_original;
	void* SL_GetStringOfSize_original;
	void* SL_GetString__original;
	void* SL_GetString__0_original;
	void* SL_GetLowercaseStringOfLen_original;
	void* SL_GetLowercaseString_original;
	void* SL_ConvertToLowercase_original;
	void* SL_TransferRefToUser_original;
	void* SL_FreeString_original;
	void* SL_RemoveRefToString_original;
	void* Scr_SetString_original;
	void* Scr_SetStringFromCharString_original;
	void* GScr_AllocString_original;
	void* SL_GetStringForFloat_original;
	void* SL_GetStringForInt_original;
	void* SL_GetStringForVector_original;
	void* SL_ShutdownSystem_original;
	void* SL_TransferSystem_original;
	void* SL_CreateCanonicalFilename_original;
	void* Scr_CreateCanonicalFilename_original;

	namespace
	{

		char* SL_ConvertToString_call(unsigned int id, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_STRINGLIST_USE_WRAPPERS
			return game::SL_ConvertToString(id, inst, SL_ConvertToString_original);
#else
			return codsrc::SL_ConvertToString(id, inst);
#endif
		}

		// char *__usercall SL_ConvertToString@<eax>(unsigned int id@<eax>, game::scriptInstance_t inst@<ecx>)
		NAKED char* SL_ConvertToString_stub()
		{
			_asm
			{
				push ecx;
				push eax;
				call SL_ConvertToString_call;
				add esp, 0x8;
				ret;
			}
		}

		int SL_GetStringLen_call(unsigned int a1, game::scriptInstance_t a2, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_STRINGLIST_USE_WRAPPERS
			return game::SL_GetStringLen(a1, a2, SL_GetStringLen_original);
#else
			return codsrc::SL_GetStringLen(a1, a2);
#endif
		}

		// int __usercall SL_GetStringLen@<eax>(unsigned int a1@<eax>, game::scriptInstance_t a2@<ecx>)
		NAKED int SL_GetStringLen_stub()
		{
			_asm
			{
				push ecx;
				push eax;
				call SL_GetStringLen_call;
				add esp, 0x8;
				ret;
			}
		}

		unsigned int GetHashCode_call(unsigned int a1, const char* a2, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_STRINGLIST_USE_WRAPPERS
			return game::GetHashCode(a1, a2, GetHashCode_original);
#else
			return codsrc::GetHashCode(a1, a2);
#endif
		}

		// unsigned int __usercall GetHashCode@<eax>(unsigned int a1@<eax>, const char *a2@<edx>)
		NAKED unsigned int GetHashCode_stub()
		{
			_asm
			{
				push edx;
				push eax;
				call GetHashCode_call;
				add esp, 0x8;
				ret;
			}
		}

		void SL_Init_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_STRINGLIST_USE_WRAPPERS
			game::SL_Init(a1, SL_Init_original);
#else
			codsrc::SL_Init(a1);
#endif
		}

		// void __usercall SL_Init(game::scriptInstance_t a1@<eax>)
		NAKED void SL_Init_stub()
		{
			_asm
			{
				push eax;
				call SL_Init_call;
				add esp, 0x4;
				ret;
			}
		}

		unsigned int SL_FindStringOfSize_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, const char* str_, unsigned int len)
		{
#ifdef RE_CSCR_STRINGLIST_USE_WRAPPERS
			return game::SL_FindStringOfSize(inst, str_, len, SL_FindStringOfSize_original);
#else
			return codsrc::SL_FindStringOfSize(inst, str_, len);
#endif
		}

		// unsigned int __usercall SL_FindStringOfSize@<eax>(game::scriptInstance_t inst@<eax>, const char *str, unsigned int len)
		NAKED unsigned int SL_FindStringOfSize_stub()
		{
			_asm
			{
				push eax;
				call SL_FindStringOfSize_call;
				add esp, 0x4;
				ret;
			}
		}

		unsigned int SL_FindString_call(const char* a1, [[maybe_unused]] void* caller_addr, game::scriptInstance_t a2)
		{
#ifdef RE_CSCR_STRINGLIST_USE_WRAPPERS
			return game::SL_FindString(a1, a2, SL_FindString_original);
#else
			return codsrc::SL_FindString(a1, a2);
#endif
		}

		// unsigned int __usercall SL_FindString@<eax>(const char *a1@<edx>, game::scriptInstance_t a2)
		NAKED unsigned int SL_FindString_stub()
		{
			_asm
			{
				push edx;
				call SL_FindString_call;
				add esp, 0x4;
				ret;
			}
		}

		unsigned int SL_FindLowercaseString_stub(const char* str, game::scriptInstance_t inst)
		{
#ifdef RE_CSCR_STRINGLIST_USE_WRAPPERS
			return SL_FindLowercaseString_hook.invoke<unsigned int>(str, inst);
#else
			return codsrc::SL_FindLowercaseString(str, inst);
#endif
		}

		void SL_AddUserInternal_call(unsigned int user, game::RefString* refStr, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_STRINGLIST_USE_WRAPPERS
			game::SL_AddUserInternal(user, refStr, SL_AddUserInternal_original);
#else
			codsrc::SL_AddUserInternal(user, refStr);
#endif
		}

		// void __usercall SL_AddUserInternal(unsigned int user@<eax>, RefString *refStr@<edx>)
		NAKED void SL_AddUserInternal_stub()
		{
			_asm
			{
				push edx;
				push eax;
				call SL_AddUserInternal_call;
				add esp, 0x8;
				ret;
			}
		}

		void Mark_ScriptStringCustom_call(unsigned int a1, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_STRINGLIST_USE_WRAPPERS
			game::Mark_ScriptStringCustom(a1, Mark_ScriptStringCustom_original);
#else
			codsrc::Mark_ScriptStringCustom(a1);
#endif
		}

		// void __usercall Mark_ScriptStringCustom(unsigned __int16 *a1@<eax>)
		NAKED void Mark_ScriptStringCustom_stub()
		{
			_asm
			{
				push eax;
				call Mark_ScriptStringCustom_call;
				add esp, 0x4;
				ret;
			}
		}

		unsigned int SL_GetStringOfSize_stub(game::scriptInstance_t inst, const char* string, unsigned int user, unsigned int len)
		{
#ifdef RE_CSCR_STRINGLIST_USE_WRAPPERS
			return SL_GetStringOfSize_hook.invoke<unsigned int>(inst, string, user, len);
#else
			return codsrc::SL_GetStringOfSize(inst, string, user, len);
#endif
		}

		unsigned int SL_GetString__call(const char* a1, [[maybe_unused]] void* caller_addr, game::scriptInstance_t a2, unsigned int user)
		{
#ifdef RE_CSCR_STRINGLIST_USE_WRAPPERS
			return game::SL_GetString_(a1, a2, user, SL_GetString__original);
#else
			return codsrc::SL_GetString_(a1, a2, user);
#endif
		}

		// unsigned int __usercall SL_GetString_@<eax>(const char *a1@<edx>, game::scriptInstance_t a2, unsigned int user)
		NAKED unsigned int SL_GetString__stub()
		{
			_asm
			{
				push edx;
				call SL_GetString__call;
				add esp, 0x4;
				ret;
			}
		}

		unsigned int SL_GetString__0_call(const char* a1, [[maybe_unused]] void* caller_addr, unsigned int user, game::scriptInstance_t a3)
		{
#ifdef RE_CSCR_STRINGLIST_USE_WRAPPERS
			return game::SL_GetString__0(a1, user, a3, SL_GetString__0_original);
#else
			return codsrc::SL_GetString__0(a1, user, a3);
#endif
		}

		// unsigned int __usercall SL_GetString__0@<eax>(const char *a1@<edx>, unsigned int user, game::scriptInstance_t a3)
		NAKED unsigned int SL_GetString__0_stub()
		{
			_asm
			{
				push edx;
				call SL_GetString__0_call;
				add esp, 0x4;
				ret;
			}
		}

		unsigned int SL_GetLowercaseStringOfLen_stub(game::scriptInstance_t a1, const char* ArgList, unsigned int user, unsigned int len)
		{
#ifdef RE_CSCR_STRINGLIST_USE_WRAPPERS
			return SL_GetLowercaseStringOfLen_hook.invoke<unsigned int>(a1, ArgList, user, len);
#else
			return codsrc::SL_GetLowercaseStringOfLen(a1, ArgList, user, len);
#endif
		}

		unsigned int SL_GetLowercaseString_call(const char* a2, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_STRINGLIST_USE_WRAPPERS
			return game::SL_GetLowercaseString(a2, SL_GetLowercaseString_original);
#else
			return codsrc::SL_GetLowercaseString(a2);
#endif
		}

		// unsigned int __usercall SL_GetLowercaseString@<eax>(const char *a2@<edx>)
		NAKED unsigned int SL_GetLowercaseString_stub()
		{
			_asm
			{
				push edx;
				call SL_GetLowercaseString_call;
				add esp, 0x4;
				ret;
			}
		}

		unsigned int SL_ConvertToLowercase_stub(game::scriptInstance_t inst, unsigned int stringVal, unsigned int user)
		{
#ifdef RE_CSCR_STRINGLIST_USE_WRAPPERS
			return SL_ConvertToLowercase_hook.invoke<unsigned int>(inst, stringVal, user);
#else
			return codsrc::SL_ConvertToLowercase(inst, stringVal, user);
#endif
		}

		void SL_TransferRefToUser_call(unsigned int stringValue, unsigned int user, [[maybe_unused]] void* caller_addr, game::scriptInstance_t inst)
		{
#ifdef RE_CSCR_STRINGLIST_USE_WRAPPERS
			game::SL_TransferRefToUser(stringValue, user, inst, SL_TransferRefToUser_original);
#else
			codsrc::SL_TransferRefToUser(stringValue, user, inst);
#endif
		}

		// void __usercall SL_TransferRefToUser(unsigned int stringValue@<eax>, unsigned int user@<ecx>, game::scriptInstance_t inst)
		NAKED void SL_TransferRefToUser_stub()
		{
			_asm
			{
				push ecx;
				push eax;
				call SL_TransferRefToUser_call;
				add esp, 0x8;
				ret;
			}
		}

		void SL_FreeString_stub(game::scriptInstance_t a1, unsigned int a2, game::RefString* a3, unsigned int a4)
		{
#ifdef RE_CSCR_STRINGLIST_USE_WRAPPERS
			SL_FreeString_hook.invoke<void>(a1, a2, a3, a4);
#else
			codsrc::SL_FreeString(a1, a2, a3, a4);
#endif
		}

		void SL_RemoveRefToString_call(unsigned int stringVal, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_STRINGLIST_USE_WRAPPERS
			game::SL_RemoveRefToString(stringVal, inst, SL_RemoveRefToString_original);
#else
			codsrc::SL_RemoveRefToString(stringVal, inst);
#endif
		}

		// void __usercall SL_RemoveRefToString(unsigned int stringVal@<edx>, game::scriptInstance_t inst@<esi>)
		NAKED void SL_RemoveRefToString_stub()
		{
			_asm
			{
				push esi;
				push edx;
				call SL_RemoveRefToString_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_SetString_call(game::scriptInstance_t inst, unsigned int from, [[maybe_unused]] void* caller_addr, unsigned __int16* to)
		{
#ifdef RE_CSCR_STRINGLIST_USE_WRAPPERS
			game::Scr_SetString(inst, from, to, Scr_SetString_original);
#else
			codsrc::Scr_SetString(inst, from, to);
#endif
		}

		// void __usercall Scr_SetString(game::scriptInstance_t inst@<eax>, unsigned int from@<edi>, unsigned __int16 *to)
		NAKED void Scr_SetString_stub()
		{
			_asm
			{
				push edi;
				push eax;
				call Scr_SetString_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_SetStringFromCharString_call(const char* a1, [[maybe_unused]] void* caller_addr, unsigned __int16* a2)
		{
#ifdef RE_CSCR_STRINGLIST_USE_WRAPPERS
			game::Scr_SetStringFromCharString(a1, a2, Scr_SetStringFromCharString_original);
#else
			codsrc::Scr_SetStringFromCharString(a1, a2);
#endif
		}

		// unsigned int __usercall Scr_SetStringFromCharString@<eax>(const char *a1@<edi>, unsigned __int16 *a2)
		NAKED void Scr_SetStringFromCharString_stub()
		{
			_asm
			{
				push edi;
				call Scr_SetStringFromCharString_call;
				add esp, 0x4;
				ret;
			}
		}

		unsigned int GScr_AllocString_call(const char* a1, [[maybe_unused]] void* caller_addr, game::scriptInstance_t inst)
		{
#ifdef RE_CSCR_STRINGLIST_USE_WRAPPERS
			return game::GScr_AllocString(a1, inst, GScr_AllocString_original);
#else
			return codsrc::GScr_AllocString(a1, inst);
#endif
		}

		// unsigned int __usercall GScr_AllocString@<eax>(const char *a1@<edx>, game::scriptInstance_t inst)
		NAKED unsigned int GScr_AllocString_stub()
		{
			_asm
			{
				push edx;
				call GScr_AllocString_call;
				add esp, 0x4;
				ret;
			}
		}

		unsigned int SL_GetStringForFloat_call(float a1, [[maybe_unused]] void* caller_addr, game::scriptInstance_t a2)
		{
#ifdef RE_CSCR_STRINGLIST_USE_WRAPPERS
			return game::SL_GetStringForFloat(a1, a2, SL_GetStringForFloat_original);
#else
			return codsrc::SL_GetStringForFloat(a1, a2);
#endif
		}

		// unsigned int __usercall SL_GetStringForFloat@<eax>(float a1@<xmm0>, game::scriptInstance_t a2)
		NAKED unsigned int SL_GetStringForFloat_stub()
		{
			_asm
			{
				movd eax, xmm0;
				push eax;
				call SL_GetStringForFloat_call;
				add esp, 0x4;
				ret;
			}
		}

		unsigned int SL_GetStringForInt_call(int a1, [[maybe_unused]] void* caller_addr, game::scriptInstance_t a2)
		{
#ifdef RE_CSCR_STRINGLIST_USE_WRAPPERS
			return game::SL_GetStringForInt(a1, a2, SL_GetStringForInt_original);
#else
			return codsrc::SL_GetStringForInt(a1, a2);
#endif
		}

		// unsigned int __usercall SL_GetStringForInt@<eax>(int a1@<eax>, game::scriptInstance_t a2)
		NAKED unsigned int SL_GetStringForInt_stub()
		{
			_asm
			{
				push eax;
				call SL_GetStringForInt_call;
				add esp, 0x4;
				ret;
			}
		}

		unsigned int SL_GetStringForVector_call(float* a1, [[maybe_unused]] void* caller_addr, game::scriptInstance_t a2)
		{
#ifdef RE_CSCR_STRINGLIST_USE_WRAPPERS
			return game::SL_GetStringForVector(a1, a2, SL_GetStringForVector_original);
#else
			return codsrc::SL_GetStringForVector(a1, a2);
#endif
		}

		// unsigned int __usercall SL_GetStringForVector@<eax>(float *a1@<eax>, game::scriptInstance_t a2)
		NAKED unsigned int SL_GetStringForVector_stub()
		{
			_asm
			{
				push eax;
				call SL_GetStringForVector_call;
				add esp, 0x4;
				ret;
			}
		}

		void SL_ShutdownSystem_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr, unsigned int a2)
		{
#ifdef RE_CSCR_STRINGLIST_USE_WRAPPERS
			game::SL_ShutdownSystem(a1, a2, SL_ShutdownSystem_original);
#else
			codsrc::SL_ShutdownSystem(a1, a2);
#endif
		}

		// void __usercall SL_ShutdownSystem(game::scriptInstance_t a1@<edi>, unsigned int a2)
		NAKED void SL_ShutdownSystem_stub()
		{
			_asm
			{
				push edi;
				call SL_ShutdownSystem_call;
				add esp, 0x4;
				ret;
			}
		}

		void SL_TransferSystem_stub()
		{
#ifdef RE_CSCR_STRINGLIST_USE_WRAPPERS
			SL_TransferSystem_hook.invoke<void>();
#else
			codsrc::SL_TransferSystem();
#endif
		}

		void SL_CreateCanonicalFilename_call(const char* filename, [[maybe_unused]] void* caller_addr, char* newFilename)
		{
#ifdef RE_CSCR_STRINGLIST_USE_WRAPPERS
			game::SL_CreateCanonicalFilename(filename, newFilename, SL_CreateCanonicalFilename_original);
#else
			codsrc::SL_CreateCanonicalFilename(filename, newFilename);
#endif
		}

		// void __usercall SL_CreateCanonicalFilename(const char *filename@<eax>, char *newFilename)
		NAKED void SL_CreateCanonicalFilename_stub()
		{
			_asm
			{
				push eax;
				call SL_CreateCanonicalFilename_call;
				add esp, 0x4;
				ret;
			}
		}

		unsigned int Scr_CreateCanonicalFilename_stub(game::scriptInstance_t a1, const char* a2)
		{
#ifdef RE_CSCR_STRINGLIST_USE_WRAPPERS
			return Scr_CreateCanonicalFilename_hook.invoke<unsigned int>(a1, a2);
#else
			return codsrc::Scr_CreateCanonicalFilename(a1, a2);
#endif
		}
	}

	class component final : public component_interface
	{
	public:
		void post_unpack() override
		{
			SL_ConvertToString_hook.create(game::SL_ConvertToString_ADDR(), SL_ConvertToString_stub);
			SL_GetStringLen_hook.create(game::SL_GetStringLen_ADDR(), SL_GetStringLen_stub);
			GetHashCode_hook.create(game::GetHashCode_ADDR(), GetHashCode_stub);
			SL_Init_hook.create(game::SL_Init_ADDR(), SL_Init_stub);
			SL_FindStringOfSize_hook.create(game::SL_FindStringOfSize_ADDR(), SL_FindStringOfSize_stub);
			SL_FindString_hook.create(game::SL_FindString_ADDR(), SL_FindString_stub);
			SL_FindLowercaseString_hook.create(game::SL_FindLowercaseString.get(), SL_FindLowercaseString_stub);
			SL_AddUserInternal_hook.create(game::SL_AddUserInternal_ADDR(), SL_AddUserInternal_stub);
			Mark_ScriptStringCustom_hook.create(game::Mark_ScriptStringCustom_ADDR(), Mark_ScriptStringCustom_stub);
			SL_GetStringOfSize_hook.create(game::SL_GetStringOfSize.get(), SL_GetStringOfSize_stub);
			SL_GetString__hook.create(game::SL_GetString__ADDR(), SL_GetString__stub);
			SL_GetString__0_hook.create(game::SL_GetString__0_ADDR(), SL_GetString__0_stub);
			SL_GetLowercaseStringOfLen_hook.create(game::SL_GetLowercaseStringOfLen.get(), SL_GetLowercaseStringOfLen_stub);
			SL_GetLowercaseString_hook.create(game::SL_GetLowercaseString_ADDR(), SL_GetLowercaseString_stub);
			SL_ConvertToLowercase_hook.create(game::SL_ConvertToLowercase.get(), SL_ConvertToLowercase_stub);
			SL_TransferRefToUser_hook.create(game::SL_TransferRefToUser_ADDR(), SL_TransferRefToUser_stub);
			SL_FreeString_hook.create(game::SL_FreeString.get(), SL_FreeString_stub);
			SL_RemoveRefToString_hook.create(game::SL_RemoveRefToString_ADDR(), SL_RemoveRefToString_stub);
			Scr_SetString_hook.create(game::Scr_SetString_ADDR(), Scr_SetString_stub);
			Scr_SetStringFromCharString_hook.create(game::Scr_SetStringFromCharString_ADDR(), Scr_SetStringFromCharString_stub);
			GScr_AllocString_hook.create(game::GScr_AllocString_ADDR(), GScr_AllocString_stub);
			SL_GetStringForFloat_hook.create(game::SL_GetStringForFloat_ADDR(), SL_GetStringForFloat_stub);
			SL_GetStringForInt_hook.create(game::SL_GetStringForInt_ADDR(), SL_GetStringForInt_stub);
			SL_GetStringForVector_hook.create(game::SL_GetStringForVector_ADDR(), SL_GetStringForVector_stub);
			SL_ShutdownSystem_hook.create(game::SL_ShutdownSystem_ADDR(), SL_ShutdownSystem_stub);
			SL_TransferSystem_hook.create(game::SL_TransferSystem.get(), SL_TransferSystem_stub);
			SL_CreateCanonicalFilename_hook.create(game::SL_CreateCanonicalFilename_ADDR(), SL_CreateCanonicalFilename_stub);
			Scr_CreateCanonicalFilename_hook.create(game::Scr_CreateCanonicalFilename.get(), Scr_CreateCanonicalFilename_stub);

			//Original hook function addresses
			SL_ConvertToString_original = SL_ConvertToString_hook.get_original();
			SL_GetStringLen_original = SL_GetStringLen_hook.get_original();
			GetHashCode_original = GetHashCode_hook.get_original();
			SL_Init_original = SL_Init_hook.get_original();
			SL_FindStringOfSize_original = SL_FindStringOfSize_hook.get_original();
			SL_FindString_original = SL_FindString_hook.get_original();
			SL_FindLowercaseString_original = SL_FindLowercaseString_hook.get_original();
			SL_AddUserInternal_original = SL_AddUserInternal_hook.get_original();
			Mark_ScriptStringCustom_original = Mark_ScriptStringCustom_hook.get_original();
			SL_GetStringOfSize_original = SL_GetStringOfSize_hook.get_original();
			SL_GetString__original = SL_GetString__hook.get_original();
			SL_GetString__0_original = SL_GetString__0_hook.get_original();
			SL_GetLowercaseStringOfLen_original = SL_GetLowercaseStringOfLen_hook.get_original();
			SL_GetLowercaseString_original = SL_GetLowercaseString_hook.get_original();
			SL_ConvertToLowercase_original = SL_ConvertToLowercase_hook.get_original();
			SL_TransferRefToUser_original = SL_TransferRefToUser_hook.get_original();
			SL_FreeString_original = SL_FreeString_hook.get_original();
			SL_RemoveRefToString_original = SL_RemoveRefToString_hook.get_original();
			Scr_SetString_original = Scr_SetString_hook.get_original();
			Scr_SetStringFromCharString_original = Scr_SetStringFromCharString_hook.get_original();
			GScr_AllocString_original = GScr_AllocString_hook.get_original();
			SL_GetStringForFloat_original = SL_GetStringForFloat_hook.get_original();
			SL_GetStringForInt_original = SL_GetStringForInt_hook.get_original();
			SL_GetStringForVector_original = SL_GetStringForVector_hook.get_original();
			SL_ShutdownSystem_original = SL_ShutdownSystem_hook.get_original();
			SL_TransferSystem_original = SL_TransferSystem_hook.get_original();
			SL_CreateCanonicalFilename_original = SL_CreateCanonicalFilename_hook.get_original();
			Scr_CreateCanonicalFilename_original = Scr_CreateCanonicalFilename_hook.get_original();
		}

	private:
	};
}
REGISTER_COMPONENT(re_cscr_stringlist::component)
#endif
