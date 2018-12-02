#pragma once


namespace RE
{
	class ConsoleManager
	{
	public:
		ConsoleManager();
		~ConsoleManager();

		static ConsoleManager*	GetSingleton();
		static bool				IsConsoleMode();
		void					Print(const char* a_fmt, ...);


		// members
		void*	scriptContext;	// 00
	};
}
