#pragma once

#include "RE/BSString.h"  // BSString
#include "RE/GFxValue.h"  // GFxValue
#include "RE/GPtr.h"  // GPtr


namespace RE
{
	class GFxMovieView;


	struct ItemCard
	{
		GFxValue			obj;		// 00 - kObject
		BSString			infoText;	// 18
		void*				unk28;		// 28
		UInt32				unk30;		// 30
		UInt32				pad34;		// 34
		GPtr<GFxMovieView>	view;		// 38
	};
	STATIC_ASSERT(sizeof(ItemCard) == 0x40);
}
