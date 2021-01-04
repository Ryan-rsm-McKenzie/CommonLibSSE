#include "RE/S/Script.h"

#include "RE/M/MemoryManager.h"

namespace RE
{
	void Script::ClearCommand()
	{
		if (text) {
			free(text);
			text = nullptr;
		}
	}

	void Script::CompileAndRun(TESObjectREFR* a_targetRef, COMPILER_NAME a_name)
	{
		ScriptCompiler compiler;
		CompileAndRun_Impl(&compiler, a_name, a_targetRef);
	}

	void Script::CompileAndRun(ScriptCompiler* a_compiler, TESObjectREFR* a_targetRef, COMPILER_NAME a_name)
	{
		CompileAndRun_Impl(a_compiler, a_name, a_targetRef);
	}

	std::string Script::GetCommand() const
	{
		return text ? text : "";
	}

	void Script::SetCommand(std::string_view a_command)
	{
		if (text) {
			free(text);
		}

		text = malloc<char>(a_command.length() + 1);
		std::memcpy(text, a_command.data(), a_command.length());
		text[a_command.length()] = '\0';
	}

	void Script::CompileAndRun_Impl(ScriptCompiler* a_compiler, COMPILER_NAME a_name, TESObjectREFR* a_targetRef)
	{
		using func_t = decltype(&Script::CompileAndRun_Impl);
		REL::Relocation<func_t> func{ Offset::Script::CompileAndRun };
		return func(this, a_compiler, a_name, a_targetRef);
	}
}
