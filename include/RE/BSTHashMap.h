#pragma once

#include <cassert>
#include <utility>

#include "RE/BSTTuple.h"
#include "RE/CRC.h"
#include "RE/MemoryManager.h"


namespace RE
{
	// scatter table with chaining
	template <class Traits, UInt32 N, template <class, UInt32> class Allocator, class Hash, class KeyEqual>
	struct BSTScatterTable
	{
	public:
		using traits_type = Traits;
		using key_type = typename traits_type::key_type;
		using mapped_type = typename traits_type::mapped_type;
		using value_type = typename traits_type::value_type;
		using size_type = UInt32;
		using hasher = Hash;
		using key_equal = KeyEqual;


		struct BSTScatterTableEntry
		{
		public:
			BSTScatterTableEntry() :
				value(),
				next(0)
			{}


			BSTScatterTableEntry(const BSTScatterTableEntry& a_rhs) :
				value(a_rhs.value),
				next(a_rhs.next)
			{}


			BSTScatterTableEntry(BSTScatterTableEntry&& a_rhs) :
				value(std::move(a_rhs.value)),
				next(std::move(a_rhs.next))
			{
				a_rhs.next = 0;
			}


			BSTScatterTableEntry& operator=(const BSTScatterTableEntry& a_rhs)
			{
				value = a_rhs.value;
				next = a_rhs.next;
				return *this;
			}


			BSTScatterTableEntry& operator=(BSTScatterTableEntry&& a_rhs)
			{
				value = std::move(a_rhs.value);

				next = std::move(a_rhs.next);
				a_rhs.next = 0;

				return *this;
			}


			value_type			  value;  // 00
			BSTScatterTableEntry* next;	  // ??
		};


		using entry_type = BSTScatterTableEntry;
		using allocator_type = Allocator<entry_type, N>;


		template <class U>
		struct iterator_base
		{
		public:
			using difference_type = std::ptrdiff_t;
			using value_type = U;
			using pointer = U*;
			using reference = U&;
			using iterator_category = std::forward_iterator_tag;


			iterator_base() :
				_entry(nullptr),
				_end(nullptr)
			{}


			iterator_base(const iterator_base& a_rhs) :
				_entry(a_rhs._entry),
				_end(a_rhs._end)
			{}


			iterator_base(iterator_base&& a_rhs) :
				_entry(std::move(a_rhs._entry)),
				_end(a_rhs._end)
			{
				a_rhs._entry = a_rhs._end;
			}


			iterator_base(entry_type* a_entry, entry_type* a_end) :
				_entry(a_entry),
				_end(a_end)
			{
				while (_entry != _end && !_entry->next) {
					++_entry;
				}
			}


			~iterator_base()
			{}


			iterator_base& operator=(const iterator_base& a_rhs)
			{
				assert(_end == a_rhs._end);
				_entry = a_rhs._entry;
			}


			iterator_base& operator=(iterator_base&& a_rhs)
			{
				assert(_end == a_rhs._end);
				_entry = std::move(a_rhs._entry);
				a_rhs._entry = a_rhs._end;
			}


			void swap(iterator_base& a_rhs)
			{
				assert(_end == a_rhs._end);
				std::swap(_entry, a_rhs._entry);
			}


			[[nodiscard]] reference operator*() const
			{
				assert(_entry != _end);
				return _entry->value;
			}


			[[nodiscard]] pointer operator->() const noexcept
			{
				assert(_entry != _end);
				return std::addressof(_entry->value);
			}


			[[nodiscard]] friend bool operator==(const iterator_base& a_lhs, const iterator_base& a_rhs) noexcept
			{
				assert(a_lhs._end == a_rhs._end);
				return a_lhs._entry == a_rhs._entry;
			}


			[[nodiscard]] friend bool operator!=(const iterator_base& a_lhs, const iterator_base& a_rhs) noexcept
			{
				return !(a_lhs == a_rhs);
			}


			// prefix
			iterator_base& operator++()
			{
				assert(_entry != _end);
				do {
					++_entry;
				} while (_entry != _end && !_entry->next);
				return *this;
			}


