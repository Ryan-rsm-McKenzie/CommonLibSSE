#pragma once

#include "RE/B/BSAtomic.h"
#include "RE/I/IMemoryPagePolicy.h"

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
			const std::uint32_t minPageSize;			   // 08
			const std::uint32_t maxPageSize;			   // 0C
			const std::uint32_t maxAllocatedMemory;		   // 10
			const std::uint32_t maxStackDepth;			   // 14
			BSSpinLock			dataLock;				   // 18
			std::uint32_t		currentMemorySize;		   // 20
			std::uint32_t		maxAdditionalAllocations;  // 20
		};
		static_assert(sizeof(SimpleAllocMemoryPagePolicy) == 0x28);
	}
}
