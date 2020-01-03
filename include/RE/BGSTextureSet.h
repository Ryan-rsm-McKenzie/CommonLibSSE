#pragma once

#include "RE/BSResource/ID.h"
#include "RE/BSTextureSet.h"
#include "RE/Color.h"
#include "RE/DecalData.h"
#include "RE/FormTypes.h"
#include "RE/TESBoundObject.h"
#include "RE/TESTexture.h"


namespace RE
{
	class BGSTextureSet :
		public TESBoundObject,	// 00
		public BSTextureSet		// 30
	{
	public:
		inline static const void* RTTI = RTTI_BGSTextureSet;


		enum { kTypeID = FormType::TextureSet };


		enum class Flag : UInt16
		{
			kNone = 0,
			kNoSpecularMap = 1 << 0,
			kFacegenTextures = 1 << 1,
			kHasModelSpaceNormalMap = 1 << 2
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSTextureSet();						// 00

		// override (TESBoundObject)
		virtual void	InitializeData() override;		// 04
		virtual void	ClearData() override;			// 05
		virtual bool	Load(TESFile* a_mod) override;	// 06
		virtual void	Unk_40(void) override;			// 40 - returns BSFadeNode*
		virtual void	Unk_41(void) override;			// 41


		// members
		TESTexture		textures[Textures::kTotal];			// 040 - TX00 - TX07
		DecalData*		decalData;							// 0C0 - DODT
		Flag			flags;								// 0C8 - DNAM
		UInt16			pad0CA;								// 0CA
		BSResource::ID	textureFileIDs[Textures::kTotal];	// 0CC
		UInt32			pad12C;								// 12C
	};
	STATIC_ASSERT(sizeof(BGSTextureSet) == 0x130);
}
