#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSApparatus

#include "RE/FormTypes.h"  // FormType
#include "RE/TESDescription.h"  // TESDescription
#include "RE/TESObjectMISC.h"  // TESObjectMISC
#include "RE/TESQualityForm.h"  // TESObjectMISC


namespace RE
{
	class BGSApparatus :
		public TESObjectMISC,	// 000
		public TESQualityForm,	// 100
		public TESDescription	// 110
	{
	public:
		inline static const void* RTTI = RTTI_BGSApparatus;


		enum { kTypeID = FormType::Apparatus };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSApparatus();						// 00

		// override (TESObjectMISC)
		virtual bool LoadForm(TESFile* a_mod) override;	// 06
	};
	STATIC_ASSERT(sizeof(BGSApparatus) == 0x120);
}
