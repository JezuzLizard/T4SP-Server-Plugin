#include <stdinc.hpp>
#include "clientscript_public.hpp"

namespace codsrc
{
	// Restored
	game::RefString* GetRefString(game::scriptInstance_t inst, unsigned int id)
	{
		assert(id);

		assert((id * MT_NODE_SIZE) < MT_SIZE);

		return (game::RefString*)&game::gScrMemTreePub[inst].mt_buffer->nodes[id];
	}

	// Restored
	game::RefString * GetRefString_0([[maybe_unused]] game::scriptInstance_t inst, const char *str)
	{
		assert(str >= (char*)game::gScrMemTreePub[inst].mt_buffer && str < (char*)(game::gScrMemTreePub[inst].mt_buffer + MT_SIZE));

		return (game::RefString *)(str - 4);
	}

	// Restored
	int SL_ConvertFromRefString(game::scriptInstance_t inst, game::RefString *refString)
	{
		return ((char *)refString - (char *)game::gScrMemTreePub[inst].mt_buffer) / MT_NODE_SIZE;
	}

	// Restored
	int SL_ConvertFromString(game::scriptInstance_t inst, const char *str)
	{
		game::RefString *v2;

		assert(str);

		v2 = game::GetRefString_0(inst, str);
		return game::SL_ConvertFromRefString(inst, v2);
	}

	// Restored
	const char* SL_ConvertToStringSafe(unsigned int id, game::scriptInstance_t inst)
	{
		if (!id)
		{
			return "(NULL)";
		}

		return game::GetRefString(inst, id)->str;
	}

	// Decomp Status: Completed
	char* SL_ConvertToString(unsigned int id, game::scriptInstance_t inst)
	{
		//assert((!id || !game::gScrStringDebugGlob[inst] || game::gScrStringDebugGlob[inst]->refCount[id]));

		if (!id)
		{
			return nullptr;
		}

		return game::GetRefString(inst, id)->str;
	}

	// Restored
	int SL_GetRefStringLen(game::RefString* refString)
	{
		int len;

		if (!refString->u.s.byteLen)
		{
			len = 256 - 1; //Bugfix for 256 % 256 = 0 or 512 % 256 = 0 or... Just promote it to 256
		}
		else
		{
			len = refString->u.s.byteLen - 1;
		}

		while (refString->str[len])
		{
			len += 256;
		}

		return len;
	}

	// Decomp Status: Completed
	int SL_GetStringLen(unsigned int stringValue, game::scriptInstance_t inst)
	{
		game::RefString *refString;

		assert(stringValue);

		refString = game::GetRefString(inst, stringValue);

		return game::SL_GetRefStringLen(refString);
	}

	// Decomp Status: Completed
	unsigned int GetHashCode(unsigned int len, const char* str)
	{
		unsigned int i;

		if (len >= 0x100)
		{
			return (len >> 2) % 0x61A7 + 1;
		}
		for (i = 0; len; --len)
		{
			i = 31 * i + *str++;
		}
		return i % 0x61A7 + 1;
	}

	// Decomp Status: Completed
	void SL_Init(game::scriptInstance_t inst)
	{
		unsigned int hash;
		game::HashEntry *entry;
		unsigned int prev;

		assert(!game::gScrStringGlob[inst].inited);

		game::MT_Init(inst);
		game::Sys_EnterCriticalSection(game::CRITSECT_SCRIPT_STRING);

		game::gScrStringGlob[inst].hashTable[0].status_next = 0;

		prev = 0;
		for (hash = 1;
			hash < HASH_MAX_HASHES;
			++hash)
		{
			assert(!(hash & HASH_STAT_MASK));

			entry = &game::gScrStringGlob[inst].hashTable[hash];
			entry->status_next = 0;
			game::gScrStringGlob[inst].hashTable[prev].status_next |= hash;
			entry->u.prev = prev;
			prev = hash;
		}

		assert(!(game::gScrStringGlob[inst].hashTable[prev].status_next));

		game::gScrStringGlob[inst].hashTable[0].u.prev = prev;
		game::gScrStringGlob[inst].inited = 1;
		game::Sys_LeaveCriticalSection(game::CRITSECT_SCRIPT_STRING);
	}

