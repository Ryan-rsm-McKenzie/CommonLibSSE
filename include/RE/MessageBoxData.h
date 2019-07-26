#pragma once

#include "skse64/GameRTTI.h"  // RTTI_MessageBoxData

#include "RE/BSString.h"  // BSString
#include "RE/BSTArray.h"  // BSTArray
#include "RE/BSTSmartPointer.h"  // BSTSmartPointer
#include "RE/IUIMessageData.h"  // IUIMessageData


namespace RE
{
	class IMessageBoxCallback;


	class MessageBoxData : public IUIMessageData
	{
	public:
		inline static const void* RTTI = RTTI_MessageBoxData;


		virtual ~MessageBoxData();	// 00


		// members
		BSString								message;	// 10
		BSTArray<BSString>						options;	// 20
		UInt32									unk38;		// 38
		SInt32									unk3C;		// 3C
		BSTSmartPointer<IMessageBoxCallback>	callback;	// 40
		UInt32									unk48;		// 48
		UInt8									unk4C;		// 4C
		UInt8									unk4D;		// 4D
		UInt8									unk4E;		// 4E
		UInt8									unk4F;		// 4F
	};
	STATIC_ASSERT(sizeof(MessageBoxData) == 0x50);
}
