#pragma once

#include <cassert>
#include <utility>

#include "RE/CRC.h"
#include "RE/TESMemoryManager.h"


namespace RE
{
	// scatter table with chaining
	template <class Key, class T, class Hash = CRC32Hash<Key>, class KeyEqual = std::equal_to<Key>>
	class BSTHashMap
	{
	public:
		template <class T1, class T2>
		struct pair
		{
		public:
			using first_type = T1;
			using second_type = T2;


			pair() :
				first{},
				second{}
			{}


			pair(const pair&) = default;
			pair(pair&&) = default;


			pair(const T1& a_first, const T2& a_second) :
				first(a_first),
				second(a_second)
			{}


			template <class... Args1, class... Args2, std::size_t... I1, std::size_t... I2>
			pair(std::piecewise_construct_t, std::tuple<Args1...> a_firstArgs, std::tuple<Args2...> a_secondArgs, std::index_sequence<I1...>, std::index_sequence<I2...>) :
				first(std::get<I1>(std::move(a_firstArgs))...),
				second(std::get<I2>(std::move(a_secondArgs))...)
			{}


			template <class... Args1, class... Args2>
			pair(std::piecewise_construct_t, std::tuple<Args1...> a_firstArgs, std::tuple<Args2...> a_secondArgs) :
				pair(a_firstArgs, a_secondArgs, std::index_sequence_for<Args1...>(), std::index_sequence_for<Args2...>())
			{}


			pair& operator=(const pair& a_rhs)
			{
				first = a_rhs.first;
				second = a_rhs.second;
			}


			pair& operator=(pair&& a_rhs)
			{
				first = std::move(a_rhs.first);
				second = std::move(a_rhs.second);
			}


			T1 first;	// 00
			T2 second;	// ??
		};


		using key_type = Key;
		using mapped_type = T;
		using value_type = pair<const Key, T>;
		using size_type = UInt32;
		using hasher = Hash;
		using key_equal = KeyEqual;


		struct Entry
		{
			Entry() :
				value(),
				next(0)
			{}


			Entry(const Entry& a_rhs) :
				value(a_rhs.value),
				next(a_rhs.next)
			{}


			Entry(Entry&& a_rhs) :
				value(std::move(a_rhs.value)),
				next(std::move(a_rhs.next))
			{
				a_rhs.next = 0;
			}


			Entry& operator=(const Entry& a_rhs)
			{
				value = a_rhs.value;
				next = a_rhs.next;
				return *this;
			}


			Entry& operator=(Entry&& a_rhs)
			{
				value = std::move(a_rhs.value);

				next = std::move(a_rhs.next);
				a_rhs.next = 0;

				return *this;
			}


			value_type value;	// 00
			Entry* next;		// ??
		};


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
				_entry(0),
				_end(0)
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


			iterator_base(Entry* a_entry, Entry* a_end) :
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


			[[nodiscard]] pointer operator->() const
			{
				assert(_entry != _end);
				return std::addressof(_entry->value);
			}


			[[nodiscard]] bool operator==(const iterator_base& a_rhs) const
			{
				assert(_end == a_rhs._end);
				return _entry == a_rhs._entry;
			}


			[[nodiscard]] bool operator!=(const iterator_base& a_rhs) const
			{
				assert(_end == a_rhs._end);
				return !operator==(a_rhs);
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
			Entry* _entry;
			Entry* _end;
		};


		using iterator = iterator_base<value_type>;
		using const_iterator = iterator_base<const value_type>;


		BSTHashMap() :
			_pad00(0),
			_pad08(0),
			_capacity(0),
			_freeCount(0),
			_freeIdx(0),
			_sentinel((const Entry*)SENTINEL),
			_pad20(0),
			_entries(0)
		{}


		TES_HEAP_REDEFINE_NEW();


		iterator begin()
		{
			return _entries ? make_iterator(_entries) : iterator();
		}


		const_iterator begin() const
		{
			return _entries ? make_iterator(_entries) : const_iterator();
		}


		const_iterator cbegin() const
		{
			return begin();
		}


