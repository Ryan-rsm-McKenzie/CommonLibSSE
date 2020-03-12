#pragma once

#include "RE/BSFixedString.h"
#include "RE/FormTypes.h"
#include "RE/TESModel.h"


namespace RE
{
	class TESModelTextureSwap : public TESModel
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESModelTextureSwap;


		struct AlternateTexture	 // MODS
		{
			BGSTextureSet* textureSet;	// 00
			UInt32		   index3D;		// 08
			UInt32		   unk0C;		// 0C
			BSFixedString  name3D;		// 10
		};
		STATIC_ASSERT(sizeof(AlternateTexture) == 0x18);


		virtual ~TESModelTextureSwap();	 // 00

		// override (TESModel)
		virtual void				 InitializeDataComponent() override;				// 01
		virtual void				 ClearDataComponent() override;						// 02
		virtual void				 CopyComponent(BaseFormComponent* a_rhs) override;	// 03
		virtual TESModelTextureSwap* GetAsModelTextureSwap() override;					// 06 - { return this; }


		// members
		AlternateTexture* alternateTextures;	 // 28 - MODS
		UInt32			  numAlternateTextures;	 // 30
		UInt32			  pad34;				 // 34
	};
	STATIC_ASSERT(sizeof(TESModelTextureSwap) == 0x38);
}
