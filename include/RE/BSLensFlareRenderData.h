#pragma once

#include "RE/BSTArray.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class BSLensFlareSpriteRenderData;


	class BSLensFlareRenderData
	{
	public:
		// members
		float											 fadeDistRadiusScale;  // 00
		float											 colorInfluence;	   // 04
		BSTArray<NiPointer<BSLensFlareSpriteRenderData>> sprites;			   // 08
	};
	STATIC_ASSERT(sizeof(BSLensFlareRenderData) == 0x20);
}
