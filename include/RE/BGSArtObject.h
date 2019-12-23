#pragma once

#include "RE/FormTypes.h"
#include "RE/TESBoundObject.h"
#include "RE/TESModelTextureSwap.h"


namespace RE
{
	class BGSArtObject :
		public TESBoundObject,		// 00
		public TESModelTextureSwap	// 30
	{
	public:
		inline static const void* RTTI = RTTI_BGSArtObject;


		enum { kTypeID = FormType::ArtObject };


		enum class ArtType : UInt32	// DNAM
		{
			kMagicCasting = 0,
			kMagicHitEffect = 1,
			kEnchantmentEffect = 2
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSArtObject();						// 00

		// override (TESBoundObject)
		virtual bool	Load(TESFile* a_mod) override;	// 06
		virtual void	InitItemImpl() override;		// 13


		// members
		ArtType	artType;	// 68 - DNAM
		UInt32	pad6C;		// 6C
	};
	STATIC_ASSERT(sizeof(BGSArtObject) == 0x70);
}
