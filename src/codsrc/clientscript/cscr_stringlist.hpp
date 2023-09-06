#pragma once

namespace codsrc
{
	char* SL_ConvertToString(unsigned int id, game::scriptInstance_t inst);
	int SL_GetStringLen(unsigned int a1, game::scriptInstance_t a2);
	unsigned int GetHashCode(unsigned int a1, const char* a2);
	void SL_Init(game::scriptInstance_t a1);
	unsigned int SL_FindStringOfSize(game::scriptInstance_t inst, const char* str, unsigned int len);
	unsigned int SL_FindString(const char* a1, game::scriptInstance_t a2);
	unsigned int SL_FindLowercaseString(const char* str, game::scriptInstance_t inst);
	void SL_AddUserInternal(unsigned int user, game::RefString* refStr);
	void Mark_ScriptStringCustom(unsigned int a1);
	unsigned int SL_GetStringOfSize(game::scriptInstance_t inst, const char* string, unsigned int user, unsigned int len);
	unsigned int SL_GetString_(const char* a1, game::scriptInstance_t a2, unsigned int user);
	unsigned int SL_GetString__0(const char* a1, unsigned int user, game::scriptInstance_t a3);
	unsigned int SL_GetLowercaseStringOfLen(game::scriptInstance_t a1, const char* ArgList, unsigned int user, unsigned int len);
	unsigned int SL_GetLowercaseString(const char* a2);
	unsigned int SL_ConvertToLowercase(game::scriptInstance_t inst, unsigned int stringVal, unsigned int user);
	void SL_TransferRefToUser(unsigned int stringValue, unsigned int user, game::scriptInstance_t inst);
	void SL_FreeString(game::scriptInstance_t inst, unsigned int stringValue, game::RefString* refStr, unsigned int len);
	void SL_RemoveRefToString(unsigned int stringVal, game::scriptInstance_t inst);
	void SL_AddRefToString(game::scriptInstance_t inst, unsigned int stringValue);
	void Scr_SetString(game::scriptInstance_t inst, unsigned int from, unsigned __int16* to);
	void Scr_SetStringFromCharString(const char* from, unsigned __int16* to);
	unsigned int GScr_AllocString(const char* a1, game::scriptInstance_t inst);
	unsigned int SL_GetStringForFloat(float floatVal, game::scriptInstance_t inst);
	unsigned int SL_GetStringForInt(int intVal, game::scriptInstance_t inst);
	unsigned int SL_GetStringForVector(float* vector, game::scriptInstance_t inst);
	void SL_ShutdownSystem(game::scriptInstance_t inst, unsigned int user);
	void SL_TransferSystem();
	void SL_CreateCanonicalFilename(const char* filename, char* newFilename);
	unsigned int Scr_CreateCanonicalFilename(game::scriptInstance_t inst, const char* filename);
	game::RefString* GetRefString(game::scriptInstance_t inst, unsigned int id);
	void SL_RemoveRefToStringOfSize(game::scriptInstance_t inst, unsigned int stringValue, unsigned int len);
	int SL_GetRefStringLen(game::RefString* refString);
	void SL_AddUser(unsigned int stringValue, unsigned int user, game::scriptInstance_t inst);
	int SL_ConvertFromString(game::scriptInstance_t inst, const char* str);
	int SL_ConvertFromRefString(game::scriptInstance_t inst, game::RefString* refString);
	game::RefString* GetRefString_0(game::scriptInstance_t inst, const char* str);
	const char* SL_ConvertToStringSafe(unsigned int id, game::scriptInstance_t inst);
}
