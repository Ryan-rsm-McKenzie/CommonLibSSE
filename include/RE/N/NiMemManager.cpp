#include "RE/N/NiMemManager.h"

namespace RE
{
	NiMemManager* NiMemManager::GetSingleton()
	{
		REL::Relocation<NiMemManager**> singleton{ Offset::NiMemManager::Singleton };
		return *singleton;
	}

	void* NiMemManager::Allocate(std::size_t a_sizeInBytes, std::size_t a_alignment, NiMemEventType a_eventType, bool a_provideAccurateSizeOnDeallocate, const char* a_sourceFile, std::int32_t a_sourceLine, const char* a_function)
	{
		assert(allocator != nullptr);
		auto mem = allocator->Allocate(a_sizeInBytes, a_alignment, a_eventType, a_provideAccurateSizeOnDeallocate, a_sourceFile, a_sourceLine, a_function);
		assert(mem != nullptr);
		return mem;
	}

	void NiMemManager::Deallocate(void* a_mem, NiMemEventType a_eventType, std::size_t a_sizeinBytes)
	{
		assert(allocator);
		allocator->Deallocate(a_mem, a_eventType, a_sizeinBytes);
	}

	void* NiMemManager::Reallocate(void* a_mem, std::size_t a_sizeInBytes, std::size_t a_alignment, NiMemEventType a_eventType, bool a_provideAccurateSizeOnDeallocate, std::size_t a_sizeCurrent, const char* a_sourceFile, std::int32_t a_sourceLine, const char* a_function)
	{
		assert(allocator != nullptr);
		auto mem = allocator->Reallocate(a_mem, a_sizeInBytes, a_alignment, a_eventType, a_provideAccurateSizeOnDeallocate, a_sizeCurrent, a_sourceFile, a_sourceLine, a_function);
		assert(mem != nullptr);
		return mem;
	}

	bool NiMemManager::TrackAllocate(const void* const a_mem, std::size_t a_sizeInBytes, NiMemEventType a_eventType, const char* a_sourceFile, std::int32_t a_sourceLine, const char* a_function)
	{
		assert(allocator);
		return allocator->TrackAllocate(a_mem, a_sizeInBytes, a_eventType, a_sourceFile, a_sourceLine, a_function);
	}

	bool NiMemManager::TrackDeallocate(const void* const a_mem, NiMemEventType a_eventType)
	{
		assert(allocator);
		return allocator->TrackDeallocate(a_mem, a_eventType);
	}
}
