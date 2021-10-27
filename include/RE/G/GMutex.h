#pragma once

#include "RE/G/GAcquireInterface.h"
#include "RE/G/GWaitable.h"

namespace RE
{
	class GMutexImpl;

	class GMutex :
		public GWaitable,         // 00
		public GAcquireInterface  // 18
	{
	public:
		GMutexImpl* impl;  // 20
	};
	static_assert(sizeof(GMutex) == 0x28);
}
