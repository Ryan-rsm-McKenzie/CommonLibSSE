#include "RE/BSTArray.h"

#include <cassert>

#include "RE/MemoryManager.h"
#include "RE/ScrapHeap.h"


namespace RE
{
	BSTArrayBase::BSTArrayBase() :
		_size(0)
	{}


	BSTArrayBase::~BSTArrayBase()
	{
		_size = 0;
	}


	[[nodiscard]] bool BSTArrayBase::empty() const
	{
		return _size == 0;
	}


	auto BSTArrayBase::size() const
		-> size_type
	{
		return _size;
	}


	void BSTArrayBase::set_size(UInt32 a_size)
	{
		_size = a_size;
	}


	BSTArrayHeapAllocator::BSTArrayHeapAllocator() :
		_data(nullptr),
		_capacity(0),
		_pad0C(0)
	{}


	BSTArrayHeapAllocator::BSTArrayHeapAllocator(BSTArrayHeapAllocator&& a_rhs) :
		_data(std::move(a_rhs._data)),
		_capacity(std::move(a_rhs._capacity)),
		_pad0C(0)
	{
		a_rhs._data = nullptr;
		a_rhs._capacity = 0;
	}


	BSTArrayHeapAllocator::~BSTArrayHeapAllocator()
	{
		if (_data) {
			free(_data);
		}
		memzero(this);
	}


	void* BSTArrayHeapAllocator::data()
	{
		return _data;
	}


	const void* BSTArrayHeapAllocator::data() const
	{
		return _data;
	}


	auto BSTArrayHeapAllocator::capacity() const
		-> size_type
	{
		return _capacity;
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


	void BSTArrayHeapAllocator::set_allocator_traits(void* a_data, UInt32 a_capacity, std::size_t)
	{
		_data = a_data;
		_capacity = a_capacity;
	}


	BSScrapArrayAllocator::BSScrapArrayAllocator() :
		_allocator(nullptr),
		_data(nullptr),
		_capacity(0),
		_pad14(0)
	{}


	BSScrapArrayAllocator::BSScrapArrayAllocator(BSScrapArrayAllocator&& a_rhs) :
		_allocator(std::move(a_rhs._allocator)),
		_data(std::move(a_rhs._data)),
		_capacity(std::move(a_rhs._capacity)),
		_pad14(0)
	{
		a_rhs._allocator = nullptr;
		a_rhs._data = nullptr;
		a_rhs._capacity = 0;
	}


	BSScrapArrayAllocator::~BSScrapArrayAllocator()
	{
		if (_data) {
			free(_data);
		}
		memzero(this);
	}


	void* BSScrapArrayAllocator::data()
	{
		return _data;
	}


	const void* BSScrapArrayAllocator::data() const
	{
		return _data;
	}


	auto BSScrapArrayAllocator::capacity() const
		-> size_type
	{
		return _capacity;
	}


	void* BSScrapArrayAllocator::allocate(std::size_t a_size)
	{
		if (!_allocator) {
			auto heap = MemoryManager::GetSingleton();
			_allocator = heap ? heap->GetThreadScrapHeap() : nullptr;
		}
		assert(_allocator);

		auto mem = _allocator->AllocateAlign(a_size, 8);
		assert(mem != nullptr);
		std::memset(mem, 0, a_size);
		return mem;
	}


	void BSScrapArrayAllocator::deallocate(void* a_ptr)
	{
		if (_allocator) {
			_allocator->DeallocateAlign(a_ptr);
		} else {
			assert(false);
		}
	}


	void BSScrapArrayAllocator::set_allocator_traits(void* a_data, UInt32 a_capacity, std::size_t)
	{
		_data = a_data;
		_capacity = a_capacity;
	}
}
