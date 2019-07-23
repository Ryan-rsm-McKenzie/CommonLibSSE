#pragma once

#include "skse64/GameRTTI.h"  // RTTI_IMemoryStore

#include "RE/IMemoryStoreBase.h"  // IMemoryStoreBase


namespace RE
{
	class IMemoryStore : public IMemoryStoreBase
	{
	public:
		inline static const void* RTTI = RTTI_IMemoryStore;


		virtual ~IMemoryStore();												// 00

		// add
		virtual void*	Allocate(std::size_t a_size, UInt32 a_alignment) = 0;	// 04
		virtual void	Free(void* a_memory) = 0;								// 05
		virtual void	Unk_06(void);											// 06 - { return 0; }
	};
	STATIC_ASSERT(sizeof(IMemoryStore) == 0x8);
}
