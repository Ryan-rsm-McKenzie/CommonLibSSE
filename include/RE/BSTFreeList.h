#pragma once


namespace RE
{
	template <class T>
	class BSTFreeList
	{
	public:
		struct Entry
		{
			T		item;	// 00
			Entry*	next;	// ??
		};
		// size == sizeof(T) + 0x8


		virtual ~BSTFreeList();	// 00


		// members
		UInt32	unk08;	// 08
		UInt32	unk0C;	// 0C
		Entry*	eol;	// 10
	};
	STATIC_ASSERT(sizeof(BSTFreeList<void*>) == 0x18);


	template <class T, std::size_t SIZE>
	class BSTStaticFreeList : public BSTFreeList<T>
	{
		using Entry = typename BSTFreeList<T>::Entry;


		virtual ~BSTStaticFreeList();	// 00


		// members
		Entry entries[SIZE];	// 18
	};
	// size == 0x18 + sizeof(Entry) * SIZE
}
