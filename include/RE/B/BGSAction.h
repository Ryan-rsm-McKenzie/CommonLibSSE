#pragma once

#include "RE/FormComponents/Enums/FormTypes.h"
#include "RE/FormComponents/TESForm/BGSKeyword/BGSKeyword.h"


namespace RE
{
	class BGSAction : public BGSKeyword
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSAction;
		inline static constexpr auto FORMTYPE = FormType::Action;


		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSAction();  // 00


		// members
		std::uint32_t index;  // 28
		std::uint32_t pad2C;  // 2C
	};
	static_assert(sizeof(BGSAction) == 0x30);
}
