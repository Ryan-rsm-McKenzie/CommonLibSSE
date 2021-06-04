#pragma once

namespace RE
{
	template <class T>
	struct BSTFreeListElem
	{
		char                elem[sizeof(T)];  // 00
		BSTFreeListElem<T>* next;             // ??
	};
	// size == sizeof(T) + 0x8

	template <class T>
	class BSTFreeList
	{
	public:
		virtual ~BSTFreeList();  // 00

		// members
		std::uint32_t       lock;   // 08
		std::uint32_t       pad0C;  // 0C
		BSTFreeListElem<T>* free;   // 10
	};
	static_assert(sizeof(BSTFreeList<void*>) == 0x18);

	template <class T, std::size_t SIZE>
	class BSTStaticFreeList : public BSTFreeList<T>
	{
		virtual ~BSTStaticFreeList();  // 00

		// members
		BSTFreeListElem<T> elems[SIZE];  // 18
	};
	// size == 0x18 + sizeof(BSTFreeListElem<T>) * SIZE
}
