#include "RE/ConsoleManager.h"

#include "skse64/GameAPI.h"  // ConsoleManager


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
		typedef void _Print_t(ConsoleManager* a_this, const char* a_fmt, va_list args);
		static uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::ConsoleManager*>(this)->_VPrint_GetPtr());
		static _Print_t* _Print = reinterpret_cast<_Print_t*>(*ptr);

		va_list	args;
		va_start(args, a_fmt);
		_Print(this, a_fmt, args);
		va_end(args);
	}
}
