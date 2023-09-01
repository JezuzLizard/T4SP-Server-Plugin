#include <stdinc.hpp>
#include "clientscript_public.hpp"

namespace codsrc
{
	// Decomp Status: Tested, Completed
	void Scr_InitOpcodeLookup(game::scriptInstance_t inst)
	{
		unsigned int opcodeLookupMaxLen;
		game::OpcodeLookup* opcodeLookup;
		unsigned int sourcePosLookupMaxLen;
		game::HunkUser* debugHunkUser;
		unsigned int sourceBufferLookupMaxLen;

		assert(!game::gScrParserGlob[inst].opcodeLookup);

		assert(!game::gScrParserGlob[inst].sourcePosLookup);

		assert(!game::gScrParserPub[inst].sourceBufferLookup);

		if (game::gScrVarPub[inst].developer)
		{
			debugHunkUser = (game::HunkUser*)game::g_DebugHunkUser.get();
			opcodeLookupMaxLen = inst != game::SCRIPTINSTANCE_CLIENT ? 0x40000 : 0x4000;
			game::gScrParserGlob[inst].opcodeLookupMaxLen = opcodeLookupMaxLen;
			game::gScrParserGlob[inst].delayedSourceIndex = -1;
			game::gScrParserGlob[inst].opcodeLookupLen = 0;
			opcodeLookup = (game::OpcodeLookup*)game::Hunk_UserAlloc(debugHunkUser, 24 * opcodeLookupMaxLen, 4);
			game::gScrParserGlob[inst].opcodeLookup = opcodeLookup;

			memset(opcodeLookup, 0, sizeof(game::OpcodeLookup) * game::gScrParserGlob[inst].opcodeLookupMaxLen);

			sourcePosLookupMaxLen = inst != game::SCRIPTINSTANCE_CLIENT ? 0x60000 : 0x10;
			game::gScrParserGlob[inst].sourcePosLookupMaxLen = sourcePosLookupMaxLen;
			game::gScrParserGlob[inst].sourcePosLookupLen = 0;
			game::gScrParserGlob[inst].sourcePosLookup = (game::SourceLookup*)game::Hunk_UserAlloc(debugHunkUser, 8 * sourcePosLookupMaxLen, 4);
			sourceBufferLookupMaxLen = inst != game::SCRIPTINSTANCE_CLIENT ? 0x100 : 0x10;
			game::gScrParserGlob[inst].sourceBufferLookupMaxLen = sourceBufferLookupMaxLen;
			game::gScrParserGlob[inst].currentCodePos = 0;
			game::gScrParserGlob[inst].currentSourcePosCount = 0;
			game::gScrParserPub[inst].sourceBufferLookupLen = 0;
			game::gScrParserPub[inst].sourceBufferLookup = (game::SourceBufferInfo*)game::Hunk_UserAlloc(debugHunkUser, 24 * sourceBufferLookupMaxLen, 4);
		}
	}

	// Decomp Status: Tested, Completed
	void Scr_ShutdownOpcodeLookup(game::scriptInstance_t inst)
	{
		if (game::gScrParserGlob[inst].opcodeLookup)
		{
			game::gScrParserGlob[inst].opcodeLookup = 0;
		}
		if (game::gScrParserGlob[inst].sourcePosLookup)
		{
			game::gScrParserGlob[inst].sourcePosLookup = 0;
		}
		if (game::gScrParserPub[inst].sourceBufferLookup != 0)
		{
			game::gScrParserPub[inst].sourceBufferLookup = 0;
		}
		if (game::gScrParserGlob[inst].saveSourceBufferLookup)
		{
			game::gScrParserGlob[inst].saveSourceBufferLookup = 0;
		}
	}

