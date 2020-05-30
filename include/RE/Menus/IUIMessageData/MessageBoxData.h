#pragma once

#include "RE/BSCore/BSString.h"
#include "RE/BSCore/BSTArray.h"
#include "RE/BSCore/BSTSmartPointer.h"
#include "RE/Menus/IUIMessageData/IUIMessageData.h"


namespace RE
{
	class IMessageBoxCallback;


	class MessageBoxData : public IUIMessageData
	{
	public:
		inline static constexpr auto RTTI = RTTI_MessageBoxData;


		virtual ~MessageBoxData();	// 00


		// members
		BSString							 bodyText;	  // 10
		BSTArray<BSString>					 buttonText;  // 20
		UInt32								 unk38;		  // 38
		SInt32								 unk3C;		  // 3C
		BSTSmartPointer<IMessageBoxCallback> callback;	  // 40
		UInt32								 unk48;		  // 48
		UInt8								 unk4C;		  // 4C
		UInt8								 unk4D;		  // 4D
		UInt8								 unk4E;		  // 4E
		UInt8								 unk4F;		  // 4F
	};
	STATIC_ASSERT(sizeof(MessageBoxData) == 0x50);
}
