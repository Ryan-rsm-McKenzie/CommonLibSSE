#pragma once

#include "RE/M/MemoryManager.h"

namespace RE
{
	struct BSIntrusiveRefCounted
	{
	public:
		template <class>
		friend struct BSTSmartPointerIntrusiveRefCount;

		std::uint32_t IncRef() const
		{
			stl::atomic_ref myRefCount{ _refCount };
			return ++myRefCount;
		}

		std::uint32_t DecRef() const
		{
			stl::atomic_ref myRefCount{ _refCount };
			return --myRefCount;
		}

		TES_HEAP_REDEFINE_NEW();

	protected:
		// members
		mutable volatile std::uint32_t _refCount{ 0 };  // 0
	};
	static_assert(sizeof(BSIntrusiveRefCounted) == 0x4);
}
