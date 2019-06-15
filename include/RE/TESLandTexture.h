#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESLandTexture

#include "RE/BSTList.h"  // BSSimpleList
#include "RE/FormTypes.h"  // FormType, BGSTextureSet, BGSMaterialType, TESGrass
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	class TESLandTexture : public TESForm
	{
	public:
		inline static const void* RTTI = RTTI_TESLandTexture;


		enum { kTypeID = FormType::LandTexture };


		enum class Flag : UInt32	// INAM
		{
			kNone = 0,
			kIsSnow = 1 << 0
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct HavokData	// HNAM
		{
			UInt32	friction;		// 0
			UInt32	restitution;	// 4
		};
		STATIC_ASSERT(sizeof(HavokData) == 0x8);


		virtual ~TESLandTexture();							// 00

		// override (TESForm)
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06
		virtual void	InitItem() override;				// 13


		// members
		BGSTextureSet*			textureSet;					// 20 - TNAM
		HavokData				havokData;					// 28 - HNAM
		BGSMaterialType*		materialType;				// 30 - MNAM
		UInt32					textureSpecularExponent;	// 38 - SNAM
		Flag					flags;						// 3C - INAM
		BSSimpleList<TESGrass*>	grasses;					// 40 - GNAM
	};
	STATIC_ASSERT(sizeof(TESLandTexture) == 0x50);
}
