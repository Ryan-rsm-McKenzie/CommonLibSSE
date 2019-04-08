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
		char	unk0;			// 0
		char	lastMessage[0];	// 1
	};
	STATIC_ASSERT(sizeof(ConsoleManager) == 0x1);
}
