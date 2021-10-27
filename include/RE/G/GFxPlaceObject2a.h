#pragma once

#include "RE/G/GFxPlaceObject2.h"

namespace RE
{
	// PlaceObject2 for SWF Version < 6
	class GFxPlaceObject2a : public GFxPlaceObject2
	{
	public:
		virtual ~GFxPlaceObject2a();  // 00

		// override (GASExecuteTag)
		void Execute1(GFxSprite* a_sprite) override;  // 01
		void Unk_07(void) override;                   // 07

		// override (GFxPlaceObjectBase)
		void GetPlaceObjectData(GFxPlaceObjectData& a_data) override;  // 08
	};
#ifndef __INTELLISENSE__
	static_assert(sizeof(GFxPlaceObject2a) == 0x10);
#endif
}
