#pragma once

#include "RE/M/MemoryManager.h"

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
			virtual bool Allocate(std::uint32_t a_num, std::uint32_t a_elemSize) = 0;																											  // 00
			virtual bool Reallocate(std::uint32_t a_minNewSizeInItems, std::uint32_t a_frontCopyCount, std::uint32_t a_shiftCount, std::uint32_t a_backCopyCount, std::uint32_t a_elemSize) = 0;  // 01
			virtual void Deallocate() = 0;																																						  // 02

			virtual ~IAllocatorFunctor() = default;	 // 03

			TES_HEAP_REDEFINE_NEW();
		};
		static_assert(sizeof(IAllocatorFunctor) == 0x8);

		constexpr BSTArrayBase() noexcept = default;
		constexpr BSTArrayBase(const BSTArrayBase&) noexcept = default;
		constexpr BSTArrayBase(BSTArrayBase&&) noexcept = default;

		inline ~BSTArrayBase() noexcept { _size = 0; }

		constexpr BSTArrayBase& operator=(const BSTArrayBase&) noexcept = default;
		constexpr BSTArrayBase& operator=(BSTArrayBase&&) noexcept = default;

		[[nodiscard]] constexpr bool	  empty() const noexcept { return _size == 0; }
		[[nodiscard]] constexpr size_type size() const noexcept { return _size; }

	protected:
		constexpr void set_size(size_type a_size) noexcept { _size = a_size; }

	private:
		// members
		std::uint32_t _size{ 0 };  // 0
	};
	static_assert(sizeof(BSTArrayBase) == 0x4);

	class BSTArrayHeapAllocator
	{
	public:
		using size_type = std::uint32_t;

		constexpr BSTArrayHeapAllocator() noexcept = default;

		inline BSTArrayHeapAllocator(const BSTArrayHeapAllocator& a_rhs)
		{
			if (a_rhs.data()) {
				_capacity = a_rhs.capacity();
				_data = allocate(capacity());
				std::memcpy(data(), a_rhs.data(), capacity());
			}
		}

		constexpr BSTArrayHeapAllocator(BSTArrayHeapAllocator&& a_rhs) noexcept :
			_data(a_rhs.data()),
			_capacity(a_rhs.capacity())
		{
			a_rhs._data = nullptr;
			a_rhs._capacity = 0;
		}

		inline ~BSTArrayHeapAllocator()
		{
			deallocate(data());
			_data = nullptr;
			_capacity = 0;
		}

		inline BSTArrayHeapAllocator& operator=(const BSTArrayHeapAllocator& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				deallocate(data());
				_data = nullptr;
				_capacity = 0;

				if (a_rhs.data()) {
					_capacity = a_rhs.capacity();
					_data = allocate(capacity());
					std::memcpy(data(), a_rhs.data(), capacity());
				}
			}
			return *this;
		}

		inline BSTArrayHeapAllocator& operator=(BSTArrayHeapAllocator&& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				deallocate(data());
				_data = a_rhs.data();
				_capacity = a_rhs.capacity();

				a_rhs._data = nullptr;
				a_rhs._capacity = 0;
			}
			return *this;
		}

		TES_HEAP_REDEFINE_NEW();

		[[nodiscard]] constexpr void*		data() noexcept { return _data; }
		[[nodiscard]] constexpr const void* data() const noexcept { return _data; }

		[[nodiscard]] constexpr size_type capacity() const noexcept { return _capacity; }

	protected:
		inline void* allocate(std::size_t a_size)
		{
			const auto mem = malloc(a_size);
			if (!mem) {
				stl::report_and_fail("out of memory"sv);
			} else {
				std::memset(mem, 0, a_size);
				return mem;
			}
		}

		inline void deallocate(void* a_ptr) { free(a_ptr); }

		constexpr void set_allocator_traits(void* a_data, std::uint32_t a_capacity, std::size_t) noexcept
		{
			_data = a_data;
			_capacity = a_capacity;
		}

	private:
		// members
		void*		  _data{ nullptr };	 // 00
		std::uint32_t _capacity{ 0 };	 // 08
	};
	static_assert(sizeof(BSTArrayHeapAllocator) == 0x10);

	template <std::uint32_t N>
	class BSTSmallArrayHeapAllocator
	{
	public:
		using size_type = std::uint32_t;

		constexpr BSTSmallArrayHeapAllocator() noexcept :
			_capacity(0),
			_local(1)
		{}

		inline BSTSmallArrayHeapAllocator(const BSTSmallArrayHeapAllocator& a_rhs) :
			_capacity(0),
			_local(1)
		{
			copy(a_rhs);
		}

		inline BSTSmallArrayHeapAllocator(BSTSmallArrayHeapAllocator&& a_rhs) :
			_capacity(0),
			_local(1)
		{
			copy(std::move(a_rhs));
		}

		inline ~BSTSmallArrayHeapAllocator() { release(); }

		inline BSTSmallArrayHeapAllocator& operator=(const BSTSmallArrayHeapAllocator& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				copy(a_rhs);
			}
			return *this;
		}

		inline BSTSmallArrayHeapAllocator& operator=(BSTSmallArrayHeapAllocator&& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				copy(std::move(a_rhs));
			}
			return *this;
		}

		TES_HEAP_REDEFINE_NEW();

		[[nodiscard]] constexpr void*		data() noexcept { return local() ? _data.local : _data.heap; }
		[[nodiscard]] constexpr const void* data() const noexcept { return local() ? _data.local : _data.heap; }

		[[nodiscard]] constexpr size_type capacity() const noexcept { return _capacity; }

	protected:
		void* allocate(std::size_t a_size)
		{
			if (a_size > N) {
				const auto mem = malloc(a_size);
				if (!mem) {
					stl::report_and_fail("out of memory"sv);
				} else {
					std::memset(mem, 0, a_size);
					return mem;
				}
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
			_capacity = a_capacity;
			if (a_capacity * a_typeSize > N) {
				_local = 0;
				_data.heap = a_data;
			}
		}

	private:
		union Data
		{
			void* heap;
			char  local[N]{ 0 };
		};

		inline void copy(const BSTSmallArrayHeapAllocator& a_rhs)
		{
			release();

			_capacity = a_rhs._capacity;
			_local = a_rhs._local;

			if (!local()) {
				const auto mem = malloc(capacity());
				if (!mem) {
					stl::report_and_fail("out of memory"sv);
				} else {
					_data.heap = mem;
				}
			}

			std::memcpy(data(), a_rhs.data(), capacity());
		}

		inline void copy(BSTSmallArrayHeapAllocator&& a_rhs)
		{
			release();

			_capacity = a_rhs._capacity;
			_local = a_rhs._local;
			std::memmove(data(), a_rhs.data(), capacity());

			std::memset(a_rhs.data(), 0, a_rhs.capacity());
			a_rhs._capacity = N;
			a_rhs._local = 1;
		}

		[[nodiscard]] constexpr bool local() const noexcept { return _local != 0; }

		inline void release()
		{
			if (!local()) {
				free(_data.heap);
			}

			std::memset(data(), 0, capacity());
			_capacity = N;
			_local = 1;
		}

		// members
		std::uint32_t _capacity : 31;  // 00
		std::uint32_t _local : 1;	   // 00
		Data		  _data;		   // 08
	};

	class BSScrapArrayAllocator
	{
	public:
		using size_type = std::uint32_t;

		constexpr BSScrapArrayAllocator() noexcept = default;

		inline BSScrapArrayAllocator(const BSScrapArrayAllocator& a_rhs) :
			_capacity(a_rhs._capacity)
		{
			if (capacity() > 0) {
				_data = allocate(capacity());
				std::memcpy(data(), a_rhs.data(), capacity());
			}
		}

		constexpr BSScrapArrayAllocator(BSScrapArrayAllocator&& a_rhs) noexcept :
			_allocator(a_rhs._allocator),
			_data(a_rhs._data),
			_capacity(a_rhs._capacity)
		{
			a_rhs._allocator = nullptr;
			a_rhs._data = nullptr;
			a_rhs._capacity = 0;
		}

		~BSScrapArrayAllocator();

		inline BSScrapArrayAllocator& operator=(const BSScrapArrayAllocator& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				if (_data) {
					deallocate(_data);
					_data = nullptr;
				}

				_capacity = a_rhs.capacity();
				if (capacity() > 0) {
					_data = allocate(capacity());
					std::memcpy(data(), a_rhs.data(), capacity());
				}
			}
			return *this;
		}

		inline BSScrapArrayAllocator& operator=(BSScrapArrayAllocator&& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				if (_data) {
					deallocate(_data);
				}

				_allocator = a_rhs._allocator;
				_data = a_rhs._data;
				_capacity = a_rhs._capacity;

				a_rhs._allocator = nullptr;
				a_rhs._data = nullptr;
				a_rhs._capacity = 0;
			}
			return *this;
		}

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
		// members
		ScrapHeap* _allocator{ nullptr };  // 00
		void*	   _data{ nullptr };	   // 08
		size_type  _capacity{ 0 };		   // 10
	};
	static_assert(sizeof(BSScrapArrayAllocator) == 0x18);

	template <class T, class Allocator = BSTArrayHeapAllocator>
	class BSTArray :
		public Allocator,
		public BSTArrayBase
	{
	public:
		using allocator_type = Allocator;
		using size_type = typename BSTArrayBase::size_type;
		using value_type = T;
		using pointer = value_type*;
		using const_pointer = const value_type*;
		using reference = value_type&;
		using const_reference = const value_type&;
		using iterator = pointer;
		using const_iterator = const_pointer;

		BSTArray() = default;

		inline BSTArray(const BSTArray& a_rhs)
		{
			const auto newCapacity = a_rhs.capacity();
			if (newCapacity == 0) {
				return;
			}

			const auto newSize = a_rhs.size();
			const auto newData = allocate(newCapacity);
			for (size_type i = 0; i < newSize; ++i) {
				std::construct_at(newData + i, a_rhs[i]);
			}

			set_allocator_traits(newData, newCapacity);
			set_size(newSize);
		}

		BSTArray(BSTArray&&) = default;

		explicit inline BSTArray(size_type a_count)
		{
			if (a_count == 0) {
				return;
			}

			const auto newCapacity = a_count;
			const auto newSize = a_count;
			const auto newData = allocate(newCapacity);
			for (size_type i = 0; i < newSize; ++i) {
				std::construct_at(newData + i);
			}

			set_allocator_traits(newData, newCapacity);
			set_size(newSize);
		}

		inline ~BSTArray() { release(); }

		inline BSTArray& operator=(const BSTArray& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				clear();

				const auto newCapacity = a_rhs.capacity();
				change_capacity(newCapacity);

				const auto newSize = a_rhs.size();
				set_size(newSize);

				const auto newData = data();
				for (size_type i = 0; i < newSize; ++i) {
					std::construct_at(newData + i, a_rhs[i]);
				}
			}
			return *this;
		}

		BSTArray& operator=(BSTArray&& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				release();

				const auto newCapacity = a_rhs.capacity();
				const auto newSize = a_rhs.size();
				const auto newData = a_rhs.data();

				set_allocator_traits(newData, newCapacity);
				a_rhs.set_allocator_traits(0, 0);

				set_size(newSize);
				a_rhs.set_size(0);
			}
			return *this;
		}

		TES_HEAP_REDEFINE_NEW();

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

		[[nodiscard]] constexpr reference		front() noexcept { return operator[](0); }
		[[nodiscard]] constexpr const_reference front() const noexcept { return operator[](0); }

		[[nodiscard]] constexpr reference		back() noexcept { return operator[](size() - 1); }
		[[nodiscard]] constexpr const_reference back() const noexcept { return operator[](size() - 1); }

		[[nodiscard]] constexpr pointer		  data() noexcept { return static_cast<pointer>(allocator_type::data()); }
		[[nodiscard]] constexpr const_pointer data() const noexcept { return static_cast<const_pointer>(allocator_type::data()); }

		[[nodiscard]] constexpr iterator	   begin() noexcept { return empty() ? nullptr : data(); }
		[[nodiscard]] constexpr const_iterator begin() const noexcept { return empty() ? nullptr : data(); }
		[[nodiscard]] constexpr const_iterator cbegin() const noexcept { return begin(); }

		[[nodiscard]] constexpr iterator	   end() noexcept { return empty() ? nullptr : data() + size(); }
		[[nodiscard]] constexpr const_iterator end() const noexcept { return empty() ? nullptr : data() + size(); }
		[[nodiscard]] constexpr const_iterator cend() const noexcept { return end(); }

		[[nodiscard]] constexpr bool empty() const noexcept { return BSTArrayBase::empty(); }

		[[nodiscard]] constexpr size_type size() const noexcept { return BSTArrayBase::size(); }

		inline void reserve(size_type a_newCap)
		{
			if (a_newCap > capacity()) {
				change_capacity(a_newCap);
			}
		}

		[[nodiscard]] constexpr size_type capacity() const noexcept { return allocator_type::capacity(); }

		inline void shrink_to_fit()
		{
			const auto newCapacity = size();
			if (newCapacity != capacity()) {
				change_capacity(newCapacity);
			}
		}

		inline void clear()
		{
			if (!empty()) {
				change_size(0);
			}
		}

		inline iterator erase(const_iterator a_pos)
		{
			auto					pos = const_cast<iterator>(a_pos);
			std::optional<iterator> result;
			if (pos != begin()) {
				result = pos - 1;
			}

			for (auto prev = pos++; pos != cend(); prev = pos++) {
				*prev = std::move(*pos);
			}
			pop_back();

			return result ? *result + 1 : begin();
		}

		inline void push_back(const value_type& a_value) { emplace_back(a_value); }
		inline void push_back(value_type&& a_value) { emplace_back(std::move(a_value)); }

		template <class... Args>
		inline reference emplace_back(Args&&... a_args)
		{
			if (size() == capacity()) {
				grow_capacity();
			}

			set_size(size() + 1);
			auto& elem = back();
			std::construct_at(std::addressof(elem), std::forward<Args>(a_args)...);
			return elem;
		}

		inline void pop_back()
		{
			assert(!empty());
			std::destroy_at(std::addressof(back()));
			set_size(size() - 1);
		}

		inline void resize(size_type a_count)
		{
			if (a_count != size()) {
				change_size(a_count);
			}
		}

		inline void resize(size_type a_count, const value_type& a_value)
		{
			if (a_count != size()) {
				change_size(a_count, a_value);
			}
		}

	private:
		static constexpr size_type DF_CAP = 4;			 // beth default
		static constexpr float	   GROWTH_FACTOR = 2.0;	 // not part of native type

		[[nodiscard]] inline pointer allocate(size_type a_num)
		{
			return static_cast<pointer>(allocator_type::allocate(a_num * sizeof(value_type)));
		}

		inline void deallocate(void* a_ptr) { allocator_type::deallocate(a_ptr); }

		constexpr void set_allocator_traits(void* a_data, size_type a_capacity) noexcept
		{
			allocator_type::set_allocator_traits(a_data, a_capacity, sizeof(value_type));
		}

		constexpr void set_size(size_type a_size) noexcept { BSTArrayBase::set_size(a_size); }

		inline void change_capacity(size_type a_newCapacity)
		{
			const auto newData = a_newCapacity > 0 ? allocate(a_newCapacity) : nullptr;
			const auto oldData = data();
			if (oldData) {
				const auto oldCapacity = capacity();
				if (newData) {
					const auto bytesToCopy = std::min(oldCapacity, a_newCapacity) * sizeof(value_type);
					std::memcpy(newData, oldData, bytesToCopy);
				}
				deallocate(oldData);
			}
			set_allocator_traits(newData, a_newCapacity);
		}

		template <class... Args>
		inline void change_size(size_type a_newSize, Args&&... a_args)
		{
			if (a_newSize > capacity()) {
				grow_capacity(a_newSize);
			}

			const auto oldSize = size();
			if (a_newSize > oldSize) {
				for (size_type i = oldSize; i < a_newSize; ++i) {
					std::construct_at(data() + i, std::forward<Args>(a_args)...);
				}
			} else {
				for (size_type i = a_newSize; i < oldSize; ++i) {
					std::destroy_at(data() + i);
				}
			}

			set_size(a_newSize);
		}

		inline void grow_capacity() { grow_capacity(capacity()); }

		inline void grow_capacity(size_type a_hint)
		{
			auto cap = a_hint;
			cap = cap > 0 ? static_cast<size_type>(std::ceil(static_cast<float>(cap) * GROWTH_FACTOR)) : DF_CAP;
			change_capacity(cap);
		}

		inline void release()
		{
			clear();
			change_capacity(0);
		}
	};

	template <class T, std::uint32_t N = 1>
	using BSTSmallArray = BSTArray<T, BSTSmallArrayHeapAllocator<sizeof(T) * N>>;

	template <class T>
	using BSScrapArray = BSTArray<T, BSScrapArrayAllocator>;

	template <class T>
	class BSStaticArray
	{
	public:
		using value_type = T;
		using size_type = std::uint32_t;
		using pointer = value_type*;
		using const_pointer = const value_type*;
		using reference = value_type&;
		using const_reference = const value_type&;
		using iterator = pointer;
		using const_iterator = const_pointer;

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

		[[nodiscard]] constexpr pointer		  data() noexcept { return _data; }
		[[nodiscard]] constexpr const_pointer data() const noexcept { return _data; }

		[[nodiscard]] constexpr iterator	   begin() noexcept { return empty() ? nullptr : data(); }
		[[nodiscard]] constexpr const_iterator begin() const noexcept { return empty() ? nullptr : data(); }
		[[nodiscard]] constexpr const_iterator cbegin() const noexcept { return begin(); }

		[[nodiscard]] constexpr iterator	   end() noexcept { return empty() ? nullptr : data() + size(); }
		[[nodiscard]] constexpr const_iterator end() const noexcept { return empty() ? nullptr : data() + size(); }
		[[nodiscard]] constexpr const_iterator cend() const noexcept { return end(); }

		[[nodiscard]] constexpr bool empty() const noexcept { return size() == 0; }

		[[nodiscard]] constexpr size_type size() const noexcept { return _size; }

	private:
		// members
		pointer		  _data{ nullptr };	 // 00
		std::uint32_t _size{ 0 };		 // 08
	};

	template <class T>
	class BSTSmallSharedArray
	{
	public:
		using value_type = T;
		using size_type = std::uint32_t;
		using pointer = value_type*;
		using const_pointer = const value_type*;
		using reference = value_type&;
		using const_reference = const value_type&;
		using iterator = pointer;
		using const_iterator = const_pointer;

		[[nodiscard]] inline reference operator[](size_type a_pos) noexcept
		{
			assert(a_pos < _size);
			return data()[a_pos];
		}

		[[nodiscard]] inline const_reference operator[](size_type a_pos) const noexcept
		{
			assert(a_pos < _size);
			return data()[a_pos];
		}

		[[nodiscard]] inline pointer data() noexcept
		{
			return size() > 1 ? _data.heap : std::addressof(_data.local);
		}

		[[nodiscard]] inline const_pointer data() const noexcept
		{
			return size() > 1 ? _data.heap : std::addressof(_data.local);
		}

		[[nodiscard]] inline iterator		begin() noexcept { return data(); }
		[[nodiscard]] inline const_iterator begin() const noexcept { return data(); }
		[[nodiscard]] inline const_iterator cbegin() const noexcept { return begin(); }

		[[nodiscard]] inline iterator		end() noexcept { return data() + size(); }
		[[nodiscard]] inline const_iterator end() const noexcept { return data() + size(); }
		[[nodiscard]] inline const_iterator cend() const noexcept { return end(); }

		[[nodiscard]] constexpr bool empty() const noexcept { return size() != 0; }

		[[nodiscard]] constexpr size_type size() const noexcept { return _size; }

	private:
		union Data
		{
			~Data(){};

			pointer	   heap{ 0 };
			value_type local;
		};

		// members
		std::uint32_t _size{ 0 };  // 00
		Data		  _data;	   // 08
	};
}
