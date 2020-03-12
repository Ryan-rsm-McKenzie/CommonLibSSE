#pragma once


namespace RE
{
	template <class T>
	struct BSTFreeListElem
	{
		char				elem[sizeof(T)];  // 00
		BSTFreeListElem<T>* next;			  // ??
	};
	// size == sizeof(T) + 0x8


	template <class T>
	class BSTFreeList
	{
	public:
		virtual ~BSTFreeList();	 // 00


		// members
		UInt32				lock;	// 08
		UInt32				pad0C;	// 0C
		BSTFreeListElem<T>* free;	// 10
	};
	STATIC_ASSERT(sizeof(BSTFreeList<void*>) == 0x18);


	template <class T, std::size_t SIZE>
	class BSTStaticFreeList : public BSTFreeList<T>
	{
		virtual ~BSTStaticFreeList();  // 00


		// members
		BSTFreeListElem<T> elems[SIZE];	 // 18
	};
	// size == 0x18 + sizeof(BSTFreeListElem<T>) * SIZE
}
