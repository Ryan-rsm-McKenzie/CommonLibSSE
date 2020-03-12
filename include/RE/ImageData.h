#pragma once

#include "RE/BSFixedString.h"


namespace RE
{
	struct ImageData
	{
		void*		  unk00;	 // 00 - smart ptr
		UInt64		  unk08;	 // 08
		BSFixedString filePath;	 // 10
	};
	STATIC_ASSERT(sizeof(ImageData) == 0x18);
}
