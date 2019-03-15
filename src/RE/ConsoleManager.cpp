#include "RE/ConsoleManager.h"

#include "skse64/GameAPI.h"  // ConsoleManager

#include <cstdarg>  // va_list


namespace RE
{
	ConsoleManager* ConsoleManager::GetSingleton()
	{
		return reinterpret_cast<ConsoleManager*>(*g_console);
	}


	bool ConsoleManager::IsConsoleMode()
	{
		return ::IsConsoleMode();
	}


	void ConsoleManager::Print(const char* a_fmt, ...)
	{
		using func_t = function_type_t<decltype(&ConsoleManager::Print)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::ConsoleManager, VPrint, func_t*);
		std::va_list args;
		va_start(args, a_fmt);
		func(this, a_fmt, args);
		va_end(args);
	}
}
