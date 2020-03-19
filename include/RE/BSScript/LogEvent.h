#pragma once

#include "RE/BSScript/ErrorLogger.h"


namespace RE
{
	namespace BSScript
	{
		struct LogEvent
		{
		public:
			// members
			const char* const			errorMsg;  // 00
			const ErrorLogger::Severity severity;  // 08
			UInt32						pad0C;	   // 0C
		};
		STATIC_ASSERT(sizeof(LogEvent) == 0x10);
	}
}