			// postfix
			iterator_base operator++(int)
			{
				iterator_base tmp{ *this };
				operator++();
				return tmp;
			}

		private:
			entry_type* _entry;
			entry_type* _end;
		};


		using iterator = iterator_base<value_type>;
		using const_iterator = iterator_base<const value_type>;


		BSTScatterTable() :
			_pad00(0),
			_pad08(0),
			_capacity(0),
			_freeCount(0),
			_freeIdx(0),
			_sentinel((const entry_type*)SENTINEL),
			_allocator()
		{}


		TES_HEAP_REDEFINE_NEW();


		iterator begin()
		{
			return get_entries() ? make_iterator(get_entries()) : iterator();
		}


		const_iterator begin() const
		{
			return get_entries() ? make_iterator(get_entries()) : const_iterator();
		}


		const_iterator cbegin() const
		{
			return begin();
		}


		iterator end()
		{
			return get_entries() ? make_iterator(get_entries() + _capacity) : iterator();
		}


		const_iterator end() const
		{
			return get_entries() ? make_iterator(get_entries() + _capacity) : const_iterator();
		}


		const_iterator cend() const
		{
			return end();
		}


		[[nodiscard]] bool empty() const
		{
			return !get_entries() || _freeCount == 0;
		}


		size_type size() const
		{
			return _capacity - _freeCount;
		}


		size_type max_size() const
		{
			return _allocator.max_size();
		}


		std::pair<iterator, bool> insert(const value_type& a_value)
		{
			return insert_impl(false, a_value);
		}


		std::pair<iterator, bool> insert(value_type&& a_value)
		{
			return insert_impl(false, std::move(a_value));
		}


		std::pair<iterator, bool> insert_or_assign(const value_type& a_value)
		{
			return insert_impl(true, a_value);
		}


		std::pair<iterator, bool> insert_or_assign(value_type&& a_value)
		{
			return insert_impl(true, std::move(a_value));
		}


		size_type erase(const key_type& a_key)
		{
			if (!get_entries()) {  // no entries
				return 0;
			}

			auto entry = calc_pos(a_key);
			if (!entry->next) {	 // key not in table
				return 0;
			}

			entry_type* tail = 0;
			while (!comp_key(get_key(entry->value), a_key)) {  // find key in table
				tail = entry;
				entry = entry->next;
				if (entry == _sentinel) {
					return 0;
				}
			}

			entry->value.~value_type();

			if (entry->next == _sentinel) {	 // if no chain
				if (tail) {
					tail->next = const_cast<entry_type*>(_sentinel);
				}
				entry->next = 0;
			} else {  // else move next entry into current
				new (entry) entry_type(std::move(*entry->next));
			}

			++_freeCount;
			return 1;
		}


		iterator find(const key_type& a_key)
		{
			auto entry = find_impl(a_key);
			return entry ? make_iterator(entry) : end();
		}


		const_iterator find(const key_type& a_key) const
		{
			auto entry = find_impl(a_key);
			return entry ? make_iterator(entry) : end();
		}


		void reserve(size_type a_count)
		{
			if (a_count <= _capacity) {
				return;
			}

			constexpr auto TOP = static_cast<UInt32>(1 << 31);
			UInt32		   leftShifts = 0;
			while ((a_count & TOP) == 0) {
				a_count <<= 1;
				++leftShifts;
			}
			auto bitPos = 31 - leftShifts;
			auto newCount = static_cast<UInt32>(1 << bitPos);
			grow(newCount);
		}


		hasher hash_function() const
		{
			return hasher();
		}


		key_equal key_eq() const
		{
			return key_equal();
		}

	private:
		entry_type* find_impl(const key_type& a_key) const
		{
			if (!get_entries()) {
				return nullptr;
			}

			auto probe = calc_pos(a_key);  // try ideal pos
			if (!probe->next) {
				return nullptr;	 // nothing there
			}

			do {
				if (comp_key(get_key(probe->value), a_key)) {
					return probe;
				} else {
					probe = probe->next;
				}
			} while (probe != _sentinel);  // follow chain

			return nullptr;
		}


