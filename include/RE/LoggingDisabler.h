#pragma once

#include "RE/GFxLog.h"  // GFxLog


namespace RE
{
	class LoggingDisabler : public GFxLog
	{
	public:
		constexpr LoggingDisabler() : GFxLog() {}
		virtual ~LoggingDisabler() = default;																			// 00

		// override (GFxLog)
		virtual void LogMessageVarg(LogMessageType a_messageType, const char* a_fmt, va_list a_argList) override {};	// 01
	};
	STATIC_ASSERT(sizeof(LoggingDisabler) == 0x20);
}
