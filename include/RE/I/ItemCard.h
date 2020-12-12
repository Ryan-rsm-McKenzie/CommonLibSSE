#pragma once

#include "RE/BSCore/BSString.h"
#include "RE/Scaleform/GFxPlayer/GFxValue.h"
#include "RE/Scaleform/GRefCount/GPtr.h"


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
		std::uint32_t	   unk30;	  // 30
		std::uint32_t	   pad34;	  // 34
		GPtr<GFxMovieView> view;	  // 38
	};
	static_assert(sizeof(ItemCard) == 0x40);
}
