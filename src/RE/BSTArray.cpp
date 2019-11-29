#include "RE/BSTArray.h"

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
		_data(0),
		_capacity(0),
		_pad0C(0)
	{}


	BSTArrayHeapAllocator::BSTArrayHeapAllocator(BSTArrayHeapAllocator&& a_rhs) :
		_data(std::move(a_rhs._data)),
		_capacity(std::move(a_rhs._capacity)),
		_pad0C(0)
	{
		a_rhs._data = 0;
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
		assert(mem != 0);
		std::memset(mem, 0, a_size);
		return mem;
	}


	void BSTArrayHeapAllocator::deallocate(void* a_ptr)
	{
		free(a_ptr);
	}


	void BSTArrayHeapAllocator::set_allocator_traits(void* a_data, UInt32 a_capacity, std::size_t a_typeSize)
	{
		_data = a_data;
		_capacity = a_capacity;
	}


	BSScrapArrayAllocator::BSScrapArrayAllocator() :
		_allocator(0),
		_data(0),
		_capacity(0),
		_pad14(0)
	{}


	BSScrapArrayAllocator::BSScrapArrayAllocator(BSScrapArrayAllocator&& a_rhs) :
		_allocator(std::move(a_rhs._allocator)),
		_data(std::move(a_rhs._data)),
		_capacity(std::move(a_rhs._capacity)),
		_pad14(0)
	{
		a_rhs._allocator = 0;
		a_rhs._data = 0;
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
		auto mem = _allocator->Allocate(a_size, 8);
		assert(mem != 0);
		std::memset(mem, 0, a_size);
		return mem;
	}


	void BSScrapArrayAllocator::deallocate(void* a_ptr)
	{
		_allocator->Free(a_ptr);
	}


	void BSScrapArrayAllocator::set_allocator_traits(void* a_data, UInt32 a_capacity, std::size_t a_typeSize)
	{
		_data = a_data;
		_capacity = a_capacity;
	}
}
