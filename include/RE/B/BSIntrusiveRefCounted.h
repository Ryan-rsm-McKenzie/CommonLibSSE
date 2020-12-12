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

		inline std::uint32_t IncRef() { return InterlockedIncrement(&_refCount); }
		inline std::uint32_t DecRef() { return InterlockedDecrement(&_refCount); }

		TES_HEAP_REDEFINE_NEW();

	protected:
		// members
		volatile std::uint32_t _refCount;  // 0
	};
	static_assert(sizeof(BSIntrusiveRefCounted) == 0x4);
}
