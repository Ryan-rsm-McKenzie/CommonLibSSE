#pragma once

#include "RE/BGSKeyword.h"  // BGSKeyword
#include "RE/FormTypes.h"  // FormType


namespace RE
{
	class BGSAction : public BGSKeyword
	{
	public:
		enum { kTypeID = (UInt32)FormType::Action };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSAction();	// 00


		// members
		UInt32	idx;	// 28
		UInt32	pad2C;	// 2C
	};
	STATIC_ASSERT(sizeof(BGSAction) == 0x30);
}
