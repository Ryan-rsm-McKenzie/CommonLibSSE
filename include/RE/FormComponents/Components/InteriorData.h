#pragma once

#include "RE/BGSDirectionalAmbientLightingColors.h"
#include "RE/Color.h"


namespace RE
{
	struct INTERIOR_DATA
	{
	public:
		enum class Inherit : UInt32
		{
			kAmbientColor = 1 << 0,
			kDirectionalColor = 1 << 1,
			kFogColor = 1 << 2,
			kFogNear = 1 << 3,
			kFogFar = 1 << 4,
			kDirectionalRotation = 1 << 5,
			kDirectionalFade = 1 << 6,
			kClipDistance = 1 << 7,
			kFogPower = 1 << 8,
			kFogMax = 1 << 9,
			kLightFadeDistances = 1 << 10
		};


		// members
		Color								ambient;						   // 00
		Color								directional;					   // 04
		Color								fogColorNear;					   // 08
		float								fogNear;						   // 0C
		float								fogFar;							   // 10
		UInt32								directionalXY;					   // 14
		UInt32								directionalZ;					   // 18
		float								directionalFade;				   // 1C
		float								clipDist;						   // 20
		float								fogPower;						   // 24
		BGSDirectionalAmbientLightingColors directionalAmbientLightingColors;  // 28
		Color								fogColorFar;					   // 48
		float								fogClamp;						   // 4C
		float								lightFadeStart;					   // 50
		float								lightFadeEnd;					   // 54
		Inherit								lightingTemplateInheritanceFlags;  // 58
		UInt32								unk5C;							   // 5C - interiorOffset?
	};
	STATIC_ASSERT(sizeof(INTERIOR_DATA) == 0x60);
}
