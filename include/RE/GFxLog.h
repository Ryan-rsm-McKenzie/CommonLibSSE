#pragma once

#include "skse64/GameRTTI.h"  // RTTI_GFxLog

#include <cstdarg>  // va_list

#include "RE/GFxLogBase.h"  // GFxLogBase
#include "RE/GFxState.h"  // GFxState


namespace RE
{
	class GFxLog :
		public GFxState,			// 00
		public GFxLogBase<GFxLog>	// 18
	{
	public:
		inline static const void* RTTI = RTTI_GFxLog;


		constexpr GFxLog() : GFxState(StateType::kLog) {}
		virtual ~GFxLog();																					// 00

		// add
		virtual void LogMessageVarg(LogMessageType a_messageType, const char* a_fmt, va_list a_argList);	// 01

		void LogMessageByType(LogMessageType a_messageType, const char* a_fmt, ...);
	};
	STATIC_ASSERT(sizeof(GFxLog) == 0x20);
}