		template <class Arg>
		std::pair<iterator, bool> insert_impl(bool a_overwrite, Arg&& a_value)
		{
			if (!get_entries() || !_freeCount) {
				if (!grow()) {
					return std::make_pair(end(), false);  // maybe throw?
				}
			}

			auto idealEntry = calc_pos(get_key(a_value));
			if (!idealEntry->next) {  // if slot empty
				new (std::addressof(idealEntry->value)) value_type(std::forward<Arg>(a_value));
				idealEntry->next = const_cast<entry_type*>(_sentinel);
				return std::make_pair(make_iterator(idealEntry), true);
			}

			for (auto iter = idealEntry; iter != _sentinel; iter = iter->next) {
				if (comp_key(get_key(iter->value), get_key(a_value))) {	 // if entry already in table
					if (a_overwrite) {
						iter->value.~value_type();
						new (std::addressof(iter->value)) value_type(std::forward<Arg>(a_value));
					}
					return std::make_pair(make_iterator(iter), false);
				}
			}

			auto freeEntry = get_free_entry();

			auto takenIdealEntry = calc_pos(get_key(idealEntry->value));
			if (takenIdealEntry == idealEntry) {  // if entry occupying our slot would've hashed here anyway
				freeEntry->next = idealEntry->next;
				idealEntry->next = freeEntry;
				new (std::addressof(freeEntry->value)) value_type(std::forward<Arg>(a_value));
				return std::make_pair(make_iterator(freeEntry), true);
			}

			while (takenIdealEntry->next != idealEntry) {  // find entry that links here
				takenIdealEntry = takenIdealEntry->next;
			}

			// move taken slot out, so we can move in
			new (std::addressof(freeEntry->value)) value_type(std::move(idealEntry->value));
			freeEntry->next = idealEntry->next;
			takenIdealEntry->next = freeEntry;
			new (std::addressof(idealEntry->value)) value_type(std::forward<Arg>(a_value));
			idealEntry->next = const_cast<entry_type*>(_sentinel);
			return std::make_pair(make_iterator(idealEntry), true);
		}


		iterator make_iterator(entry_type* a_entry)
		{
			return iterator(a_entry, get_entries() + _capacity);
		}


		const_iterator make_iterator(entry_type* a_entry) const
		{
			return const_iterator(a_entry, get_entries() + _capacity);
		}


		UInt32 calc_hash(const key_type& a_key) const
		{
			return hash_function()(a_key);
		}


		UInt32 calc_idx(const key_type& a_key) const
		{
			return calc_hash(a_key) & (_capacity - 1);	// capacity is always a factor of 2, so this is a faster modulo
		}


		entry_type* calc_pos(const key_type& a_key) const
		{
			return const_cast<entry_type*>(get_entries() + calc_idx(a_key));
		}


		// assumes not empty
		entry_type* get_free_entry()
		{
			entry_type* entry = nullptr;
			do {
				_freeIdx = (_capacity - 1) & (_freeIdx - 1);
				entry = get_entries() + _freeIdx;
			} while (entry->next);

			--_freeCount;
			return entry;
		}


		bool comp_key(const key_type& a_lhs, const key_type& a_rhs) const
		{
			return key_eq()(a_lhs, a_rhs);
		}


		bool grow()
		{
			if (_capacity == (UInt32)1 << 31) {
				return false;
			}

			UInt32 newCapacity = _capacity ? _capacity << 1 : min_size();
			return grow(newCapacity);
		}


		bool grow(UInt32 a_newCapacity)
		{
			auto oldEntries = get_entries();
			auto begIter = begin();
			auto endIter = end();

			auto newEntries = allocate(a_newCapacity);
			if (!newEntries) {
				return false;
			} else if (newEntries == oldEntries) {
				_capacity = a_newCapacity;
				return true;
			} else {
				_capacity = a_newCapacity;
				_freeCount = a_newCapacity;
				_freeIdx = a_newCapacity;
				set_entries(newEntries);

				while (begIter != endIter) {
					insert(std::move(*begIter));
					++begIter;
				}

				deallocate(oldEntries);
				return true;
			}
		}


