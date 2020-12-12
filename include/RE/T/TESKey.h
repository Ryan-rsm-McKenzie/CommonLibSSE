#pragma once

#include "RE/FormComponents/Enums/FormTypes.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESObjectMISC/TESObjectMISC.h"


namespace RE
{
	class TESKey : public TESObjectMISC
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESKey;
		inline static constexpr auto FORMTYPE = FormType::KeyMaster;


		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
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
	static_assert(sizeof(TESKey) == 0x100);
}
