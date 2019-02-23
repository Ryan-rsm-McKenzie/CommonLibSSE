#pragma once

#include "RE/FormTypes.h"  // FormType
#include "RE/TESObjectMISC.h"  // TESObjectMISC


namespace RE
{
	class TESKey : public TESObjectMISC
	{
	public:
		enum { kTypeID = FormType::Key };


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
	};
	STATIC_ASSERT(sizeof(TESKey) == 0x100);
}
