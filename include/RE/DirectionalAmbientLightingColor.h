#pragma once

#include "RE/Color.h"  // Color


namespace RE
{
	struct DirectionalAmbientLightingColor
	{
		struct Directional
		{
			Color	xMax;	// 00
			Color	xMin;	// 04
			Color	yMax;	// 08
			Color	yMin;	// 0C
			Color	zMax;	// 10
			Color	zMin;	// 14
		};
		STATIC_ASSERT(sizeof(Directional) == 0x18);


		Directional	directional;	// 00
		Color		specular;		// 18
		float		fresnelPower;	// 1C
	};
	STATIC_ASSERT(sizeof(DirectionalAmbientLightingColor) == 0x20);
}
