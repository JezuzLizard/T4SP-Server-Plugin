#include <stdinc.hpp>
#include "clientscript_public.hpp"

namespace codsrc
{
	// Restored inlined function
	int Scr_IsInOpcodeMemory(game::scriptInstance_t inst, const char* pos)
	{
		assert(game::gScrVarPub[inst].programBuffer);
		assert(pos);

		return (unsigned int)(pos - game::gScrVarPub[inst].programBuffer) < game::gScrCompilePub[inst].programLen;
	}

	// Decomp Status: Completed
	bool Scr_IsIdentifier(char* token)
	{
		while ( *token )
		{
			if (!iscsym(*token))
			{
				return false;
			}

			++token;
		}

		return true;
	}

	// Decomp Status: Completed
	unsigned int Scr_GetFunctionHandle(const char* file, game::scriptInstance_t inst, const char* handle)
	{
		assert(game::gScrCompilePub[inst].scriptsPos);
		assert(strlen(file) < 0x40);

		unsigned int fileNameHash = game::Scr_CreateCanonicalFilename(inst, file);
		int id = game::FindVariable(fileNameHash, game::gScrCompilePub[inst].scriptsPos, inst);

		game::SL_RemoveRefToString(fileNameHash, inst);

		if (!id)
		{
			return 0;
		}

		unsigned int posId = game::FindObject(inst, id);
		unsigned int str = game::SL_FindLowercaseString(handle, inst);
		if (!str)
		{
			return 0;
		}

		unsigned int filePosId = game::FindVariable(str, posId, inst);
		if (!filePosId)
		{
			return 0;
		}

		game::VariableValue val = game::Scr_EvalVariable(inst, filePosId);

		assert(val.type == game::VAR_CODEPOS);

		const char* pos = val.u.codePosValue;
		if (!game::Scr_IsInOpcodeMemory(inst, pos))
		{
			return 0;
		}

		assert(pos - game::gScrVarPub[inst].programBuffer);

		assert(pos > game::gScrVarPub[inst].programBuffer);

		return pos - game::gScrVarPub[inst].programBuffer;
	}

	// Decomp Status: Completed
	unsigned int SL_TransferToCanonicalString(game::scriptInstance_t inst, unsigned int stringValue)
	{
		assert(stringValue);

		game::SL_TransferRefToUser(stringValue, 2u, inst);

		if ( game::gScrCompilePub[inst].canonicalStrings[stringValue] )
		{
			return game::gScrCompilePub[inst].canonicalStrings[stringValue];
		}

		game::gScrCompilePub[inst].canonicalStrings[stringValue] = ++game::gScrVarPub[inst].canonicalStrCount;

		return game::gScrVarPub[inst].canonicalStrCount;
	}

	// Decomp Status: Tested, Completed
	unsigned int SL_GetCanonicalString(char* token, game::scriptInstance_t inst)
	{
		unsigned int str;

		str = game::SL_FindString(token, inst);

		if ( game::gScrCompilePub[inst].canonicalStrings[str] )
		{
			return game::gScrCompilePub[inst].canonicalStrings[str];
		}

		str = game::SL_GetString_(token, inst, 0);

		return game::SL_TransferToCanonicalString(inst, str);
	}

	// Restored
	void SL_BeginLoadScripts(game::scriptInstance_t inst)
	{
		memset(game::gScrCompilePub[inst].canonicalStrings, 0, sizeof(game::gScrCompilePub[inst].canonicalStrings));
		game::gScrVarPub[inst].canonicalStrCount = 0;
	}

	// Restored
	void Scr_SetLoadedImpureScript(bool loadedImpureScript)
	{
		*game::loadedImpureScript = loadedImpureScript;
	}

