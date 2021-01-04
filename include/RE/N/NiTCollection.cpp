#include "RE/N/NiTCollection.h"

#include "RE/N/NiMemManager.h"

namespace RE
{
	void* NiMalloc(std::size_t a_sizeInBytes)
	{
		auto memManager = NiMemManager::GetSingleton();
		auto mem = memManager->Allocate(a_sizeInBytes, 0, NiMemEventType::kMalloc, false);
		assert(mem != nullptr);
		return mem;
	}

	void* NiAlignedMalloc(std::size_t a_sizeInBytes, std::size_t a_alignment)
	{
		auto memManager = NiMemManager::GetSingleton();
		auto mem = memManager->Allocate(a_sizeInBytes, a_alignment, NiMemEventType::kAlignedMalloc, false);
		assert(mem != nullptr);
		return mem;
	}

	void* NiRealloc(void* a_mem, std::size_t a_sizeInBytes)
	{
		if (a_sizeInBytes == 0 && a_mem) {
			NiFree(a_mem);
			return nullptr;
		} else if (!a_mem) {
			return NiMalloc(a_sizeInBytes);
		}

		auto memManager = NiMemManager::GetSingleton();
		auto mem = memManager->Reallocate(a_mem, a_sizeInBytes, 4, NiMemEventType::kRealloc, false, static_cast<std::size_t>(-1));
		assert(mem != nullptr);
		return mem;
	}

	void* NiAlignedRealloc(void* a_mem, std::size_t a_sizeInBytes, std::size_t a_alignment)
	{
		if (a_sizeInBytes == 0 && a_mem) {
			NiAlignedFree(a_mem);
			return nullptr;
		} else if (!a_mem) {
			return NiAlignedMalloc(a_sizeInBytes, a_alignment);
		}

		auto memManager = NiMemManager::GetSingleton();
		auto mem = memManager->Reallocate(a_mem, a_sizeInBytes, a_alignment, NiMemEventType::kAlignedRealloc, false, static_cast<std::size_t>(-1));
		assert(mem != nullptr);
		return mem;
	}

	void NiFree(void* a_mem)
	{
		if (a_mem) {
			auto memManager = NiMemManager::GetSingleton();
			memManager->Deallocate(a_mem, NiMemEventType::kFree);
		}
	}

	void NiAlignedFree(void* a_mem)
	{
		if (a_mem) {
			auto memManager = NiMemManager::GetSingleton();
			memManager->Deallocate(a_mem, NiMemEventType::kAlignedFree);
		}
	}
}