		iterator end()
		{
			return _entries ? make_iterator(_entries + _capacity) : iterator();
		}


		const_iterator end() const
		{
			return _entries ? make_iterator(_entries + _capacity) : const_iterator();
		}


		const_iterator cend() const
		{
			return end();
		}


		[[nodiscard]] bool empty() const
		{
			return !_entries || _freeCount == 0;
		}


		size_type size() const
		{
			return _capacity - _freeCount;
		}


		std::pair<iterator, bool> insert(const value_type& a_value)
		{
			return insert_impl(a_value);
		}


		std::pair<iterator, bool> insert(value_type&& a_value)
		{
			return insert_impl(std::move(a_value));
		}


		size_type erase(const key_type& a_key)
		{
			if (!_entries) {	// no entries
				return 0;
			}

			auto entry = calc_pos(a_key);
			if (!entry->next) {	// key not in table
				return 0;
			}

			Entry* tail = 0;
			while (!comp_key(entry->value.first, a_key)) {	// find key in table
				tail = entry;
				entry = entry->next;
				if (entry == _sentinel) {
					return 0;
				}
			}

			entry->value.~value_type();

			if (entry->next == _sentinel) {	// if no chain
				if (tail) {
					tail->next = _sentinel;
				}
				entry->next = 0;
			} else {	// else move next entry into current
				new(entry) Entry(std::move(*entry->next));
			}

			++_freeCount;
			return 1;
		}


		iterator find(const Key& a_key)
		{
			auto entry = find_impl(a_key);
			return entry ? make_iterator(entry) : end();
		}


		const_iterator find(const Key& a_key) const
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
			UInt32 leftShifts = 0;
			while ((a_count & TOP) == 0) {
				a_count <<= 1;
				++leftShifts;
			}
			auto bitPos = 31 - leftShifts;
			auto newCount = static_cast<UInt32>(1 << bitPos);
			grow(newCount);
		}

	private:
		Entry* find_impl(const Key& a_key) const
		{
			if (!_entries) {
				return 0;
			}

			auto probe = calc_pos(a_key);	// try ideal pos
			if (!probe->next) {
				return 0;	// nothing there
			}

			do {
				if (comp_key(probe->value.first, a_key)) {
					return probe;
				} else {
					probe = probe->next;
				}
			} while (probe != _sentinel);	// follow chain

			return 0;
		}


		template <class Arg>
		std::pair<iterator, bool> insert_impl(Arg&& a_value)
		{
			if (!_entries || !_freeCount) {
				if (!grow()) {
					return std::make_pair(end(), false);
				}
			}

			auto idealEntry = calc_pos(a_value.first);
			if (!idealEntry->next) {	// if slot empty
				new(std::addressof(idealEntry->value)) value_type(std::forward<Arg>(a_value));
				idealEntry->next = const_cast<Entry*>(_sentinel);
				return std::make_pair(make_iterator(idealEntry), true);
			}

			for (auto iter = idealEntry; iter != _sentinel; iter = iter->next) {
				if (comp_key(iter->value.first, a_value.first)) {	// if entry already in table
					return std::make_pair(make_iterator(iter), false);
				}
			}

			auto freeEntry = get_free_entry();

			auto takenIdealEntry = calc_pos(idealEntry->value.first);
			if (takenIdealEntry == idealEntry) {	// if entry occupying our slot would've hashed here anyway
				freeEntry->next = idealEntry->next;
				idealEntry->next = freeEntry;
				new(std::addressof(freeEntry->value)) value_type(std::forward<Arg>(a_value));
				return std::make_pair(make_iterator(freeEntry), true);
			}

			while (takenIdealEntry->next != idealEntry) {	// find entry that links here
				takenIdealEntry = takenIdealEntry->next;
			}

			// move taken slot out, so we can move in
			new(std::addressof(freeEntry->value)) value_type(std::move(idealEntry->value));
			freeEntry->next = idealEntry->next;
			takenIdealEntry->next = freeEntry;
			new(std::addressof(idealEntry->value)) value_type(std::forward<Arg>(a_value));
			idealEntry->next = const_cast<Entry*>(_sentinel);
			return std::make_pair(make_iterator(idealEntry), true);
		}


