#pragma once

#include "skse64/GameRTTI.h"  // RTTI_LoggingDisabler

#include "RE/GFxLog.h"  // GFxLog


namespace RE
{
	class LoggingDisabler : public GFxLog
	{
	public:
		inline static const void* RTTI = RTTI_LoggingDisabler;


		constexpr LoggingDisabler() : GFxLog() {}
		virtual ~LoggingDisabler();																					// 00

		// override (GFxLog)
		virtual void LogMessageVarg(LogMessageType a_messageType, const char* a_fmt, va_list a_argList) override;	// 01
	};
	STATIC_ASSERT(sizeof(LoggingDisabler) == 0x20);
}
