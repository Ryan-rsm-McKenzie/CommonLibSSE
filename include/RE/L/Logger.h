#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/E/ErrorLogger.h"

namespace RE
{
	namespace SkyrimScript
	{
		class Logger : public BSScript::ErrorLogger
		{
		public:
			inline static constexpr auto RTTI = RTTI_SkyrimScript__Logger;

			~Logger() override;  // 00

			// override (BSScript::ErrorLogger)
			void PostErrorImpl(const char* a_logEvent, Severity a_severity) override;  // 01

			// members
			BSFixedString logName;  // 98
			BSFixedString logPath;  // A0
			std::uint64_t unkA8;    // A8
		};
		static_assert(sizeof(Logger) == 0xB0);
	}
}
