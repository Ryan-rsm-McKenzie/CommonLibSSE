#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESWordOfPower

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm
#include "RE/TESFullName.h"  // TESFullName


namespace RE
{
	class TESWordOfPower :
		public TESForm,		// 00
		public TESFullName	// 20
	{
	public:
		inline static const void* RTTI = RTTI_TESWordOfPower;


		enum { kTypeID = FormType::WordOfPower };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~TESWordOfPower();						// 00

		// override (TESForm)
		virtual bool LoadForm(TESFile* a_mod) override;	// 06


		// members
		BSFixedString translation;	// 30 - TNAM
	};
	STATIC_ASSERT(sizeof(TESWordOfPower) == 0x38);
}
