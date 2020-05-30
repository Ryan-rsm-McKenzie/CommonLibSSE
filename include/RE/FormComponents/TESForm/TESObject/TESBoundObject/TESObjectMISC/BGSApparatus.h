#pragma once

#include "RE/FormTypes.h"
#include "RE/TESDescription.h"
#include "RE/TESObjectMISC.h"
#include "RE/TESQualityForm.h"


namespace RE
{
	class BGSApparatus :
		public TESObjectMISC,	// 000
		public TESQualityForm,	// 100
		public TESDescription	// 110
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSApparatus;
		inline static constexpr auto FORMTYPE = FormType::Apparatus;


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSApparatus();  // 00

		// override (TESObjectMISC)
		virtual bool Load(TESFile* a_mod) override;	 // 06
	};
	STATIC_ASSERT(sizeof(BGSApparatus) == 0x120);
}