	// Decomp Status: Completed
	unsigned int SL_FindStringOfSize(game::scriptInstance_t inst, const char* str, unsigned int len)
	{
		unsigned int stringValue;
		game::HashEntry *entry;
		int hash;
		unsigned int newIndex;
		game::RefString *refStr;
		game::RefString *refStra;
		unsigned int prev;
		game::HashEntry *newEntry;

		assert(str);

		hash = game::GetHashCode(len, str);
		game::Sys_EnterCriticalSection(game::CRITSECT_SCRIPT_STRING);
		entry = &game::gScrStringGlob[inst].hashTable[hash];

		if ( (entry->status_next & HASH_STAT_MASK) != HASH_STAT_HEAD )
		{
			game::Sys_LeaveCriticalSection(game::CRITSECT_SCRIPT_STRING);
			return 0;
		}

		refStr = game::GetRefString(inst, entry->u.prev);
		if ( (unsigned char)refStr->u.s.byteLen != (unsigned char)len || memcmp(refStr->str, str, len) )
		{
			prev = hash;
			newIndex = (unsigned short)entry->status_next;

			for ( newEntry = &game::gScrStringGlob[inst].hashTable[newIndex];
				newEntry != entry;
				newEntry = &game::gScrStringGlob[inst].hashTable[newIndex] )
			{
				assert((newEntry->status_next & HASH_STAT_MASK) == HASH_STAT_MOVABLE);

				refStra = game::GetRefString(inst, newEntry->u.prev);

				if ( (unsigned char)refStra->u.s.byteLen == (unsigned char)len && !memcmp(refStra->str, str, len) )
				{
					game::gScrStringGlob[inst].hashTable[prev].status_next = (unsigned short)newEntry->status_next | game::gScrStringGlob[inst].hashTable[prev].status_next & HASH_STAT_MASK;
					newEntry->status_next = (unsigned short)entry->status_next | newEntry->status_next & HASH_STAT_MASK;
					entry->status_next = newIndex | entry->status_next & HASH_STAT_MASK;
					stringValue = newEntry->u.prev;
					newEntry->u.prev = entry->u.prev;
					entry->u.prev = stringValue;

					assert((newEntry->status_next & HASH_STAT_MASK) != HASH_STAT_FREE);

					assert((entry->status_next & HASH_STAT_MASK) != HASH_STAT_FREE);

					assert(refStra->str == game::SL_ConvertToString(stringValue, inst));

					game::Sys_LeaveCriticalSection(game::CRITSECT_SCRIPT_STRING);
					return stringValue;
				}

				prev = newIndex;
				newIndex = (unsigned short)newEntry->status_next;
			}

			game::Sys_LeaveCriticalSection(game::CRITSECT_SCRIPT_STRING);
			return 0;
		}

		assert((entry->status_next & HASH_STAT_MASK) != HASH_STAT_FREE);

		stringValue = entry->u.prev;

		assert(refStr->str == game::SL_ConvertToString(stringValue, inst));

		game::Sys_LeaveCriticalSection(game::CRITSECT_SCRIPT_STRING);
		return stringValue;
	}

	// Decomp Status: Completed
	unsigned int SL_FindString(const char* str, game::scriptInstance_t inst)
	{
		return game::SL_FindStringOfSize(inst, str, strlen(str) + 1);
	}

	// Decomp Status: Completed
	unsigned int SL_FindLowercaseString(const char* str, game::scriptInstance_t inst)
	{
		char stra[8196];
		unsigned int len;
		int i;

		len = strlen(str) + 1;

		if ( (int)len > 0x2000 )
			return 0;

		for ( i = 0;
			i < (int)len;
			++i )
		{
			stra[i] = (char)tolower(str[i]);
		}

		return game::SL_FindStringOfSize(inst, stra, len);
	}

