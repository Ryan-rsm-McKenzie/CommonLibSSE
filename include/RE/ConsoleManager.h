#pragma once


namespace RE
{
	class ConsoleManager
	{
	public:
		static ConsoleManager*	GetSingleton();
		static bool				IsConsoleMode();
		void					Print(const char* a_fmt, ...);


		// members
		void* scriptContext;	// 00
	};
	STATIC_ASSERT(sizeof(ConsoleManager) == 0x8);
}
