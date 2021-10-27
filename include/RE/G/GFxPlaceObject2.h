#pragma once

#include "RE/G/GFxPlaceObjectBase.h"

namespace RE
{
	class GFxPlaceObject2 : public GFxPlaceObjectBase
	{
	public:
		enum class PlaceFlags : std::uint8_t
		{
			kNone = 0,
			kMove = 1 << 0,
			kHasCharacter = 1 << 1,
			kHasMatrix = 1 << 2,
			kHasColorTransform = 1 << 3,
			kHasRatio = 1 << 4,
			kHasName = 1 << 5,
			kHasClipDepth = 1 << 6,
			kHasClipActions = 1 << 7,
		};

		virtual ~GFxPlaceObject2();  // 00

		// override (GASExecuteTag)
		void Execute1(GFxSprite* a_sprite) override;  // 01
		void Unk_06(void) override;                   // 06
		void Unk_07(void) override;                   // 07

		// override (GFxPlaceObjectBase)
		void  GetPlaceObjectData(GFxPlaceObjectData& a_data) override;  // 08
		void* GetClipActions() override;                                // 09
		void  GetPlaceFlags(GFxPlaceFlags& a_flags) override;           // 0A

		// members
		char data[1];  // 08 - This buffer is sized according to the tag length in the SWF file
	};
#ifndef __INTELLISENSE__
	static_assert(sizeof(GFxPlaceObject2) == 0x10);
#endif
}
