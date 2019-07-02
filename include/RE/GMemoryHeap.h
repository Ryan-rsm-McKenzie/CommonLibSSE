#pragma once

#include "GAtomic.h"  // GLock
#include "GList.h"  // GListNode, GList
#include "GStats.h"  // GHeapID


namespace RE
{
	struct GAllocDebugInfo;
	struct GHeapMemVisitor;
	struct GHeapSegVisitor;
	struct GStatBag;
	struct GSysAllocPaged;


	class GMemoryHeap : public GListNode<GMemoryHeap>
	{
	private:
		friend class GMemoryHeapPT;
		friend class GMemoryHeapMH;
		friend class GHeapRoot;
		friend class GHeapRootMH;

	public:
		enum class MemReportType : UInt32
		{
			kBrief,
			kSummary,
			kMedium,
			kFull,
			kSimple,
			kSimpleBrief,
			kFileSummary,
			kHeapsOnly
		};


		enum class HeapFlags : UInt32
		{
			kNone = 0,
			kThreadUnsafe = 1 << 0,
			kFastTinyBlocks = 1 << 1,
			kFixedGranularity = 1 << 2,
			kRoot = 1 << 3,
			kNoDebugInfo = 1 << 4,
			kUserDebug = 1 << 12
		};


		struct RootHeapParameters
		{
			enum RootHeapParameter : UPInt
			{
				kMinAlign = 16,
				kGranularity = 16 * 1024,
				kReserve = 16 * 1024,
				kThreshold = 256 * 1024,
				kLimit = 0
			};
		};


		struct HeapDesc
		{
		public:
			HeapDesc(HeapFlags a_flags = HeapFlags::kNone,
					 UPInt a_minAlign = 16,
					 UPInt a_granularity = 8 * 1024,
					 UPInt a_reserve = 8 * 1024,
					 UPInt a_threshold = UPINT_MAX,
					 UPInt a_limit = 0,
					 GHeapID a_heapID = GHeapID::kReserved,
					 UPInt a_arena = 0);

			void Clear();


			// members
			HeapFlags	flags;			// 00
			UInt32		pad04;			// 04
			UPInt		minAlign;		// 08
			UPInt		granularity;	// 10
			UPInt		reserve;		// 18
			UPInt		threshold;		// 20
			UPInt		limit;			// 28
			GHeapID		heapID;			// 30
			UPInt		arena;			// 38
		};
		STATIC_ASSERT(sizeof(HeapDesc) == 0x40);


		struct RootHeapDesc : public HeapDesc
		{
			RootHeapDesc();
		};
		STATIC_ASSERT(sizeof(RootHeapDesc) == 0x40);


		struct HeapInfo
		{
			HeapDesc		desc;	// 00
			GMemoryHeap*	parent;	// 40 - NULL == root heap
			char*			name;	// 48
		};
		STATIC_ASSERT(sizeof(HeapInfo) == 0x50);


		struct HeapVisitor
		{
			virtual ~HeapVisitor();															// 00

			virtual void Visit(GMemoryHeap* a_parentHeap, GMemoryHeap* a_childHeap) = 0;	// 01
		};
		STATIC_ASSERT(sizeof(HeapVisitor) == 0x8);


		struct LimitHandler
		{
			virtual ~LimitHandler();													// 00

			virtual bool OnExceedLimit(GMemoryHeap* a_heap, UPInt a_overLimit) = 0;		// 01
			virtual void OnFreeSegment(GMemoryHeap* a_heap, UPInt a_freeingSize) = 0;	// 02
		};
		STATIC_ASSERT(sizeof(LimitHandler) == 0x8);


		struct HeapTracer
		{
			virtual ~HeapTracer();																									// 00

			virtual void OnCreateHeap(const GMemoryHeap* a_heap) = 0;																// 01
			virtual void OnDestroyHeap(const GMemoryHeap* a_heap) = 0;																// 02
			virtual void OnAlloc(const GMemoryHeap* a_heap, UPInt a_size, UPInt a_align, unsigned a_sID, const void* a_ptr) = 0;	// 03
			virtual void OnRealloc(const GMemoryHeap* a_heap, const void* a_oldPtr, UPInt a_newSize, const void* a_newPtr) = 0;		// 04
			virtual void OnFree(const GMemoryHeap* a_heap, const void* a_ptr) = 0;													// 05
		};
		STATIC_ASSERT(sizeof(HeapTracer) == 0x8);


		struct RootStats
		{
		public:
			UPInt	sysMemFootprint;		// 00
			UPInt	sysMemUsedSpace;		// 08
			UPInt	pageMapFootprint;		// 10
			UPInt	pageMapUsedSpace;		// 18
			UPInt	bookkeepingFootprint;	// 20
			UPInt	bookkeepingUsedSpace;	// 28
			UPInt	debugInfoFootprint;		// 30
			UPInt	debugInfoUsedSpace;		// 38
			UPInt	userDebugFootprint;		// 40
			UPInt	userDebugUsedSpace;		// 48
		};
		STATIC_ASSERT(sizeof(RootStats) == 0x50);