	// Decomp Status: Tested, Completed
	void Scr_BeginLoadScripts(game::scriptInstance_t inst, int user)
	{
		assert(!game::gScrCompilePub[inst].script_loading);

		game::gScrCompilePub[inst].script_loading = 1;

		game::Scr_InitOpcodeLookup(inst);

		assert(!game::gScrCompilePub[inst].loadedscripts);

		game::gScrCompilePub[inst].loadedscripts = game::Scr_AllocArray(inst);

		assert(!game::gScrCompilePub[inst].scriptsPos);

		game::gScrCompilePub[inst].scriptsPos = game::Scr_AllocArray(inst);

		assert(!game::gScrCompilePub[inst].scriptsCount);

		game::gScrCompilePub[inst].scriptsCount = game::Scr_AllocArray(inst);

		assert(!game::gScrCompilePub[inst].builtinFunc);

		game::gScrCompilePub[inst].builtinFunc = game::Scr_AllocArray(inst);

		assert(!game::gScrCompilePub[inst].builtinMeth);

		game::gScrCompilePub[inst].builtinMeth = game::Scr_AllocArray(inst);

		game::gScrVarPub[inst].programHunkUser = game::Hunk_UserCreate(0x100000, "Scr_BeginLoadScripts", 1, 0, 0, 7);
		game::TempMemoryReset(game::gScrVarPub[inst].programHunkUser);
		game::gScrVarPub[inst].programBuffer = game::TempMalloc(0);

		assert(((int)game::gScrVarPub[inst].programBuffer & 0x1F) == 0);

		game::gScrCompilePub[inst].programLen = 0;
		game::gScrVarPub[inst].endScriptBuffer = 0;
		
		game::SL_BeginLoadScripts(inst);

		game::gScrVarPub[inst].fieldBuffer = 0;
		game::gScrCompilePub[inst].value_count = 0;
		game::gScrVarPub[inst].error_message = 0;
		game::gScrVmGlob[inst].dialog_error_message = 0;
		game::gScrVarPub[inst].error_index = 0;
		game::gScrCompilePub[inst].func_table_size = 0;
		
		game::Scr_SetLoadedImpureScript(false);

		game::gScrAnimPub[inst].animTreeNames = 0;
		game::Scr_BeginLoadAnimTrees(inst, user);
	}

	// Decomp Status: Completed
	void Scr_BeginLoadAnimTrees(game::scriptInstance_t inst, int user)
	{
		assert(!game::gScrAnimPub[inst].animtree_loading);

		game::gScrAnimPub[inst].animtree_loading = 1;
		game::gScrAnimPub[inst].xanim_num[user] = 0;
		game::gScrAnimPub[inst].xanim_lookup[user][0].anims = 0;

		assert(!game::gScrAnimPub[inst].animtrees);

		game::gScrAnimPub[inst].animtrees = game::Scr_AllocArray(inst);
		game::gScrAnimPub[inst].animtree_node = 0;
		game::gScrCompilePub[inst].developer_statement = 0;
	}

	// Decomp Status: Completed
	int Scr_ScanFile(int max_size, char* buf)
	{
		char c;
		int n;
		game::scriptInstance_t inst;

		inst = *game::gInst;

		c = '*';
		for ( n = 0;
			n < max_size;
			++n )
		{
			c = *game::gScrCompilePub[inst].in_ptr++;

			if ( !c || c == '\n')
			{
				break;
			}

			buf[n] = c;
		}
		if ( c == '\n')
		{
			buf[n++] = c;
		}
		else if ( !c )
		{
			if ( game::gScrCompilePub[inst].parseBuf )
			{
				game::gScrCompilePub[inst].in_ptr = game::gScrCompilePub[inst].parseBuf;
				game::gScrCompilePub[inst].parseBuf = 0;
			}
			else
			{
				--game::gScrCompilePub[inst].in_ptr;
			}
		}

		return n;
	}

