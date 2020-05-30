#pragma once

#include "RE/BSFixedString.h"
#include "RE/FormTypes.h"
#include "RE/TESForm.h"


namespace RE
{
	class BGSAssociationType : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSAssociationType;
		inline static constexpr auto FORMTYPE = FormType::AssociationType;


		enum class FLAGS : UInt32  // DATA
		{
			kNone = 0,
			kFamily = 1 << 0
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct Members
		{
			enum
			{
				kParent,
				kChild,

				kTotal
			};
		};


		struct Sexes
		{
			enum
			{
				kMale,
				kFemale,

				kTotal
			};
		};


		virtual ~BGSAssociationType();	// 00

		// override (TESForm)
		virtual void InitializeData() override;		 // 04
		virtual bool Load(TESFile* a_mod) override;	 // 06


		// members
		BSFixedString associationLabels[Members::kTotal][Sexes::kTotal];  // 20 - MPRT - FCHT
		FLAGS		  flags;											  // 40 - DATA
		UInt32		  pad44;											  // 44
	};
	STATIC_ASSERT(sizeof(BGSAssociationType) == 0x48);
}
