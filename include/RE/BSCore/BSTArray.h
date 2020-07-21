#pragma once

#include "RE/Memory/MemoryManager.h"


namespace RE
{
	class ScrapHeap;


	class BSTArrayBase
	{
	public:
		using size_type = std::uint32_t;

		class IAllocatorFunctor
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSTArrayBase__IAllocatorFunctor;

			// add
			virtual bool Allocate(std::uint32_t a_num, std::uint32_t a_valueSize) = 0;																							  // 00
			virtual bool Resize(std::uint32_t a_needNum, std::uint32_t a_copyFrontNum, std::uint32_t a_copySkipNum, std::uint32_t a_copyTailNum, std::uint32_t a_valueSize) = 0;  // 01
			virtual void Free(void* a_ptr) = 0;																																	  // 02

			IAllocatorFunctor() = default;
			virtual ~IAllocatorFunctor() = default;	 // 03

			TES_HEAP_REDEFINE_NEW();
		};
		static_assert(sizeof(IAllocatorFunctor) == 0x8);

		constexpr BSTArrayBase() noexcept = default;
		inline ~BSTArrayBase() noexcept { _size = 0; }

		[[nodiscard]] constexpr bool	  empty() const noexcept { return _size == 0; }
		[[nodiscard]] constexpr size_type size() const noexcept { return _size; }

	protected:
		constexpr void set_size(size_type a_size) noexcept { _size = a_size; }

