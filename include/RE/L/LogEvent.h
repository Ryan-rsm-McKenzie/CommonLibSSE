#pragma once

#include "RE/E/ErrorLogger.h"

namespace RE
{
	namespace BSScript
	{
		struct LogEvent
		{
		public:
			// members
			const char* const           errorMsg;  // 00
			const ErrorLogger::Severity severity;  // 08
			std::uint32_t               pad0C;     // 0C
		};
		static_assert(sizeof(LogEvent) == 0x10);
	}
}
