#pragma once

#include "RE/B/BSFixedString.h"

namespace RE
{
	namespace BSScript
	{
		struct ILoader;

		class IObjectProcessor
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSScript__IObjectProcessor;

			virtual ~IObjectProcessor();  // 00

			// add
			virtual IObjectProcessor* Clone() = 0;                                    // 01
			virtual void              SetLoader(ILoader* a_loader) = 0;               // 02
			virtual bool              Process(const BSFixedString& a_className) = 0;  // 03
		};
		static_assert(sizeof(IObjectProcessor) == 0x8);
	}
}