	// Decomp Status: Completed
	void SL_AddUserInternal(unsigned int user, game::RefString* refStr)
	{
		unsigned __int32 data;

		if ( ((unsigned __int8)user & (unsigned __int8)refStr->u.s.user) == 0 )
		{
			do
				data = refStr->u.data;
			while ( InterlockedCompareExchange((volatile unsigned int*)&refStr->u.data, data | (user << 16), data) != data);

			InterlockedExchangeAdd((volatile unsigned int*)&refStr->u.data, 1u);
		}
	}

	// Restored
	void SL_AddUser(unsigned int stringValue, unsigned int user, game::scriptInstance_t inst)
	{
		game::RefString *refStr;

		refStr = game::GetRefString(inst, stringValue);
		game::SL_AddUserInternal(user, refStr);
	}

	// Decomp Status: Untested unknown how to test, completed
	void Mark_ScriptStringCustom(unsigned int var)
	{
		game::SL_AddUser(var, 4u, game::SCRIPTINSTANCE_SERVER);
	}

	// Decomp Status: Completed
	unsigned int SL_GetStringOfSize(game::scriptInstance_t inst, const char* str, unsigned int user, unsigned int len)
	{
		unsigned int stringValue;
		game::HashEntry* entry;
		unsigned int newNext;
		unsigned int newNexta;
		int hash;
		unsigned int newIndex;
		unsigned int newIndexa;
		unsigned int newIndexb;
		game::RefString *refStr;
		game::RefString *refStra;
		game::RefString *refStrb;
		unsigned int nexta;
		unsigned int next;
		unsigned int prev;
		unsigned int prevb;
		unsigned int preva;
		game::HashEntry *newEntry;
		game::HashEntry *newEntrya;
		game::HashEntry *newEntryb;

		assert(str);

		hash = game::GetHashCode(len, str);
		game::Sys_EnterCriticalSection(game::CRITSECT_SCRIPT_STRING);
		entry = &game::gScrStringGlob[inst].hashTable[hash];

		if ( (entry->status_next & HASH_STAT_MASK) == HASH_STAT_HEAD )
		{
			refStr = game::GetRefString(inst, entry->u.prev);

			if ( (unsigned char)refStr->u.s.byteLen == (unsigned char)len && !memcmp(refStr->str, str, len) )
			{
				game::SL_AddUserInternal(user, refStr);

				assert((entry->status_next & HASH_STAT_MASK) != HASH_STAT_FREE);

				stringValue = entry->u.prev;

				assert(refStr->str == game::SL_ConvertToString(stringValue, inst));

				game::Sys_LeaveCriticalSection(game::CRITSECT_SCRIPT_STRING);
				return stringValue;
			}

			prev = hash;
			newIndex = (unsigned short)entry->status_next;
			for ( newEntry = &game::gScrStringGlob[inst].hashTable[newIndex];
				newEntry != entry;
				newEntry = &game::gScrStringGlob[inst].hashTable[newIndex] )
			{
				assert((newEntry->status_next & HASH_STAT_MASK) == HASH_STAT_MOVABLE);

				refStra = game::GetRefString(inst, newEntry->u.prev);

				if ( (unsigned char)refStra->u.s.byteLen == (unsigned char)len && !memcmp(refStra->str, str, len) )
				{
					game::gScrStringGlob[inst].hashTable[prev].status_next = (unsigned short)newEntry->status_next | game::gScrStringGlob[inst].hashTable[prev].status_next & HASH_STAT_MASK;
					newEntry->status_next = (unsigned short)entry->status_next | newEntry->status_next & HASH_STAT_MASK;
					entry->status_next = newIndex | entry->status_next & HASH_STAT_MASK;
					stringValue = newEntry->u.prev;
					newEntry->u.prev = entry->u.prev;
					entry->u.prev = stringValue;
					game::SL_AddUserInternal(user, refStra);

					assert((newEntry->status_next & HASH_STAT_MASK) != HASH_STAT_FREE);

					assert((entry->status_next & HASH_STAT_MASK) != HASH_STAT_FREE);

					assert(refStra->str == game::SL_ConvertToString(stringValue, inst));

					game::Sys_LeaveCriticalSection(game::CRITSECT_SCRIPT_STRING);
					return stringValue;
				}

				prev = newIndex;
				newIndex = (unsigned short)newEntry->status_next;
			}

			newIndexa = game::gScrStringGlob[inst].hashTable->status_next;
			if ( !newIndexa )
			{
				game::Scr_DumpScriptThreads(inst);
				game::Com_Error(game::ERR_DROP, "\x15" "exceeded maximum number of script strings\n");
			}

			stringValue = game::MT_AllocIndex(inst, len + 4);
			newEntrya = &game::gScrStringGlob[inst].hashTable[newIndexa];

			assert((newEntrya->status_next & HASH_STAT_MASK) == HASH_STAT_FREE);

			newNext = (unsigned short)newEntrya->status_next;
			game::gScrStringGlob[inst].hashTable->status_next = newNext;
			game::gScrStringGlob[inst].hashTable[newNext].u.prev = 0;
			newEntrya->status_next = (unsigned short)entry->status_next | HASH_STAT_MOVABLE;
			entry->status_next = (unsigned short)newIndexa | entry->status_next & HASH_STAT_MASK;
			newEntrya->u.prev = entry->u.prev;
		}
		else
		{
			if ( (entry->status_next & HASH_STAT_MASK) != HASH_STAT_FREE )
			{
				assert((entry->status_next & HASH_STAT_MASK) == HASH_STAT_MOVABLE);

				next = (unsigned short)entry->status_next;
				for ( preva = next;
					(unsigned short)game::gScrStringGlob[inst].hashTable[preva].status_next != hash;
					preva = (unsigned short)game::gScrStringGlob[inst].hashTable[preva].status_next )
				{
					;
				}

				assert(preva);

				newIndexb = game::gScrStringGlob[inst].hashTable->status_next;
				if ( !newIndexb )
				{
					game::Scr_DumpScriptThreads(inst);
					game::Com_Error(game::ERR_DROP, "\x15" "exceeded maximum number of script strings\n");
				}

				stringValue = game::MT_AllocIndex(inst, len + 4);
				newEntryb = &game::gScrStringGlob[inst].hashTable[newIndexb];

				assert((newEntryb->status_next & HASH_STAT_MASK) == HASH_STAT_FREE);

				newNexta = (unsigned short)newEntryb->status_next;
				game::gScrStringGlob[inst].hashTable->status_next = newNexta;
				game::gScrStringGlob[inst].hashTable[newNexta].u.prev = 0;
				game::gScrStringGlob[inst].hashTable[preva].status_next = newIndexb | game::gScrStringGlob[inst].hashTable[preva].status_next & HASH_STAT_MASK;
				newEntryb->status_next = next | HASH_STAT_MOVABLE;
				newEntryb->u.prev = entry->u.prev;
			}
			else
			{
				stringValue = game::MT_AllocIndex(inst, len + 4);
				prevb = entry->u.prev;
				nexta = (unsigned short)entry->status_next;
				game::gScrStringGlob[inst].hashTable[prevb].status_next = nexta | game::gScrStringGlob[inst].hashTable[prevb].status_next & HASH_STAT_MASK;
				game::gScrStringGlob[inst].hashTable[nexta].u.prev = prevb;
			}

			assert((hash & HASH_STAT_MASK) == 0);

			entry->status_next = hash | HASH_STAT_HEAD;
		}

		assert(stringValue);

		entry->u.prev = stringValue;

		refStrb = game::GetRefString(inst, stringValue);
		memcpy(refStrb->str, str, len);

		refStrb->u.s.user = user;
		assert(refStrb->u.s.user == user);
		refStrb->u.s.refCount = 1;
		refStrb->u.s.byteLen = len;

		assert((entry->status_next & HASH_STAT_MASK) != HASH_STAT_FREE);
		assert(refStrb->str == game::SL_ConvertToString(stringValue, inst));

		game::Sys_LeaveCriticalSection(game::CRITSECT_SCRIPT_STRING);
		return stringValue;
	}

