#pragma once

#include "RE/IUIMessageData.h"  // IUIMessageData


namespace RE
{
	class ConsoleData : public IUIMessageData
	{
	public:
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
