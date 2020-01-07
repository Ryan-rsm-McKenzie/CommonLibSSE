#pragma once

#include "RE/BSScript/ErrorLogger.h"
#include "RE/BSFixedString.h"


namespace RE
{
	namespace SkyrimScript
	{
		class Logger : public BSScript::ErrorLogger
		{
		public:
			inline static const void* RTTI = RTTI_SkyrimScript__Logger;


			virtual ~Logger();																	// 00

			// override (BSScript::ErrorLogger)
			virtual void PostErrorImpl(const char* a_logEvent, Severity a_severity) override;	// 01


			// members
			BSFixedString	logName;	// 98
			BSFixedString	logPath;	// A0
			UInt64			unkA8;		// A8
		};
		STATIC_ASSERT(sizeof(Logger) == 0xB0);
	}
}
