#pragma once

// libskyrim by himika
// https://github.com/himika/libSkyrim/blob/master/Skyrim/include/Skyrim/BSCore/BSTHashMap.h

#include "RE/BSTScatterTable.h"


template <class Key, class Value, class Table>
struct BSTHashMapTraits
{
	typedef Table	table_type;
};


template <class Traits>
class BSTHashMapBase :
	public Traits,
	public Traits::table_type
{};


template <class Key, class Value, template <class, class> class Table = BSTDefaultScatterTable>
class BSTHashMap : public BSTHashMapBase< BSTHashMapTraits<Key, Value, Table<Key, Value>> >
{};

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
//0C	| | | | | | m_size
//10	| | | | | | m_freeCount
//14	| | | | | | m_freeOffset
//18	| | | | | | m_eolPtr
//	| | | | | +-- -
//21	| | | | | +-- - (base class BSTScatterTableHeapAllocator<struct BSTScatterTableEntry<unsigned int, unsigned int, struct BSTScatterTableDefaultKVStorage> >)
//	| | | | | +-- -
//  	| | | | | <alignment member> (size = 7)
//28	| | | | | m_entries
//	| | | | +-- -
//	| | | +-- -
//	| | +-- -
// | +-- -
//	+-- -
// verified

using TestHashMap = BSTHashMap <uint32_t, uint32_t>;

STATIC_ASSERT(offsetof(TestHashMap, m_size) == 0x0C);
STATIC_ASSERT(offsetof(TestHashMap, m_entries) == 0x28);

STATIC_ASSERT(sizeof(TestHashMap) == 0x30);
