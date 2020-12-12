#pragma once

#include "RE/BSCore/BSTArray.h"
#include "RE/NetImmerse/NiSmartPointer.h"


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
	static_assert(sizeof(BSLensFlareRenderData) == 0x20);
}