		iterator make_iterator(Entry* a_entry)
		{
			return iterator(a_entry, _entries + _capacity);
		}


		const_iterator make_iterator(Entry* a_entry) const
		{
			return const_iterator(a_entry, _entries + _capacity);
		}


		UInt32 calc_hash(const Key& a_key) const
		{
			hasher h;
			return h(a_key);
		}


		UInt32 calc_idx(const Key& a_key) const
		{
			return calc_hash(a_key) & (_capacity - 1);	// capacity is always a factor of 2, so this is a faster modulo
		}


		Entry* calc_pos(const Key& a_key) const
		{
			return const_cast<Entry*>(_entries + calc_idx(a_key));
		}


		// assumes not empty
		Entry* get_free_entry()
		{
			Entry* entry = 0;
			do {
				_freeIdx = (_capacity - 1) & (_freeIdx - 1);
				entry = _entries + _freeIdx;
			} while (entry->next);

			--_freeCount;
			return entry;
		}


		bool comp_key(const Key& a_lhs, const Key& a_rhs) const
		{
			key_equal eq;
			return eq(a_lhs, a_rhs);
		}


		bool grow()
		{
			if (_capacity == 1 << 31) {
				return false;
			}

			UInt32 newCapacity = _capacity ? _capacity << 1 : MIN_CAP;
			grow(newCapacity);
			return true;
		}


		void grow(UInt32 a_newCapacity)
		{
			auto oldEntries = _entries;
			iterator begIter = begin();
			iterator endIter = end();

			auto newEntriesSize = sizeof(Entry) * a_newCapacity;
			auto newEntries = malloc<Entry>(newEntriesSize);
			std::memset(newEntries, 0, newEntriesSize);

			_capacity = a_newCapacity;
			_freeCount = a_newCapacity;
			_freeIdx = a_newCapacity;
			_entries = newEntries;

			while (begIter != endIter) {
				insert(std::move(*begIter));
				++begIter;
			}

			free(oldEntries);
		}


		static constexpr UInt8 SENTINEL[] = { (UInt8)0xDE, (UInt8)0xAD, (UInt8)0xBE, (UInt8)0xEF };
		static constexpr UInt32 MIN_CAP = 1 << 3;


