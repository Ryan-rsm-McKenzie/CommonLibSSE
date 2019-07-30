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


		struct Data
		{
			UInt64	unk00;	// 00
			UInt64	unk08;	// 08
		};
		STATIC_ASSERT(sizeof(Data) == 0x10);


		virtual ~BSUIMessageData();	// 00


		// members
		Data*			unk10;	// 10
		BSFixedString	unk18;	// 18
		UInt8			unk20;	// 20
		UInt8			pad21;	// 21
		UInt16			pad22;	// 22
		UInt32			pad24;	// 24
	};
	STATIC_ASSERT(sizeof(BSUIMessageData) == 0x28);
}
