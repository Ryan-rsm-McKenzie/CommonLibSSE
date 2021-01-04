#pragma once

#include "RE/B/BSTArray.h"
#include "RE/F/FormTypes.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BGSOutfit : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSOutfit;
		inline static constexpr auto FORMTYPE = FormType::Outfit;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
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
	static_assert(sizeof(BGSOutfit) == 0x38);
}
