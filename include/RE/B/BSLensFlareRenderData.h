#pragma once

#include "RE/B/BSTArray.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class BSLensFlareSpriteRenderData;

	class BSLensFlareRenderData
	{
	public:
		// members
		float                                            fadeDistRadiusScale;  // 00
		float                                            colorInfluence;       // 04
		BSTArray<NiPointer<BSLensFlareSpriteRenderData>> sprites;              // 08
	};
	static_assert(sizeof(BSLensFlareRenderData) == 0x20);
}
