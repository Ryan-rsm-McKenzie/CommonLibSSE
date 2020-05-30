#pragma once

#include "RE/BSAtomic.h"
#include "RE/BSScript/IMemoryPagePolicy.h"


namespace RE
{
	namespace BSScript
	{
		class SimpleAllocMemoryPagePolicy : public IMemoryPagePolicy
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSScript__SimpleAllocMemoryPagePolicy;


			virtual ~SimpleAllocMemoryPagePolicy();	 // 00

			// override (IMemoryPagePolicy)
			virtual void Unk_01(void) override;	 // 01 - { return maxPageSize; }
			virtual void Unk_02(void) override;	 // 02
			virtual void Unk_03(void) override;	 // 03
			virtual void Unk_04(void) override;	 // 04


			// members
			const UInt32 minPageSize;				// 08
			const UInt32 maxPageSize;				// 0C
			const UInt32 maxAllocatedMemory;		// 10
			const UInt32 maxStackDepth;				// 14
			BSSpinLock	 dataLock;					// 18
			UInt32		 currentMemorySize;			// 20
			UInt32		 maxAdditionalAllocations;	// 20
		};
		STATIC_ASSERT(sizeof(SimpleAllocMemoryPagePolicy) == 0x28);
	}
}
