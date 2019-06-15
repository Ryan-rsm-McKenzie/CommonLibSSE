#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ConsoleData

#include "RE/IUIMessageData.h"  // IUIMessageData


namespace RE
{
	class ConsoleData : public IUIMessageData
	{
	public:
		inline static const void* RTTI = RTTI_ConsoleData;


		virtual ~ConsoleData();	// 00


		// members
		UInt64		unk10;	// 10
		RefHandle	handle;	// 18
		UInt32		unk1C;	// 1C
		UInt64		unk20;	// 20
		UInt32		unk28;	// 28
		UInt32		unk2C;	// 2C
	};
	STATIC_ASSERT(sizeof(ConsoleData) == 0x30);
}
