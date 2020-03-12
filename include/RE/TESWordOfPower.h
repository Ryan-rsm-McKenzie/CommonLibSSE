#pragma once

#include "RE/BSFixedString.h"
#include "RE/FormTypes.h"
#include "RE/TESForm.h"
#include "RE/TESFullName.h"


namespace RE
{
	class TESWordOfPower :
		public TESForm,		// 00
		public TESFullName	// 20
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESWordOfPower;
		inline static constexpr auto FORMTYPE = FormType::WordOfPower;


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~TESWordOfPower();	// 00

		// override (TESForm)
		virtual bool Load(TESFile* a_mod) override;	 // 06


		// members
		BSFixedString translation;	// 30 - TNAM
	};
	STATIC_ASSERT(sizeof(TESWordOfPower) == 0x38);
}
