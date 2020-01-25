#pragma once

#include "RE/BSResource/BSSystemFile.h"
#include "RE/BSFixedString.h"


namespace RE
{
	namespace BSResource
	{
		struct LooseFileStreamBase
		{
		public:
			BSFixedString	prefix;		// 00
			BSFixedString	dirName;	// 08
			BSFixedString	fileName;	// 10
			BSSystemFile	file;		// 18
		};
		STATIC_ASSERT(sizeof(LooseFileStreamBase) == 0x28);
	}
}
