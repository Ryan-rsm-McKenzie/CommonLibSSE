#pragma once

// libskyrim by himika with 64bit updates
// https://github.com/himika/libSkyrim/blob/master/Skyrim/include/Skyrim/BSCore/BSTScatterTable.h

//
// === SCATTER TABLE USING OPEN ADDRESSING ===
//
// c:_skyrim\code\tesv\bscore\BSTScatterTable.h

#include "skse64/GameAPI.h"

#include <type_traits>  // enable_if_t, is_base_of
#include <new>
#include <memory.h>	// for memcpy_s

#include "RE/CRC.h"  // CalcCRC32
#include "RE/Memory.h"  // TES_HEAP_REDEFINE_NEW
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	// 00
	template <class Key, class Enable = void>
	struct BSTScatterTableDefaultHashPolicy
	{
		using hash_type = std::uint32_t;


		inline static hash_type get_hash(const Key& a_key)
		{
			return CalcCRC32(a_key);
		}


		inline static bool is_key_equal(const Key& a_lhs, const Key& a_rhs)
		{
			return a_lhs == a_rhs;
		}
	};


	template <typename T>
	using op_c_str_t = decltype(std::declval<T>().c_str());

	template <typename T>
	using has_op_c_str = is_detected<T, op_c_str_t>;


	// Specialization for BSFixedString, BSFixedStringCI, etc
	// Requires "c_str()" to be defined
	// Be sure to include the class you want to instantiate this for, a forward delcaration will not suffice
	template <class Key>
	struct BSTScatterTableDefaultHashPolicy<Key, std::enable_if_t<has_op_c_str<Key>::value>>
	{
		using hash_type = std::uint32_t;


		inline static hash_type get_hash(const Key& a_key)
		{
			return CalcCRC32String(a_key.c_str());
		}


		inline static bool is_key_equal(const Key& a_lhs, const Key& a_rhs)
		{
			return a_lhs == a_rhs;
		}
	};


	template <typename T> using is_char_pointer = std::is_convertible<T, const char*>;
	template <typename T> using is_wchar_pointer = std::is_convertible<T, const wchar_t*>;
	template <typename T> using is_char16_pointer = std::is_convertible<T, const char16_t*>;
	template <typename T> using is_char32_pointer = std::is_convertible<T, const char32_t*>;

	template <typename T, class Enable = void> struct is_charT_pointer : std::false_type {};

	template <typename T>
	struct is_charT_pointer<T, std::enable_if_t<is_char_pointer<T>::value>> : std::true_type
	{
		using char_type = const char*;
	};

	template <typename T>
	struct is_charT_pointer<T, std::enable_if_t<is_wchar_pointer<T>::value>> : std::true_type
	{
		using char_type = const wchar_t*;
	};

	template <typename T>
	struct is_charT_pointer<T, std::enable_if_t<is_char16_pointer<T>::value>> : std::true_type
	{
		using char_type = const char16_t*;
	};

	template <typename T>
	struct is_charT_pointer<T, std::enable_if_t<is_char32_pointer<T>::value>> : std::true_type
	{
		using char_type = const char32_t*;
	};


	// Specialization for "const CharT*" types
	// Requires implicit conversion to "const CharT*" to be defined
	// Be sure to include the class you want to instantiate this for, a forward delcaration will not suffice
	template <class Key>
	struct BSTScatterTableDefaultHashPolicy<Key, std::enable_if_t<is_charT_pointer<Key>::value>>
	{
	private:
		using char_type = typename is_charT_pointer<Key>::char_type;

	public:
		using hash_type = std::uint32_t;


		inline static hash_type get_hash(const Key& a_key)
		{
			return CalcCRC32String(static_cast<char_type>(a_key));
		}


		inline static bool is_key_equal(const Key& a_lhs, const Key& a_rhs)
		{
			return a_lhs == a_rhs;
		}
	};


	template <class Key, class Value, class Enable = void>
	struct BSTScatterTableDefaultKVStorage
	{
		using key_type = Key;
		using value_type = Value;


		TES_HEAP_REDEFINE_NEW();


		inline key_type& GetKey()
		{
			return _key;
		}


		inline void SetKey(const key_type& a_key)
		{
			_key = a_key;
		}


		inline void SetKeyNew(const key_type& a_key)
		{
			new (&_key)key_type(a_key);
		}


		inline void DestroyKey()
		{
			_key.~key_type();
		}


		inline value_type& GetValue()
		{
			return _value;
		}


		inline void SetValue(const value_type& a_value)
		{
			_value = a_value;
		}


		inline void SetValueNew(const value_type& a_value)
		{
			new (&_value)value_type(a_value);
		}


		inline void DestroyValue()
		{
			_value.~value_type();
		}

	private:
		key_type	_key;
		value_type	_value;
	};


	// Specialization for TESForms
	// Be sure to include the class you want to instantiate this for, a forward delcaration will not suffice
	template <class Key, class Value>
	struct BSTScatterTableDefaultKVStorage<Key, Value, typename std::enable_if_t<std::is_base_of<TESForm, Value>::value>>
	{
		using key_type = Key;
		using value_type = Value * ;


		TES_HEAP_REDEFINE_NEW();


		inline key_type& GetKey()
		{
			return _value->formID;
		}


		inline void SetKey(const key_type& a_key)
		{
			_value->formID = a_key;
		}


		inline void SetKeyNew(const key_type& a_key)
		{
			new (&_value->formID)key_type(a_key);
		}


		inline void DestroyKey()
		{}


		inline value_type& GetValue()
		{
			return _value;
		}


		inline void SetValue(const value_type& a_value)
		{
			_value = a_value;
		}


		inline void SetValueNew(const value_type& a_value)
		{
			new (&_value)value_type(a_value);
		}


		inline void DestroyValue()
		{
			_value->~value_type();
		}

	private:
		value_type	_value;
	};


	template <class Key, class Value, template <class, class> class Storage = BSTScatterTableDefaultKVStorage>
	struct BSTScatterTableEntry : public Storage<Key, Value>
	{
	private:
		using _base_t = Storage<Key, Value>;

	public:
		BSTScatterTableEntry() :
			next(0)
		{}


		~BSTScatterTableEntry()
		{
			next = 0;
		}


		bool empty() const
		{
			return next == 0;
		}


		// members
		//Value					value;
		BSTScatterTableEntry*	next;
	};


	// 00
	template <class Entry>
	struct BSTScatterTableHeapAllocator
	{
	public:
		using entry_type = Entry;
		using key_type = typename entry_type::key_type;
		using value_type = typename entry_type::value_type;

	protected:
		static inline entry_type* Allocate(std::size_t a_num)
		{
			entry_type* entries = (entry_type*)Heap_Allocate(sizeof(entry_type)* a_num);
			if (entries) {
				entry_type* p = entries;
				while (a_num--) {
					p->next = 0;
					++p;
				}
			}
			return entries;
		}


		static inline void Free(entry_type* a_ptr)
		{
			if (a_ptr) {
				Heap_Free(a_ptr);
			}
		}


		static inline std::size_t GetRelevantSize(std::size_t a_num)
		{
			if (a_num > 0) {
				a_num = 1 << _msb(a_num - 1);
			}
			return a_num;
		}

	private:
		static inline std::size_t _msb(unsigned int a_x)
		{
			union
			{
				UInt32	as_uint32;
				float	as_float;
			} data;
			data.as_float = (float)a_x + 0.5f;

			return (data.as_uint32 >> 23) - 126;
		}
	};


	// 00
	template <class Key, class Value, template <class, class> class Storage, class HashPolicy, class Allocator, std::size_t INITIAL_TABLE_SIZE>
	struct BSTScatterTableTraits
	{
		using size_type = std::uint32_t;
		using key_type = Key;
		using value_type = Value;
		using storage_type = Storage<Key, Value>;
		using hash_policy = HashPolicy;
		using allocator_type = Allocator;

		using entry_type = typename allocator_type::entry_type;
		using hash_type = typename hash_policy::hash_type;

		const static size_type initial_table_size = INITIAL_TABLE_SIZE;
	};


	// 15
	template <class Traits>
	class BSTScatterTableKernel :
		public Traits,						// 00
		protected Traits::hash_policy		// 01
	{
	public:
		typedef typename Traits::size_type			size_type;
		typedef typename Traits::key_type			key_type;
		typedef typename Traits::value_type			value_type;
		typedef typename Traits::storage_type		storage_type;
		typedef typename Traits::hash_policy		hash_policy;
		typedef typename Traits::allocator_type		allocator_type;
		typedef typename Traits::entry_type			entry_type;
		typedef typename Traits::hash_type			hash_type;

		using hash_policy::get_hash;
		using hash_policy::is_key_equal;

		class hasher
		{
		public:
			hasher()
			{}


			hash_type operator()(const key_type& a_key) const
			{
				return hash_policy::get_hash(a_key);
			}
		};


		class key_equal
		{
		public:
			key_equal()
			{}


			bool operator()(const key_type& a_lhs, const key_type& a_rhs) const
			{
				return hash_policy::is_key_equal(a_lhs, a_rhs);
			}
		};


		bool empty() const
		{
			return size() == 0;
		}


		size_type max_size() const
		{
			return _size;
		}


		size_type size() const
		{
			return _size - _freeCount;
		}


		size_type free_count() const
		{
			return _freeCount;
		}

	protected:
		BSTScatterTableKernel() :
			_size(0),
			_freeCount(0),
			_freeOffset(0)
		{
			_eolPtr = (entry_type*)&sentinel;
		}


		inline entry_type* _entry_at(entry_type* a_entries, hash_type a_hash) const
		{
			return a_entries + (a_hash & (_size - 1));
		}


		static void _entry_new(entry_type* a_ptr, entry_type* a_next, const key_type& a_key, const value_type& a_value)
		{
			if (a_ptr) {
				a_ptr->SetKeyNew(a_key);
				a_ptr->SetValueNew(a_value);
				a_ptr->next = a_next;
			}
		}

		static inline void _entry_move(entry_type* a_to, entry_type* a_from)
		{
			memcpy_s(a_to, sizeof(*a_to), a_from, sizeof(*a_from));
		}


		void _clear(entry_type* a_entries)
		{
			if (a_entries && _size) {
				const entry_type* tail = a_entries + _size;
				for (entry_type* p = a_entries; p < tail; ++p) {
					if (!p->empty()) {
						p->~entry_type();
					}
				}
				_freeCount = _freeOffset = _size;
			}
		}


		entry_type* _get_free_entry(entry_type* a_entries)
		{
			if (_freeCount == 0) {
				return 0;
			}

			entry_type* p = 0;
			while (true) {
				_freeOffset = (_freeOffset - 1) & (max_size() - 1);
				p = a_entries + _freeOffset;
				if (p->empty()) {
					break;
				}
			}

			_freeCount--;

			return p;
		}


		entry_type* _find(const entry_type* a_entries, hash_type a_hash, const key_type& a_key) const
		{
			if (!a_entries) {
				return 0;
			}

			entry_type* p = _entry_at(const_cast<entry_type*>(a_entries), a_hash);

			if (p->empty()) {
				return 0;
			}

			while (!is_key_equal(p->GetKey(), a_key)) {
				p = p->next;
				if (p == _eolPtr) {
					p = 0;
					break;
				}
			}

			return p;
		}


		bool _insert(entry_type* a_entries, hash_type a_hash, const key_type& a_key, const value_type& a_value, UInt16& a_unk)
		{
			if (!a_entries) {
				return false;
			}

			entry_type* targetEntry = _entry_at(a_entries, a_hash);
			if (targetEntry->empty()) {
				// target entry is free
				targetEntry->SetKeyNew(a_key);
				targetEntry->SetValueNew(a_value);
				targetEntry->next = _eolPtr;
				--_freeCount;
				return true;
			}

			entry_type* p = targetEntry;
			do {
				if (is_key_equal(p->GetKey(), a_key)) {
					// already exists
					p->SetValue(a_value);
					return true;
				}
				p = p->next;
			} while (p != _eolPtr);

			entry_type* freeEntry = _get_free_entry(a_entries);
			if (!freeEntry) {
				return false;
			}

			p = _entry_at(a_entries, get_hash(targetEntry->GetKey()));
			if (p == targetEntry) {
				// hash collision
				// insert new entry after target entry
				_entry_new(freeEntry, targetEntry->next, a_key, a_value);
				targetEntry->next = freeEntry;
				return true;
			}

			// bucket overlap
			while (p->next != targetEntry) {
				p = p->next;
			}

			_entry_move(freeEntry, targetEntry);

			p->next = freeEntry;
			_entry_new(targetEntry, _eolPtr, a_key, a_value);
			return true;
		}


		entry_type* _insert(entry_type* a_entries, hash_type a_hash, const key_type& a_key)
		{
			if (!a_entries) {
				return 0;
			}

			entry_type* targetEntry = _entry_at(a_entries, a_hash);
			if (targetEntry->empty()) {
				// target entry is free
				--_freeCount;
				targetEntry->next = _eolPtr;
				targetEntry->SetKeyNew(a_key);
				return targetEntry;
			}

			entry_type* p = targetEntry;
			do {
				if (is_key_equal(p->GetKey(), a_key)) {
					// already exists
					p->DestroyValue();
					return p;
				}
				p = p->next;
			} while (p != _eolPtr);

			entry_type* freeEntry = _get_free_entry(a_entries);
			if (!freeEntry) {
				return 0;
			}

			p = _entry_at(a_entries, get_hash(targetEntry->GetKey()));
			if (p == targetEntry) {
				// hash collision
				// insert new entry after target entry
				freeEntry->next = targetEntry->next;
				targetEntry->next = freeEntry;
				p = freeEntry;
			} else {
				// bucket overlap
				while (p->next != targetEntry) {
					p = p->next;
				}
				p->next = freeEntry;

				_entry_move(freeEntry, targetEntry);

				targetEntry->next = _eolPtr;
				p = targetEntry;
			}

			p->SetKeyNew(a_key);
			return p;
		}


		bool _insert_move(entry_type* a_entries, hash_type a_hash, entry_type* a_kv)
		{
			if (!a_entries) {
				return false;
			}

			entry_type* targetEntry = _entry_at(a_entries, a_hash);
			if (targetEntry->empty()) {
				// target entry is free
				_entry_move(targetEntry, a_kv);
				targetEntry->next = _eolPtr;
				--_freeCount;
				return true;
			}

			entry_type* freeEntry = _get_free_entry(a_entries);

			entry_type* p = _entry_at(a_entries, get_hash(targetEntry->GetKey()));
			if (p == targetEntry) {
				// hash collision
				_entry_move(freeEntry, a_kv);
				freeEntry->next = targetEntry->next;
				targetEntry->next = freeEntry;
				return true;
			}

			// bucket overlap
			while (p->next != targetEntry) {
				p = p->next;
			}

			_entry_move(freeEntry, targetEntry);
			p->next = freeEntry;
			_entry_move(targetEntry, a_kv);
			targetEntry->next = _eolPtr;

			return true;
		}


		bool _erase(entry_type* a_entries, hash_type a_hash, const key_type& a_key)
		{
			if (!a_entries) {
				return false;
			}

			entry_type* targetEntry = _entry_at(a_entries, a_hash);
			if (targetEntry->empty()) {
				return false;
			}

			if (is_key_equal(targetEntry->GetKey(), a_key)) {
				entry_type* nextEntry = targetEntry->next;
				targetEntry->~entry_type();
				++_freeCount;

				if (nextEntry != _eolPtr) {
					_entry_move(targetEntry, nextEntry);
					nextEntry->next = 0;
				}
				return true;
			}

			entry_type* prevEntry = targetEntry;
			entry_type* curEntry = targetEntry->next;
			while (true) {
				if (curEntry == _eolPtr) {
					return false;		// not found
				}
				if (is_key_equal(curEntry->GetKey(), a_key)) {
					break;				// found
				}

				prevEntry = curEntry;
				curEntry = curEntry->next;
			}
			entry_type* nextEntry = curEntry->next;

			curEntry->~entry_type();
			++_freeCount;

			if (nextEntry != _eolPtr) {
				_entry_move(curEntry, nextEntry);
				nextEntry->next = 0;
			} else {
				prevEntry->next = _eolPtr;
			}

			return true;
		}


		// members
		//Traits	pad00;			// 00
	public:
		size_type	_size;			// 04
		size_type	_freeCount;		// 08
		size_type	_freeOffset;	// 0C
		entry_type*	_eolPtr;		// 10

		static UInt32 sentinel;		// DEADBEEF
	};

	template <class Traits>
	UInt32 BSTScatterTableKernel<Traits>::sentinel = 0x0EFBEADDE;	// DEADBEEF


																	//1>class BSTScatterTableBase<struct BSTScatterTableTraits<struct StringCache::Ref, class NiPointer<class BGSAttackData>, struct BSTScatterTableDefaultKVStorage, struct BSTScatterTableDefaultHashPolicy<struct StringCache::Ref>, struct BSTScatterTableHeapAllocator<struct BSTScatterTableEntry<struct StringCache::Ref, class NiPointer<class BGSAttackData>, struct BSTScatterTableDefaultKVStorage> >, 8> >	size(28) :
																	//1>	+-- -
																	//1> 0 | +-- - (base class BSTScatterTableKernel<struct BSTScatterTableTraits<struct StringCache::Ref, class NiPointer<class BGSAttackData>, struct BSTScatterTableDefaultKVStorage, struct BSTScatterTableDefaultHashPolicy<struct StringCache::Ref>, struct BSTScatterTableHeapAllocator<struct BSTScatterTableEntry<struct StringCache::Ref, class NiPointer<class BGSAttackData>, struct BSTScatterTableDefaultKVStorage> >, 8> >)
																	//1> 0	| | +-- - (base class BSTScatterTableTraits<struct StringCache::Ref, class NiPointer<class BGSAttackData>, struct BSTScatterTableDefaultKVStorage, struct BSTScatterTableDefaultHashPolicy<struct StringCache::Ref>, struct BSTScatterTableHeapAllocator<struct BSTScatterTableEntry<struct StringCache::Ref, class NiPointer<class BGSAttackData>, struct BSTScatterTableDefaultKVStorage> >, 8>)
																	//1>	| | +-- -
																	//1> 1	| | +-- - (base class BSTScatterTableDefaultHashPolicy<struct StringCache::Ref>)
																	//1>	| | +-- -
																	//1>  	| | <alignment member> (size = 3)
																	//1> 4	| | _size
																	//1> 8	| | _freeCount
																	//1>0C	| | _freeOffset
																	//1>10	| | _eolPtr
																	//1> | +-- -
																	//1>19 | +-- - (base class BSTScatterTableHeapAllocator<struct BSTScatterTableEntry<struct StringCache::Ref, class NiPointer<class BGSAttackData>, struct BSTScatterTableDefaultKVStorage> >)
																	//1> | +-- -
																	//1> | <alignment member> (size = 7)
																	//1>20 | _entries
																	//1>	+-- -

	template <class Traits>
	class BSTScatterTableBase :
		public BSTScatterTableKernel<Traits>,	// 00
		protected Traits::allocator_type		// 18
	{
	public:
		using Kernel = BSTScatterTableKernel<Traits>;

		using size_type = typename Kernel::size_type;
		using key_type = typename Kernel::key_type;
		using value_type = typename Kernel::value_type;
		using storage_type = typename Kernel::storage_type;
		using hash_policy = typename Kernel::hash_policy;
		using allocator_type = typename Kernel::allocator_type;
		using entry_type = typename Kernel::entry_type;
		using hash_type = typename Kernel::hash_type;
		using hasher = typename Kernel::hasher;
		using key_equal = typename Kernel::key_equal;

		// compile hints for GCC
		using Kernel::_size;
		using Kernel::_freeCount;
		using Kernel::_freeOffset;
		using Kernel::_eolPtr;
		using Kernel::size;
		using Kernel::max_size;
		using Kernel::empty;
		using Kernel::initial_table_size;


		class const_iterator
		{
		public:
			typedef const_iterator		_iter;
			typedef const storage_type*	pointer;
			typedef const storage_type&	reference;


			const_iterator(const BSTScatterTableBase* a_table, entry_type* a_entry) :
				_table(a_table),
				_entry(a_entry)
			{
				if (a_entry) {
					const entry_type* tail = _table->_entry_tail();
					while (_entry < tail && _entry->empty()) {
						_entry += 1;
					}
				} else {
					_entry = const_cast<entry_type*>(_table->_entry_tail());
				}
			}


			operator pointer() const
			{
				return static_cast<pointer>(_entry);
			}


			reference operator*() const
			{
				return *(pointer)*this;
			}


			pointer operator->() const
			{
				return (pointer)*this;
			}


			_iter& operator++()
			{
				const entry_type* tail = _table->_entry_tail();
				do {
					_entry += 1;
				} while (_entry < tail && _entry->empty());

				return *this;
			}


			_iter operator++(int)
			{
				_iter tmp = *this;
				++*this;
				return tmp;
			}


			_iter& operator--()
			{
				const entry_type* head = _table->_entry_head();
				do {
					_entry -= 1;
				} while (_entry >= head && _entry->empty());

				return *this;
			}


			_iter operator--(int)
			{
				_iter tmp = *this;
				--*this;
				return tmp;
			}


			bool operator==(const _iter& a_rhs) const
			{
				return (_entry == a_rhs._entry);
			}


			bool operator!=(const _iter& a_rhs) const
			{
				return (!(*this == a_rhs));
			}

		protected:
			const BSTScatterTableBase*	_table;
			entry_type*					_entry;
		};


		class iterator : public const_iterator
		{
		public:
			typedef iterator		_iter;
			typedef storage_type*	pointer;
			typedef storage_type&	reference;

			// compiler hits for GCC
			using const_iterator::_entry;


			iterator(const BSTScatterTableBase* a_table, entry_type* a_entry) :
				const_iterator(a_table, a_entry)
			{}


			operator pointer()
			{
				return static_cast<pointer>(_entry);
			}


			reference operator*()
			{
				return *(pointer)*this;
			}


			pointer operator->()
			{
				return (pointer)*this;
			}
		};


		iterator begin()
		{
			return iterator(this, _entry_head());
		}


		const_iterator begin() const
		{
			return const_iterator(this, _entry_head());
		}


		const_iterator cbegin() const
		{
			return const_iterator(this, _entry_head());
		}


		iterator end()
		{
			return iterator(this, _entry_head() + _size);
		}


		const_iterator end() const
		{
			return const_iterator(this, _entry_head() + _size);
		}


		const_iterator cend() const
		{
			return const_iterator(this, _entry_head() + _size);
		}


		hasher hash_function() const
		{
			return hasher();
		}


		key_equal key_eq() const
		{
			return key_equal();
		}


		inline void clear()
		{
			_clear(_entries);
		}

	protected:
		BSTScatterTableBase() :
			Kernel(),
			_entries(0)
		{}


		~BSTScatterTableBase()
		{
			if (_entries) {
				clear();
				Free(_entries);
			}
		}


		inline entry_type* _entry_head() const
		{
			return const_cast<entry_type*>(_entries);
		}


		inline entry_type* _entry_last() const
		{
			return _entry_head() + (max_size() - 1);
		}


		inline entry_type* _entry_tail() const
		{
			return _entry_head() + max_size();
		}


		inline entry_type* _get_free_entry()
		{
			return BSTScatterTableKernel::_get_free_entry(_entries);
		}

		// 008BF970
		void _grow_table()
		{
			size_type oldSize = _size;
			entry_type* oldEntries = _entries;

			_size = (oldSize) ? (oldSize * 2) : initial_table_size;
			_entries = (entry_type*)allocator_type::Allocate(_size);
			_freeCount = _size;
			_freeOffset = _size;

			if (_entries && _size) {
				// init entries
				entry_type* p = _entries;
				for (size_type i = _size; i; --i) {
					p->next = 0;
					++p;
				};
			}

			// move from old entries to new one
			if (oldEntries) {
				entry_type* from = oldEntries;
				for (size_type i = oldSize; i; --i) {
					if (!from->empty()) {
						hash_type hash = hash_policy::get_hash(from->GetKey());
						_insert_move(_entries, hash, from);
					}
					++from;
				}

				Heap_Free(oldEntries);
			}
		}

		void _assign(const BSTScatterTableBase& a_rhs)
		{
			if (!empty()) {
				clear();
				Free(_entries);
				_entries = 0;
			}

			if (a_rhs.empty()) {
				return;
			}

			_entries = allocator_type::Allocate(a_rhs._size);
			if (_entries) {
				_size = a_rhs._size;
				_freeCount = a_rhs._freeCount;
				_freeOffset = a_rhs._freeOffset;

				entry_type* to = _entries;
				entry_type* from = a_rhs._entries;
				std::size_t count = _size;
				while (--count) {
					if (!from->empty()) {
						to->SetKeyNew(from->GetKey());
						to->SetValueNew(from->GetValue());
						to->next = (from->next == a_rhs._eolPtr) ? _eolPtr : (_entries + (from - a_rhs._entries));
					}
					++to;
					++from;
				}
			}
		}

		void _assign(BSTScatterTableBase&& a_rhs)
		{
			if (!empty()) {
				clear();
				Free(_entries);
				_entries = 0;
			}

			_size = a_rhs._size;
			_freeCount = a_rhs._freeCount;
			_freeOffset = a_rhs._freeOffset;
			_eolPtr = a_rhs._eolPtr;
			_entries = a_rhs._entries;

			a_rhs._size = 0;
			a_rhs._freeCount = 0;
			a_rhs._freeOffset = 0;
			a_rhs._entries = 0;
		}

		// members
		//Traits			pad00;			// 00
		//size_type			_size;			// 04
		//size_type			_freeCount;		// 08
		//size_type			_freeOffset;	// 0C
		//entry_type*		_eolPtr;		// 10
		//allocator_type	pad18;			// 18
	public:
		entry_type*			_entries;		// 20
	};


	//1>class BSTScatterTable<struct StringCache::Ref, class NiPointer<class BGSAttackData>, struct BSTScatterTableDefaultKVStorage, struct BSTScatterTableDefaultHashPolicy, struct BSTScatterTableHeapAllocator, 8>	size(28) :
	//1>	+-- -
	//1> 0 | +-- - (base class BSTScatterTableBase<struct BSTScatterTableTraits<struct StringCache::Ref, class NiPointer<class BGSAttackData>, struct BSTScatterTableDefaultKVStorage, struct BSTScatterTableDefaultHashPolicy<struct StringCache::Ref>, struct BSTScatterTableHeapAllocator<struct BSTScatterTableEntry<struct StringCache::Ref, class NiPointer<class BGSAttackData>, struct BSTScatterTableDefaultKVStorage> >, 8> >)
	//1> 0	| | +-- - (base class BSTScatterTableKernel<struct BSTScatterTableTraits<struct StringCache::Ref, class NiPointer<class BGSAttackData>, struct BSTScatterTableDefaultKVStorage, struct BSTScatterTableDefaultHashPolicy<struct StringCache::Ref>, struct BSTScatterTableHeapAllocator<struct BSTScatterTableEntry<struct StringCache::Ref, class NiPointer<class BGSAttackData>, struct BSTScatterTableDefaultKVStorage> >, 8> >)
	//1> 0	| | | +-- - (base class BSTScatterTableTraits<struct StringCache::Ref, class NiPointer<class BGSAttackData>, struct BSTScatterTableDefaultKVStorage, struct BSTScatterTableDefaultHashPolicy<struct StringCache::Ref>, struct BSTScatterTableHeapAllocator<struct BSTScatterTableEntry<struct StringCache::Ref, class NiPointer<class BGSAttackData>, struct BSTScatterTableDefaultKVStorage> >, 8>)
	//1>	| | | +-- -
	//1> 1	| | | +-- - (base class BSTScatterTableDefaultHashPolicy<struct StringCache::Ref>)
	//1>	| | | +-- -
	//1>  	| | | <alignment member> (size = 3)
	//1> 4	| | | _size
	//1> 8	| | | _freeCount
	//1>0C	| | | _freeOffset
	//1>10	| | | _eolPtr
	//1>	| | +-- -
	//1>19	| | +-- - (base class BSTScatterTableHeapAllocator<struct BSTScatterTableEntry<struct StringCache::Ref, class NiPointer<class BGSAttackData>, struct BSTScatterTableDefaultKVStorage> >)
	//1>	| | +-- -
	//1>  	| | <alignment member> (size = 7)
	//1>20	| | _entries
	//1> | +-- -
	//1>	+-- -
	template <
		class Key,
		class Value,
		template <class, class> class Storage,
		template <class> class Policy,
		template <class> class Allocator,
		std::uint32_t INITIAL_TABLE_SIZE
	>
		class BSTScatterTable : public BSTScatterTableBase<BSTScatterTableTraits<Key, Value, Storage, Policy<Key>, Allocator<BSTScatterTableEntry<Key, Value, Storage>>, INITIAL_TABLE_SIZE>>
	{
	private:
		using Base = BSTScatterTableBase<BSTScatterTableTraits<Key, Value, Storage, Policy<Key>, Allocator<BSTScatterTableEntry<Key, Value, Storage>>, INITIAL_TABLE_SIZE>>;

	public:
		using size_type = typename Base::size_type;
		using key_type = typename Base::key_type;
		using value_type = typename Base::value_type;
		using storage_type = typename Base::storage_type;
		using hash_policy = typename Base::hash_policy;
		using allocator_type = typename Base::allocator_type;
		using entry_type = typename Base::entry_type;
		using hash_type = typename Base::hash_type;

		// compiler hints for GCC
		using typename Base::const_iterator;
		using typename Base::iterator;
		using Base::_size;
		using Base::_freeCount;
		using Base::_freeOffset;
		using Base::_eolPtr;
		using Base::_entries;
		using Base::size;
		using Base::max_size;
		using Base::free_count;
		using Base::empty;
		using Base::clear;
		using Base::hash_function;
		using Base::key_eq;
		using Base::cend;
		using Base::end;
		using Base::initial_table_size;
		using Base::_grow_table;
		using Base::get_hash;
		using Base::_find;


		TES_HEAP_REDEFINE_NEW();


		BSTScatterTable() :
			Base()
		{}


		BSTScatterTable(const BSTScatterTable& a_rhs) :
			Base()
		{
			_assign(a_rhs);
		}


		BSTScatterTable(BSTScatterTable&& a_rhs)
		{
			_assign(a_rhs);
		}


		BSTScatterTable& operator=(const BSTScatterTable& a_rhs)
		{
			_assign(a_rhs);
			return *this;
		}


		BSTScatterTable& operator=(BSTScatterTable&& a_rhs)
		{
			_assign(a_rhs);
			return *this;
		}


		const_iterator find(const key_type& a_key) const
		{
			entry_type* entry = _find(_entries, get_hash(a_key), a_key);
			return entry ? const_iterator(this, entry) : cend();
		}


		iterator find(const key_type& a_key)
		{
			entry_type* entry = _find(_entries, get_hash(a_key), a_key);
			return entry ? iterator(this, entry) : end();
		}


		size_type count(const key_type& a_key) const
		{
			return _find(_entries, get_hash(a_key), a_key) ? 1 : 0;
		}


		bool insert(const key_type& a_key, const value_type& a_lvalue)
		{
			hash_type hash = get_hash(a_key);
			entry_type* p = 0;

			while (!(p = _insert(_entries, hash, a_key))) {
				_grow_table();
				if (!_entries || !_freeCount) {
					return false;
				}
			}

			p->SetValueNew(a_lvalue);
			return true;
		}


		bool insert(const key_type& a_key, value_type&& a_rvalue)
		{
			hash_type hash = get_hash(a_key);
			entry_type* p = 0;

			while (!(p = _insert(_entries, hash, a_key))) {
				_grow_table();
				if (!_entries || !_freeCount) {
					return false;
				}
			}

			p->SetValueNew(a_rvalue);
			return true;
		}


		// original implementation
		bool insert(const key_type& a_key, const value_type& a_value, UInt16& a_unk)
		{
			hash_type hash = get_hash(a_key);
			while (!insert_original(_entries, hash, a_key, a_value, a_unk)) {
				_grow_table();
			}
			return true;
		}


		inline size_type erase(const key_type& a_key)
		{
			return _erase(_entries, get_hash(a_key), a_key) ? 1 : 0;
		}


		bool GetAt(key_type a_key, value_type& a_value) const
		{
			entry_type* entry = _find(_entries, get_hash(a_key), a_key);
			if (entry) {
				a_value = entry->GetValue();
				return true;
			}
			return false;
		}


		inline bool SetAt(key_type a_key, const value_type& a_lvalue)
		{
			return insert(a_key, a_lvalue);
		}


		inline bool SetAt(key_type a_key, value_type&& a_rvalue)
		{
			return insert(a_key, a_rvalue);
		}


		inline bool RemoveAt(key_type a_key)
		{
			return erase(a_key) != 0;
		}


		inline void RemoveAll()
		{
			clear();
		}


		// members
		//BSTScatterTableTraits	pad00;			// 00
		//size_type				_size;			// 04
		//size_type				_freeCount;		// 08
		//size_type				_freeOffset;	// 0C
		//entry_type*			_eolPtr;		// 10
		//allocator_type		pad18;			// 18
		//entry_type*			_entries;		// 20
	};


	//1>class BSTDefaultScatterTable<struct StringCache::Ref, class NiPointer<class BGSAttackData> >	size(28) :
	//1>	+-- -
	//1> 0 | +-- - (base class BSTScatterTable<struct StringCache::Ref, class NiPointer<class BGSAttackData>, struct BSTScatterTableDefaultKVStorage, struct BSTScatterTableDefaultHashPolicy, struct BSTScatterTableHeapAllocator, 8>)
	//1> 0	| | +-- - (base class BSTScatterTableBase<struct BSTScatterTableTraits<struct StringCache::Ref, class NiPointer<class BGSAttackData>, struct BSTScatterTableDefaultKVStorage, struct BSTScatterTableDefaultHashPolicy<struct StringCache::Ref>, struct BSTScatterTableHeapAllocator<struct BSTScatterTableEntry<struct StringCache::Ref, class NiPointer<class BGSAttackData>, struct BSTScatterTableDefaultKVStorage> >, 8> >)
	//1> 0	| | | +-- - (base class BSTScatterTableKernel<struct BSTScatterTableTraits<struct StringCache::Ref, class NiPointer<class BGSAttackData>, struct BSTScatterTableDefaultKVStorage, struct BSTScatterTableDefaultHashPolicy<struct StringCache::Ref>, struct BSTScatterTableHeapAllocator<struct BSTScatterTableEntry<struct StringCache::Ref, class NiPointer<class BGSAttackData>, struct BSTScatterTableDefaultKVStorage> >, 8> >)
	//1> 0	| | | | +-- - (base class BSTScatterTableTraits<struct StringCache::Ref, class NiPointer<class BGSAttackData>, struct BSTScatterTableDefaultKVStorage, struct BSTScatterTableDefaultHashPolicy<struct StringCache::Ref>, struct BSTScatterTableHeapAllocator<struct BSTScatterTableEntry<struct StringCache::Ref, class NiPointer<class BGSAttackData>, struct BSTScatterTableDefaultKVStorage> >, 8>)
	//1>	| | | | +-- -
	//1> 1	| | | | +-- - (base class BSTScatterTableDefaultHashPolicy<struct StringCache::Ref>)
	//1>	| | | | +-- -
	//1>  	| | | | <alignment member> (size = 3)
	//1> 4	| | | | _size
	//1> 8	| | | | _freeCount
	//1>0C	| | | | _freeOffset
	//1>10	| | | | _eolPtr
	//1>	| | | +-- -
	//1>19	| | | +-- - (base class BSTScatterTableHeapAllocator<struct BSTScatterTableEntry<struct StringCache::Ref, class NiPointer<class BGSAttackData>, struct BSTScatterTableDefaultKVStorage> >)
	//1>	| | | +-- -
	//1>  	| | | <alignment member> (size = 7)
	//1>20	| | | _entries
	//1>	| | +-- -
	//1> | +-- -
	//1>	+-- -
	//1>
	template <class Key, class Value>
	struct BSTDefaultScatterTable : public BSTScatterTable<Key, Value, BSTScatterTableDefaultKVStorage, BSTScatterTableDefaultHashPolicy, BSTScatterTableHeapAllocator, 8>
	{};


	using Test = BSTDefaultScatterTable<uint32_t, uint32_t>;

	STATIC_ASSERT(sizeof(Test) == 0x28);
}