	// Decomp Status: Tested, Completed
	unsigned int Scr_LoadScriptInternal(game::scriptInstance_t inst, const char* filename, game::PrecacheEntry* entries, int entriesCount)
	{
		unsigned int scriptPosVar;
		unsigned int scriptCountVar;
		const char *codepos;
		char extFilename[64];
		unsigned int fileCountId;
		unsigned int filePosPtr;
		char *sourceBuffer;
		const char *oldFilename;
		unsigned int name;
		unsigned int oldAnimTreeNames;
		const char *oldSourceBuf;
		unsigned int scriptId;
		unsigned int filePosId;
		const char *formatExtString;
		game::sval_u parseData;

		assert(game::gScrCompilePub[inst].script_loading);

		assert(strlen(filename) < 0x40);

		name = game::Scr_CreateCanonicalFilename(inst, filename);
		if ( game::FindVariable(name, game::gScrCompilePub[inst].loadedscripts, inst) )
		{
			game::SL_RemoveRefToString(name, inst);
			filePosPtr = game::FindVariable(name, game::gScrCompilePub[inst].scriptsPos, inst);
			if ( filePosPtr )
			{
				return game::FindObject(inst, filePosPtr);
			}
			
			return 0;
		}

		scriptId = game::GetNewVariable(inst, name, game::gScrCompilePub[inst].loadedscripts);
		game::SL_RemoveRefToString(name, inst);
		formatExtString = "%s.gsc";

		if ( inst == game::SCRIPTINSTANCE_CLIENT && !strncmp(filename, "clientscripts", 13) )
		{
			formatExtString = "%s.csc";
		}

		snprintf(extFilename, 64, formatExtString, filename);
		oldSourceBuf = game::gScrParserPub[inst].sourceBuf;
		codepos = (const char *)game::TempMalloc(0);
		sourceBuffer = game::Scr_AddSourceBuffer(inst, (int)filename, extFilename, codepos);

		if (!sourceBuffer)
		{
			return 0;
		}

		oldAnimTreeNames = game::gScrAnimPub[inst].animTreeNames;
		game::gScrAnimPub[inst].animTreeNames = 0;
		game::gScrCompilePub[inst].far_function_count = 0;

		game::Scr_InitAllocNode(inst);

		oldFilename = game::gScrParserPub[inst].scriptfilename;
		game::gScrParserPub[inst].scriptfilename = extFilename;
		game:: gScrCompilePub[inst].in_ptr = "+";
		game::gScrCompilePub[inst].parseBuf = sourceBuffer;

		// pluto
		if (game::plutonium::script_preprocess != nullptr)
		{
			game::plutonium::script_preprocess(sourceBuffer, inst, &parseData); // the pluto hook will call ScriptParse, so we dont have to
		}

		//
		else
		{
			game::ScriptParse(inst, &parseData);
		}

		scriptPosVar = game::GetVariable(inst, game::gScrCompilePub[inst].scriptsPos, name);
		filePosId = game::GetObject(inst, scriptPosVar);
		scriptCountVar = game::GetVariable(inst, game::gScrCompilePub[inst].scriptsCount, name);
		fileCountId = game::GetObject(inst, scriptCountVar);

		game::ScriptCompile(inst, parseData, filePosId, fileCountId, scriptId, entries, entriesCount);

		game::gScrParserPub[inst].scriptfilename = oldFilename;
		game::gScrParserPub[inst].sourceBuf = oldSourceBuf;
		game::gScrAnimPub[inst].animTreeNames = oldAnimTreeNames;

		return filePosId;
	}

	// Decomp Status: Tested, Completed
	unsigned int Scr_LoadScript(const char* file, game::scriptInstance_t inst)
	{
		game::PrecacheEntry entries[1024];

		return game::Scr_LoadScriptInternal(inst, file, entries, 0);
	}