	private:
		// members
		std::uint32_t _size{ 0 };  // 0
	};
	static_assert(sizeof(BSTArrayBase) == 0x4);


	template <class Allocator>
	class BSTArrayAllocatorFunctor;


	class BSTArrayHeapAllocator
	{
	public:
		using size_type = typename BSTArrayBase::size_type;
		using functor_type = BSTArrayAllocatorFunctor<BSTArrayHeapAllocator>;

		constexpr BSTArrayHeapAllocator() noexcept = default;
		BSTArrayHeapAllocator(const BSTArrayHeapAllocator&) = delete;

		constexpr BSTArrayHeapAllocator(BSTArrayHeapAllocator&& a_rhs) noexcept :
			_data(std::move(a_rhs._data)),
			_capacity(std::move(a_rhs._capacity))
		{
			a_rhs._data = nullptr;
			a_rhs._capacity = 0;
		}

		~BSTArrayHeapAllocator();

		TES_HEAP_REDEFINE_NEW();

		[[nodiscard]] constexpr void*		data() noexcept { return _data; }
		[[nodiscard]] constexpr const void* data() const noexcept { return _data; }

		[[nodiscard]] constexpr size_type capacity() const noexcept { return _capacity; }

	protected:
		void* allocate(std::size_t a_size);
		void  deallocate(void* a_ptr);

		constexpr void set_allocator_traits(void* a_data, std::uint32_t a_capacity, std::size_t) noexcept
		{
			_data = a_data;
			_capacity = a_capacity;
		}

	private:
		friend class BSTArrayAllocatorFunctor<BSTArrayHeapAllocator>;

		// members
		void*		  _data{ nullptr };	 // 00
		std::uint32_t _capacity{ 0 };	 // 08
		std::uint32_t _pad0C{ 0 };		 // 0C
	};
	static_assert(sizeof(BSTArrayHeapAllocator) == 0x10);


	template <std::uint32_t BUFFER_SIZE>
	class BSTSmallArrayHeapAllocator
	{
	public:
		using size_type = typename BSTArrayBase::size_type;
		using functor_type = BSTArrayAllocatorFunctor<BSTSmallArrayHeapAllocator>;

		enum : std::uint32_t
		{
			kLocalAlloc = static_cast<std::uint32_t>(1 << 31)
		};

		union Data
		{
			Data() :
				heap(nullptr)
			{
				std::memset(local, 0, BUFFER_SIZE);
			}

			void* heap;
			char  local[BUFFER_SIZE];
		};

		BSTSmallArrayHeapAllocator() = default;
		BSTSmallArrayHeapAllocator(const BSTSmallArrayHeapAllocator&) = delete;

		BSTSmallArrayHeapAllocator(BSTSmallArrayHeapAllocator&& a_rhs) :
			_capacity(std::move(a_rhs._capacity))
		{
			a_rhs._capacity = kLocalAlloc;
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

		[[nodiscard]] constexpr void*		data() noexcept { return is_local() ? _data.local : _data.heap; }
		[[nodiscard]] constexpr const void* data() const noexcept { return is_local() ? _data.local : _data.heap; }

		[[nodiscard]] constexpr size_type capacity() const noexcept { return (_capacity & ~kLocalAlloc); }

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
			if (a_ptr != _data.local) {
				free(a_ptr);
			}
		}

		constexpr void set_allocator_traits(void* a_data, std::uint32_t a_capacity, std::size_t a_typeSize) noexcept
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

		[[nodiscard]] constexpr bool is_local() const noexcept { return (_capacity & kLocalAlloc) != 0; }

		constexpr void set_local(bool a_local) noexcept
		{
			if (a_local) {
				_capacity |= kLocalAlloc;
			} else {
				_capacity &= ~kLocalAlloc;
			}
		}

		constexpr void set_capacity(std::uint32_t a_capacity) noexcept
		{
			auto local = is_local();
			_capacity = a_capacity;
			set_local(local);
		}

		// members
		std::uint32_t _capacity{ kLocalAlloc };	 // 00
		std::uint32_t _pad04{ 0 };				 // 04
		Data		  _data{};					 // 08
	};
	static_assert(sizeof(BSTSmallArrayHeapAllocator<sizeof(void*)>) == 0x10);


	class BSScrapArrayAllocator
	{
	public:
		using size_type = typename BSTArrayBase::size_type;
		using functor_type = BSTArrayAllocatorFunctor<BSScrapArrayAllocator>;


		constexpr BSScrapArrayAllocator() noexcept = default;
		BSScrapArrayAllocator(const BSScrapArrayAllocator&) = delete;

		constexpr BSScrapArrayAllocator(BSScrapArrayAllocator&& a_rhs) noexcept :
			_allocator(std::move(a_rhs._allocator)),
			_data(std::move(a_rhs._data)),
			_capacity(std::move(a_rhs._capacity))
		{
			a_rhs._allocator = nullptr;
			a_rhs._data = nullptr;
			a_rhs._capacity = 0;
		}

		~BSScrapArrayAllocator();

		TES_HEAP_REDEFINE_NEW();

		[[nodiscard]] constexpr void*		data() noexcept { return _data; }
		[[nodiscard]] constexpr const void* data() const noexcept { return _data; }

		[[nodiscard]] constexpr size_type capacity() const noexcept { return _capacity; }

	protected:
		void* allocate(std::size_t a_size);
		void  deallocate(void* a_ptr);

		constexpr void set_allocator_traits(void* a_data, std::uint32_t a_capacity, std::size_t) noexcept
		{
			_data = a_data;
			_capacity = a_capacity;
		}

	private:
		friend class BSTArrayAllocatorFunctor<BSScrapArrayAllocator>;
		friend class BSTArrayAllocatorFunctor<BSTArrayHeapAllocator>;


		// members
		ScrapHeap* _allocator{ nullptr };  // 00
		void*	   _data{ nullptr };	   // 08
		size_type  _capacity{ 0 };		   // 10
		size_type  _pad14{ 0 };			   // 14
	};
	static_assert(sizeof(BSScrapArrayAllocator) == 0x18);


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

		BSTArray() = default;

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
			for (std::uint32_t i = 0; i < newSize; ++i) {
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
			for (std::uint32_t i = 0; i < newSize; ++i) {
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
			if (this != std::addressof(a_rhs)) {
				clear();

				auto newCapacity = a_rhs.capacity();
				change_capacity(newCapacity);

				auto newSize = a_rhs.size();
				set_size(newSize);

				auto newData = data();
				for (size_type i = 0; i < newSize; ++i) {
					stl::construct_at<value_type>(newData + i, a_rhs[i]);
				}
			}
			return *this;
		}

		BSTArray& operator=(BSTArray&& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
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
			}
			return *this;
		}

		[[nodiscard]] constexpr reference operator[](size_type a_pos) noexcept
		{
			assert(a_pos < size());
			return data()[a_pos];
		}

		[[nodiscard]] constexpr const_reference operator[](size_type a_pos) const noexcept
		{
			assert(a_pos < size());
			return data()[a_pos];
		}

		[[nodiscard]] constexpr reference front() noexcept
		{
			return operator[](0);
		}

		[[nodiscard]] constexpr const_reference front() const noexcept
		{
			return operator[](0);
		}

		[[nodiscard]] constexpr reference back() noexcept
		{
			return operator[](size() - 1);
		}

		[[nodiscard]] constexpr const_reference back() const noexcept
		{
			return operator[](size() - 1);
		}

		[[nodiscard]] constexpr T* data() noexcept
		{
			return static_cast<T*>(allocator_type::data());
		}

		[[nodiscard]] constexpr const T* data() const noexcept
		{
			return static_cast<const T*>(allocator_type::data());
		}

		[[nodiscard]] constexpr iterator begin() noexcept
		{
			return empty() ? iterator{} : std::addressof(data()[0]);
		}

		[[nodiscard]] constexpr const_iterator begin() const noexcept
		{
			return empty() ? const_iterator{} : std::addressof(data()[0]);
		}

		[[nodiscard]] constexpr const_iterator cbegin() const noexcept
		{
			return begin();
		}

		[[nodiscard]] constexpr iterator end() noexcept
		{
			return empty() ? iterator{} : std::addressof(data()[size()]);
		}

		[[nodiscard]] constexpr const_iterator end() const noexcept
		{
			return empty() ? const_iterator{} : std::addressof(data()[size()]);
		}

		[[nodiscard]] constexpr const_iterator cend() const noexcept
		{
			return end();
		}

		[[nodiscard]] constexpr bool empty() const noexcept
		{
			return BSTArrayBase::empty();
		}

		[[nodiscard]] constexpr size_type size() const noexcept
		{
			return BSTArrayBase::size();
		}

		void reserve(size_type a_newCap)
		{
			if (a_newCap > capacity()) {
				change_capacity(a_newCap);
			}
		}

		[[nodiscard]] constexpr size_type capacity() const noexcept
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

		T* allocate(size_type a_num)
		{
			return static_cast<T*>(allocator_type::allocate(a_num * sizeof(T)));
		}

		void deallocate(void* a_ptr)
		{
			allocator_type::deallocate(a_ptr);
		}

		constexpr void set_allocator_traits(void* a_data, size_type a_capacity) noexcept
		{
			allocator_type::set_allocator_traits(a_data, a_capacity, sizeof(T));
		}

		constexpr void set_size(size_type a_size) noexcept
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
			cap = cap ? static_cast<size_type>(std::ceil(static_cast<float>(cap) * GROWTH_FACTOR)) : DF_CAP;
			change_capacity(cap);
		}

		void grow_capacity(size_type a_hint)
		{
			auto cap = a_hint;
			cap = cap ? static_cast<size_type>(std::ceil(static_cast<float>(cap) * GROWTH_FACTOR)) : DF_CAP;
			change_capacity(cap);
		}

		//members
		//void*		_data;		// 00
		//std::uint32_t	_capacity;	// 08
		//std::uint32_t	_pad0C;		// 0C
		//std::uint32_t	_size;		// 10
		//std::uint32_t	_pad14;		// 14
	};
	static_assert(sizeof(BSTArray<void*>) == 0x18);


	template <class T, std::uint32_t SIZE = 1>
	class BSTSmallArray : public BSTArray<T, BSTSmallArrayHeapAllocator<sizeof(T) * SIZE>>
	{
	private:
		using super = BSTArray<T, BSTSmallArrayHeapAllocator<sizeof(T) * SIZE>>;

	public:
		using super::super;
		using super::operator=;

	private:
		//members
		//std::uint32_t	_capacity;	// 00
		//std::uint32_t	_pad04;		// 04
		//Data		_data;		// 08
		//std::uint32_t	_size;		// 10
		//std::uint32_t	_pad14;		// 14
	};
	static_assert(sizeof(BSTSmallArray<void*>) == 0x18);


	template <class T>
	class BSScrapArray : public BSTArray<T, BSScrapArrayAllocator>
	{
	private:
		using super = BSTArray<T, BSScrapArrayAllocator>;

	public:
		using super::super;
		using super::operator=;

	protected:
		//members
		//ScrapArray*	_allocator;	// 00
		//void*			_data;		// 08
		//std::uint32_t		_capacity;	// 10
		//std::uint32_t		_pad14;		// 14
		//std::uint32_t		_size;		// 18
		//std::uint32_t		_pad14;		// 1C
	};
	static_assert(sizeof(BSScrapArray<void*>) == 0x20);


	template <class T>
	class BSStaticArray
	{
	public:
		using value_type = T;
		using size_type = std::uint32_t;
		using reference = value_type&;
		using const_reference = const value_type&;
		using iterator = T*;
		using const_iterator = const T*;

		[[nodiscard]] constexpr reference operator[](size_type a_pos) noexcept
		{
			assert(a_pos < _size);
			return _data[a_pos];
		}

		[[nodiscard]] constexpr const_reference operator[](size_type a_pos) const noexcept
		{
			assert(a_pos < _size);
			return _data[a_pos];
		}

		[[nodiscard]] constexpr reference		front() noexcept { return operator[](0); }
		[[nodiscard]] constexpr const_reference front() const noexcept { return operator[](0); }

		[[nodiscard]] constexpr reference		back() noexcept { return operator[](size() - 1); }
		[[nodiscard]] constexpr const_reference back() const noexcept { return operator[](size() - 1); }

		[[nodiscard]] constexpr T*		 data() noexcept { return _data; }
		[[nodiscard]] constexpr const T* data() const noexcept { return _data; }

		[[nodiscard]] constexpr iterator	   begin() noexcept { return empty() ? iterator{} : data(); }
		[[nodiscard]] constexpr const_iterator begin() const noexcept { return empty() ? const_iterator{} : data(); }
		[[nodiscard]] constexpr const_iterator cbegin() const noexcept { return begin(); }

		[[nodiscard]] constexpr iterator	   end() noexcept { return empty() ? iterator{} : data() + size(); }
		[[nodiscard]] constexpr const_iterator end() const noexcept { return empty() ? const_iterator{} : data() + size(); }
		[[nodiscard]] constexpr const_iterator cend() const noexcept { return end(); }

		[[nodiscard]] constexpr bool empty() const noexcept { return size() == 0; }

		[[nodiscard]] constexpr size_type size() const noexcept { return _size; }

	private:
		T*			  _data;   // 00
		std::uint32_t _size;   // 08
		std::uint32_t _pad0C;  // 0C
	};
	static_assert(sizeof(BSStaticArray<void*>) == 0x10);


	template <class T>
	class BSTSmallSharedArray
	{
	public:
		using value_type = T;
		using size_type = std::uint32_t;
		using reference = value_type&;
		using const_reference = const value_type&;
		using iterator = T*;
		using const_iterator = const T*;

		[[nodiscard]] reference operator[](size_type a_pos) noexcept
		{
			assert(a_pos < _size);
			return data()[a_pos];
		}

		[[nodiscard]] const_reference operator[](size_type a_pos) const noexcept
		{
			assert(a_pos < _size);
			return data()[a_pos];
		}

		[[nodiscard]] value_type* data() noexcept
		{
			return size() > 1 ? _data.heap : reinterpret_cast<value_type*>(_data.local);
		}

		[[nodiscard]] const value_type* data() const noexcept
		{
			return size() > 1 ? _data.heap : reinterpret_cast<value_type*>(_data.local);
		}

		[[nodiscard]] iterator		 begin() noexcept { return data(); }
		[[nodiscard]] const_iterator begin() const noexcept { return data(); }
		[[nodiscard]] const_iterator cbegin() const noexcept { return begin(); }

		[[nodiscard]] iterator		 end() noexcept { return data() + size(); }
		[[nodiscard]] const_iterator end() const noexcept { return data() + size(); }
		[[nodiscard]] const_iterator cend() const noexcept { return end(); }

		[[nodiscard]] constexpr bool empty() const noexcept { return size() != 0; }

		[[nodiscard]] constexpr size_type size() const noexcept { return _size; }

		[[nodiscard]] constexpr size_type capacity() const noexcept { return size(); }

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
		std::uint32_t _size{ 0 };	// 00
		std::uint32_t _pad04{ 0 };	// 04
		Data		  _data{};		// 08
	};
	static_assert(sizeof(BSTSmallSharedArray<void*>) == 0x10);
}
