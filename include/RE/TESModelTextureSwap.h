#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESModelTextureSwap

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/FormTypes.h"  // BGSTextureSet
#include "RE/TESModel.h"  // TESModel


namespace RE
{
	class TESModelTextureSwap : public TESModel
	{
	public:
		inline static const void* RTTI = RTTI_TESModelTextureSwap;


		struct AlternateTexture	// MODS
		{
			BGSTextureSet*	textureSet;	// 00
			UInt32			index3D;	// 08
			UInt32			unk0C;		// 0C
			BSFixedString	name3D;		// 10
		};
		STATIC_ASSERT(sizeof(AlternateTexture) == 0x18);


		virtual ~TESModelTextureSwap();										// 00

		// override (TESModel)
		virtual void	Init() override;									// 01
		virtual void	ReleaseRefs() override;								// 02
		virtual void	CopyFromBase(BaseFormComponent* a_rhs) override;	// 03


		// members
		AlternateTexture*	alternateTextures;		// 28 - MODS
		UInt32				numAlternateTextures;	// 30
		UInt32				pad34;					// 34
	};
	STATIC_ASSERT(sizeof(TESModelTextureSwap) == 0x38);
}