		const key_type& get_key(const value_type& a_value) const
		{
			traits_type traits;
			return traits(a_value);
		}


		entry_type* allocate(std::size_t a_num)
		{
			return _allocator.allocate(a_num);
		}


		void deallocate(entry_type* a_ptr)
		{
			_allocator.deallocate(a_ptr);
		}


		entry_type* get_entries() const
		{
			return _allocator.get_entries();
		}


		void set_entries(entry_type* a_entries)
		{
			_allocator.set_entries(a_entries);
		}


		size_type min_size() const
		{
			return _allocator.min_size();
		}


		static constexpr UInt8 SENTINEL[] = { (UInt8)0xDE, (UInt8)0xAD, (UInt8)0xBE, (UInt8)0xEF };


		// members
		UInt64			  _pad00;	   // 00
		UInt32			  _pad08;	   // 08
		UInt32			  _capacity;   // 0C - this must be 2^n, or else terrible things will happen
		UInt32			  _freeCount;  // 10
		UInt32			  _freeIdx;	   // 14
		const entry_type* _sentinel;   // 18
		allocator_type	  _allocator;  // 20
	};


	template <class Key, class T>
	struct BSTScatterTableTraits
	{
	public:
		using key_type = Key;
		using mapped_type = T;
		using value_type = BSTTuple<const Key, T>;


		const key_type& operator()(const value_type& a_value) const
		{
			return a_value.first;
		}
	};


	template <class T, UInt32 N = 8>
	struct BSTScatterTableHeapAllocator
	{
	public:
		using entry_type = T;
		using size_type = UInt32;


		BSTScatterTableHeapAllocator() :
			_pad00(0),
			_entries(0)
		{}


		entry_type* allocate(std::size_t a_num)
		{
			auto size = a_num * sizeof(entry_type);
			auto mem = malloc<entry_type>(size);
			std::memset(mem, 0, size);
			return mem;
		}


		void deallocate(entry_type* a_ptr)
		{
			free(a_ptr);
		}


		entry_type* get_entries() const noexcept
		{
			return _entries;
		}


		void set_entries(entry_type* a_entries)
		{
			_entries = a_entries;
		}


		size_type min_size() const
		{
			return static_cast<size_type>(1) << 3;
		}


		size_type max_size() const
		{
			return static_cast<size_type>(1) << 31;
		}

	private:
		// members
		UInt64		_pad00;	   // 00 (20)
		entry_type* _entries;  // 08 (28)
	};
	STATIC_ASSERT(sizeof(BSTScatterTableHeapAllocator<void*, 8>) == 0x10);


	template <class Key, class T, class Hash = CRC32Hash<Key>, class KeyEqual = std::equal_to<Key>>
	using BSTHashMap = BSTScatterTable<BSTScatterTableTraits<Key, T>, 8, BSTScatterTableHeapAllocator, Hash, KeyEqual>;
	STATIC_ASSERT(sizeof(BSTHashMap<UInt32, void*>) == 0x30);


	template <class Key>
	struct BSTSetTraits
	{
	public:
		using key_type = Key;
		using mapped_type = void;
		using value_type = Key;


		const key_type& operator()(const value_type& a_value) const
		{
			return a_value;
		}
	};


	template <class Key, class Hash = CRC32Hash<Key>, class KeyEqual = std::equal_to<Key>>
	using BSTSet = BSTScatterTable<BSTSetTraits<Key>, 8, BSTScatterTableHeapAllocator, Hash, KeyEqual>;
	STATIC_ASSERT(sizeof(BSTSet<UInt32, void*>) == 0x30);


	struct BSTStaticHashMapBase
	{
	public:
		template <class T, UInt32 N>
		struct Allocator
		{
		public:
			using entry_type = T;
			using size_type = UInt32;


			Allocator() :
				_data{ 0 },
				_entries(_data)
			{}


