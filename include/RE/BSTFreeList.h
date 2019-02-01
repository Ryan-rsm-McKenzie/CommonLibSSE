#pragma once


namespace RE
{
	// Need more examples of this class instance to be able to differentiate between the class and the template
	template <typename T>
	class BSTFreeList
	{
	public:
		struct Entry
		{
			UInt32	unk00;	// 00
			UInt32	unk04;	// 04
			void*	unk08;	// 08 - memPolicy?
			T*		unk10;	// 10
			Entry*	next;	// 18
		};
		STATIC_ASSERT(sizeof(Entry) == 0x20);


		virtual ~BSTFreeList();	// 00


		// members
		UInt64	unk08;	// 08
		Entry*	eol;	// 10
	};
	STATIC_ASSERT(sizeof(BSTFreeList<void*>) == 0x18);


	template <typename T, std::size_t SIZE>
	class BSTStaticFreeList : public BSTFreeList<T>
	{
		using Entry = BSTFreeList<T>::Entry;


		virtual ~BSTStaticFreeList();	// 00


		// members
		Entry entries[SIZE];	// 18
	};
}
