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
			BSFixedString	currentDirectory;	// 00
			BSFixedString	unk08;				// 08
			BSFixedString	fileName;			// 10
			UInt64			unk18;				// 18
			HANDLE			handle;				// 20
		};
		STATIC_ASSERT(sizeof(LooseFileStreamBase) == 0x28);
	}
}
