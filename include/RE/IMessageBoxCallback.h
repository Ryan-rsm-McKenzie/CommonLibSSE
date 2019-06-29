#pragma once

#include "skse64/GameRTTI.h"  // RTTI_IMessageBoxCallback

#include "RE/BSIntrusiveRefCounted.h"  // BSIntrusiveRefCounted


namespace RE
{
	class IMessageBoxCallback : public BSIntrusiveRefCounted
	{
	public:
		inline static const void* RTTI = RTTI_IMessageBoxCallback;


		enum class Message : UInt8
		{
			kUnk0 = 0,
			kUnk1 = 1,
			kUnk2 = 2
		};


		virtual ~IMessageBoxCallback();			// 00

		// add
		virtual void Run(Message a_msg) = 0;	// 01


		// members
		UInt32 unk0C;	// 0C
	};
	STATIC_ASSERT(sizeof(IMessageBoxCallback) == 0x10);
}
