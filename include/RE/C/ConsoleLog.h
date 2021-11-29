#pragma once

#include "RE/B/BSString.h"
#include "RE/B/BSTSingleton.h"

namespace RE
{
	class ConsoleLog : public BSTSingletonSDM<ConsoleLog>
	{
	public:
		static ConsoleLog* GetSingleton();
		static bool        IsConsoleMode();

		void Print(const char* a_fmt, ...);
		void VPrint(const char* a_fmt, std::va_list a_args);

		// members
		char          lastMessage[0x400];  // 001
		std::uint8_t  pad401;              // 401
		std::uint16_t pad402;              // 402
		std::uint32_t pad404;              // 404
		BSString      buffer;              // 408
	};
	static_assert(sizeof(ConsoleLog) == 0x418);
}