	// Decomp Status: Untested unknown how to test, Completed
	unsigned int SL_GetString_(const char* str, game::scriptInstance_t inst, unsigned int user)
	{
		return game::SL_GetStringOfSize(inst, str, user, strlen(str) + 1);
	}

	// Decomp Status: Completed
	unsigned int SL_GetString__0(const char* str, unsigned int user, game::scriptInstance_t inst)
	{
		return game::SL_GetStringOfSize(inst, str, user, strlen(str) + 1);
	}

	// Decomp Status: Completed
	unsigned int SL_GetLowercaseStringOfLen(game::scriptInstance_t inst, const char* str, unsigned int user, unsigned int len)
	{
		char stra[SL_MAX_STRING_LEN];
		unsigned int i;

		if (len > SL_MAX_STRING_LEN)
		{
			game::Com_Error(game::ERR_DROP, "max string length exceeded: \"%s\"", str);
		}

		for ( i = 0;
			i < len;
			++i )
		{
			stra[i] = (char)tolower(str[i]);
		}

		return game::SL_GetStringOfSize(inst, stra, user, len);
	}

	// Decomp Status: Completed
	unsigned int SL_GetLowercaseString(const char* str)
	{
		return game::SL_GetLowercaseStringOfLen(game::SCRIPTINSTANCE_SERVER, str, 0, strlen(str) + 1);
	}

