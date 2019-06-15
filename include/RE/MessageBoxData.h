#pragma once

#include "skse64/GameRTTI.h"  // RTTI_MessageBoxData

#include "RE/BSString.h"  // BSString
#include "RE/BSTArray.h"  // BSTArray
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
		BSString				message;	// 10
		BSTArray<BSString>		options;	// 20
		UInt32					unk38;		// 38
		UInt32					pad3C;		// 3C
		IMessageBoxCallback*	callback;	// 40
		UInt32					unk48;		// 48
		UInt32					pad4C;		// 4C
	};
	STATIC_ASSERT(sizeof(MessageBoxData) == 0x50);
}
