#include "RE/CommandTable.h"

#include <string>

#include "RE/Offsets.h"
#include "REL/Relocation.h"


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
		REL::Offset<CommandInfo*> ptr(Offset::CommandInfo::FirstScriptCommand);
		return ptr.GetType();
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
		REL::Offset<CommandInfo*> ptr(Offset::CommandInfo::FirstConsoleCommand);
		return ptr.GetType();
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
