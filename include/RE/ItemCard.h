#pragma once

#include "RE/BSString.h"
#include "RE/GFxValue.h"
#include "RE/GPtr.h"


namespace RE
{
	class GFxMovieView;


	struct ItemCard
	{
	public:
		// members
		GFxValue		   obj;		  // 00 - kObject
		BSString		   infoText;  // 18
		void*			   unk28;	  // 28
		UInt32			   unk30;	  // 30
		UInt32			   pad34;	  // 34
		GPtr<GFxMovieView> view;	  // 38
	};
	STATIC_ASSERT(sizeof(ItemCard) == 0x40);
}