			entry_type* allocate(std::size_t a_num)
			{
				return a_num <= N ? _data : 0;
			}


			void deallocate(entry_type* a_ptr)
			{
				return;
			}


			entry_type* get_entries() const
			{
				return _entries;
			}


			void set_entries(entry_type* a_entries)
			{
				_entries = a_entries;
			}


			size_type min_size() const
			{
				return 1;
			}


			size_type max_size() const
			{
				return N;
			}

		private:
			// members
			entry_type	_data[N];  // 00 (20)
			entry_type* _entries;  // ?? (??)
		};
	};


	template <class Key, class T, UInt32 N, class Hash = CRC32Hash<Key>, class KeyEqual = std::equal_to<Key>>
	using BSTStaticHashMap = BSTScatterTable<BSTScatterTableTraits<Key, T>, N, BSTStaticHashMapBase::Allocator, Hash, KeyEqual>;


	using UnkKey = UInt64;
	using UnkValue = UInt64;


	//class BSTHashMap<unsigned int, unsigned int, struct BSTDefaultScatterTable>	size(30) :
	//	+-- -
	// 0 | +-- - (base class BSTHashMapBase<struct BSTHashMapTraits<unsigned int, unsigned int, struct BSTDefaultScatterTable<unsigned int, unsigned int> > >)
	// 0	| | +-- - (base class BSTHashMapTraits<unsigned int, unsigned int, struct BSTDefaultScatterTable<unsigned int, unsigned int> >)
	//	| | +-- -
	// 8	| | +-- - (base class BSTDefaultScatterTable<unsigned int, unsigned int>)
	// 8	| | | +-- - (base class BSTScatterTable<unsigned int, unsigned int, struct BSTScatterTableDefaultKVStorage, struct BSTScatterTableDefaultHashPolicy, struct BSTScatterTableHeapAllocator, 8>)
	// 8	| | | | +-- - (base class BSTScatterTableBase<struct BSTScatterTableTraits<unsigned int, unsigned int, struct BSTScatterTableDefaultKVStorage, struct BSTScatterTableDefaultHashPolicy<unsigned int>, struct BSTScatterTableHeapAllocator<struct BSTScatterTableEntry<unsigned int, unsigned int, struct BSTScatterTableDefaultKVStorage> >, 8> >)
	// 8	| | | | | +-- - (base class BSTScatterTableKernel<struct BSTScatterTableTraits<unsigned int, unsigned int, struct BSTScatterTableDefaultKVStorage, struct BSTScatterTableDefaultHashPolicy<unsigned int>, struct BSTScatterTableHeapAllocator<struct BSTScatterTableEntry<unsigned int, unsigned int, struct BSTScatterTableDefaultKVStorage> >, 8> >)
	// 8	| | | | | | +-- - (base class BSTScatterTableTraits<unsigned int, unsigned int, struct BSTScatterTableDefaultKVStorage, struct BSTScatterTableDefaultHashPolicy<unsigned int>, struct BSTScatterTableHeapAllocator<struct BSTScatterTableEntry<unsigned int, unsigned int, struct BSTScatterTableDefaultKVStorage> >, 8>)
	//	| | | | | | +-- -
	// 9	| | | | | | +-- - (base class BSTScatterTableDefaultHashPolicy<unsigned int>)
	//	| | | | | | +-- -
	//  	| | | | | | <alignment member> (size = 3)
	//0C	| | | | | | _size
	//10	| | | | | | _freeCount
	//14	| | | | | | _freeOffset
	//18	| | | | | | _eolPtr
	//	| | | | | +-- -
	//21	| | | | | +-- - (base class BSTScatterTableHeapAllocator<struct BSTScatterTableEntry<unsigned int, unsigned int, struct BSTScatterTableDefaultKVStorage> >)
	//	| | | | | +-- -
	//  	| | | | | <alignment member> (size = 7)
	//28	| | | | | _entries
	//	| | | | +-- -
	//	| | | +-- -
	//	| | +-- -
	// | +-- -
	//	+-- -


#if 0
	namespace TODO
	{
		template <class Traits>
		struct BSTScatterTableKernel :
			public Traits,
			public Traits::hasher
		{
		public:
			using traits_type = Traits;
			using hasher = typename traits_type::hasher;
			using allocator_type = typename traits_type::allocator_type;
			using entry_type = typename allocator_type::value_type;


			// members
			UInt32				_capacity;	// ?? (0C) - this must be 2^n, or else terrible things will happen
			UInt32				_freeCount;	// ?? (10)
			UInt32				_freeIdx;	// ?? (14)
			const entry_type*	_sentinel;	// ?? (18)
		};


