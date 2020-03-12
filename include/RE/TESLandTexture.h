#pragma once

#include "RE/BSTList.h"
#include "RE/FormTypes.h"
#include "RE/TESForm.h"


namespace RE
{
	struct TEXTURE_HAVOK_DATA  // HNAM
	{
		SInt32 friction;	 // 0
		SInt32 restitution;	 // 4
	};
	STATIC_ASSERT(sizeof(TEXTURE_HAVOK_DATA) == 0x8);


	class TESLandTexture : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESLandTexture;
		inline static constexpr auto FORMTYPE = FormType::LandTexture;


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~TESLandTexture();	// 00

		// override (TESForm)
		virtual void InitializeData() override;		 // 04
		virtual void ClearData() override;			 // 05
		virtual bool Load(TESFile* a_mod) override;	 // 06
		virtual void InitItemImpl() override;		 // 13


		// members
		BGSTextureSet*			textureSet;			 // 20 - TNAM
		TEXTURE_HAVOK_DATA		havokData;			 // 28 - HNAM
		BGSMaterialType*		materialType;		 // 30 - MNAM
		SInt8					specularExponent;	 // 38 - SNAM
		UInt8					pad39;				 // 39
		UInt16					pad3A;				 // 3A
		SInt32					shaderTextureIndex;	 // 3C - INAM
		BSSimpleList<TESGrass*> textureGrassList;	 // 40 - GNAM
	};
	STATIC_ASSERT(sizeof(TESLandTexture) == 0x50);
}
