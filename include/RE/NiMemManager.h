#pragma once

#include "RE/NiAllocator.h"  // NiAllocator, NiMemEventType


namespace RE
{
	class NiMemManager
	{
	public:
		static NiMemManager* GetSingleton();

		void* Allocate(std::size_t a_sizeInBytes, std::size_t a_alignment, NiMemEventType a_eventType, bool a_provideAccurateSizeOnDeallocate = false, const char* a_sourceFile = 0, SInt32 a_sourceLine = -1, const char* a_function = 0);
		void Deallocate(void* a_mem, NiMemEventType a_eventType, std::size_t a_sizeinBytes = static_cast<std::size_t>(-1));
		void* Reallocate(void* a_mem, std::size_t a_sizeInBytes, std::size_t a_alignment, NiMemEventType a_eventType, bool a_provideAccurateSizeOnDeallocate = false, std::size_t a_sizeCurrent = static_cast<std::size_t>(-1), const char* a_sourceFile = 0, SInt32 a_sourceLine = -1, const char* a_function = 0);
		bool TrackAllocate(const void* const a_mem, std::size_t a_sizeInBytes, NiMemEventType a_eventType, const char* a_sourceFile = 0, SInt32 a_sourceLine = -1, const char* a_function = 0);
		bool TrackDeallocate(const void* const a_mem, NiMemEventType a_eventType);


		// members
		NiAllocator* allocator;	// 00
	};
	STATIC_ASSERT(sizeof(NiMemManager) == 0x8);
}