	// Decomp Status: Completed
	unsigned int SL_ConvertToLowercase(game::scriptInstance_t inst, unsigned int stringVal, unsigned int user)
	{
		char *strCopy;
		char str[SL_MAX_STRING_LEN];
		unsigned int answer;
		unsigned int len;
		unsigned int i;

		len = game::SL_GetStringLen(stringVal, inst) + 1;
		if ( len > SL_MAX_STRING_LEN)
		{
			return stringVal;
		}

		strCopy = game::SL_ConvertToString(stringVal, inst);

		for ( i = 0;
			i < len;
			++i )
		{
			str[i] = (char)tolower(strCopy[i]);
		}

		answer = game::SL_GetStringOfSize(inst, str, user, len);
		game::SL_RemoveRefToString(stringVal, inst);
		return answer;
	}

	// Decomp Status: Completed
	void SL_TransferRefToUser(unsigned int stringValue, unsigned int user, game::scriptInstance_t inst)
	{
		unsigned int data;
		game::RefString *refStr;

		refStr = game::GetRefString(inst, stringValue);
		if ( ((unsigned char)user & (unsigned char)refStr->u.s.user) != 0 )
		{
			InterlockedExchangeAdd((volatile unsigned int*)&refStr->u.data, 0xFFFFFFFF);
		}
		else
		{
			do
				data = refStr->u.data;
			while ( InterlockedCompareExchange((volatile unsigned int*)&refStr->u.data, data | (user << 16), data) != data );
		}
	}

