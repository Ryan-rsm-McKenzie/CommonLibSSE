#pragma once

#include "RE/ImageSpaceModifierInstanceTemp.h"


namespace RE
{
	struct ImageSpaceModData
	{
		enum
		{
			kFadeAmount = 0,
			kFadeR = 1,
			kFadeG = 2,
			kFadeB = 3,
			kBlurRadius = 4,
			kDoubleVisionStrength = 5,
			kRadialBlurStrength = 6,
			kRadialBlurRampup = 7,
			kRadialBlurStart = 8,
			kRadialBlurRampdown = 9,
			kRadialBlurDownStart = 10,
			kRadialBlurCenterX = 11,
			kRadialBlurCenterY = 12,
			kDOFStrength = 13,
			kDOFDistance = 14,
			kDOFRange = 15,
			kDOFMode = 16,
			kMotionBlurStrength = 17,

			kTotal = 18
		};


		float data[kTotal];	 // 00
	};
	STATIC_ASSERT(sizeof(ImageSpaceModData) == 0x48);


	class ImageSpaceModifierInstanceDOF : public ImageSpaceModifierInstanceTemp
	{
	public:
		inline static constexpr auto RTTI = RTTI_ImageSpaceModifierInstanceDOF;


		enum class DepthOfFieldMode : UInt8
		{
			kFrontBack = 0,
			kFront = 1,
			kBack = 2,
			kNone = 3
		};


		virtual ~ImageSpaceModifierInstanceDOF();  // 00

		// override (ImageSpaceModifierInstanceTemp)
		virtual void Unk_26(void) override;	 // 26
		virtual void Unk_28(void) override;	 // 28


		// members
		ImageSpaceModData data;	 // 30
	};
	STATIC_ASSERT(sizeof(ImageSpaceModifierInstanceDOF) == 0x78);
}
