#include "RE/BSCore/BSTArray.h"

#include "RE/Memory/IMemoryStoreBase/IMemoryStore/ScrapHeap.h"
#include "RE/Memory/MemoryManager.h"


namespace RE
{
	BSTArrayHeapAllocator::~BSTArrayHeapAllocator()
	{
		if (_data) {
			free(_data);
		}
		memzero(this);
	}


	void* BSTArrayHeapAllocator::allocate(std::size_t a_size)
	{
		auto mem = malloc(a_size);
		assert(mem != nullptr);
		std::memset(mem, 0, a_size);
		return mem;
	}


	void BSTArrayHeapAllocator::deallocate(void* a_ptr)
	{
		free(a_ptr);
	}


	BSScrapArrayAllocator::~BSScrapArrayAllocator()
	{
		if (_data) {
			deallocate(_data);
		}
		memzero(this);
	}


	void* BSScrapArrayAllocator::allocate(std::size_t a_size)
	{
		if (!_allocator) {
			auto heap = MemoryManager::GetSingleton();
			_allocator = heap ? heap->GetThreadScrapHeap() : nullptr;
		}
		assert(_allocator);

		auto mem = _allocator->Allocate(a_size, alignof(void*));
		assert(mem != nullptr);
		std::memset(mem, 0, a_size);
		return mem;
	}


	void BSScrapArrayAllocator::deallocate(void* a_ptr)
	{
		if (_allocator) {
			_allocator->Deallocate(a_ptr);
		} else {
			assert(false);
		}
	}
}
