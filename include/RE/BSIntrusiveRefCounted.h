#pragma once

#include "RE/MemoryManager.h"


namespace RE
{
	struct BSIntrusiveRefCounted
	{
	public:
		friend struct BSTSmartPointerIntrusiveRefCount;


		BSIntrusiveRefCounted();

		SInt32	IncRefCount();
		SInt32	DecRefCount();

		TES_HEAP_REDEFINE_NEW();

	protected:
		// members
		volatile SInt32 _refCount;	// 0
	};
	STATIC_ASSERT(sizeof(BSIntrusiveRefCounted) == 0x4);
}
