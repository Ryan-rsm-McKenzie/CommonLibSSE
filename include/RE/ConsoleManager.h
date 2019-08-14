#pragma once

#include <cstdarg>  // va_list

#include "RE/BSString.h"  // BSString
#include "RE/BSTSingleton.h"  // BSTSingletonSDM


namespace RE
{
	class ConsoleManager : public BSTSingletonSDM<ConsoleManager>
	{
	public:
		static ConsoleManager*	GetSingleton();
		static bool				IsConsoleMode();

		void Print(const char* a_fmt, ...);
		void VPrint(const char* a_fmt, std::va_list a_args);


		// members
		char		lastMessage[0x400];	// 001
		UInt8		pad401;				// 401
		UInt16		pad402;				// 402
		UInt32		pad404;				// 404
		BSString	buffer;				// 408
	};
	STATIC_ASSERT(offsetof(ConsoleManager, lastMessage) == 0x1);
	STATIC_ASSERT(sizeof(ConsoleManager) == 0x418);
}