		// members
		UInt64			_pad00;		// 00
		UInt32			_pad08;		// 08
		UInt32			_capacity;	// 0C - this must be 2^n, or else terrible things will happen
		UInt32			_freeCount;	// 10
		UInt32			_freeIdx;	// 14
		const Entry*	_sentinel;	// 18
		UInt64			_pad20;		// 20
		Entry*			_entries;	// 28
	};
	STATIC_ASSERT(sizeof(BSTHashMap<UInt32, void*>) == 0x30);


	// scatter table with chaining
	template <class Key, class Hash = CRC32Hash<Key>, class KeyEqual = std::equal_to<Key>>
	class BSTHashSet
	{
	public:
		using key_type = Key;
		using value_type = Key;
		using size_type = UInt32;
		using hasher = Hash;
		using key_equal = KeyEqual;


		struct Entry
		{
			Entry() :
				value(),
				next(0)
			{}


			Entry(const Entry& a_rhs) :
				value(a_rhs.value),
				next(a_rhs.next)
			{}


			Entry(Entry&& a_rhs) :
				value(std::move(a_rhs.value)),
				next(std::move(a_rhs.next))
			{
				a_rhs.next = 0;
			}


			Entry& operator=(const Entry& a_rhs)
			{
				value = a_rhs.value;
				next = a_rhs.next;
				return *this;
			}


			Entry& operator=(Entry&& a_rhs)
			{
				value = std::move(a_rhs.value);

				next = std::move(a_rhs.next);
				a_rhs.next = 0;

				return *this;
			}


			value_type value;	// 00
			Entry* next;		// ??
		};


		template <class U>
		struct iterator_base
		{
		public:
			using difference_type = std::ptrdiff_t;
			using value_type = U;
			using pointer = U *;
			using reference = U &;
			using iterator_category = std::forward_iterator_tag;


			iterator_base() :
				_entry(0),
				_end(0)
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


			iterator_base(Entry* a_entry, Entry* a_end) :
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


			[[nodiscard]] pointer operator->() const
			{
				assert(_entry != _end);
				return std::addressof(_entry->value);
			}


			[[nodiscard]] bool operator==(const iterator_base& a_rhs) const
			{
				assert(_end == a_rhs._end);
				return _entry == a_rhs._entry;
			}


			[[nodiscard]] bool operator!=(const iterator_base& a_rhs) const
			{
				assert(_end == a_rhs._end);
				return !operator==(a_rhs);
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
			Entry* _entry;
			Entry* _end;
		};


		using iterator = iterator_base<value_type>;
		using const_iterator = iterator_base<const value_type>;


		BSTHashSet() :
			_pad00(0),
			_pad08(0),
			_capacity(0),
			_freeCount(0),
			_freeIdx(0),
			_sentinel((const Entry*)SENTINEL),
			_pad20(0),
			_entries(0)
		{}


		TES_HEAP_REDEFINE_NEW();


		iterator begin()
		{
			return _entries ? make_iterator(_entries) : iterator();
		}


		const_iterator begin() const
		{
			return _entries ? make_iterator(_entries) : const_iterator();
		}


		const_iterator cbegin() const
		{
			return begin();
		}


		iterator end()
		{
			return _entries ? make_iterator(_entries + _capacity) : iterator();
		}


		const_iterator end() const
		{
			return _entries ? make_iterator(_entries + _capacity) : const_iterator();
		}


		const_iterator cend() const
		{
			return end();
		}


		[[nodiscard]] bool empty() const
		{
			return !_entries || _freeCount == 0;
		}


		size_type size() const
		{
			return _capacity - _freeCount;
		}


		std::pair<iterator, bool> insert(const value_type& a_value)
		{
			return insert_impl(a_value);
		}


		std::pair<iterator, bool> insert(value_type&& a_value)
		{
			return insert_impl(std::move(a_value));
		}


		size_type erase(const key_type& a_key)
		{
			if (!_entries) {	// no entries
				return 0;
			}

			auto entry = calc_pos(a_key);
			if (!entry->next) {	// key not in table
				return 0;
			}

			Entry* tail = 0;
			while (!comp_key(entry->value, a_key)) {	// find key in table
				tail = entry;
				entry = entry->next;
				if (entry == _sentinel) {
					return 0;
				}
			}

			entry->value.~value_type();

			if (entry->next == _sentinel) {	// if no chain
				if (tail) {
					tail->next = _sentinel;
				}
				entry->next = 0;
			} else {	// else move next entry into current
				new(entry) Entry(std::move(*entry->next));
			}

			++_freeCount;
			return 1;
		}


		iterator find(const Key& a_key)
		{
			auto entry = find_impl(a_key);
			return entry ? make_iterator(entry) : end();
		}


		const_iterator find(const Key& a_key) const
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
			UInt32 leftShifts = 0;
			while ((a_count & TOP) == 0) {
				a_count <<= 1;
				++leftShifts;
			}
			auto bitPos = 31 - leftShifts;
			auto newCount = static_cast<UInt32>(1 << bitPos);
			grow(newCount);
		}

	private:
		Entry* find_impl(const Key& a_key) const
		{
			if (!_entries) {
				return 0;
			}

			auto probe = calc_pos(a_key);	// try ideal pos
			if (!probe->next) {
				return 0;	// nothing there
			}

			do {
				if (comp_key(probe->value, a_key)) {
					return probe;
				} else {
					probe = probe->next;
				}
			} while (probe != _sentinel);	// follow chain

			return 0;
		}


		template <class Arg>
		std::pair<iterator, bool> insert_impl(Arg&& a_value)
		{
			if (!_entries || !_freeCount) {
				if (!grow()) {
					return std::make_pair(end(), false);
				}
			}

			auto idealEntry = calc_pos(a_value);
			if (!idealEntry->next) {	// if slot empty
				new(std::addressof(idealEntry->value)) value_type(std::forward<Arg>(a_value));
				idealEntry->next = const_cast<Entry*>(_sentinel);
				return std::make_pair(make_iterator(idealEntry), true);
			}

			for (auto iter = idealEntry; iter != _sentinel; iter = iter->next) {
				if (comp_key(iter->value, a_value)) {	// if entry already in table
					return std::make_pair(make_iterator(iter), false);
				}
			}

			auto freeEntry = get_free_entry();

			auto takenIdealEntry = calc_pos(idealEntry->value);
			if (takenIdealEntry == idealEntry) {	// if entry occupying our slot would've hashed here anyway
				freeEntry->next = idealEntry->next;
				idealEntry->next = freeEntry;
				new(std::addressof(freeEntry->value)) value_type(std::forward<Arg>(a_value));
				return std::make_pair(make_iterator(freeEntry), true);
			}

			while (takenIdealEntry->next != idealEntry) {	// find entry that links here
				takenIdealEntry = takenIdealEntry->next;
			}

			// move taken slot out, so we can move in
			new(std::addressof(freeEntry->value)) value_type(std::move(idealEntry->value));
			freeEntry->next = idealEntry->next;
			takenIdealEntry->next = freeEntry;
			new(std::addressof(idealEntry->value)) value_type(std::forward<Arg>(a_value));
			idealEntry->next = const_cast<Entry*>(_sentinel);
			return std::make_pair(make_iterator(idealEntry), true);
		}


		iterator make_iterator(Entry* a_entry)
		{
			return iterator(a_entry, _entries + _capacity);
		}


		const_iterator make_iterator(Entry* a_entry) const
		{
			return const_iterator(a_entry, _entries + _capacity);
		}


		UInt32 calc_hash(const Key& a_key) const
		{
			hasher h;
			return h(a_key);
		}


		UInt32 calc_idx(const Key& a_key) const
		{
			return calc_hash(a_key) & (_capacity - 1);	// capacity is always a factor of 2, so this is a faster modulo
		}


		Entry* calc_pos(const Key& a_key) const
		{
			return const_cast<Entry*>(_entries + calc_idx(a_key));
		}


		Entry* get_free_entry()
		{
			Entry* entry = 0;
			do {
				_freeIdx = (_capacity - 1) & (_freeIdx - 1);
				entry = _entries + _freeIdx;
			} while (entry->next);

			--_freeCount;
			return entry;
		}


		bool comp_key(const Key& a_lhs, const Key& a_rhs) const
		{
			key_equal eq;
			return eq(a_lhs, a_rhs);
		}


		bool grow()
		{
			if (_capacity == 1 << 31) {
				return false;
			}

			UInt32 newCapacity = _capacity ? _capacity << 1 : MIN_CAP;
			grow(newCapacity);
			return true;
		}


		void grow(UInt32 a_newCapacity)
		{
			auto oldEntries = _entries;
			iterator begIter = begin();
			iterator endIter = end();

			auto newEntriesSize = sizeof(Entry) * a_newCapacity;
			auto newEntries = malloc<Entry>(newEntriesSize);
			std::memset(newEntries, 0, newEntriesSize);

			_capacity = a_newCapacity;
			_freeCount = a_newCapacity;
			_freeIdx = a_newCapacity;
			_entries = newEntries;

			while (begIter != endIter) {
				insert(std::move(*begIter));
				++begIter;
			}

			free(oldEntries);
		}


		static constexpr UInt8 SENTINEL[] = { (UInt8)0xDE, (UInt8)0xAD, (UInt8)0xBE, (UInt8)0xEF };
		static constexpr UInt32 MIN_CAP = 1 << 3;


		// members
		UInt64			_pad00;		// 00
		UInt32			_pad08;		// 08
		UInt32			_capacity;	// 0C - this must be 2^n, or else terrible things will happen
		UInt32			_freeCount;	// 10
		UInt32			_freeIdx;	// 14
		const Entry*	_sentinel;	// 18
		UInt64			_pad20;		// 20
		Entry*			_entries;	// 28
	};
	STATIC_ASSERT(sizeof(BSTHashSet<UInt32, void*>) == 0x30);


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
}
