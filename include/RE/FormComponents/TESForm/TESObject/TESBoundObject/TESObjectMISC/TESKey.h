#pragma once

#include "RE/FormTypes.h"
#include "RE/TESObjectMISC.h"


namespace RE
{
	class TESKey : public TESObjectMISC
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESKey;
		inline static constexpr auto FORMTYPE = FormType::KeyMaster;


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kNonPlayable = 1 << 2,
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~TESKey();	// 00

		// override (BGSKeywordForm)
		virtual BGSKeyword* GetDefaultKeyword() const override;	 // 05
	};
	STATIC_ASSERT(sizeof(TESKey) == 0x100);
}
