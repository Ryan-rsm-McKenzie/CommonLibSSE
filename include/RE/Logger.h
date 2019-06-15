#pragma once

#include "skse64/GameRTTI.h"  // RTTI_SkyrimScript__Logger

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/ErrorLogger.h"  // ErrorLogger


namespace RE
{
	namespace SkyrimScript
	{
		class Logger : BSScript::ErrorLogger
		{
		public:
			inline static const void* RTTI = RTTI_SkyrimScript__Logger;


			virtual ~Logger();												// 00

			// override (BSScript::ErrorLogger)
			virtual const char*	FormatLog(const char* a_logEvent) override;	// 01


			// members
			BSFixedString	logName;	// 98
			BSFixedString	logPath;	// A0
			UInt64			unkA8;		// A8
		};
		STATIC_ASSERT(sizeof(Logger) == 0xB0);
	}
}
