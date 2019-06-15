#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSUIMessageData

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/IUIMessageData.h"  // IUIMessageData


namespace RE
{
	class BSUIMessageData : public IUIMessageData
	{
	public:
		inline static const void* RTTI = RTTI_BSUIMessageData;


		virtual ~BSUIMessageData();	// 00


		// members
		UInt64			unk10;	// 10
		BSFixedString	unk18;	// 18
		UInt64			unk20;	// 20
	};
	STATIC_ASSERT(sizeof(BSUIMessageData) == 0x28);
}
