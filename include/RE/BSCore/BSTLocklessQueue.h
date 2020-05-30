#pragma once


namespace RE
{
	struct BSTLocklessQueue
	{
		template <class T, UInt32 SIZE, UInt32 UNKNOWN>
		class PtrMultiProdCons
		{
			T*				data[SIZE];	 // 00
			volatile UInt32 start;		 // 08
			volatile UInt32 fetched;	 // 0C
			volatile UInt32 end;		 // 10
			volatile UInt32 allocated;	 // 14
		};
		STATIC_ASSERT(sizeof(PtrMultiProdCons<void*, 1, 1>) == 0x18);


		template <class QueueContainer, class T, UInt32 SIZE, UInt32 UNKNOWN>
		struct ObjQueueBase
		{
			T			   data[SIZE];	// 00
			QueueContainer queued;		// ??
			QueueContainer free;		// ??
		};


		template <class T, UInt32 SIZE, UInt32 UNKNOWN>
		class ObjMultiProdCons : public ObjQueueBase<PtrMultiProdCons<T, SIZE * 2, UNKNOWN>, T, SIZE, UNKNOWN>
		{};
	};
}
