#pragma once

#include "RE/G/GAcquireInterface.h"
#include "RE/G/GMutex.h"
#include "RE/G/GWaitCondition.h"
#include "RE/G/GWaitable.h"

namespace RE
{
	class GEvent :
		public GWaitable,         // 00
		public GAcquireInterface  // 18
	{
	public:
		volatile bool  state;               // 20
		volatile bool  temporary;           // 21
		std::uint16_t  pad22;               // 22
		std::uint32_t  pad24;               // 24
		mutable GMutex stateMutex;          // 28
		GWaitCondition stateWaitCondition;  // 50
	};
	static_assert(sizeof(GEvent) == 0x58);
}
