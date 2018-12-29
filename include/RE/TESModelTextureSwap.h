#pragma once

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/FormTypes.h"  // BGSTextureSet
#include "RE/TESModel.h"  // TESModel


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


		virtual ~TESModelTextureSwap();										// 00

		// override (TESModel)
		virtual void	Init() override;									// 01
		virtual void	ReleaseRefs() override;								// 02
		virtual void	CopyFromBase(BaseFormComponent* a_rhs) override;	// 03


		// members
		SwapInfo*	modelSwaps;	// 28
		UInt32		swapCount;	// 30
		UInt32		pad34;		// 34
	};
	STATIC_ASSERT(sizeof(TESModelTextureSwap) == 0x38);
}
