#include "RE/Script.h"

#include <cstring>  // memcpy

#include "RE/TESMemoryManager.h"  // malloc, free


namespace RE
{
	void Script::SetCommand(std::string_view a_command)
	{
		if (command) {
			free(command);
		}

		command = malloc<char>(a_command.length() + 1);
		std::memcpy(command, a_command.data(), a_command.length());
	}


	void Script::ClearCommand()
	{
		if (command) {
			free(command);
			command = 0;
		}
	}
}
