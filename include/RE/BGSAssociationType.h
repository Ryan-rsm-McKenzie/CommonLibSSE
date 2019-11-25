#pragma once

#include "RE/BSFixedString.h"
#include "RE/FormTypes.h"
#include "RE/TESForm.h"


namespace RE
{
	class BGSAssociationType : public TESForm
	{
	public:
		inline static const void* RTTI = RTTI_BGSAssociationType;


		enum { kTypeID = FormType::AssociationType };


		enum class Flag : UInt32	// DATA
		{
			kNone = 0,
			kFamilyAssociation = 1 << 0
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSAssociationType();						// 00

		// override (TESForm)
		virtual void	InitDefaults() override;			// 04
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06


		// members
		BSFixedString	maleParentTitle;	// 20 - MPRT
		BSFixedString	femaleParentTitle;	// 28 - FPRT
		BSFixedString	maleChildTitle;		// 30 - MCHT
		BSFixedString	femaleChildTitle;	// 38 - FCHT
		Flag			flags;				// 40 - DATA
		UInt32			pad44;				// 44
	};
	STATIC_ASSERT(sizeof(BGSAssociationType) == 0x48);
}
