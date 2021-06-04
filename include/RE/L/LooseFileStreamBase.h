#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSSystemFile.h"

namespace RE
{
	namespace BSResource
	{
		struct LooseFileStreamBase
		{
		public:
			// members
			BSFixedString prefix;    // 00
			BSFixedString dirName;   // 08
			BSFixedString fileName;  // 10
			BSSystemFile  file;      // 18
		};
		static_assert(sizeof(LooseFileStreamBase) == 0x28);
	}
}
