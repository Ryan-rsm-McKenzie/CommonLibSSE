#pragma once

#include "RE/BSString.h"  // BSString
#include "RE/IUIMessageData.h"  // IUIMessageData


namespace RE
{
	class HUDData : public IUIMessageData
	{
	public:
		enum class Type : UInt32
		{
			kUnk0 = 0,
			kNotification = 1
		};


		virtual ~HUDData();	// 00


		// members
		Type		type;	// 10
		UInt32		pad14;	// 14
		BSString	text;	// 18
		UInt32		unk28;	// 28
		UInt32		pad2C;	// 2C
		UInt64		unk30;	// 30
		UInt64		unk38;	// 38
		UInt8		unk40;	// 40
		UInt8		pad41;	// 41
		UInt16		pad42;	// 42
		UInt32		unk44;	// 44
	};
	STATIC_ASSERT(sizeof(HUDData) == 0x48);
}
