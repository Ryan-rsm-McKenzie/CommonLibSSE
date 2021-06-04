#pragma once

#include "RE/B/BSString.h"
#include "RE/G/GFxValue.h"
#include "RE/G/GPtr.h"

namespace RE
{
	class GFxMovieView;

	struct ItemCard
	{
	public:
		// members
		GFxValue           obj;       // 00 - kObject
		BSString           infoText;  // 18
		void*              unk28;     // 28
		std::uint32_t      unk30;     // 30
		std::uint32_t      pad34;     // 34
		GPtr<GFxMovieView> view;      // 38
	};
	static_assert(sizeof(ItemCard) == 0x40);
}
