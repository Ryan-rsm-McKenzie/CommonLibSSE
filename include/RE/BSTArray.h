#pragma once

#include <cassert>

#include "RE/MemoryManager.h"


namespace RE
{
	class ScrapHeap;


	class BSTArrayBase
	{
	public:
		using size_type = UInt32;


		class IAllocatorFunctor
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSTArrayBase__IAllocatorFunctor;


			// add
			virtual bool Allocate(UInt32 a_num, UInt32 a_valueSize) = 0;																	   // 00
			virtual bool Resize(UInt32 a_needNum, UInt32 a_copyFrontNum, UInt32 a_copySkipNum, UInt32 a_copyTailNum, UInt32 a_valueSize) = 0;  // 01
			virtual void Free(void* a_ptr) = 0;																								   // 02

			IAllocatorFunctor() = default;
			virtual ~IAllocatorFunctor() = default;	 // 03

			TES_HEAP_REDEFINE_NEW();
		};
		STATIC_ASSERT(sizeof(IAllocatorFunctor) == 0x8);


		BSTArrayBase();
		~BSTArrayBase();

		[[nodiscard]] bool empty() const;

		size_type size() const;

	protected:
		void set_size(UInt32 a_size);

	private:
		// members
		UInt32 _size;  // 0
	};
	STATIC_ASSERT(sizeof(BSTArrayBase) == 0x4);


	template <class Allocator>
	class BSTArrayAllocatorFunctor;


	class BSTArrayHeapAllocator
	{
	public:
		using size_type = typename BSTArrayBase::size_type;
		using functor_type = BSTArrayAllocatorFunctor<BSTArrayHeapAllocator>;


		BSTArrayHeapAllocator();
		BSTArrayHeapAllocator(const BSTArrayHeapAllocator&) = delete;
		BSTArrayHeapAllocator(BSTArrayHeapAllocator&& a_rhs);
		~BSTArrayHeapAllocator();

		TES_HEAP_REDEFINE_NEW();

		void*		data();
		const void* data() const;

		size_type capacity() const;

	protected:
		void* allocate(std::size_t a_size);
		void  deallocate(void* a_ptr);
		void  set_allocator_traits(void* a_data, UInt32 a_capacity, std::size_t a_typeSize);

	private:
		friend class BSTArrayAllocatorFunctor<BSTArrayHeapAllocator>;


		// members
		void*  _data;	   // 00
		UInt32 _capacity;  // 08
		UInt32 _pad0C;	   // 0C
	};
	STATIC_ASSERT(sizeof(BSTArrayHeapAllocator) == 0x10);


	template <UInt32 BUFFER_SIZE>
	class BSTSmallArrayHeapAllocator
	{
	public:
		using size_type = typename BSTArrayBase::size_type;
		using functor_type = BSTArrayAllocatorFunctor<BSTSmallArrayHeapAllocator>;


		enum : UInt32
		{
			kLocalAlloc = static_cast<UInt32>(1 << 31)
		};


		union Data
		{
			Data() :
				local{ 0 }
			{}

			void* heap;
			char  local[BUFFER_SIZE];
		};


		BSTSmallArrayHeapAllocator() :
			_capacity(kLocalAlloc),
			_pad04(0),
			_data()
		{}


		BSTSmallArrayHeapAllocator(const BSTSmallArrayHeapAllocator&) = delete;


		BSTSmallArrayHeapAllocator(BSTSmallArrayHeapAllocator&& a_rhs) :
			_capacity(std::move(a_rhs._capacity)),
			_pad04(0),
			_data()
		{
			a_rhs._capacity = BUFFER_SIZE | kLocalAlloc;
			std::memmove(_data.local, a_rhs._data.local, BUFFER_SIZE);
			std::memset(a_rhs._data.local, 0, BUFFER_SIZE);
		}


		~BSTSmallArrayHeapAllocator()
		{
			if (!is_local()) {
				free(_data.heap);
			}
			memzero(this);
		}


		TES_HEAP_REDEFINE_NEW();


		void* data()
		{
			return is_local() ? _data.local : _data.heap;
		}


		const void* data() const
		{
			return is_local() ? _data.local : _data.heap;
		}


		size_type capacity() const
		{
			return (_capacity & ~kLocalAlloc);
		}

	protected:
		void* allocate(std::size_t a_size)
		{
			if (a_size > BUFFER_SIZE) {
				auto mem = malloc(a_size);
				assert(mem != nullptr);
				std::memset(mem, 0, a_size);
				return mem;
			} else {
				return _data.local;
			}
		}


		void deallocate(void* a_ptr)
		{
			free(a_ptr);
		}


		void set_allocator_traits(void* a_data, UInt32 a_capacity, std::size_t a_typeSize)
		{
			if (a_capacity * a_typeSize > BUFFER_SIZE) {
				_capacity = a_capacity;
				_data.heap = a_data;
			} else {
				_capacity = kLocalAlloc | a_capacity;
			}
		}

	private:
		friend class BSTArrayAllocatorFunctor<BSTSmallArrayHeapAllocator>;


		bool is_local() const
		{
			return (_capacity & kLocalAlloc) != 0;
		}


		void set_local(bool a_local)
		{
			if (a_local) {
				_capacity |= kLocalAlloc;
			} else {
				_capacity &= ~kLocalAlloc;
			}
		}


		void set_capacity(UInt32 a_capacity)
		{
			auto local = is_local();
			_capacity = a_capacity;
			set_local(local);
		}


		// members
		UInt32 _capacity;  // 00
		UInt32 _pad04;	   // 04
		Data   _data;	   // 08
	};
	STATIC_ASSERT(sizeof(BSTSmallArrayHeapAllocator<sizeof(void*)>) == 0x10);


	class BSScrapArrayAllocator
	{
	public:
		using size_type = typename BSTArrayBase::size_type;
		using functor_type = BSTArrayAllocatorFunctor<BSScrapArrayAllocator>;


		BSScrapArrayAllocator();
		BSScrapArrayAllocator(const BSScrapArrayAllocator&) = delete;
		BSScrapArrayAllocator(BSScrapArrayAllocator&& a_rhs);
		~BSScrapArrayAllocator();

		TES_HEAP_REDEFINE_NEW();

		void*		data();
		const void* data() const;

		size_type capacity() const;

	protected:
		void* allocate(std::size_t a_size);
		void  deallocate(void* a_ptr);
		void  set_allocator_traits(void* a_data, UInt32 a_capacity, std::size_t a_typeSize);

	private:
		friend class BSTArrayAllocatorFunctor<BSScrapArrayAllocator>;
		friend class BSTArrayAllocatorFunctor<BSTArrayHeapAllocator>;


		// members
		ScrapHeap* _allocator;	// 00
		void*	   _data;		// 08
		size_type  _capacity;	// 10
		size_type  _pad14;		// 14
	};
	STATIC_ASSERT(sizeof(BSScrapArrayAllocator) == 0x18);


	template <class T, class Allocator = BSTArrayHeapAllocator>
	class BSTArray :
		public Allocator,
		public BSTArrayBase
	{
	public:
		using value_type = T;
		using allocator_type = Allocator;
		using size_type = typename BSTArrayBase::size_type;
		using reference = value_type&;
		using const_reference = const value_type&;
		using iterator = T*;
		using const_iterator = const T*;


		BSTArray() :
			Allocator(),
			BSTArrayBase()
		{}


		explicit BSTArray(size_type a_count) :
			Allocator(),
			BSTArrayBase()
		{
			if (a_count == 0) {
				return;
			}

			auto newCapacity = a_count;
			auto newSize = a_count;
			auto newData = allocate(newCapacity);
			for (UInt32 i = 0; i < newSize; ++i) {
				new (std::addressof(newData[i])) value_type();
			}

			set_allocator_traits(newData, newCapacity);
			set_size(newSize);
		}


		BSTArray(const BSTArray& a_rhs) :
			Allocator(),
			BSTArrayBase()
		{
			auto newCapacity = a_rhs.capacity();
			if (newCapacity == 0) {
				return;
			}

			auto newSize = a_rhs.size();
			auto newData = allocate(newCapacity);
			for (UInt32 i = 0; i < newSize; ++i) {
				new (std::addressof(newData[i])) value_type(a_rhs[i]);
			}

			set_allocator_traits(newData, newCapacity);
			set_size(newSize);
		}


		BSTArray(BSTArray&& a_rhs) :
			Allocator(std::move(a_rhs)),
			BSTArrayBase(std::move(a_rhs))
		{}


		~BSTArray()
		{
			clear();
			// parents will free their own data
		}


		TES_HEAP_REDEFINE_NEW();


		BSTArray& operator=(const BSTArray& a_rhs)
		{
			if (this == &a_rhs) {
				return *this;
			}

			clear();

			auto newCapacity = a_rhs.capacity();
			change_capacity(newCapacity);

			auto newSize = a_rhs.size();
			set_size(newSize);

			auto newData = data();
			for (UInt32 i = 0; i < newSize; ++i) {
				new (std::addressof(newData[i])) value_type(a_rhs[i]);
			}

			return *this;
		}


		BSTArray& operator=(BSTArray&& a_rhs)
		{
			if (this == &a_rhs) {
				return *this;
			}

			clear();

			auto newCapacity = a_rhs.capacity();
			auto newSize = a_rhs.size();
			auto newData = a_rhs.data();

			auto oldData = data();
			if (oldData) {
				deallocate(oldData);
			}

			set_allocator_traits(newData, newCapacity);
			a_rhs.set_allocator_traits(0, 0);

			set_size(newSize);
			a_rhs.set_size(0);

			return *this;
		}


		reference operator[](size_type a_pos)
		{
			assert(a_pos < size());
			return data()[a_pos];
		}


		const_reference operator[](size_type a_pos) const
		{
			assert(a_pos < size());
			return data()[a_pos];
		}


		reference front()
		{
			return operator[](0);
		}


		const_reference front() const
		{
			return operator[](0);
		}


		reference back()
		{
			return operator[](size() - 1);
		}


		const_reference back() const
		{
			return operator[](size() - 1);
		}


		T* data()
		{
			return static_cast<T*>(allocator_type::data());
		}


		const T* data() const
		{
			return static_cast<const T*>(allocator_type::data());
		}


		iterator begin()
		{
			return empty() ? iterator{} : std::addressof(data()[0]);
		}


		const_iterator begin() const
		{
			return empty() ? const_iterator{} : std::addressof(data()[0]);
		}


		const_iterator cbegin() const
		{
			return begin();
		}


		iterator end()
		{
			return empty() ? iterator{} : std::addressof(data()[size()]);
		}


		const_iterator end() const
		{
			return empty() ? const_iterator{} : std::addressof(data()[size()]);
		}


		const_iterator cend() const
		{
			return end();
		}


		[[nodiscard]] bool empty() const
		{
			return BSTArrayBase::empty();
		}


		size_type size() const
		{
			return BSTArrayBase::size();
		}


		void reserve(size_type a_newCap)
		{
			if (a_newCap > capacity()) {
				change_capacity(a_newCap);
			}
		}


		size_type capacity() const
		{
			return allocator_type::capacity();
		}


		void shrink_to_fit()
		{
			auto newCapacity = size();
			if (newCapacity != capacity()) {
				change_capacity(newCapacity);
			}
		}


		void clear()
		{
			if (!empty()) {
				change_size(0);
			}
		}


		iterator erase(iterator a_pos)
		{
			iterator result = a_pos;
			bool	 doBegin = false;
			if (a_pos == begin()) {
				doBegin = true;
			} else {
				doBegin = false;
				--result;
			}

			for (auto prev = a_pos++; a_pos != end(); prev = a_pos++) {
				*prev = std::move(*a_pos);
			}
			pop_back();

			return doBegin ? begin() : result + 1;
		}


		iterator erase(const_iterator a_pos)
		{
			auto pos = *reinterpret_cast<iterator*>(&a_pos);
			return erase(std::move(pos));
		}


		void push_back(const T& a_value)
		{
			if (size() == capacity()) {
				grow_capacity();
			}

			set_size(size() + 1);
			new (std::addressof(back())) value_type(a_value);
		}


		void push_back(T&& a_value)
		{
			if (size() == capacity()) {
				grow_capacity();
			}

			set_size(size() + 1);
			new (std::addressof(back())) value_type(std::move(a_value));
		}


		template <class... Args>
		reference emplace_back(Args&&... a_args)
		{
			if (size() == capacity()) {
				grow_capacity();
			}

			set_size(size() + 1);
			auto elem = back();
			new (std::addressof(elem)) value_type(std::forward<Args>(a_args)...);
			return elem;
		}


		void pop_back()
		{
			assert(!empty());
			back().~value_type();
			set_size(size() - 1);
		}


		void resize(size_type a_count)
		{
			if (a_count != size()) {
				change_size(a_count);
			}
		}


		void resize(size_type a_count, const value_type& a_value)
		{
			if (a_count != size()) {
				change_size(a_count, a_value);
			}
		}


	private:
		static constexpr size_type DF_CAP = 4;			 // beth default
		static constexpr float	   GROWTH_FACTOR = 1.5;	 // not part of native type


		T* allocate(UInt32 a_num)
		{
			return static_cast<T*>(allocator_type::allocate(a_num * sizeof(T)));
		}


		void deallocate(void* a_ptr)
		{
			allocator_type::deallocate(a_ptr);
		}


		void set_allocator_traits(void* a_data, UInt32 a_capacity)
		{
			allocator_type::set_allocator_traits(a_data, a_capacity, sizeof(T));
		}


		void set_size(UInt32 a_size)
		{
			BSTArrayBase::set_size(a_size);
		}


		void change_capacity(size_type a_newCapacity)
		{
			auto newData = a_newCapacity > 0 ? allocate(a_newCapacity) : nullptr;
			auto oldData = data();
			if (oldData) {
				const auto oldCapacity = capacity();
				if (newData) {
					const auto bytesToCopy = std::min(oldCapacity, a_newCapacity) * sizeof(T);
					std::memcpy(newData, oldData, bytesToCopy);
				}
				deallocate(oldData);
			}
			set_allocator_traits(newData, a_newCapacity);
		}


		template <class... Args>
		void change_size(size_type a_newSize, Args... a_args)
		{
			if (a_newSize > capacity()) {
				grow_capacity(a_newSize);
			}

			const auto oldSize = size();
			if (a_newSize > oldSize) {
				for (size_type i = oldSize; i < a_newSize; ++i) {
					new (std::addressof(data()[i])) value_type(std::forward<Args>(a_args)...);
				}
			} else {
				for (size_type i = a_newSize; i < oldSize; ++i) {
					data()[i].~value_type();
				}
			}

			set_size(a_newSize);
		}


		void grow_capacity()
		{
			auto cap = capacity();
			cap = cap ? static_cast<size_type>(std::ceil(cap * GROWTH_FACTOR)) : DF_CAP;
			change_capacity(cap);
		}


		void grow_capacity(size_type a_hint)
		{
			auto cap = a_hint;
			cap = cap ? static_cast<size_type>(std::ceil(cap * GROWTH_FACTOR)) : DF_CAP;
			change_capacity(cap);
		}


		//members
		//void*		_data;		// 00
		//UInt32	_capacity;	// 08
		//UInt32	_pad0C;		// 0C
		//UInt32	_size;		// 10
		//UInt32	_pad14;		// 14
	};
	STATIC_ASSERT(sizeof(BSTArray<void*>) == 0x18);


	template <class T, UInt32 SIZE = 1>
	class BSTSmallArray : public BSTArray<T, BSTSmallArrayHeapAllocator<sizeof(T) * SIZE>>
	{
	private:
		using Base = BSTArray<T, BSTSmallArrayHeapAllocator<sizeof(T) * SIZE>>;

	public:
		using size_type = typename Base::size_type;


		BSTSmallArray() :
			Base()
		{
			Base::set_allocator_traits(0, SIZE, sizeof(T));
		}


		explicit BSTSmallArray(size_type a_count) :
			Base(a_count)
		{}


		BSTSmallArray(const BSTSmallArray&) = default;
		BSTSmallArray(BSTSmallArray&&) = default;
		~BSTSmallArray() = default;


		BSTSmallArray& operator=(const BSTSmallArray& a_rhs)
		{
			Base::operator=(a_rhs);
			return *this;
		}


		BSTSmallArray& operator=(BSTSmallArray&& a_rhs)
		{
			Base::operator=(std::move(a_rhs));
			return *this;
		}

	private:
		//members
		//UInt32	_capacity;	// 00
		//UInt32	_pad04;		// 04
		//Data		_data;		// 08
		//UInt32	_size;		// 10
		//UInt32	_pad14;		// 14
	};
	STATIC_ASSERT(sizeof(BSTSmallArray<void*>) == 0x18);


	template <class T>
	class BSScrapArray : public BSTArray<T, BSScrapArrayAllocator>
	{
	private:
		using Base = BSTArray<T, BSScrapArrayAllocator>;

	public:
		using size_type = typename Base::size_type;


		BSScrapArray() = default;


		explicit BSScrapArray(size_type a_count) :
			Base(a_count)
		{}


		BSScrapArray(const BSScrapArray&) = default;
		BSScrapArray(BSScrapArray&&) = default;
		~BSScrapArray() = default;


		BSScrapArray& operator=(const BSScrapArray& a_rhs)
		{
			Base::operator=(a_rhs);
			return *this;
		}


		BSScrapArray& operator=(BSScrapArray&& a_rhs)
		{
			Base::operator=(std::move(a_rhs));
			return *this;
		}

	protected:
		//members
		//ScrapArray*	_allocator;	// 00
		//void*			_data;		// 08
		//UInt32		_capacity;	// 10
		//UInt32		_pad14;		// 14
		//UInt32		_size;		// 18
		//UInt32		_pad14;		// 1C
	};
	STATIC_ASSERT(sizeof(BSScrapArray<void*>) == 0x20);


	template <class T>
	class BSStaticArray
	{
	public:
		using value_type = T;
		using size_type = UInt32;
		using reference = value_type&;
		using const_reference = const value_type&;
		using iterator = T*;
		using const_iterator = const T*;

		reference operator[](size_type a_pos) noexcept
		{
			assert(a_pos < _size);
			return _data[a_pos];
		}


		const_reference operator[](size_type a_pos) const noexcept
		{
			assert(a_pos < _size);
			return _data[a_pos];
		}


		reference front() noexcept
		{
			return operator[](0);
		}


		const_reference front() const noexcept
		{
			return operator[](0);
		}


		reference back() noexcept
		{
			return operator[](size() - 1);
		}


		const_reference back() const noexcept
		{
			return operator[](size() - 1);
		}


		T* data() noexcept
		{
			return _data;
		}


		const T* data() const noexcept
		{
			return _data;
		}


		iterator begin()
		{
			return empty() ? iterator{} : std::addressof(data()[0]);
		}


		const_iterator begin() const
		{
			return empty() ? const_iterator{} : std::addressof(data()[0]);
		}


		const_iterator cbegin() const
		{
			return begin();
		}


		iterator end()
		{
			return empty() ? iterator{} : std::addressof(data()[size()]);
		}


		const_iterator end() const
		{
			return empty() ? const_iterator{} : std::addressof(data()[size()]);
		}


		const_iterator cend() const
		{
			return end();
		}


		[[nodiscard]] bool empty() const noexcept
		{
			return size() == 0;
		}


		size_type size() const noexcept
		{
			return _size;
		}


	private:
		T*	   _data;	// 00
		UInt32 _size;	// 08
		UInt32 _pad0C;	// 0C
	};
	STATIC_ASSERT(sizeof(BSStaticArray<void*>) == 0x10);


	template <class T>
	class BSTSmallSharedArray
	{
	public:
		using value_type = T;
		using size_type = UInt32;
		using reference = value_type&;
		using const_reference = const value_type&;
		using iterator = T*;
		using const_iterator = const T*;


		reference operator[](size_type a_pos)
		{
			assert(a_pos < _size);
			return data()[a_pos];
		}


		const_reference operator[](size_type a_pos) const
		{
			assert(a_pos < _size);
			return data()[a_pos];
		}


		value_type* data()
		{
			return size() > 1 ? _data.heap : reinterpret_cast<value_type*>(_data.local);
		}


		const value_type* data() const
		{
			return size() > 1 ? _data.heap : reinterpret_cast<value_type*>(_data.local);
		}


		iterator begin()
		{
			return data();
		}


		const_iterator begin() const
		{
			return data();
		}


		const_iterator cbegin() const
		{
			return begin();
		}


		iterator end()
		{
			return data() + size();
		}


		const_iterator end() const
		{
			return data() + size();
		}


		const_iterator cend() const
		{
			return end();
		}


		[[nodiscard]] bool empty() const
		{
			return size() != 0;
		}


		size_type size() const
		{
			return _size;
		}


		size_type capacity() const
		{
			return size();
		}

	private:
		union Data
		{
			Data() :
				local{ 0 } {}
			~Data() {}


			value_type* heap;
			char		local[sizeof(value_type)];
		};


		// members
		UInt32 _size;	// 00
		UInt32 _pad04;	// 04
		Data   _data;	// 08
	};
	STATIC_ASSERT(sizeof(BSTSmallSharedArray<void*>) == 0x10);
}
