#pragma once

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/TESModel.h"  // TESModel

class BGSTextureSet;


namespace RE
{
	// 38   
	class TESModelTextureSwap : public TESModel
	{
	public:
		// 18
		struct SwapInfo
		{
			BGSTextureSet*	textureSet;	// 00
			UInt32			unk08;		// 08 - index
			BSFixedString	name;		// 10
		};

		SwapInfo*	m_swaps;	// 28
		UInt32		m_count;	// 30
	};
}