	// Decomp Status: Completed
	void SL_FreeString(game::scriptInstance_t inst, unsigned int stringValue, game::RefString* refStr, unsigned int len)
	{
		game::HashEntry *entry;
		unsigned int newIndex;
		unsigned int newNext;
		int index;
		unsigned int prev;
		game::HashEntry *newEntry;

		index = game::GetHashCode(len, refStr->str);
		game::Sys_EnterCriticalSection(game::CRITSECT_SCRIPT_STRING);

		if ( !(unsigned short)refStr->u.s.refCount )
		{
			entry = &game::gScrStringGlob[inst].hashTable[index];
			game::MT_FreeIndex(len + 4, inst, stringValue);

			assert(((entry->status_next & HASH_STAT_MASK) == HASH_STAT_HEAD));

			newIndex = (unsigned short)entry->status_next;
			newEntry = &game::gScrStringGlob[inst].hashTable[newIndex];
			if ( entry->u.prev == stringValue )
			{
				if ( newEntry == entry )
				{
					newEntry = entry;
					newIndex = index;
				}
				else
				{
					entry->status_next = (unsigned short)newEntry->status_next | HASH_STAT_HEAD;
					entry->u.prev = newEntry->u.prev;
					game::gScrStringGlob[inst].nextFreeEntry = entry;
				}
			}
			else
			{
				prev = index;
				while ( 1 )
				{
					assert(newEntry != entry);

					assert((newEntry->status_next & HASH_STAT_MASK) == HASH_STAT_MOVABLE);

					if ( newEntry->u.prev == stringValue )
					{
						break;
					}

					prev = newIndex;
					newIndex = (unsigned short)newEntry->status_next;
					newEntry = &game::gScrStringGlob[inst].hashTable[newIndex];
				}

				game::gScrStringGlob[inst].hashTable[prev].status_next = (unsigned short)newEntry->status_next | game::gScrStringGlob[inst].hashTable[prev].status_next & HASH_STAT_MASK;
			}

			assert((newEntry->status_next & HASH_STAT_MASK) != HASH_STAT_FREE);

			newNext = game::gScrStringGlob[inst].hashTable->status_next;

			assert((newNext & HASH_STAT_MASK) == HASH_STAT_FREE);

			newEntry->status_next = newNext;
			newEntry->u.prev = 0;
			game::gScrStringGlob[inst].hashTable[newNext].u.prev = newIndex;
			game::gScrStringGlob[inst].hashTable->status_next = newIndex;
		}

		game::Sys_LeaveCriticalSection(game::CRITSECT_SCRIPT_STRING);
	}

	// Restored
	void SL_RemoveRefToStringOfSize(game::scriptInstance_t inst, unsigned int stringValue, unsigned int len)
	{
		game::RefString *refStr;

		refStr = game::GetRefString(inst, stringValue);
		if ( !(unsigned __int16)InterlockedDecrement((volatile unsigned int*)&refStr->u.data))
		{
			game::SL_FreeString(inst, stringValue, refStr, len);
		}
	}

	// Decomp Status: Tested, Completed
	void SL_RemoveRefToString(unsigned int stringVal, game::scriptInstance_t inst)
	{
		game::RefString *refStr;
		int len;

		refStr = game::GetRefString(inst, stringVal);
		len = game::SL_GetRefStringLen(refStr) + 1;
		game::SL_RemoveRefToStringOfSize(inst, stringVal, len);
	}

	// Restored
	void SL_AddRefToString(game::scriptInstance_t inst, unsigned int stringValue)
	{
		game::RefString* refStr = game::GetRefString(inst, stringValue);
		InterlockedExchangeAdd((volatile unsigned int*)&refStr->u.data, 1u);
	}

	// Decomp Status: Tested, Completed
	void Scr_SetString(game::scriptInstance_t inst, unsigned int from, unsigned __int16* to)
	{
		if (from)
		{
			game::SL_AddRefToString(inst, from);
		}

		if (*to)
		{
			game::SL_RemoveRefToString(*to, inst);
		}

		*to = (unsigned short)from;
	}

	// Decomp Status: Tested, Completed
	void Scr_SetStringFromCharString(const char* from, unsigned __int16* to)
	{
		if (*to)
		{
			game::SL_RemoveRefToString(*to, game::SCRIPTINSTANCE_SERVER);
		}

		*to = (unsigned short)game::SL_GetString_(from, game::SCRIPTINSTANCE_SERVER, 0);
	}

	// Decomp Status: Tested, Completed
	unsigned int GScr_AllocString(const char* str, game::scriptInstance_t inst)
	{
		return game::SL_GetString_(str, inst, 1);
	}

	// Decomp Status: Tested, Completed
	unsigned int SL_GetStringForFloat(float floatVal, game::scriptInstance_t inst)
	{
		char Buffer[128];

		sprintf_s(Buffer, "%g", floatVal);
		return game::SL_GetString_(Buffer, inst, 0);
	}

