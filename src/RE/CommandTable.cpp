#include "RE/CommandTable.h"

#include "skse64/ObScript.h"  // g_firstObScriptCommand, g_firstConsoleCommand

#include <cstdint>  // uintptr_t
#include <string>  // string


namespace RE
{
	std::string CommandInfo::StringChunk::GetString() const
	{
		return std::string(str, length);
	}


	CommandInfo::Chunk* CommandInfo::StringChunk::GetNext()
	{
		return (Chunk*)(str + length);
	}


	int CommandInfo::IntegerChunk::GetInteger() const
	{
		return *(int*)((char*)this + 1);
	}


	CommandInfo::Chunk* CommandInfo::IntegerChunk::GetNext()
	{
		return (Chunk*)(this + 1);
	}


	CommandInfo::Chunk* CommandInfo::ScriptData::GetChunk()
	{
		return (Chunk*)((std::uintptr_t)this + 6);
	}


	CommandInfo* CommandInfo::GetFirstScriptCommand()
	{
		return reinterpret_cast<CommandInfo*>(g_firstObScriptCommand.GetPtr());
	}


	CommandInfo* CommandInfo::GetFirstConsoleCommand()
	{
		return reinterpret_cast<CommandInfo*>(g_firstConsoleCommand.GetPtr());
	}


	CommandInfo* CommandInfo::Locate(const char* a_longName)
	{
		CommandInfo* commands = GetFirstConsoleCommand();
		for (UInt16 i = kCommand_ConsoleCommandsBegin; i <= kCommand_ScriptCommandsEnd; ++i) {
			if (!strcmp(commands[i].longName, a_longName)) {
				return &commands[i];
			}
		}
		return 0;
	}


	void CommandInfo::SetParameters()
	{
		numParams = 0;
		params = 0;
	}
}