	// Decomp Status: Completed
	void AddOpcodePos(game::scriptInstance_t inst, unsigned int sourcePos, int type)
	{
		game::OpcodeLookup* newOpcodeLookup;
		game::SourceLookup* newSourcePosLookup;
		char* compilerOpcodePos;
		game::OpcodeLookup* opcodeLookup;
		int posIndex;
		game::SourceLookup* sourcePosLookup;
		int delayedSourceIndex;
		int allocSize;

		if (game::gScrVarPub[inst].developer)
		{
			if (game::gScrCompilePub[inst].developer_statement != 2)
			{
				if (!game::gScrCompilePub[inst].allowedBreakpoint)
				{
					type &= ~1u;
				}

				assert(game::gScrParserGlob[inst].opcodeLookup);

				assert(game::gScrParserGlob[inst].opcodeLookupMaxLen);

				assert(game::gScrParserGlob[inst].sourcePosLookup);

				assert(game::gScrCompilePub[inst].opcodePos);

				if (game::gScrParserGlob[inst].opcodeLookupLen >= game::gScrParserGlob[inst].opcodeLookupMaxLen)
				{
					allocSize = (sizeof(game::OpcodeLookup) * 2) * game::gScrParserGlob[inst].opcodeLookupMaxLen;
					game::gScrParserGlob[inst].opcodeLookupMaxLen *= 2;

					assert(game::gScrParserGlob[inst].opcodeLookupLen < game::gScrParserGlob[inst].opcodeLookupMaxLen);

					newOpcodeLookup = (game::OpcodeLookup*)game::Hunk_UserAlloc((game::HunkUser*)game::g_DebugHunkUser.get(), allocSize, 4);
					memcpy(newOpcodeLookup, game::gScrParserGlob[inst].opcodeLookup, sizeof(game::OpcodeLookup) * game::gScrParserGlob[inst].opcodeLookupLen);
					game::gScrParserGlob[inst].opcodeLookup = newOpcodeLookup;
				}

				if (game::gScrParserGlob[inst].sourcePosLookupLen >= game::gScrParserGlob[inst].sourcePosLookupMaxLen)
				{
					allocSize = (sizeof(game::SourceLookup) * 2) * game::gScrParserGlob[inst].sourcePosLookupMaxLen;
					game::gScrParserGlob[inst].sourcePosLookupMaxLen *= 2;

					assert(game::gScrParserGlob[inst].sourcePosLookupLen < game::gScrParserGlob[inst].sourcePosLookupMaxLen);

					newSourcePosLookup = (game::SourceLookup*)game::Hunk_UserAlloc((game::HunkUser*)game::g_DebugHunkUser.get(), allocSize, 4);
					memcpy(newSourcePosLookup, game::gScrParserGlob[inst].sourcePosLookup, sizeof(game::SourceLookup) * game::gScrParserGlob[inst].sourcePosLookupLen);
					game::gScrParserGlob[inst].sourcePosLookup = newSourcePosLookup;
				}

				compilerOpcodePos = game::gScrCompilePub[inst].opcodePos;
				if ((char*)game::gScrParserGlob[inst].currentCodePos == compilerOpcodePos)
				{
					//assert(game::gScrParserGlob[inst].currentSourcePosCount);

					opcodeLookup = &game::gScrParserGlob[inst].opcodeLookup[--game::gScrParserGlob[inst].opcodeLookupLen];

					//assert(opcodeLookup->sourcePosIndex + game::gScrParserGlob[inst].currentSourcePosCount == game::gScrParserGlob[inst].sourcePosLookupLen);

					//assert(opcodeLookup->codePos == (char*)game::gScrParserGlob[inst].currentCodePos);
				}
				else
				{
					game::gScrParserGlob[inst].currentCodePos = (const unsigned char*)compilerOpcodePos;
					opcodeLookup = &game::gScrParserGlob[inst].opcodeLookup[game::gScrParserGlob[inst].opcodeLookupLen];
					game::gScrParserGlob[inst].currentSourcePosCount = 0;
					opcodeLookup->sourcePosIndex = game::gScrParserGlob[inst].sourcePosLookupLen;
					opcodeLookup->codePos = (const char*)game::gScrParserGlob[inst].currentCodePos;
				}

				posIndex = game::gScrParserGlob[inst].currentSourcePosCount + opcodeLookup->sourcePosIndex;
				sourcePosLookup = &game::gScrParserGlob[inst].sourcePosLookup[posIndex];
				sourcePosLookup->sourcePos = sourcePos;
				if (sourcePos == -1)
				{
					assert(game::gScrParserGlob[inst].delayedSourceIndex == -1);

					assert(type & game::SOURCE_TYPE_BREAKPOINT);

					game::gScrParserGlob[inst].delayedSourceIndex = posIndex;
				}
				else if (sourcePos == -2)
				{
					game::gScrParserGlob[inst].threadStartSourceIndex = posIndex;
				}
				else
				{
					delayedSourceIndex = game::gScrParserGlob[inst].delayedSourceIndex;
					if (delayedSourceIndex >= 0 && (type & 1) != 0)
					{
						game::gScrParserGlob[inst].sourcePosLookup[delayedSourceIndex].sourcePos = sourcePos;
						game::gScrParserGlob[inst].delayedSourceIndex = -1;
					}
				}

				sourcePosLookup->type |= type;
				opcodeLookup->sourcePosCount = ++game::gScrParserGlob[inst].currentSourcePosCount;
				++game::gScrParserGlob[inst].opcodeLookupLen;
				++game::gScrParserGlob[inst].sourcePosLookupLen;
			}
			else
			{
				assert(!game::gScrVarPub[inst].developer_script);
			}
		}
	}

