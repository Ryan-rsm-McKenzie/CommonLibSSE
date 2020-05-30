#pragma once

#include "RE/BSFixedString.h"
#include "RE/FormTypes.h"
#include "RE/TESForm.h"


namespace RE
{
	class BGSFootstep : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSFootstep;
		inline static constexpr auto FORMTYPE = FormType::Footstep;


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSFootstep();	 // 00

		// override (TESForm)
		virtual void InitializeData() override;		 // 04
		virtual bool Load(TESFile* a_mod) override;	 // 06
		virtual void InitItemImpl() override;		 // 13


		// members
		BSFixedString	  tag;		  // 20 - ANAM
		BGSImpactDataSet* impactSet;  // 28 - DATA
	};
	STATIC_ASSERT(sizeof(BGSFootstep) == 0x30);
}
