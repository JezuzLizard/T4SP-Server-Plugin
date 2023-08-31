#pragma once

namespace game
{
	WEAK symbol<unsigned int(const char* str, scriptInstance_t inst)>SL_FindLowercaseString{ 0x0, 0x68DD50 };
	WEAK symbol<unsigned int(scriptInstance_t inst, const char* string, unsigned int user, unsigned int len)>SL_GetStringOfSize{ 0x0, 0x68DE50 };
	WEAK symbol<unsigned int(scriptInstance_t inst, const char* str, unsigned int user, unsigned int len)>SL_GetLowercaseStringOfLen{ 0x0, 0x68E390 };
	WEAK symbol<unsigned int(scriptInstance_t inst, unsigned int stringVal, unsigned int user)>SL_ConvertToLowercase{ 0x0, 0x68E450 };
	WEAK symbol<void(scriptInstance_t inst, unsigned int stringValue, RefString* refStr, unsigned int len)>SL_FreeString{ 0x0, 0x68E570 };
	WEAK symbol<void()>SL_TransferSystem{ 0x0, 0x68E9D0 };
	WEAK symbol<unsigned int(scriptInstance_t inst, const char* filename)>Scr_CreateCanonicalFilename{ 0x0, 0x68EB00 };

	inline void* SL_ConvertToString_ADDR() { return CALL_ADDR(0x0, 0x68D950); }
	char* SL_ConvertToString(unsigned int stringValue, scriptInstance_t inst, void* call_addr = SL_ConvertToString_ADDR());
	inline void* SL_GetStringLen_ADDR() { return CALL_ADDR(0x0, 0x68D970); }
	int SL_GetStringLen(unsigned int stringValue, scriptInstance_t inst, void* call_addr = SL_GetStringLen_ADDR());
	inline void* GetHashCode_ADDR() { return CALL_ADDR(0x0, 0x68D9A0); }
	unsigned int GetHashCode(unsigned int len, const char* str, void* call_addr = GetHashCode_ADDR());
	inline void* SL_Init_ADDR() { return CALL_ADDR(0x0, 0x68D9F0); }
	void SL_Init(scriptInstance_t inst, void* call_addr = SL_Init_ADDR());
	inline void* SL_FindStringOfSize_ADDR() { return CALL_ADDR(0x0, 0x68DA90); }
	unsigned int SL_FindStringOfSize(scriptInstance_t inst, const char* str, unsigned int len, void* call_addr = SL_FindStringOfSize_ADDR());
	inline void* SL_FindString_ADDR() { return CALL_ADDR(0x0, 0x68DD20); }
	unsigned int SL_FindString(const char* str, scriptInstance_t inst, void* call_addr = SL_FindString_ADDR());
	inline void* SL_AddUserInternal_ADDR() { return CALL_ADDR(0x0, 0x68DDE0); }
	signed __int32 SL_AddUserInternal(unsigned int user, RefString* refStr, void* call_addr = SL_AddUserInternal_ADDR());
	inline void* Mark_ScriptStringCustom_ADDR() { return CALL_ADDR(0x0, 0x68DE10); }
	int Mark_ScriptStringCustom(unsigned int stringValue, void* call_addr = Mark_ScriptStringCustom_ADDR());
	inline void* SL_GetString__ADDR() { return CALL_ADDR(0x0, 0x68E330); }
	unsigned int SL_GetString_(const char* str, scriptInstance_t inst, unsigned int user, void* call_addr = SL_GetString__ADDR());
	inline void* SL_GetString__0_ADDR() { return CALL_ADDR(0x0, 0x68E360); }
	unsigned int SL_GetString__0(const char* str, unsigned int user, scriptInstance_t inst, void* call_addr = SL_GetString__0_ADDR());
	inline void* SL_GetLowercaseString_ADDR() { return CALL_ADDR(0x0, 0x68E420); }
	unsigned int SL_GetLowercaseString(const char* str, void* call_addr = SL_GetLowercaseString_ADDR());
	inline void* SL_TransferRefToUser_ADDR() { return CALL_ADDR(0x0, 0x68E530); }
	void SL_TransferRefToUser(unsigned int stringValue, int user, scriptInstance_t inst, void* call_addr = SL_TransferRefToUser_ADDR());
	inline void* SL_RemoveRefToString_ADDR() { return CALL_ADDR(0x0, 0x68E680); }
	void SL_RemoveRefToString(unsigned int stringVal, scriptInstance_t inst, void* call_addr = SL_RemoveRefToString_ADDR());
	inline void* Scr_SetString_ADDR() { return CALL_ADDR(0x0, 0x68E6E0); }
	void Scr_SetString(scriptInstance_t inst, unsigned int from, unsigned __int16* to, void* call_addr = Scr_SetString_ADDR());
	inline void* Scr_SetStringFromCharString_ADDR() { return CALL_ADDR(0x0, 0x68E720); }
	void Scr_SetStringFromCharString(const char* from, unsigned short* to, void* call_addr = Scr_SetStringFromCharString_ADDR());
	inline void* GScr_AllocString_ADDR() { return CALL_ADDR(0x0, 0x68E770); }
	unsigned int GScr_AllocString(const char* str, scriptInstance_t inst, void* call_addr = GScr_AllocString_ADDR());
	inline void* SL_GetStringForFloat_ADDR() { return CALL_ADDR(0x0, 0x68E7A0); }
	unsigned int SL_GetStringForFloat(float value, scriptInstance_t inst, void* call_addr = SL_GetStringForFloat_ADDR());
	inline void* SL_GetStringForInt_ADDR() { return CALL_ADDR(0x0, 0x68E800); }
	unsigned int SL_GetStringForInt(int value, scriptInstance_t inst, void* call_addr = SL_GetStringForInt_ADDR());
	inline void* SL_GetStringForVector_ADDR() { return CALL_ADDR(0x0, 0x68E850); }
	unsigned int SL_GetStringForVector(float* value, scriptInstance_t inst, void* call_addr = SL_GetStringForVector_ADDR());
	inline void* SL_ShutdownSystem_ADDR() { return CALL_ADDR(0x0, 0x68E8D0); }
	void SL_ShutdownSystem(scriptInstance_t inst, unsigned int user, void* call_addr = SL_ShutdownSystem_ADDR());
	inline void* SL_CreateCanonicalFilename_ADDR() { return CALL_ADDR(0x0, 0x68EA80); }
	void SL_CreateCanonicalFilename(const char* filename, char* newFilename, void* call_addr = SL_CreateCanonicalFilename_ADDR());

	RefString* GetRefString(scriptInstance_t inst, unsigned int id);
	void SL_AddRefToString(scriptInstance_t inst, unsigned int stringValue);
	void SL_RemoveRefToStringOfSize(scriptInstance_t inst, unsigned int stringValue, unsigned int len);
	int SL_GetRefStringLen(RefString* refString);
	void SL_AddUser(unsigned int stringValue, unsigned int user, scriptInstance_t inst);
	int SL_ConvertFromString(scriptInstance_t inst, const char* str);
	int SL_ConvertFromRefString(scriptInstance_t inst, RefString* refString);
	RefString* GetRefString_0(scriptInstance_t inst, const char* str);
	const char* SL_DebugConvertToString(unsigned int stringValue, scriptInstance_t inst);
}