#pragma once

#include "RE/MemoryManager.h"


namespace RE
{
	struct BSIntrusiveRefCounted
	{
	public:
		template <class>
		friend struct BSTSmartPointerIntrusiveRefCount;


		BSIntrusiveRefCounted();

		UInt32 IncRef();
		UInt32 DecRef();

		TES_HEAP_REDEFINE_NEW();

	protected:
		// members
		volatile UInt32 _refCount;	// 0
	};
	STATIC_ASSERT(sizeof(BSIntrusiveRefCounted) == 0x4);
}
