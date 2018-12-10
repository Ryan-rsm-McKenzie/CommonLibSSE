#pragma once

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/TESModel.h"  // TESModel

class BGSTextureSet;


namespace RE
{
	class TESModelTextureSwap : public TESModel
	{
	public:
		struct SwapInfo
		{
			BGSTextureSet*	textureSet;	// 00
			UInt32			unk08;		// 08 - index
			BSFixedString	name;		// 10
		};
		STATIC_ASSERT(sizeof(SwapInfo) == 0x18);


		// members
		SwapInfo*	m_swaps;	// 28
		UInt32		m_count;	// 30
	};
	STATIC_ASSERT(sizeof(TESModelTextureSwap) == 0x38);
}