	protected:
		virtual ~GMemoryHeap();																			// 00

	public:
		// add
		virtual void			CreateArena(UPInt a_arena, GSysAllocPaged* a_sysAlloc) = 0;				// 01
		virtual void			DestroyArena(UPInt a_arena) = 0;										// 02
		virtual bool			ArenaIsEmpty(UPInt a_arena) = 0;										// 03
		virtual GMemoryHeap*	CreateHeap(const char* a_name, const HeapDesc& a_desc) = 0;				// 04
		virtual void			SetLimitHandler(LimitHandler* handler) = 0;								// 05
		virtual void			SetLimit(UPInt newLimit) = 0;											// 06
		virtual void			AddRef() = 0;															// 07
		virtual void			Release() = 0;															// 08
		virtual void*			Alloc(UPInt a_size) = 0;												// 09
		virtual void*			Alloc(UPInt a_size, UPInt a_align) = 0;									// 0A
		virtual void*			Realloc(void* a_oldPtr, UPInt a_newSize) = 0;							// 0B
		virtual void			Free(void* a_ptr) = 0;													// 0C
		virtual void*			AllocAutoHeap(const void* a_this, UPInt a_size) = 0;					// 0D
		virtual void*			AllocAutoHeap(const void* a_this, UPInt a_size, UPInt a_align) = 0;		// 0E
		virtual GMemoryHeap*	GetAllocHeap(const void* a_this) = 0;									// 0F
		virtual UPInt			GetUsableSize(const void* a_ptr) = 0;									// 10
		virtual void*			AllocSysDirect(UPInt a_size) = 0;										// 11
		virtual void			FreeSysDirect(void* a_ptr, UPInt a_size) = 0;							// 12
		virtual bool			GetStats(GStatBag* a_bag) = 0;											// 13
		virtual UPInt			GetFootprint() const = 0;												// 14
		virtual UPInt			GetTotalFootprint() const = 0;											// 15
		virtual UPInt			GetUsedSpace() const = 0;												// 16
		virtual UPInt			GetTotalUsedSpace() const = 0;											// 17
		virtual void			GetRootStats(RootStats* a_stats) = 0;									// 18
		virtual void			VisitMem(GHeapMemVisitor* a_visitor, UInt32 a_flags) = 0;				// 19
		virtual void			VisitRootSegments(GHeapSegVisitor* a_visitor) = 0;						// 1A
		virtual void			VisitHeapSegments(GHeapSegVisitor* a_visitor) const = 0;				// 1B
		virtual void			SetTracer(HeapTracer* a_tracer) = 0;									// 1C - { return; }

	protected:
		virtual void			DestroyItself() = 0;													// 1D
		virtual void			UltimateCheck_Internal() = 0;											// 1E - { return; }
		virtual void			ReleaseCachedMem() = 0;													// 1F
		virtual bool			DumpMemoryLeaks_Internal() = 0;											// 20 - { return false; }
		virtual void			CheckIntegrity_Internal() const = 0;									// 21
		virtual void			GetUserDebugStats(RootStats* a_stats) const = 0;						// 22

	public:
		GMemoryHeap*			CreateHeap(const char* a_name,
										   HeapFlags a_flags = HeapFlags::kNone,
										   UPInt a_minAlign = 16,
										   UPInt a_granularity = 16 * 1024,
										   UPInt a_reserve = 16 * 1024,
										   UPInt a_threshold = UPINT_MAX,
										   UPInt a_limit = 0,
										   GHeapID a_heapID = GHeapID::kReserved,
										   UPInt a_arena = 0);

		void					GetHeapInfo(HeapInfo* a_info) const;
		const char*				GetName() const;
		GHeapID					GetID() const;
		GMemoryHeap*			GetParentHeap() const;
		HeapFlags				GetFlags() const;
		UPInt					GetGranularity() const;
		UPInt					GetLimit() const;
		bool					IsThreadSafe() const;
		void					ReleaseOnFree(void* a_ptr);
		void					AssignToCurrentThread();
		bool					DumpMemoryLeaks();
		void					UltimateCheck();
		void					CheckIntegrity();

	protected:
		using ChildListType = GList<GMemoryHeap>;


		// members
		UPInt			_selfSize;			// 18
		volatile UInt32	_refCount;			// 20
		UInt32			_pad24;				// 24
		UPInt			_ownerThreadID;		// 28
		void*			_autoRelease;		// 30 - auto frees heap when freed
		HeapInfo		_info;				// 38
		ChildListType	_childHeaps;		// 88
		mutable GLock	_heapLock;			// 98
		bool			_useLocks;			// C0
		bool			_trackDebugInfo;	// C1
		UInt16			_padC2;				// C2
		UInt32			_padC4;				// C4
		void*			_unkC8;				// C8
		void*			_unkD0;				// D0
	};
	STATIC_ASSERT(sizeof(GMemoryHeap) == 0xD8);
}
