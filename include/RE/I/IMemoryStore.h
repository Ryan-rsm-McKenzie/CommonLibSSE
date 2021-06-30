#pragma once

#include "RE/I/IMemoryStoreBase.h"

namespace RE
{
	class IMemoryStore : public IMemoryStoreBase
	{
	public:
		inline static constexpr auto RTTI = RTTI_IMemoryStore;

		~IMemoryStore() override = default;  // 00

		// add
		virtual void* AllocateAlignImpl(std::size_t a_size, std::uint32_t a_alignment) = 0;                                                 // 04
		virtual void  DeallocateAlignImpl(void*& a_block) = 0;                                                                              // 05
		virtual void* TryAllocateImpl([[maybe_unused]] std::size_t a_size, [[maybe_unused]] std::uint32_t a_alignment) { return nullptr; }  // 06

		void* AllocateAlign(std::size_t a_size, std::uint32_t a_alignment);
		void  DeallocateAlign(void*& a_freeBlock);
	};
	static_assert(sizeof(IMemoryStore) == 0x8);
}