	// Decomp Status: Tested, Completed
	void RemoveOpcodePos(game::scriptInstance_t inst)
	{
		game::OpcodeLookup* opcodeLookup;

		if (game::gScrVarPub[inst].developer)
		{
			if (game::gScrCompilePub[inst].developer_statement == 2)
			{
				assert(!game::gScrVarPub[inst].developer_script);
			}
			else
			{
				assert(game::gScrParserGlob[inst].opcodeLookup);

				assert(game::gScrParserGlob[inst].opcodeLookupMaxLen);

				assert(game::gScrParserGlob[inst].sourcePosLookup);

				assert(game::gScrCompilePub[inst].opcodePos);

				assert(game::gScrParserGlob[inst].sourcePosLookupLen);

				--game::gScrParserGlob[inst].sourcePosLookupLen;

				assert(game::gScrParserGlob[inst].opcodeLookupLen);

				--game::gScrParserGlob[inst].opcodeLookupLen;

				assert(game::gScrParserGlob[inst].currentSourcePosCount);

				--game::gScrParserGlob[inst].currentSourcePosCount;
				opcodeLookup = &game::gScrParserGlob[inst].opcodeLookup[game::gScrParserGlob[inst].opcodeLookupLen];

				assert((char*)game::gScrParserGlob[inst].currentCodePos == game::gScrCompilePub[inst].opcodePos);

				assert(opcodeLookup->sourcePosIndex + game::gScrParserGlob[inst].currentSourcePosCount == game::gScrParserGlob[inst].sourcePosLookupLen);

				assert(opcodeLookup->codePos == (char*)game::gScrParserGlob[inst].currentCodePos);

				if (game::gScrParserGlob[inst].currentSourcePosCount == 1)
				{
					game::gScrParserGlob[inst].currentCodePos = 0;
				}

				game::gScrParserGlob[inst].opcodeLookup[game::gScrParserGlob[inst].opcodeLookupLen].sourcePosCount = game::gScrParserGlob[inst].currentSourcePosCount;
			}

		}
	}

	// Decomp Status: Tested, Completed
	void AddThreadStartOpcodePos(game::scriptInstance_t inst, unsigned int sourcePos)
	{
		game::SourceLookup* sourcePosLookup;

		if (game::gScrVarPub[inst].developer)
		{
			if (game::gScrCompilePub[inst].developer_statement == 2)
			{
				assert(!game::gScrVarPub[inst].developer_script);
			}
			else
			{
				assert(game::gScrParserGlob[inst].threadStartSourceIndex >= 0);

				sourcePosLookup = &game::gScrParserGlob[inst].sourcePosLookup[game::gScrParserGlob[inst].threadStartSourceIndex];
				sourcePosLookup->sourcePos = sourcePos;

				assert(!sourcePosLookup->type);

				sourcePosLookup->type = 4;
				game::gScrParserGlob[inst].threadStartSourceIndex = -1;
			}
		}
	}

	// Decomp Status: Completed
	unsigned int Scr_GetSourceBuffer(game::scriptInstance_t inst, const char* codePos)
	{
		unsigned int bufferIndex;
		
		assert(game::Scr_IsInOpcodeMemory(inst, codePos));

		assert(game::gScrParserPub[inst].sourceBufferLookupLen > 0);

		for ( bufferIndex = game::gScrParserPub[inst].sourceBufferLookupLen - 1;
			bufferIndex && (!game::gScrParserPub[inst].sourceBufferLookup[bufferIndex].codePos || game::gScrParserPub[inst].sourceBufferLookup[bufferIndex].codePos > codePos);
			--bufferIndex )
		{
			;
		}

		return bufferIndex;
	}

