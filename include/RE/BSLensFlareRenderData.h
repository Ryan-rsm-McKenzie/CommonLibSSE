#pragma once

#include "RE/BSTArray.h"  // BSTArray


namespace RE
{
	class BSLensFlareRenderData
	{
	public:
		float			unk00;	// 00
		UInt32			unk04;	// 04
		BSTArray<void*>	unk08;	// 08
	};
	STATIC_ASSERT(sizeof(BSLensFlareRenderData) == 0x20);
}
