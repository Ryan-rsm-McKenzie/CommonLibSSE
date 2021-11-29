#pragma once

#include "RE/N/NiAllocator.h"

namespace RE
{
	class BSNiAllocator : public NiAllocator
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSNiAllocator;

		~BSNiAllocator() override;  // 00

		// override (
		void* Allocate(std::size_t& a_sizeInBytes, std::size_t& a_alignment, NiMemEventType a_eventType, bool a_provideAccurateSizeOnDeallocate, const char* a_file, std::int32_t a_line, const char* a_function) override;                                          // 01
		void  Deallocate(void* a_memory, NiMemEventType a_eventType, std::size_t a_sizeInBytes) override;                                                                                                                                                            // 02
		void* Reallocate(void* a_memory, size_t& a_sizeInBytes, std::size_t& a_alignment, NiMemEventType a_eventType, bool a_provideAccurateSizeOnDeallocate, std::size_t a_sizeCurrent, const char* a_file, std::int32_t a_line, const char* a_function) override;  // 03
		bool  TrackAllocate(const void* const a_memory, std::size_t a_sizeInBytes, NiMemEventType a_eventType, const char* a_file, std::int32_t a_line, const char* a_function) override;                                                                            // 04
		bool  TrackDeallocate(const void* const a_memory, NiMemEventType a_eventType) override;                                                                                                                                                                      // 05
		void  Unk_06(void) override;                                                                                                                                                                                                                                 // 06 - implements a realloc
		void  Initialize() override;                                                                                                                                                                                                                                 // 07 - { return; }
		void  Shutdown() override;                                                                                                                                                                                                                                   // 08 - { return; }
		bool  VerifyAddress(const void* a_memory) override;                                                                                                                                                                                                          // 09 - { return true; }
	};
	static_assert(sizeof(BSNiAllocator) == 0x8);
}