	// Decomp Status: Tested, Completed
	unsigned int Scr_GetLineNumInternal(const char** startLine, const char* buf, const char* sourcePos, int* col)
	{
		unsigned int lineNum;

		assert(buf);

		lineNum = 0;
		for (*startLine = buf; sourcePos; --sourcePos)
		{
			if (!*buf)
			{
				*startLine = buf + 1;
				++lineNum;
			}
			++buf;
		}
		*col = buf - *startLine;
		return lineNum;
	}

	// Decomp Status: Tested, Completed
	game::SourceBufferInfo* Scr_GetNewSourceBuffer(game::scriptInstance_t inst)
	{
		unsigned int* sourceBufferLookupMaxLen;
		int allocSize;
		game::SourceBufferInfo* newSourceBufferInfo;

		assert(game::gScrParserPub[inst].sourceBufferLookup);

		assert(game::gScrParserGlob[inst].sourceBufferLookupMaxLen);

		if (game::gScrParserPub[inst].sourceBufferLookupLen < game::gScrParserGlob[inst].sourceBufferLookupMaxLen)
		{
			return &game::gScrParserPub[inst].sourceBufferLookup[game::gScrParserPub[inst].sourceBufferLookupLen++];
		}

		//assert(gScrParserPub[inst].sourceBufferLookupLen >= gScrParserGlob[inst].sourceBufferLookupMaxLen);

		sourceBufferLookupMaxLen = &game::gScrParserGlob[inst].sourceBufferLookupMaxLen;
		allocSize = 2 * *sourceBufferLookupMaxLen;
		*sourceBufferLookupMaxLen = allocSize;
		newSourceBufferInfo = (game::SourceBufferInfo*)game::Hunk_UserAlloc((game::HunkUser*)game::g_DebugHunkUser.get(), sizeof(game::OpcodeLookup) * allocSize, 4);
		memcpy(newSourceBufferInfo, game::gScrParserPub[inst].sourceBufferLookup, sizeof(game::OpcodeLookup) * game::gScrParserPub[inst].sourceBufferLookupLen);
		game::gScrParserPub[inst].sourceBufferLookup = newSourceBufferInfo;
		return &game::gScrParserPub[inst].sourceBufferLookup[game::gScrParserPub[inst].sourceBufferLookupLen++];
	}

	// Decomp Status: Tested, Completed
	void Scr_AddSourceBufferInternal(const char* filename, game::scriptInstance_t inst, const char* codepos, char* buffer, int len, int archive)
	{
		game::SourceBufferInfo* newBuffer;
		const char* source;
		char* buf;
		char c;
		int i;
		char* tmp;
		size_t size;
		char* dest;

		if (game::gScrParserPub[inst].sourceBufferLookup)
		{
			size = strlen(filename);
			dest = (char*)game::Hunk_UserAlloc((struct game::HunkUser*)game::g_DebugHunkUser.get(), size + len + 3, 4);
			memcpy(dest, filename, size + 1);
			if (buffer)
			{
				source = &dest[size + 1];
			}
			else
			{
				source = 0;
			}
			buf = buffer;
			tmp = (char*)source;
			if (len >= 0)
			{
				for (i = 0; i <= len; ++i)
				{
					c = *buf++;
					if (c == '\n' || c == '\r' && *buf != '\n')
						*tmp = 0;
					else
						*tmp = c;
					++tmp;
				}
			}
			newBuffer = game::Scr_GetNewSourceBuffer(inst);
			newBuffer->codePos = codepos;
			newBuffer->buf = dest;
			newBuffer->sourceBuf = source;
			newBuffer->len = len;
			newBuffer->sortedIndex = -1;
			newBuffer->archive = archive;
			if (source)
			{
				game::gScrParserPub[inst].sourceBuf = source;
			}
		}
		else
		{
			game::gScrParserPub[inst].sourceBuf = 0;
		}
	}

	// Decomp Status: Tested, Completed
	char* Scr_ReadFile_FastFile(game::scriptInstance_t inst, [[maybe_unused]] int unused, char* filename, const char* codepos, int archive)
	{
		char* buffer;
		game::RawFile* scriptFile;

		scriptFile = game::DB_FindXAssetHeader(game::ASSET_TYPE_RAWFILE, filename, 1, -1).rawfile;
		if ((*game::useFastFile)->current.enabled && scriptFile != 0)
		{
			game::Scr_AddSourceBufferInternal(filename, inst, codepos, scriptFile->buffer, strlen(scriptFile->buffer), archive);
			buffer = scriptFile->buffer;
		}
		else
		{
			game::Scr_AddSourceBufferInternal(filename, inst, codepos, 0, -1, archive);
			buffer = 0;
		}
		return buffer;
	}

