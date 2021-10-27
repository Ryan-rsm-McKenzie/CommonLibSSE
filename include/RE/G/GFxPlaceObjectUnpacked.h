#pragma once

#include "RE/G/GFxPlaceObjectBase.h"

namespace RE
{
	class GFxPlaceObjectUnpacked : public GFxPlaceObjectBase
	{
	public:
		~GFxPlaceObjectUnpacked() override;  // 00

		// override (GASExecuteTag)
		void Execute1(GFxSprite* a_sprite) override;  // 01
		void Unk_06(void) override;                   // 06

		// override (GFxPlaceObjectBase)
		void GetPlaceObjectData(GFxPlaceObjectData& a_data) override;  // 08
		void GetPlaceFlags(GFxPlaceFlags& a_flags) override;           // 0A

		// members
		GFxPlaceObjectUnpackedData data;  // 08
	};
	static_assert(sizeof(GFxPlaceObjectUnpacked) == 0x68);
}
