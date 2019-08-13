#include "RE/CommandTable.h"

#include "skse64/ObScript.h"  // g_firstObScriptCommand, g_firstConsoleCommand

#include <string.h>  // _stricmp

#include <cstdint>  // uintptr_t
#include <string>  // string


namespace RE
{
	auto CommandInfo::Chunk::AsString()
		-> StringChunk*
	{
		return static_cast<StringChunk*>(this);
	}


	auto CommandInfo::Chunk::AsInteger()
		-> IntegerChunk*
	{
		return static_cast<IntegerChunk*>(this);
	}


	std::string CommandInfo::StringChunk::GetString() const
	{
		return length ? std::string(str, length) : "";
	}


	auto CommandInfo::StringChunk::GetNext()
		-> Chunk*
	{
		return reinterpret_cast<Chunk*>(str + length);
	}


	int CommandInfo::IntegerChunk::GetInteger() const
	{
		return *(int*)((std::uintptr_t)this + 1);
	}


	auto CommandInfo::IntegerChunk::GetNext()
		-> Chunk*
	{
		return reinterpret_cast<Chunk*>(this + 1);
	}


	auto CommandInfo::ScriptData::GetChunk()
		-> Chunk*
	{
		return reinterpret_cast<Chunk*>(this + 1);
	}


	auto CommandInfo::ScriptData::GetStringChunk()
		-> StringChunk*
	{
		return static_cast<StringChunk*>(GetChunk());
	}


	auto CommandInfo::ScriptData::GetIntegerChunk()
		-> IntegerChunk*
	{
		return static_cast<IntegerChunk*>(GetChunk());
	}


	CommandInfo* CommandInfo::GetFirstScriptCommand()
	{
		return reinterpret_cast<CommandInfo*>(g_firstObScriptCommand.GetPtr());
	}


	CommandInfo* CommandInfo::LocateScriptCommand(const char* a_longName)
	{
		auto scriptCommands = GetFirstScriptCommand();
		for (UInt16 i = 0; i < Commands::kScriptCommandsEnd; ++i) {
			if (_stricmp(scriptCommands[i].longName, a_longName) == 0) {
				return &scriptCommands[i];
			}
		}
		return 0;
	}


	CommandInfo* CommandInfo::GetFirstConsoleCommand()
	{
		return reinterpret_cast<CommandInfo*>(g_firstConsoleCommand.GetPtr());
	}


	CommandInfo* CommandInfo::LocateConsoleCommand(const char* a_longName)
	{
		auto consoleCommands = GetFirstConsoleCommand();
		for (UInt16 i = 0; i < Commands::kConsoleCommandsEnd; ++i) {
			if (_stricmp(consoleCommands[i].longName, a_longName) == 0) {
				return &consoleCommands[i];
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