	// Decomp Status: Tested, Completed
	char* Scr_ReadFile_LoadObj(game::scriptInstance_t inst, [[maybe_unused]] int unused_arg1, const char* filename, const char* codepos, int archive)
	{
		int fileLen;
		int fh;
		char* buffer;

		fileLen = game::FS_FOpenFileRead(filename, &fh);
		if (fh)
		{
			game::fsh[fh].fileSize = fileLen;
			game::fsh[fh].streamed = 0;
		}

		game::fsh[fh].handleSync = 0;
		if (fileLen >= 0)
		{
			if (!(*game::fs_game)->current.string)
			{
				game::Scr_SetLoadedImpureScript(true);
			}
			buffer = (char*)game::Hunk_AllocateTempMemoryHigh(fileLen + 1);
			game::FS_Read(buffer, fileLen, fh);
			buffer[fileLen] = 0;
			game::FS_FCloseFile(fh);
			game::Scr_AddSourceBufferInternal(filename, inst, codepos, buffer, fileLen, archive);
		}
		else
		{
			game::Scr_AddSourceBufferInternal(filename, inst, codepos, 0, -1, archive);
			buffer = 0;
		}

		return buffer;
	}

	// Decomp Status: Tested, Completed
	char* Scr_ReadFile(const char* codepos, char* filename, game::scriptInstance_t inst, int unused)
	{
		char* buffer;
		int fh;

		if (*(*game::fs_game)->current.string || (*game::com_developer)->current.enabled)
		{
			*game::statmon_related_bool = 1;
			if (game::FS_FOpenFileByMode(filename, &fh, game::FS_READ) < 0)
			{
				buffer = game::Scr_ReadFile_FastFile(inst, unused, filename, codepos, 1);
			}
			else
			{
				game::FS_FCloseFile(fh);
				buffer = game::Scr_ReadFile_LoadObj(inst, unused, filename, codepos, 1);
			}
		}
		else
		{
			if (!(*game::useFastFile)->current.enabled)
			{
				buffer = game::Scr_ReadFile_LoadObj(inst, unused, filename, codepos, 1);
			}
			else
			{
				buffer = game::Scr_ReadFile_FastFile(inst, unused, filename, codepos, 1);
			}

		}
		return buffer;
	}

	// Decomp Status: Completed
	char* Scr_AddSourceBuffer(game::scriptInstance_t inst, int unused_arg1, char* filename, const char* codepos)
	{
		unsigned int saveSourceBufferLookupLen;
		int len;
		game::SaveSourceBufferInfo* saveSourceBuffer;
		char* dest;
		char* sourceBuf;
		char* source;
		int len2;
		char c;

		if (!game::gScrParserGlob[inst].saveSourceBufferLookup)
		{
			return game::Scr_ReadFile(codepos, filename, inst, unused_arg1);
		}

		assert(game::gScrParserGlob[inst].saveSourceBufferLookupLen > 0);

		saveSourceBufferLookupLen = --game::gScrParserGlob[inst].saveSourceBufferLookupLen;
		len = game::gScrParserGlob[inst].saveSourceBufferLookup[saveSourceBufferLookupLen].len;
		saveSourceBuffer = &game::gScrParserGlob[inst].saveSourceBufferLookup[saveSourceBufferLookupLen];

		assert(len >= -1);

		if (len >= 0)
		{
			sourceBuf = (char*)game::Hunk_AllocateTempMemoryHigh(len + 1);
			source = (char*)saveSourceBuffer->sourceBuf;
			dest = sourceBuf;
			if (len > 0)
			{
				len2 = len;
				do
				{
					c = *source++;
					if (!c)
					{
						c = '\n';
					}
					*dest++ = c;
					--len2;
				} while (len2);
			}
			*dest = 0;
		}
		else
		{
			dest = 0;
		}

		game::Scr_AddSourceBufferInternal(filename, inst, codepos, dest, len, 1);
		return dest;
	}

