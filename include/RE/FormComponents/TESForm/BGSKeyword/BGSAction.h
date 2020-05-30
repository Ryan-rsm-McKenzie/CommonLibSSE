#pragma once

#include "RE/BGSKeyword.h"
#include "RE/FormTypes.h"


namespace RE
{
	class BGSAction : public BGSKeyword
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSAction;
		inline static constexpr auto FORMTYPE = FormType::Action;


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSAction();  // 00


		// members
		UInt32 index;  // 28
		UInt32 pad2C;  // 2C
	};
	STATIC_ASSERT(sizeof(BGSAction) == 0x30);
}
