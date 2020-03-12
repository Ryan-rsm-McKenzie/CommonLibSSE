#pragma once

#include "RE/ImageSpaceModifierInstance.h"


namespace RE
{
	class ImageSpaceModifierInstanceTemp : public ImageSpaceModifierInstance
	{
	public:
		inline static constexpr auto RTTI = RTTI_ImageSpaceModifierInstanceTemp;


		virtual ~ImageSpaceModifierInstanceTemp();	// 00

		// override (ImageSpaceModifierInstance)
		virtual void Unk_25(void) override;	 // 25
		virtual void Unk_28(void) override;	 // 28


		// members
		float  duration;  // 28
		UInt32 pad3C;	  // 2C
	};
	STATIC_ASSERT(sizeof(ImageSpaceModifierInstanceTemp) == 0x30);
}
