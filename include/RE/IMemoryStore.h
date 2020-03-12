#pragma once

#include "RE/IMemoryStoreBase.h"


namespace RE
{
	class IMemoryStore : public IMemoryStoreBase
	{
	public:
		inline static constexpr auto RTTI = RTTI_IMemoryStore;


		virtual ~IMemoryStore();  // 00

		// add
		virtual void* AllocateAlignImpl(std::size_t a_size, UInt32 a_alignment) = 0;  // 04
		virtual void  DeallocateAlignImpl(void* a_freeBlock) = 0;					  // 05
		virtual void* TryAllocateImpl(std::size_t a_size, UInt32 a_alignment);		  // 06 - { return 0; }

		void* AllocateAlign(std::size_t a_size, UInt32 a_alignment);
		void  DeallocateAlign(void* a_freeBlock);
	};
	STATIC_ASSERT(sizeof(IMemoryStore) == 0x8);
}
