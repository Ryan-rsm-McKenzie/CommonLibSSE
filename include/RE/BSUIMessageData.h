#pragma once

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/IUIMessageData.h"  // IUIMessageData


namespace RE
{
	class BSUIMessageData : public IUIMessageData
	{
	public:
		virtual ~BSUIMessageData();	// 00


		// members
		UInt64			unk10;	// 10
		BSFixedString	unk18;	// 18
		UInt64			unk20;	// 20
	};
	STATIC_ASSERT(sizeof(BSUIMessageData) == 0x28);
}
