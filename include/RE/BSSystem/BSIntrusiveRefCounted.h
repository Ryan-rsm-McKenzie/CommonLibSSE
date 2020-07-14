#pragma once

#include "RE/Memory/MemoryManager.h"


namespace RE
{
	struct BSIntrusiveRefCounted
	{
	public:
		template <class>
		friend struct BSTSmartPointerIntrusiveRefCount;

		constexpr BSIntrusiveRefCounted() noexcept :
			_refCount(0)
		{}

		inline UInt32 IncRef() { return InterlockedIncrement(&_refCount); }
		inline UInt32 DecRef() { return InterlockedDecrement(&_refCount); }

		TES_HEAP_REDEFINE_NEW();

	protected:
		// members
		volatile UInt32 _refCount;	// 0
	};
	STATIC_ASSERT(sizeof(BSIntrusiveRefCounted) == 0x4);
}