		template <class Key, class T>
		struct BSTScatterTableDefaultKVStorage
		{
		public:
			// members
			Key first;	// 00
			T second;	// ??
		};


		template <class Key, class T, template <class, class> class Storage>
		struct BSTScatterTableEntry : public Storage<Key, T>
		{
		public:
			using base = Storage<Key, T>;
			using value_type = Storage<const Key, T>;


			// members
			BSTScatterTableEntry* next;	// ??
		};


		template <class Key>
		struct BSTScatterTableDefaultHashPolicy
		{
		public:
			UInt32 operator()(const Key& a_key) const
			{
				return CRC32Hash<Key>()(a_key);
			}
		};


		template <class T>
		struct BSTScatterTableHeapAllocator
		{
		public:
			using entry_type = T;
		};


		template <class Key, class T, class Storage, class Hash, class Allocator, UInt32 N>
		struct BSTScatterTableTraits
		{
		public:
			using key_type = Key;
			using mapped_type = T;
			using hasher = Hash;
			using allocator_type = Allocator;
			using entry_type = typename allocator_type::entry_type;
			using value_type = typename entry_type::value_type;
		};


		template <class Traits>
		struct BSTScatterTableBase :
			public BSTScatterTableKernel<Traits>,
			public Traits::allocator_type
		{
		public:
			using kernel_type = BSTScatterTableKernel<Traits>;
			using traits_type = Traits;

			using key_type = typename traits_type::key_type;
			using mapped_type = typename traits_type::mapped_type;
			using value_type = typename traits_type::value_type;
			using size_type = UInt32;
			using hasher = Hash;
			using key_equal = KeyEqual;
			using allocator_type = typename traits_type::allocator_type;

			using entry_type = typename traits_type::entry_type;


			// members
			entry_type* _entries;	// ?? (28)
		};


		template <class Key, class T, class Storage, class Hash, class Allocator, UInt32 N>
		struct BSTScatterTable :
			public BSTScatterTableBase<BSTScatterTableTraits<Key, T, Storage, Hash, Allocator, N>>
		{
		public:
			using base = BSTScatterTableBase<BSTScatterTableTraits<Key, T, Storage, Hash, Allocator, N>>;
			using traits_type = typename base::traits_type;
		};


		template <class Key, class T>
		struct BSTDefaultScatterTable :
			public BSTScatterTable<Key, T, BSTScatterTableDefaultKVStorage, BSTScatterTableDefaultHashPolicy, BSTScatterTableHeapAllocator, 8>
		{
		public:
			using base = BSTScatterTable<Key, T, BSTScatterTableDefaultKVStorage, BSTScatterTableDefaultHashPolicy, BSTScatterTableHeapAllocator, 8>;
			using traits_type = typename base::traits_type;
		};


		template <class Key, class T, class Table>
		struct BSTHashMapTraits
		{
		public:
			using table_type = Table;
		};


		template <class Traits>
		struct BSTHashMapBase :
			public Traits,
			public Traits::table_type
		{
		public:
		};


		template <class Key, class T, template <class, class> class Table = BSTDefaultScatterTable>
		class BSTHashMap :
			public BSTHashMapBase<BSTHashMapTraits<Key, T, Table<Key, T>>>
		{
		public:
		};
		STATIC_ASSERT(sizeof(BSTHashMap<UInt32, void*>) == 0x30);
	}
#endif
}
