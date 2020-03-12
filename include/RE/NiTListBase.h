#pragma once


namespace RE
{
	template <class T>
	class NiTListItem
	{
	public:
		NiTListItem* next;	   // 00
		NiTListItem* prev;	   // 08
		T			 element;  // 10
	};
	STATIC_ASSERT(sizeof(NiTListItem<void*>) == 0x18);


	template <class Allocator, class T>
	class NiTListBase
	{
	public:
		struct AntiBloatAllocator : public Allocator
		{
			// members
			UInt32 size;  // ??
		};


		// members
		NiTListItem<T>*	   head;	   // 00
		NiTListItem<T>*	   tail;	   // 08
		AntiBloatAllocator allocator;  // 10
	};
}
