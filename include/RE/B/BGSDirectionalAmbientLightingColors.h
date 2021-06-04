#pragma once

#include "RE/C/Color.h"

namespace RE
{
	class BGSDirectionalAmbientLightingColors
	{
	public:
		struct Directional
		{
		public:
			template <class T>
			struct MaxMin
			{
			public:
				// members
				T max;  // 0
				T min;  // ?
			};
			static_assert(sizeof(MaxMin<Color>) == 0x8);

			// members
			MaxMin<Color> x;  // 00
			MaxMin<Color> y;  // 08
			MaxMin<Color> z;  // 10
		};
		static_assert(sizeof(Directional) == 0x18);

		// members
		Directional directional;   // 00
		Color       specular;      // 18
		float       fresnelPower;  // 1C
	};
	static_assert(sizeof(BGSDirectionalAmbientLightingColors) == 0x20);
}
