#pragma once

#include "RE/B/BSFixedString.h"

namespace RE
{
	struct ImageData
	{
		void*         unk00;     // 00 - smart ptr
		std::uint64_t unk08;     // 08
		BSFixedString filePath;  // 10
	};
	static_assert(sizeof(ImageData) == 0x18);
}
