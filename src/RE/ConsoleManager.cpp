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
		using func_t = void(ConsoleManager*, const char*, ...);
		func_t* func = reinterpret_cast<func_t*>(((::ConsoleManager*)0)->_VPrint_GetPtr());
		std::va_list args;
		va_start(args, a_fmt);
		func(this, a_fmt, args);
		va_end(args);
	}
}
