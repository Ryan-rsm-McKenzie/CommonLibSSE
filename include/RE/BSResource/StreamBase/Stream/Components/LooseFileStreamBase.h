#pragma once

#include "RE/BSFixedString.h"
#include "RE/BSResource/BSSystemFile.h"


namespace RE
{
	namespace BSResource
	{
		struct LooseFileStreamBase
		{
		public:
			// members
			BSFixedString prefix;	 // 00
			BSFixedString dirName;	 // 08
			BSFixedString fileName;	 // 10
			BSSystemFile  file;		 // 18
		};
		STATIC_ASSERT(sizeof(LooseFileStreamBase) == 0x28);
	}
}
