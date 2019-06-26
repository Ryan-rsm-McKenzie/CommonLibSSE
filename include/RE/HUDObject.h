#pragma once

#include "skse64/GameRTTI.h"  // RTTI_HUDObject

#include "RE/GFxValue.h"  // GFxValue


namespace RE
{
	class GFxMovieView;


	class HUDObject
	{
	public:
		inline static const void* RTTI = RTTI_HUDObject;


		virtual ~HUDObject();				// 00

		// add
		virtual void	Update(void) = 0;	// 01
		virtual void	Unk_02(void);		// 02 - { return 0; }
		virtual void	Unk_03(void);		// 03
		virtual void	Unk_04(void);		// 04 - { return; }


		// members
		GFxMovieView*	view;	// 08
		GFxValue		unk18;	// 10
	};
	STATIC_ASSERT(sizeof(HUDObject) == 0x28);
}
