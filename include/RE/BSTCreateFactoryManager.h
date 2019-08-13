#pragma once

#include <utility>

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/CRC.h"
#include "RE/Offsets.h"
#include "REL/Relocation.h"  // Offset


namespace RE
{
	template <class> struct IBSTCreator;


	// hash map, where entries get inlined
	template <class Key, class T, UInt32 SIZE>
	class BSTCreateFactoryManager
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
		using value_type = pair<const Key, IBSTCreator<T>*>;
		using size_type = UInt32;
		using hasher = CRC32Hash<Key>;
		using key_equal = std::equal_to<Key>;


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
				return std::make_pair(end(), false);
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


		static constexpr UInt8 SENTINEL[] = { (UInt8)0xDE, (UInt8)0xAD, (UInt8)0xBE, (UInt8)0xEF };


		// members
		UInt64			_unk00;			// 00
		UInt32			_unk08;			// 08
		UInt32			_capacity;		// 0C
		UInt32			_freeCount;		// 10
		UInt32			_freeIdx;		// 14
		const Entry*	_sentinel;		// 18
		Entry			_data[SIZE];	// 20
		Entry*			_entries;		// ??
	};


	class IUIMessageData;
	template <class, class> struct BSTDerivedCreator;


	class MessageDataFactoryManager : public BSTCreateFactoryManager<BSFixedString, IUIMessageData, 16>
	{
	private:
		using Base = BSTCreateFactoryManager<BSFixedString, IUIMessageData, 16>;

	public:
		inline static MessageDataFactoryManager* GetSingleton()
		{
			using func_t = function_type_t<decltype(&MessageDataFactoryManager::GetSingleton)>;
			REL::Offset<func_t*> func(Offset::MessageDataFactoryManager::GetSingleton);
			return func();
		}


		template <class T = IUIMessageData> inline BSTDerivedCreator<T, IUIMessageData>* GetCreator(const BSFixedString& a_type) const
		{
			auto it = Base::find(a_type);
			return it != Base::end() ? static_cast<BSTDerivedCreator<T, IUIMessageData>*>(it->second) : 0;
		}
	};
	STATIC_ASSERT(sizeof(MessageDataFactoryManager) == 0x1A8);
}
