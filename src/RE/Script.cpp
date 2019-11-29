#include "RE/Script.h"

#include <cstring>

#include "RE/Offsets.h"
#include "RE/TESMemoryManager.h"
#include "REL/Relocation.h"


namespace RE
{
	std::string Script::GetCommand() const
	{
		return command ? command : "";
	}


	void Script::SetCommand(std::string_view a_command)
	{
		if (command) {
			free(command);
		}

		command = malloc<char>(a_command.length() + 1);
		std::memcpy(command, a_command.data(), a_command.length());
		command[a_command.length()] = '\0';
	}


	void Script::ClearCommand()
	{
		if (command) {
			free(command);
			command = 0;
		}
	}


	void Script::Invoke(TESObjectREFR* a_targetRef, InvokeType a_type)
	{
		Invoke_Impl(0, a_type, a_targetRef);
	}


	void Script::Invoke_Impl(void* a_arg1, InvokeType a_type, TESObjectREFR* a_targetRef)
	{
		using func_t = function_type_t<decltype(&Script::Invoke_Impl)>;
		REL::Offset<func_t*> func(Offset::Script::Invoke);
		return func(this, a_arg1, a_type, a_targetRef);
	}
}
