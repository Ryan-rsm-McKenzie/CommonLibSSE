#pragma once

#include "RE/BSCore/BSTArray.h"
#include "RE/FormComponents/Enums/FormTypes.h"
#include "RE/FormComponents/TESForm/TESForm.h"


namespace RE
{
	class BGSOutfit : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSOutfit;
		inline static constexpr auto FORMTYPE = FormType::Outfit;


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSOutfit();  // 00

		// override (TESForm)
		virtual void ClearData() override;			 // 05
		virtual bool Load(TESFile* a_mod) override;	 // 06
		virtual void InitItemImpl() override;		 // 13


		// members
		BSTArray<TESForm*> outfitItems;	 // 20 - INAM
	};
	STATIC_ASSERT(sizeof(BGSOutfit) == 0x38);
}
