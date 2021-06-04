#pragma once

namespace RE
{
	struct BSTLocklessQueue
	{
		template <class T, std::uint32_t SIZE, std::uint32_t UNKNOWN>
		class PtrMultiProdCons
		{
			T*                     data[SIZE];  // 00
			volatile std::uint32_t start;       // 08
			volatile std::uint32_t fetched;     // 0C
			volatile std::uint32_t end;         // 10
			volatile std::uint32_t allocated;   // 14
		};
		static_assert(sizeof(PtrMultiProdCons<void*, 1, 1>) == 0x18);

		template <class QueueContainer, class T, std::uint32_t SIZE, std::uint32_t UNKNOWN>
		struct ObjQueueBase
		{
			T              data[SIZE];  // 00
			QueueContainer queued;      // ??
			QueueContainer free;        // ??
		};

		template <class T, std::uint32_t SIZE, std::uint32_t UNKNOWN>
		class ObjMultiProdCons : public ObjQueueBase<PtrMultiProdCons<T, SIZE * 2, UNKNOWN>, T, SIZE, UNKNOWN>
		{};
	};
}