	// Decomp Status: Completed
	void Scr_CopyFormattedLine(const char* rawLine, char* line)
	{
		char cleanChar;
		int len;
		int i;

		len = strlen(rawLine);
		if ( len >= 1024 )
		{
			len = 1023;
		}

		for ( i = 0;
			i < len;
			++i )
		{
			if ( rawLine[i] == '\t' )
			{
				cleanChar = ' ';
			}
			else
			{
				cleanChar = rawLine[i];
			}

			line[i] = cleanChar;
		}

		if ( line[len - 1] == '\r' )
		{
			line[len - 1] = 0;
		}

		line[len] = 0;
	}

	// Decomp Status: Completed
	unsigned int Scr_GetLineInfo(int* col, const char* buf, unsigned int sourcePos, char* line)
	{
		const char *startLine;
		unsigned int lineNum;

		if ( buf )
		{
			lineNum = game::Scr_GetLineNumInternal(&startLine, buf, (const char*)sourcePos, col);
		}
		else
		{
			lineNum = 0;
			startLine = "";
			*col = 0;
		}

		game::Scr_CopyFormattedLine(startLine, line);
		return lineNum;
	}

	// Decomp Status: Completed
	void Scr_PrintSourcePos(unsigned int sourcePos, const char* buf, game::con_channel_e channel, game::scriptInstance_t inst, const char* file)
	{
		const char *fileVaLine;
		const char *lineStr;
		const char *savegameStr;
		unsigned int lineNum;
		char line[1024];
		int i;
		int col;

		assert(file);

		lineNum = game::Scr_GetLineInfo(&col, buf, sourcePos, line);

		if ( game::gScrParserGlob[inst].saveSourceBufferLookup )
		{
			savegameStr = " (savegame)";
		}
		else
		{
			savegameStr = "";
		}

		fileVaLine = game::va("(file '%s'%s, line %d)\n", file, savegameStr, lineNum + 1);
		game::Com_PrintMessage(channel, fileVaLine, 0);

		lineStr = game::va("%s\n", line);
		game::Com_PrintMessage(channel, lineStr, 0);

		for ( i = 0;
			i < col;
			++i )
		{
			game::Com_PrintMessage(channel, " ", 0);
		}

		game::Com_PrintMessage(channel, "*\n", 0);
	}

	// Decomp Status: Completed
	game::OpcodeLookup* Scr_GetPrevSourcePosOpcodeLookup(game::scriptInstance_t inst, const char* codePos)
	{
		unsigned int low;
		unsigned int middle;
		unsigned int high;

		assert(game::Scr_IsInOpcodeMemory(inst, codePos));

		assert(game::gScrParserGlob[inst].opcodeLookup);

		low = 0;
		high = game::gScrParserGlob[inst].opcodeLookupLen - 1;
		while ( low <= high )
		{
			middle = (high + low) >> 1;
			if ( codePos < game::gScrParserGlob[inst].opcodeLookup[middle].codePos )
			{
				high = middle - 1;
			}
			else
			{
				low = middle + 1;
				if ( middle + 1 == game::gScrParserGlob[inst].opcodeLookupLen || codePos < game::gScrParserGlob[inst].opcodeLookup[low].codePos )
				{
					return &game::gScrParserGlob[inst].opcodeLookup[middle];
				}
			}
		}

		assert(false);

		return 0;
	}

	// Restored
	unsigned int Scr_GetPrevSourcePos(game::scriptInstance_t inst, const char *codePos, unsigned int index)
	{
		return game::gScrParserGlob[inst].sourcePosLookup[index + game::Scr_GetPrevSourcePosOpcodeLookup(inst, codePos)->sourcePosIndex].sourcePos;
	}

	// Decomp Status: Completed
	void Scr_GetTextSourcePos(char* line, const char* codePos, game::scriptInstance_t inst)
	{
		unsigned int prevsourcePos;
		unsigned int bufferIndex;
		int col;

		if ( game::gScrVarPub[inst].developer
			&& codePos
			&& codePos != game::g_EndPos.get()
			&& game::gScrVarPub[inst].programBuffer
			&& game::Scr_IsInOpcodeMemory(inst, codePos) )
		{
			bufferIndex = game::Scr_GetSourceBuffer(inst, codePos - 1);
			prevsourcePos = game::Scr_GetPrevSourcePos(inst, codePos - 1, 0);
			game::Scr_GetLineInfo(&col, game::gScrParserPub[inst].sourceBufferLookup[bufferIndex].sourceBuf, prevsourcePos, line);
		}
		else
		{
			*line = 0;
		}
	}

