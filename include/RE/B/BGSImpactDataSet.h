#pragma once

#include "RE/B/BGSPreloadable.h"
#include "RE/B/BSTHashMap.h"
#include "RE/F/FormTypes.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BGSImpactDataSet :
		public TESForm,		   // 00
		public BGSPreloadable  // 20
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSImpactDataSet;
		inline static constexpr auto FORMTYPE = FormType::ImpactDataSet;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		virtual ~BGSImpactDataSet();  // 00

		// override (TESForm)
		virtual void ClearData() override;			 // 05
		virtual bool Load(TESFile* a_mod) override;	 // 06
		virtual void InitItemImpl() override;		 // 13

		// members
		BSTHashMap<const BGSMaterialType*, BGSImpactData*> impactMap;  // 28 - PNAM
	};
	static_assert(sizeof(BGSImpactDataSet) == 0x58);
}
