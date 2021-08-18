#include "RE/G/GMemoryHeap.h"

namespace RE
{
	GMemoryHeap::HeapDesc::HeapDesc(HeapFlags a_flags, UPInt a_minAlign, UPInt a_granularity, UPInt a_reserve, UPInt a_threshold, UPInt a_limit, GHeapID a_heapID, UPInt a_arena) :
		flags(a_flags),
		pad04(0),
		minAlign(a_minAlign),
		granularity(a_granularity),
		reserve(a_reserve),
		threshold(a_threshold),
		limit(a_limit),
		heapID(a_heapID),
		arena(a_arena)
	{}

	void GMemoryHeap::HeapDesc::Clear()
	{
		flags = HeapFlags::kNone;
		granularity = 0;
		minAlign = 16;
		reserve = 0;
		threshold = UPINT_MAX;
		limit = 0;
		heapID = GHeapID::kReserved;
		arena = 0;
	}

	GMemoryHeap::RootHeapDesc::RootHeapDesc() :
		HeapDesc(HeapFlags::kNone,
			RootHeapParameters::kMinAlign,
			RootHeapParameters::kGranularity,
			RootHeapParameters::kReserve,
			RootHeapParameters::kThreshold,
			RootHeapParameters::kLimit,
			GHeapID::kGlobal)
	{}

	GMemoryHeap::HeapVisitor::~HeapVisitor()
	{}

	GMemoryHeap::LimitHandler::~LimitHandler()
	{}

	GMemoryHeap::HeapTracer::~HeapTracer()
	{}

	GMemoryHeap::~GMemoryHeap()
	{}

	GMemoryHeap* GMemoryHeap::CreateHeap(const char* a_name, HeapFlags a_flags, UPInt a_minAlign, UPInt a_granularity, UPInt a_reserve, UPInt a_threshold, UPInt a_limit, GHeapID a_heapID, UPInt a_arena)
	{
		return CreateHeap(a_name, { a_flags, a_minAlign, a_granularity, a_reserve, a_threshold, a_limit, a_heapID, a_arena });
	}

	void GMemoryHeap::GetHeapInfo(HeapInfo* a_info) const
	{
		a_info->desc = _info.desc;
		a_info->parent = _info.parent;
		a_info->name = _info.name;
	}

	const char* GMemoryHeap::GetName() const
	{
		return _info.name;
	}

	GHeapID GMemoryHeap::GetID() const
	{
		return _info.desc.heapID;
	}

	GMemoryHeap* GMemoryHeap::GetParentHeap() const
	{
		return _info.parent;
	}

	GMemoryHeap::HeapFlags GMemoryHeap::GetFlags() const
	{
		return *_info.desc.flags;
	}

	UPInt GMemoryHeap::GetGranularity() const
	{
		return _info.desc.granularity;
	}

	UPInt GMemoryHeap::GetLimit() const
	{
		return _info.desc.limit;
	}

	bool GMemoryHeap::IsThreadSafe() const
	{
		return _info.desc.flags.none(HeapFlags::kThreadUnsafe);
	}

	void GMemoryHeap::ReleaseOnFree(void* a_ptr)
	{
		_autoRelease = a_ptr;
	}

	void GMemoryHeap::AssignToCurrentThread()
	{
		assert(_ownerThreadID == 0 || _ownerThreadID == WinAPI::GetCurrentThreadID());
		_ownerThreadID = WinAPI::GetCurrentThreadID();
	}

	bool GMemoryHeap::DumpMemoryLeaks()
	{
		return DumpMemoryLeaks_Internal();
	}

	void GMemoryHeap::UltimateCheck()
	{
		return UltimateCheck_Internal();
	}

	void GMemoryHeap::CheckIntegrity()
	{
		return CheckIntegrity_Internal();
	}
}
