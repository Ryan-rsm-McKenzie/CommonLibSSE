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
		inline static constexpr auto RTTI = RTTI_BGSArtObject;
		inline static constexpr auto FORMTYPE = FormType::ArtObject;


		enum class ArtType : UInt32
		{
			kMagicCastingArt = 0,
			kMagicHitEffect = 1,
			kMagicEnchantEffect = 2
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct Data	 // DNAM
		{
			ArtType artType;  // 0
		};
		STATIC_ASSERT(sizeof(Data) == 0x4);


		virtual ~BGSArtObject();  // 00

		// override (TESBoundObject)
		virtual bool Load(TESFile* a_mod) override;	 // 06
		virtual void InitItemImpl() override;		 // 13


		// members
		Data   data;   // 68 - DNAM
		UInt32 pad6C;  // 6C
	};
	STATIC_ASSERT(sizeof(BGSArtObject) == 0x70);
}
