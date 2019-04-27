#pragma once

#include "RE/BSTextureSet.h"  // BSTextureSet
#include "RE/Color.h"  // Color
#include "RE/FormTypes.h"  // FormType
#include "RE/TESBoundObject.h"  // TESBoundObject
#include "RE/TESTexture.h"  // TESTexture


namespace RE
{
	class BGSTextureSet :
		public TESBoundObject,	// 00
		public BSTextureSet		// 30
	{
	public:
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


		struct DecalData
		{
			enum Flag : UInt8
			{
				kNone = 0,
				kParallax = 1 << 0,
				kAlphaBlending = 1 << 1,
				kAlphaTesting = 1 << 2,
				kNoSubtextures = 1 << 3
			};


			float	minWidth;		// 00
			float	maxWidth;		// 04
			float	minHeight;		// 08
			float	maxHeight;		// 0C
			float	depth;			// 10
			float	shininess;		// 14
			float	parallaxScale;	// 18
			UInt8	parralaxPasses;	// 1C
			Flag	flags;			// 1D
			UInt16	unk1E;			// 1E
			Color	color;			// 20
			UInt32	pad24;			// 24
		};
		STATIC_ASSERT(sizeof(DecalData) == 0x28);


		virtual ~BGSTextureSet();							// 00

		// override (TESBoundObject)
		virtual void	InitDefaults() override;			// 04
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06


		// members
		TESTexture	textures[Textures::kTotal];				// 040 - TX00 - TX07
		DecalData*	decalData;								// 0C0 - DODT
		Flag		flags;									// 0C8 - DNAM
		UInt16		pad0CA;									// 0CA
		FileHash	textureFileHashes[Textures::kTotal];	// 0CC
		UInt32		pad12C;									// 12C
	};
	STATIC_ASSERT(sizeof(BGSTextureSet) == 0x130);
}
