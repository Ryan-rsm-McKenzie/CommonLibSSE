#pragma once

#include <cassert>  // assert
#include <cstring>  // memset
#include <utility>  // forward

#include "RE/TESMemoryManager.h"  // malloc, free


namespace RE
{
	template <class Key, class T>
	class NiTMapItem
	{
	public:
		using key_type = Key;
		using mapped_type = T;


		// members
		NiTMapItem*	next;	// 00
		key_type	key;	// 08
		mapped_type	mapped;	// ??
	};
	namespace { using TestNiTMapItem = NiTMapItem<std::uint32_t, std::uint64_t>; }
	STATIC_ASSERT(offsetof(TestNiTMapItem, next) == 0x00);
	STATIC_ASSERT(offsetof(TestNiTMapItem, key) == 0x08);
	STATIC_ASSERT(offsetof(TestNiTMapItem, mapped) == 0x10);
	STATIC_ASSERT(sizeof(TestNiTMapItem) == 0x18);


	// 20
	template <class Allocator, class Key, class T>
	class NiTMapBase
	{
	public:
		using key_type = Key;
		using mapped_type = T;
		using value_type = NiTMapItem<Key, T>;
		using size_type = UInt32;


		// 4
		struct AntiBloatAllocator : public Allocator
		{
			AntiBloatAllocator() :
				Allocator(),
				count(0)
			{}


			// members
			size_type count;	// ??
		};


		NiTMapBase(size_type a_hashSize = 37) :
			_hashSize(a_hasSize),
			_pad0C(0),
			_hashTable(0),
			_allocator()
		{
			std::size_t tableSize = sizeof(value_type*) * _hashSize;
			_hashTable = malloc<value_type**>(tableSize);
			std::memset(_hashTable, 0, tableSize);
		}


		virtual ~NiTMapBase()
		{
			clear();
			if (_hashTable) {
				free(_hashTable);
			}
		}

	protected:
		virtual	UInt32		hash_function(key_type a_key) const;										// 01 - { return a_key % _hashSize; }
		virtual	bool		key_eq(key_type a_lhs, key_type a_rhs) const;								// 02 - { return stricmp(a_lhs == a_rhs); }
		virtual	void		assign_value(value_type* a_value, key_type a_key, mapped_type a_mapped);	// 03 - { a_value->key = a_key; a_value->mapped = a_mapped; }
		virtual void		clear_value(value_type* a_value);											// 04 - { return; }
		virtual	value_type*	malloc_value() = 0;															// 05
		virtual	void		free_value(value_type* a_value) = 0;										// 06

	public:
		[[nodiscard]] bool empty() const noexcept
		{
			return _allocator.count == 0;
		}


		size_type size() const noexcept
		{
			return _allocator.count;
		}


		void clear() noexcept
		{
			for (size_type i = 0; i < _hashSize; i++) {
				while (_hashTable[i]) {
					auto elem = _hashTable[i];
					_hashTable[i] = _hashTable[i]->next;
					clear_value(elem);
					free_value(elem);
				}
			}

			_allocator.count = 0;
		}


		template <class M>
		bool insert_or_assign(key_type&& a_key, M&& a_obj)
		{
			// look up hash table location for key
			auto index = hash_function(a_key);
			auto item = _hashTable[index];

			// search list at hash table location for key
			while (item) {
				if (key_eq(a_key, item->key)) {
					// item already in hash table, set its new value
					item->val = std::forward<M>(a_obj);
					return false;
				}
				item = item->next;
			}

			// add object to beginning of list for this hash table index
			item = malloc_value();

			assert(item != 0);
			assign_value(item, std::move(a_key), std::forward<M>(a_obj));
			item->next = _hashTable[index];
			_hashTable[index] = item;
			++_allocator.count;
			return true;
		}


		size_type erase(const key_type& a_key)
		{
			// look up hash table location for key
			auto index = hash_function(a_key);
			auto item = _hashTable[index];

			// search list at hash table location for key
			if (item) {
				if (key_eq(a_key, item->key)) {
					// item at front of list, remove it
					_hashTable[index] = item->next;
					remove_value(item);
					return 1;
				} else {
					// search rest of list for item
					auto prev = item;
					auto curr = prev->next;
					while (curr && !key_eq(a_key, curr->key)) {
						prev = curr;
						curr = curr->next;
					}
					if (curr) {
						// found the item, remove it
						prev->next = curr->next;
						remove_value(curr);
						return 1;
					}
				}
			}

			return 0;
		}


		std::pair<mapped_type, bool> find(const Key& a_key) const
		{
			size_type idx = hash_function(a_key);
			for (auto iter = _hashTable[idx]; iter; iter = iter->next) {
				if (key_eq(a_key, iter->key)) {
					return std::make_pair(iter->mapped, true);
				}
			}

			return std::make_pair(mapped_type{}, false);
		}

	protected:
		inline void remove_value(value_type* a_value)
		{
			clear_value(a_value);
			free_value(a_value);
			--_allocator.count;
		}

	public:
		// members
		size_type			_hashSize;	// 08
		UInt32				_pad0C;		// 0C
		value_type**		_hashTable;	// 10 - hash table storage
		AntiBloatAllocator	_allocator;	// 18
	};
}
