#pragma once

#include "RE/BSTEvent.h"
#include "RE/BSTHashMap.h"


namespace RE
{
	namespace BSScript
	{
		struct LogEvent;


		class ErrorLogger : public BSTEventSource<LogEvent>
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSScript__ErrorLogger;


			enum class Severity : UInt32
			{
				kInfo,
				kWarning,
				kError,
				kFatal
			};


			struct PerThreadErrorCounts
			{
				UInt32 fatalCount;	  // 0
				UInt32 errorCount;	  // 4
				UInt32 warningCount;  // 8
			};
			STATIC_ASSERT(sizeof(PerThreadErrorCounts) == 0xC);


			virtual ~ErrorLogger();	 // 00

			// add
			virtual void PostErrorImpl(const char* a_message, Severity a_severity) = 0;	 // 01
			virtual void ResetImpl();													 // 02 - { return; }


			// members
			UInt64									 unk60;			// 60
			BSTHashMap<UInt32, PerThreadErrorCounts> threadErrors;	// 68
		};
		STATIC_ASSERT(sizeof(ErrorLogger) == 0x98);
	}
}
