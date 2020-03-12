#pragma once

#include "RE/BSFixedString.h"
#include "RE/BSIntrusiveRefCounted.h"


namespace RE
{
	class BSAnimationGraphChannel : public BSIntrusiveRefCounted
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSAnimationGraphChannel;


		virtual ~BSAnimationGraphChannel();	 // 00

		// add
		virtual void PollChannelUpdateImpl(bool a_arg1) = 0;  // 01
		virtual void ResetImpl() = 0;						  // 02


		// members
		UInt32				pad0C;		  // 0C
		const BSFixedString channelName;  // 10
		UInt32				value;		  // 18
		UInt32				pad1C;		  // 1C
	};
	STATIC_ASSERT(sizeof(BSAnimationGraphChannel) == 0x20);
}
