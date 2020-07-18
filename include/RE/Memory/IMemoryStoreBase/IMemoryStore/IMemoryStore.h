#pragma once

#include "RE/Memory/IMemoryStoreBase/IMemoryStoreBase.h"


namespace RE
{
	class IMemoryStore : public IMemoryStoreBase
	{
	public:
		inline static constexpr auto RTTI = RTTI_IMemoryStore;


		virtual ~IMemoryStore();  // 00

		// add
		virtual void* AllocateAlignImpl(std::size_t a_size, std::uint32_t a_alignment) = 0;	 // 04
		virtual void  DeallocateAlignImpl(void* a_freeBlock) = 0;							 // 05
		virtual void* TryAllocateImpl(std::size_t a_size, std::uint32_t a_alignment);		 // 06 - { return 0; }

		void* AllocateAlign(std::size_t a_size, std::uint32_t a_alignment);
		void  DeallocateAlign(void* a_freeBlock);
	};
	static_assert(sizeof(IMemoryStore) == 0x8);
}
