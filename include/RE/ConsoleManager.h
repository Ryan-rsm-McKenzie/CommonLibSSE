#pragma once

#include <cstdarg>  // va_list


namespace RE
{
	class ConsoleManager
	{
	public:
		static ConsoleManager*	GetSingleton();
		static bool				IsConsoleMode();

		void Print(const char* a_fmt, ...);
		void VPrint(const char* a_fmt, std::va_list a_args);


		// members
		char	unk0;			// 0
		char	lastMessage[1];	// 1
	};
	STATIC_ASSERT(sizeof(ConsoleManager) == 0x2);
}
