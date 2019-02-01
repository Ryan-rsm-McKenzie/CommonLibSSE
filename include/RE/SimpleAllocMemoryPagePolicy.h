#pragma once

#include "RE/IMemoryPagePolicy.h"  // IMemoryPagePolicy


namespace RE
{
	namespace BSScript
	{
		class SimpleAllocMemoryPagePolicy : public IMemoryPagePolicy
		{
		public:
			virtual ~SimpleAllocMemoryPagePolicy();	// 00


			// members
			UInt64	unk08;	// 08
			UInt64	unk10;	// 10
			UInt64	unk18;	// 18
			UInt64	unk20;	// 20
		};
		STATIC_ASSERT(sizeof(SimpleAllocMemoryPagePolicy) == 0x28);
	}
}
