#pragma once

#include "RE/B/BGSKeyword.h"
#include "RE/F/FormTypes.h"

namespace RE
{
	class BGSLocationRefType : public BGSKeyword
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSLocationRefType;
		inline static constexpr auto VTABLE = VTABLE_BGSLocationRefType;
		inline static constexpr auto FORMTYPE = FormType::LocationRefType;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		~BGSLocationRefType() override;  // 00

		// override (BGSKeyword)
		void InitItemImpl() override;  // 13
	};
	static_assert(sizeof(BGSLocationRefType) == 0x28);
}