	// Decomp Status: Completed
	void Scr_PrintPrevCodePos(const char* codepos, game::scriptInstance_t scriptInstance, game::con_channel_e channel, unsigned int index)
	{
		unsigned int bufferIndex; // esi
		unsigned int prevSourcepos; // eax

		if (!codepos)
		{
			game::Com_PrintMessage(channel, "<frozen thread>\n", 0);
			return;
		}

		if (codepos == game::g_EndPos.get())
		{
			game::Com_PrintMessage(channel, "<removed thread>\n", 0);
		}
		else
		{
			if (game::gScrVarPub[scriptInstance].developer)
			{
				if (game::gScrVarPub[scriptInstance].programBuffer && game::Scr_IsInOpcodeMemory(scriptInstance, codepos)) 
				{
					bufferIndex = game::Scr_GetSourceBuffer(scriptInstance, codepos - 1);
					prevSourcepos = game::Scr_GetPrevSourcePos(scriptInstance, codepos - 1, index);

					game::Scr_PrintSourcePos(
						prevSourcepos,
						game::gScrParserPub[scriptInstance].sourceBufferLookup[bufferIndex].sourceBuf,
						channel,
						scriptInstance,
						game::gScrParserPub[scriptInstance].sourceBufferLookup[bufferIndex].buf);
					return;
				}
			}
			else
			{
				if (game::Scr_IsInOpcodeMemory(scriptInstance, codepos - 1))
				{
					game::Com_PrintMessage(channel, game::va("@ %d\n", codepos - game::gScrVarPub[scriptInstance].programBuffer), 0);
					return;
				}
			}

			game::Com_PrintMessage(channel, game::va("%s\n\n", codepos), 0);
		}
	}

	// Restored
	void Scr_ShutdownAllocNode(game::scriptInstance_t inst)
	{
		if (game::g_allocNodeUser[inst])
		{
			game::Hunk_UserDestroy(game::g_allocNodeUser[inst]);
			game::g_allocNodeUser[inst] = 0;
		}
	}

	// Decomp Status: Completed
	void CompileError(game::scriptInstance_t inst, unsigned int codePos, const char* msg, ...)
	{
		const char* instStr;
		int col;
		int lineNumber;
		char text[1024];
		char line[1024];
		va_list va;

		va_start(va, msg);
		vsnprintf(text, 0x400u, msg, va);
		va_end(va);

		instStr = "Server";
		if (inst)
		{
			instStr = "Client";
		}

		if (game::gScrVarPub[inst].evaluate)
		{
			if (!game::gScrVarPub[inst].error_message)
			{
				game::gScrVarPub[inst].error_message = (char*)game::va("%s", text);
			}
		}
		else
		{
			game::Scr_ShutdownAllocNode(inst);

			game::Com_PrintError(game::CON_CHANNEL_PARSERSCRIPT, "\n");
			game::Com_PrintError(game::CON_CHANNEL_PARSERSCRIPT, "******* %s script compile error *******\n", instStr);

			if (game::gScrVarPub[inst].developer && game::gScrParserPub[inst].sourceBuf)
			{
				game::Com_PrintError(game::CON_CHANNEL_PARSERSCRIPT, "%s: ", text);
				game::Scr_PrintSourcePos(
					codePos,
					game::gScrParserPub[inst].sourceBuf,
					game::CON_CHANNEL_PARSERSCRIPT,
					inst,
					game::gScrParserPub[inst].scriptfilename);
				lineNumber = game::Scr_GetLineInfo(&col, game::gScrParserPub[inst].sourceBuf, codePos, line);
			}
			else
			{
				game::Com_PrintError(game::CON_CHANNEL_PARSERSCRIPT, "%s\n", text);
				line[0] = 0;
				lineNumber = 0;
			}
			game::Com_Printf(game::CON_CHANNEL_PARSERSCRIPT, "************************************\n");
			game::Com_Error(game::ERR_SCRIPT_DROP, "\x15" "%s script compile error\n%s\n%s\n(see console for details)\n", instStr, text, line);
		}
	}

