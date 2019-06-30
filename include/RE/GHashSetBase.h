#pragma once

#include <cassert>  // assert

#include "RE/GFixedSizeHash.h"  // GFixedSizeHash
#include "RE/GHashAllocator.h"  // GAllocatorGH
#include "RE/GHashsetCachedEntry.h"  // GHashsetCachedEntry
#include "GMath.h"  // gfchop, glog2f
#include "RE/GMemory.h"  // GFC_MEMORY_REDEFINE_NEW


namespace RE
{
	template <
		class C,
		class HashF = GFixedSizeHash<C>,
		class AltHashF = HashF,
		class Allocator = GAllocatorGH<C>,
		class Entry = GHashsetCachedEntry<C, HashF>
	> class GHashSetBase
	{
	public:
		using SelfType = GHashSetBase<C, HashF, AltHashF, Allocator, Entry>;


		struct const_iterator
		{
		public:
			const_iterator() :
				hash(0),
				index(0)
			{}


			const C& operator*() const
			{
				assert(index >= 0 && index <= (SPInt)hash->table->sizeMask);
				return hash->E(index).value;
			}


			const C* operator->() const
			{
				assert(index >= 0 && index <= (SPInt)hash->table->sizeMask);
				return &hash->E(index).value;
			}


			void operator++()
			{
				if (index <= (SPInt)hash->table->sizeMask) {
					++index;
					while ((UPInt)index <= hash->table->sizeMask && hash->E(index).IsEmpty()) {
						++index;
					}
				}
			}


			bool operator==(const const_iterator& a_it) const
			{
				if (IsEnd() && a_it.IsEnd()) {
					return true;
				} else {
					return (hash == a_it.hash) && (index == a_it.index);
				}
			}


			bool operator!=(const const_iterator& a_it) const
			{
				return !(*this == a_it);
			}


			bool IsEnd() const
			{
				return (!hash) || (!hash->table) || (index > (SPInt)hash->table->sizeMask);
			}

		protected:
			friend class GHashSetBase<C, HashF, AltHashF, Allocator, Entry>;


			const_iterator(const SelfType* a_hash, SPInt a_index) :
				hash(a_hash),
				index(a_index)
			{}


			const SelfType*	hash;	// 00
			SPInt			index;	// 08
		};
		STATIC_ASSERT(sizeof(const_iterator) == 0x10);


		friend struct const_iterator;


		struct iterator : public const_iterator
		{
		public:
			iterator() :
				const_iterator(0, 0)
			{}


			C& operator*() const
			{
				assert(const_iterator::index >= 0 && const_iterator::index <= (SPInt)const_iterator::hash->table->sizeMask);
				return const_cast<SelfType*>(const_iterator::hash)->E(const_iterator::index).value;
			}


			C* operator->() const
			{
				return &(operator*());
			}


			void Remove()
			{
				SelfType* theHash = const_cast<SelfType*>(const_iterator::hash);
				Entry* ee = &theHash->E(const_iterator::index);
				const C& key = ee->value;

				UPInt hashValue = AltHashF()(key);
				SPInt index = hashValue & hash->table->sizeMask;

				Entry* entry = &hash->E(index);

				if (entry->IsEmpty() || (entry->GetCachedHash(hash->table->sizeMask) != (UPInt)index)) {
					return;
				}

				SPInt naturalIndex = index;
				SPInt prevIndex = -1;

				while ((entry->GetCachedHash(hash->table->sizeMask) != (UPInt)naturalIndex) || !(entry->value == key)) {
					prevIndex = index;
					index = entry->nextInChain;
					if (index == -1) {
						return;
					}
					entry = &phash->E(index);
				}

				if (index == (SPInt)const_iterator::index) {
					if (naturalIndex == index) {
						if (!entry->IsEndOfChain()) {
							Entry* nextEntry = &phash->E(entry->nextInChain);
							entry->Clear();
							new (entry) Entry(*nextEntry);
							entry = nextEntry;
							--const_iterator::index;
						}
					} else {
						phash->E(prevIndex).NextInChain = entry->NextInChain;
					}

					entry->Clear();
					--(hash->table->entryCount);
				} else {
					assert(false);
				}
			}

		private:
			friend class GHashSetBase<C, HashF, AltHashF, Allocator, Entry>;

			iterator(SelfType* a_hash, SPInt a_idx) :
				const_iterator(a_hash, a_idx)
			{}
		};


		friend struct iterator;


		GHashSetBase() :
			table(0)
		{}


		GHashSetBase(SInt32 a_sizeHint) :
			table(0)
		{
			SetCapacity(this, a_sizeHint);
		}


		explicit GHashSetBase(void* a_memAddr) :
			table(0)
		{}


		GHashSetBase(void* a_memAddr, SInt32 a_sizeHint) :
			table(0)
		{
			SetCapacity(a_memAddr, a_sizeHint);
		}


		GHashSetBase(const SelfType& a_src) :
			table(0)
		{
			Assign(this, a_src);
		}


		~GHashSetBase()
		{
			if (table) {
				// Delete the entries.
				for (UPInt i = 0, n = table->sizeMask; i <= n; i++) {
					Entry* entry = &E(i);
					if (!entry->IsEmpty()) {
						entry->Free();
					}
				}

				Allocator::Free(table);
				table = 0;
			}
		}


		GFC_MEMORY_REDEFINE_NEW(GHashSetBase, Allocator::kStatID);


		void Assign(void* a_memAddr, const SelfType& a_src)
		{
			Clear();
			if (a_src.IsEmpty() == false) {
				SetCapacity(a_memAddr, a_src.GetSize());
				for (const_iterator it = a_src.Begin(); it != a_src.End(); ++it) {
					Add(a_memAddr, *it);
				}
			}
		}


		void Clear()
		{
			if (table) {
				for (UPInt i = 0, n = table->sizeMask; i <= n; i++) {
					Entry* entry = &E(i);
					if (!entry->IsEmpty()) {
						entry->Clear();
					}
				}

				Allocator::Free(table);
				table = 0;
			}
		}


		bool IsEmpty() const
		{
			return !table || table->entryCount == 0;
		}


		template <class CRef>
		void Set(void* a_memAddr, const CRef& a_key)
		{
			UPInt hashValue = HashF()(a_key);
			SPInt index = static_cast<SPInt>(-1);

			if (table) {
				index = FindIndexCore(a_key, hashValue & table->sizeMask);
			}

			if (index >= 0) {
				E(index).value = a_key;
			} else {
				Add(a_memAddr, a_key, hashValue);
			}
		}


		template <class CRef>
		inline void Add(void* a_memAddr, const CRef& a_key)
		{
			UPInt hashValue = HashF()(a_key);
			Add(a_memAddr, a_key, hashValue);
		}


		template <class K>
		void RemoveAlt(const K& a_key)
		{
			if (!table) {
				return;
			}

			UPInt hashValue = AltHashF()(a_key);
			SPInt index = hashValue & table->sizeMask;

			Entry* entry = &E(index);

			if (entry->IsEmpty() || (entry->GetCachedHash(table->sizeMask) != (UPInt)index)) {
				return;
			}

			// Save index
			SPInt naturalIndex = index;
			SPInt prevIndex = -1;

			while ((entry->GetCachedHash(table->sizeMask) != (UPInt)naturalIndex) || !(entry->value == a_key)) {
				prevIndex = index;
				index = entry->nextInChain;
				if (index == -1) {
					return;
				}
				entry = &E(index);
			}

			if (naturalIndex == index) {
				if (!entry->IsEndOfChain()) {
					Entry* nextEntry = &E(entry->nextInChain);
					entry->Clear();
					new (entry) Entry(*nextEntry);
					entry = nextEntry;
				}
			} else {
				E(prevIndex).nextInChain = entry->nextInChain;
			}

			entry->Clear();
			--(table->entryCount);
		}


		template <class CRef>
		void Remove(const CRef& a_key)
		{
			RemoveAlt(a_key);
		}


		template <class K>
		C* Get(const K& a_key)
		{
			SPInt index = FindIndex(a_key);
			if (index >= 0) {
				return &E(index).value;
			} else {
				return 0;
			}
		}


		template<class K>
		const C* Get(const K& key) const
		{
			SPInt index = FindIndex(key);
			if (index >= 0) {
				return &E(index).value;
			} else {
				return 0;
			}
		}


		template <class K>
		const C* GetAlt(const K& a_key) const
		{
			SPInt index = FindIndexAlt(a_key);
			if (index >= 0) {
				return &E(index).value;
			} else {
				return 0;
			}
		}


		template <class K>
		C* GetAlt(const K& a_key)
		{
			SPInt   index = FindIndexAlt(a_key);
			if (index >= 0)
				return &E(index).value;
			return 0;
		}


		template <class K>
		bool GetAlt(const K& a_key, C* a_val) const
		{
			SPInt index = FindIndexAlt(a_key);
			if (index >= 0) {
				if (a_val) {
					*a_val = E(index).value;
				}
				return true;
			} else {
				return false;
			}
		}


		UPInt GetSize() const
		{
			return table ? 0 : (UPInt)table->entryCount;
		}


		void CheckExpand(void* a_memAddr)
		{
			if (!table) {
				SetRawCapacity(a_memAddr, HashMinSize);
			} else if (table->entryCount * 5 > (table->sizeMask + 1) * 4) {
				SetRawCapacity(a_memAddr, (table->sizeMask + 1) * 2);
			}
		}


		void Resize(void* a_memAddr, UPInt a_count)
		{
			SetCapacity(a_memAddr, a_count);
		}


		void SetCapacity(void* a_memAddr, UPInt a_newSize)
		{
			UPInt newRawSize = (a_newSize * 5) / 4;
			if (newRawSize <= GetSize()) {
				return;
			}
			SetRawCapacity(a_memAddr, newRawSize);
		}


		iterator begin()
		{
			if (table == 0) {
				return iterator(0, 0);
			}

			UPInt idx = 0;
			while (idx <= table->sizeMask && E(idx).IsEmpty()) {
				++idx;
			}
			return iterator(this, idx);
		}


		iterator end()
		{
			return iterator(0, 0);
		}


		const_iterator begin() const
		{
			return const_cast<SelfType*>(this)->Begin();
		}


		const_iterator end() const
		{
			return const_cast<SelfType*>(this)->End();
		}


		template <class K>
		iterator Find(const K& a_key)
		{
			SPInt index = FindIndex(a_key);
			if (index >= 0) {
				return iterator(this, index);
			}
			return iterator(0, 0);
		}


		template <class K>
		iterator FindAlt(const K& a_key)
		{
			SPInt index = FindIndexAlt(a_key);
			if (index >= 0) {
				return iterator(this, index);
			}
			return iterator(0, 0);
		}


		template <class K>
		const_iterator Find(const K& a_key) const
		{
			return const_cast<SelfType*>(this)->Find(a_key);
		}


		template <class K>
		const_iterator FindAlt(const K& a_key) const
		{
			return const_cast<SelfType*>(this)->FindAlt(a_key);
		}

	private:
		enum { HashMinSize = 8 };


		struct TableType
		{
			UPInt	entryCount;	// 00
			UPInt	sizeMask;	// 08
			//Entry	entries[0];	// 10
		};
		STATIC_ASSERT(sizeof(TableType) == 0x10);


		template <class K>
		SPInt FindIndex(const K& a_key) const
		{
			if (!table) {
				return -1;
			}
			UPInt hashValue = HashF()(a_key) & table->sizeMask;
			return FindIndexCore(a_key, hashValue);
		}


		template <class K>
		SPInt FindIndexAlt(const K& a_key) const
		{
			if (!table) {
				return -1;
			}
			UPInt hashValue = AltHashF()(a_key) & table->sizeMask;
			return FindIndexCore(a_key, hashValue);
		}


		template <class K>
		SPInt FindIndexCore(const K& a_key, UPInt a_hashValue) const
		{
			assert(table);
			assert((a_hashValue & ~table->sizeMask) == 0);

			UPInt index = a_hashValue;
			const Entry* entry = &E(index);

			if (entry->IsEmpty() || (entry->GetCachedHash(table->sizeMask) != index)) {
				return -1;
			}

			for (;;) {
				assert(entry->GetCachedHash(table->sizeMask) == a_hashValue);
				if (entry->GetCachedHash(table->sizeMask) == a_hashValue && entry->value == a_key) {
					return index;
				}
				assert(!(entry->value == a_key));

				index = entry->nextInChain;
				if (index == (UPInt)-1) {
					break;
				}

				entry = &E(index);
				assert(!entry->IsEmpty());
			}
			return -1;
		}


		template <class CRef>
		void Add(void* a_memAddr, const CRef& a_key, UPInt a_hashValue)
		{
			CheckExpand(a_memAddr);
			a_hashValue &= table->sizeMask;

			++(table->entryCount);

			SPInt index = a_hashValue;
			Entry* naturalEntry = &(E(index));

			if (naturalEntry->IsEmpty()) {
				new(naturalEntry) Entry(a_key, -1);
			} else {
				SPInt blankIndex = index;
				do {
					blankIndex = (blankIndex + 1) & table->sizeMask;
				} while (!E(blankIndex).IsEmpty());

				Entry* blankEntry = &E(blankIndex);

				if (naturalEntry->GetCachedHash(table->sizeMask) == (UPInt)index) {
					new(blankEntry) Entry(*naturalEntry);
					naturalEntry->value = a_key;
					naturalEntry->nextInChain = blankIndex;
				} else {
					SPInt collidedIndex = naturalEntry->GetCachedHash(table->sizeMask);
					assert(collidedIndex >= 0 && collidedIndex <= (SPInt)table->sizeMask);
					for (;;) {
						Entry* entry = &E(collidedIndex);
						if (entry->nextInChain == index) {
							new(blankEntry) Entry(*naturalEntry);
							entry->nextInChain = blankIndex;
							break;
						}
						collidedIndex = entry->nextInChain;
						assert(collidedIndex >= 0 && collidedIndex <= (SPInt)table->sizeMask);
					}

					naturalEntry->value = a_key;
					naturalEntry->nextInChain = -1;
				}
			}

			naturalEntry->SetCachedHash(a_hashValue);
		}


		Entry& E(UPInt a_index)
		{
			assert(a_index <= table->sizeMask);
			return *(((Entry*)(table + 1)) + a_index);
		}


		const Entry& E(UPInt a_index) const
		{
			assert(a_index <= table->sizeMask);
			return *(((Entry*)(table + 1)) + a_index);
		}


		void SetRawCapacity(void* a_heapAddr, UPInt a_newSize)
		{
			if (a_newSize == 0) {
				Clear();
				return;
			}

			if (a_newSize < HashMinSize) {
				a_newSize = HashMinSize;
			} else {
				int bits = gfchop(glog2f((float)(a_newSize - 1)) + 1);
				a_newSize = UPInt(1) << bits;
			}

			SelfType newHash;
			newHash.table = static_cast<TableType*>(Allocator::Alloc(sizeof(TableType) + sizeof(Entry) * a_newSize));
			assert(newHash.table);

			newHash.table->entryCount = 0;
			newHash.table->sizeMask = a_newSize - 1;
			UPInt i;
			UPInt n;

			for (i = 0; i < a_newSize; i++) {
				newHash.E(i).nextInChain = -2;
			}

			if (table) {
				for (i = 0, n = table->sizeMask; i <= n; ++i) {
					Entry* entry = &E(i);
					if (entry->IsEmpty() == false) {
						newHash.Add(a_heapAddr, entry->value);
						entry->Clear();
					}
				}
				Allocator::Free(table);
			}

			// Steal newHash's data.
			table = newHash.table;
			newHash.table = 0;
		}


		// members
		TableType* table;	// 00
	};
	// size == 0x8
}
