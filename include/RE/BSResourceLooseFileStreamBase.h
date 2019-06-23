#pragma once

#include <winnt.h>  // HANDLE

#include "RE/BSFixedString.h"  // BSFixedString


namespace RE
{
	namespace BSResource
	{
		struct LooseFileStreamBase
		{
		public:
			BSFixedString	curDir;		// 00
			BSFixedString	relDir;		// 08
			BSFixedString	fileName;	// 10
			UInt64			unk18;		// 18
			HANDLE			handle;		// 20
		};
		STATIC_ASSERT(sizeof(LooseFileStreamBase) == 0x28);
	}
}