	// Decomp Status: Completed
	void CompileError2(const char* codePos, game::scriptInstance_t inst, const char* msg, ...)
	{
		const char* instStr;
		char text[1024];
		char line[1024];
		va_list va;

		va_start(va, msg);

		assert(!game::gScrVarPub[inst].evaluate);

		assert(game::Scr_IsInOpcodeMemory(inst, codePos));

		vsnprintf(text, 0x400u, msg, va);
		va_end(va);

		instStr = "Server";
		if (inst)
		{
			instStr = "Client";
		}

		game::Com_PrintError(game::CON_CHANNEL_PARSERSCRIPT, "\n");
		game::Com_PrintError(game::CON_CHANNEL_PARSERSCRIPT, "******* %s script compile error *******\n", instStr);
		game::Com_PrintError(game::CON_CHANNEL_PARSERSCRIPT, "%s: ", text);
		game::Scr_PrintPrevCodePos(codePos, inst, game::CON_CHANNEL_PARSERSCRIPT, 0);
		game::Com_Printf(game::CON_CHANNEL_PARSERSCRIPT, "************************************\n");
		game::Scr_GetTextSourcePos(line, codePos, inst);
		game::Com_Error(game::ERR_SCRIPT_DROP, "\x15" "%s script compile error\n%s\n%s\n(see console for details)\n", instStr, text, line);
	}

	// Decomp Status: Completed
	void RuntimeErrorInternal(const char* msg, game::scriptInstance_t inst, game::con_channel_e channel, const char* codepos, int index)
	{
		int functionCount;
		int i;

		assert(game::Scr_IsInOpcodeMemory(inst, codepos));

		game::Com_PrintError(channel, "\n******* script runtime error *******\n%s: ", msg);
		game::Scr_PrintPrevCodePos(codepos, inst, channel, index);
		functionCount = game::gScrVmPub[inst].function_count;
		if (functionCount)
		{
			for (i = game::gScrVmPub[inst].function_count - 1;
				i >= 1;
				--i)
			{
				game::Com_PrintError(channel, "called from:\n");
				game::Scr_PrintPrevCodePos(game::gScrVmPub[inst].function_frame_start[i].fs.pos, inst, game::CON_CHANNEL_DONT_FILTER, game::gScrVmPub[inst].function_frame_start[i].fs.localId == 0);
			}

			game::Com_PrintError(channel, "started from:\n");
			game::Scr_PrintPrevCodePos(game::gScrVmPub[inst].function_frame_start[0].fs.pos, inst, game::CON_CHANNEL_DONT_FILTER, 1u);
		}
		game::Com_PrintError(channel, "************************************\n");
	}

	// Decomp Status: Completed
	void RuntimeError(game::scriptInstance_t inst, const char* codePos, int index, const char* msg, const char* dialogMessage)
	{
		bool abort_or_terminal;
		const char* errNewline;
		const char* errNewline2;

		if (!game::gScrVarPub[inst].developer)
		{
			assert(game::Scr_IsInOpcodeMemory(inst, codePos));

			if (!game::gScrVmPub[inst].terminal_error)
			{
				return;
			}
		}

		if (game::gScrVmPub[inst].debugCode)
		{
			game::Com_Printf(game::CON_CHANNEL_PARSERSCRIPT, "%s\n", msg);

			if (!game::gScrVmPub[inst].terminal_error)
			{
				return;
			}
		}
		else
		{
			abort_or_terminal = game::gScrVmPub[inst].abort_on_error || game::gScrVmPub[inst].terminal_error;
			game::RuntimeErrorInternal(
				msg,
				inst,
				abort_or_terminal ? game::CON_CHANNEL_PARSERSCRIPT : game::CON_CHANNEL_LOGFILEONLY,
				codePos,
				index);

			if (!abort_or_terminal)
			{
				return;
			}
		}

		// pluto
		if (!game::gScrVmPub[inst].terminal_error)
		{
			return;
		}
		//

		errNewline = dialogMessage;
		if (dialogMessage)
		{
			errNewline2 = "\n";
		}
		else
		{
			errNewline = "";
			errNewline2 = "";
		}

		game::Com_Error(
			game::gScrVmPub[inst].terminal_error ? game::ERR_FATAL : game::ERR_SCRIPT,
			"\x15" "script runtime error\n(see console for details)\n%s%s%s",
			msg,
			errNewline2,
			errNewline);
	}
}