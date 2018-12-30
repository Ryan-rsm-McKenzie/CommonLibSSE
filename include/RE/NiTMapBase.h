#pragma once

#include "RE/NiMemory.h"  // NiMalloc, NiFree


namespace RE
{
	template <class TKEY, class TVAL>
	class NiTMapItem
	{
	public:
		typedef TKEY key_type;
		typedef TVAL value_type;


		// members
		NiTMapItem*	next;	// 00
		key_type	key;	// 08
		value_type	value;	// ??
	};
	using TestNiTMapItem = NiTMapItem<uint32_t, uint64_t>;
	STATIC_ASSERT(offsetof(TestNiTMapItem, next) == 0x00);
	STATIC_ASSERT(offsetof(TestNiTMapItem, key) == 0x08);
	STATIC_ASSERT(offsetof(TestNiTMapItem, value) == 0x10);
	STATIC_ASSERT(sizeof(TestNiTMapItem) == 0x18);


	template <class TheAllocator, class TKEY, class TVAL>
	class NiTMapBase
	{
	public:
		typedef TKEY					key_type;
		typedef TVAL					value_type;
		typedef NiTMapItem<TKEY, TVAL>	item_type;


		struct AntiBloatAllocator : public TheAllocator
		{
			// members
			UInt32 _count;	// 00
		};


		NiTMapBase(std::uint32_t a_hashSize = 37)
		{
			_hashSize = a_hashSize;
			_allocator._count = 0;

			std::uint32_t tableSize = sizeof(item_type*) * _hashSize;
			_hashTable = (item_type**)NiMalloc(tableSize);

			memset(_hashTable, 0, tableSize);
		}


		virtual ~NiTMapBase()
		{
			RemoveAll();
			NiFree(_hashTable);
		}

	protected:
		virtual	std::uint32_t	KeyToHashIndex(key_type a_key) const;								// 01 - return hash % _hashSize;
		virtual	bool			IsKeysEqual(key_type a_lhs, key_type a_rhs) const;					// 02 - return lhs == rhs;

		virtual	void			SetValue(item_type* a_item, key_type a_key, value_type a_value);	// 03 - item->key = key; item->value = value;
		virtual void			ClearValue(item_type* a_item);										// 04 - nop
		virtual	item_type*		NewItem() = 0;														// 05 - return new item_type;
		virtual	void			DeleteItem(item_type* a_item) = 0;									// 06 - item->value = 0; delete item;

	public:
		// counting elements in map
		UInt32 GetCount() const
		{
			return _allocator._count;
		}


		bool IsEmpty() const
		{
			return _allocator._count == 0;
		}


		// add or remove elements
		void SetAt(TKEY a_key, TVAL a_val)
		{
			// look up hash table location for key
			UInt32 index = KeyToHashIndex(a_key);
			item_type* item = _hashTable[index];

			UInt32 depth = 0;

			// search list at hash table location for key
			while (item) {
				depth++;
				if (IsKeysEqual(a_key, item->key)) {
					// item already in hash table, set its new value
					item->val = a_val;
					return;
				}
				item = item->next;
			}

			// add object to beginning of list for this hash table index
			item = (item_type*)NewItem();

			NIASSERT(item);
			SetValue(item, a_key, a_val);
			item->next = _hashTable[index];
			_hashTable[index] = item;
			_allocator._count++;
		}

		bool RemoveAt(TKEY a_key)
		{
			// look up hash table location for key
			UInt32 index = KeyToHashIndex(a_key);
			item_type* item = _hashTable[index];

			// search list at hash table location for key
			if (item) {
				if (IsKeysEqual(a_key, item->key)) {
					// item at front of list, remove it
					_hashTable[index] = item->next;
					ClearValue(item);

					DeleteItem(item);

					_allocator._count--;
					return true;
				} else {
					// search rest of list for item
					item_type* prev = item;
					item_type* curr = prev->next;
					while (curr && !IsKeysEqual(a_key, curr->key)) {
						prev = curr;
						curr = curr->next;
					}
					if (curr) {
						// found the item, remove it
						prev->next = curr->next;
						ClearValue(curr);

						DeleteItem(curr);

						_allocator._count--;
						return true;
					}
				}
			}

			return false;
		}

		void RemoveAll()
		{
			for (UInt32 i = 0; i < _hashSize; i++) {
				while (_hashTable[i]) {
					item_type* save = _hashTable[i];
					_hashTable[i] = _hashTable[i]->next;
					ClearValue(save);

					DeleteItem(save);
				}
			}

			_allocator._count = 0;
		}

		// element access
		bool GetAt(key_type a_key, value_type& a_val) const
		{
			std::uint32_t idx = KeyToHashIndex(a_key);
			for (item_type* p = _hashTable[idx]; p; p = p->next) {
				if (IsKeysEqual(a_key, p->key)) {
					a_val = p->value;
					return true;
				}
			}

			return false;
		}

		// map traversal
		//NiTMapIterator GetFirstPos() const;
		//void GetNext(NiTMapIterator& pos, TKEY& key, TVAL& val) const;

	public:
		// members
		std::uint32_t		_hashSize;		// 08
		item_type**			_hashTable;		// 10 - hash table storage
		AntiBloatAllocator	_allocator;		// 18

	private:
		NiTMapBase(const NiTMapBase&) = delete;
		NiTMapBase& operator=(const NiTMapBase&) = delete;
	};
}
