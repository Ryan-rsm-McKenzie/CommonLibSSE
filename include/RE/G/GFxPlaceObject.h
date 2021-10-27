#pragma once

#include "RE/G/GFxPlaceObjectBase.h"

namespace RE
{
	// Rarely used in SWF 3 and later versions
	class GFxPlaceObject : public GFxPlaceObjectBase
	{
	public:
		virtual ~GFxPlaceObject();  // 00

		// override (GASExecuteTag)
		void Execute1(GFxSprite* a_sprite) override;  // 01

		// override (GFxPlaceObjectBase)
		void GetPlaceObjectData(GFxPlaceObjectData& a_data) override;  // 08
		void GetPlaceFlags(GFxPlaceFlags& a_flags) override;           // 0A

		// members
		char data[1];  // 08 - This buffer is sized according to the tag length in the SWF file
	};
#ifndef __INTELLISENSE__
	static_assert(sizeof(GFxPlaceObject) == 0x10);
#endif
}