	// Decomp Status: Tested, Completed
	unsigned int SL_GetStringForInt(int intVal, game::scriptInstance_t inst)
	{
		char Buffer[128];

		sprintf_s(Buffer, "%i", intVal);
		return game::SL_GetString_(Buffer, inst, 0);
	}

	// Decomp Status: Tested, Completed
	unsigned int SL_GetStringForVector(float* vector, game::scriptInstance_t inst)
	{
		char Buffer[128];

		sprintf_s(Buffer, "(%g, %g, %g)", vector[0], vector[1], vector[2]);
		return game::SL_GetString_(Buffer, inst, 0);
	}

	// Decomp Status: Tested, Completed
	void SL_ShutdownSystem(game::scriptInstance_t inst, unsigned int user)
	{
		unsigned int hash;
		game::HashEntry *entry;
		game::RefString *refStr;

		assert(user);

		game::Sys_EnterCriticalSection(game::CRITSECT_SCRIPT_STRING);

		for ( hash = 1;
			hash < HASH_MAX_HASHES;
			++hash )
		{
			do
			{
				entry = &game::gScrStringGlob[inst].hashTable[hash];
				if ( (entry->status_next & HASH_STAT_MASK) == HASH_STAT_FREE )
				{
					break;
				}

				refStr = game::GetRefString(inst, entry->u.prev);
				if ( ((unsigned char)user & (unsigned char)refStr->u.s.user) == 0 )
				{
					break;
				}

				refStr->u.s.user &= ~user;
				game::gScrStringGlob[inst].nextFreeEntry = 0;
				game::SL_RemoveRefToString(entry->u.prev, inst);
			}
			while ( game::gScrStringGlob[inst].nextFreeEntry );
		}

		game::Sys_LeaveCriticalSection(game::CRITSECT_SCRIPT_STRING);
	}

	// Decomp Status: Tested, Completed, Optimized args
	void SL_TransferSystem()
	{
		unsigned int hash;
		game::HashEntry *entry;
		game::RefString* refStr;

		// args
		int from = 4;
		int to = 8;
		game::scriptInstance_t inst = game::SCRIPTINSTANCE_SERVER;

		assert(from);
		assert(to);

		game::Sys_EnterCriticalSection(game::CRITSECT_SCRIPT_STRING);

		for (hash = 1; hash < HASH_MAX_HASHES; hash++)
		{
			entry = &game::gScrStringGlob[inst].hashTable[hash];

			if ((entry->status_next & HASH_STAT_MASK) != HASH_STAT_FREE)
			{
				refStr = game::GetRefString(inst, entry->u.prev);

				if ( ((unsigned __int8)from & (unsigned __int8)refStr->u.s.user) != 0 )
				{
					refStr->u.s.user &= ~from;
					refStr->u.s.user |= to;
				}
			}
		}

		game::Sys_LeaveCriticalSection(game::CRITSECT_SCRIPT_STRING);
	}

	// Decomp Status: Tested, Completed
	void SL_CreateCanonicalFilename(const char* filename, char* newFilename)
	{
		int count;
		unsigned int c;

		count = 1024;
		do
		{
			do
			{
				do
				{
					c = *filename++;
				} while (c == '\\');
			} while (c == '/');
			if (c >= ' ')
			{
				while (1)
				{
					*newFilename++ = (char)tolower(c);
					if (!--count)
					{
						game::Com_Error(game::ERR_DROP, "\x15" "Filename '%s' exceeds maximum length of %d", filename, 0);
					}
					if (c == '/')
					{
						break;
					}
					c = *filename++;
					if (c == '\\')
					{
						c = '/';
					}
					else if (c < ' ')
					{
						break;
					}
				}
			}
		} while (c);
		*newFilename = 0;
	}

	// Decomp Status: Tested, Completed
	unsigned int Scr_CreateCanonicalFilename(game::scriptInstance_t inst, const char* filename)
	{
		char newFileName[1024];

		game::SL_CreateCanonicalFilename(filename, newFileName);
		return game::SL_GetString_(newFileName, inst, 0);
	}
}