#pragma once

#include "RE/BGSKeyword.h"
#include "RE/FormTypes.h"


namespace RE
{
	class BGSLocationRefType : public BGSKeyword
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSLocationRefType;
		inline static constexpr auto FORMTYPE = FormType::LocationRefType;


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSLocationRefType();	// 00

		// override (BGSKeyword)
		virtual void InitItemImpl() override;  // 13
	};
	STATIC_ASSERT(sizeof(BGSLocationRefType) == 0x28);
}
