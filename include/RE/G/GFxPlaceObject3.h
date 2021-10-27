#pragma once

#include "RE/G/GFxPlaceObjectBase.h"

namespace RE
{
	class GFxPlaceObject3 : public GFxPlaceObjectBase
	{
	public:
		enum class PlaceFlags1 : std::uint8_t
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

		enum class PlaceFlags2 : std::uint8_t
		{
			kNone = 0,
			kHasFilterList = 1 << 0,
			kHasBlendMode = 1 << 1,
			kHasCacheAsBitmap = 1 << 2,
			kHasClassName = 1 << 3,
			kHasImage = 1 << 4,
			kHasVisible = 1 << 5,
			kOpaqueBackground = 1 << 6,
		};

		virtual ~GFxPlaceObject3();  // 00

		// override (GASExecuteTag)
		void Execute1(GFxSprite* a_sprite) override;  // 01
		void Unk_06(void) override;                   // 06

		// override (GFxPlaceObjectBase)
		void  GetPlaceObjectData(GFxPlaceObjectData& a_data) override;  // 08
		void* GetClipActions() override;                                // 09
		void  GetPlaceFlags(GFxPlaceFlags& a_flags) override;           // 0A

		// members
		char data[1];  // 08 - This buffer is sized according to the tag length in the SWF file
	};
#ifndef __INTELLISENSE__
	static_assert(sizeof(GFxPlaceObject3) == 0x10);
#endif
}