	// Decomp Status: Tested, Completed
	void Scr_EndLoadScripts(game::scriptInstance_t inst)
	{
		// pluto
		if (game::plutonium::load_custom_script_func != nullptr)
		{
			game::plutonium::load_custom_script_func(inst);
		}
		//

		game::SL_ShutdownSystem(inst, 2u);
		game::gScrCompilePub[inst].script_loading = 0;
		
		assert(game::gScrCompilePub[inst].loadedscripts);

		game::ClearObject(game::gScrCompilePub[inst].loadedscripts, inst);
		game::RemoveRefToObject(game::gScrCompilePub[inst].loadedscripts, inst);
		game::gScrCompilePub[inst].loadedscripts = 0;

		assert(game::gScrCompilePub[inst].scriptsPos);

		game::ClearObject(game::gScrCompilePub[inst].scriptsPos, inst);
		game::RemoveRefToObject(game::gScrCompilePub[inst].scriptsPos, inst);
		game::gScrCompilePub[inst].scriptsPos = 0;

		assert(game::gScrCompilePub[inst].scriptsCount);

		game::ClearObject(game::gScrCompilePub[inst].scriptsCount, inst);
		game::RemoveRefToObject(game::gScrCompilePub[inst].scriptsCount, inst);
		game::gScrCompilePub[inst].scriptsCount = 0;

		assert(game::gScrCompilePub[inst].builtinFunc);

		game::ClearObject(game::gScrCompilePub[inst].builtinFunc, inst);
		game::RemoveRefToObject(game::gScrCompilePub[inst].builtinFunc, inst);
		game::gScrCompilePub[inst].builtinFunc = 0;
		
		assert(game::gScrCompilePub[inst].builtinMeth);

		game::ClearObject(game::gScrCompilePub[inst].builtinMeth, inst);
		game::RemoveRefToObject(game::gScrCompilePub[inst].builtinMeth, inst);
		game::gScrCompilePub[inst].builtinMeth = 0;
	}

	// Decomp Status: Tested, Completed
	void Scr_PrecacheAnimTrees(game::scriptInstance_t inst, void* (__cdecl *Alloc)(int), int user, int modChecksum)
	{
		unsigned int i;

		for (i = 1; i <= game::gScrAnimPub[inst].xanim_num[user]; ++i)
		{
			game::Scr_LoadAnimTreeAtIndex(inst, user, i, Alloc, modChecksum);
		}
	}

	// Decomp Status: Tested, Completed
	void Scr_EndLoadAnimTrees(game::scriptInstance_t inst)
	{
		unsigned int animtreeNode;

		assert(game::gScrAnimPub[inst].animtrees);

		game::ClearObject(game::gScrAnimPub[inst].animtrees, inst);
		game::RemoveRefToObject(game::gScrAnimPub[inst].animtrees, inst);
		animtreeNode = game::gScrAnimPub[inst].animtree_node;
		game::gScrAnimPub[inst].animtrees = 0;

		if (animtreeNode)
		{
			game::RemoveRefToObject(animtreeNode, inst);
		}

		game::SL_ShutdownSystem(inst, 2u);

		if (game::gScrVarPub[inst].programBuffer && !game::gScrVarPub[inst].endScriptBuffer)
		{
			game::gScrVarPub[inst].endScriptBuffer = game::TempMalloc(0);
		}

		game::gScrAnimPub[inst].animtree_loading = 0;
	}

	// Decomp Status: Tested, Completed
	void Scr_FreeScripts(game::scriptInstance_t inst)
	{
		//char sys = 1;

		//assert(sys == SCR_SYS_GAME);

		if (game::gScrCompilePub[inst].script_loading)
		{
			game::gScrCompilePub[inst].script_loading = 0;
			game::Scr_EndLoadScripts(inst);
		}

		if (game::gScrAnimPub[inst].animtree_loading)
		{
			game::gScrAnimPub[inst].animtree_loading = 0;
			game::Scr_EndLoadAnimTrees(inst);
		}

		game::SL_ShutdownSystem(inst, 1u);
		game::Scr_ShutdownOpcodeLookup(inst);

		if (game::gScrVarPub[inst].programHunkUser)
		{
			game::Hunk_UserDestroy(game::gScrVarPub[inst].programHunkUser);
			game::gScrVarPub[inst].programHunkUser = 0;
		}

		game::gScrVarPub[inst].programBuffer = 0;
		game::gScrVarPub[inst].endScriptBuffer = 0;
		game::gScrVarPub[inst].checksum = 0;
		game::gScrCompilePub[inst].programLen = 0;
	}
}