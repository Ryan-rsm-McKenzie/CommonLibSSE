#pragma once

#include "RE/TESMemoryManager.h"  // TES_HEAP_REDEFINE_NEW


namespace RE
{
	struct BSIntrusiveRefCounted
	{
	public:
		template <class T> friend struct BSTSmartPointerIntrusiveRefCount;


		BSIntrusiveRefCounted();

		SInt32	IncRefCount();
		SInt32	DecRefCount();

		TES_HEAP_REDEFINE_NEW();


		// members
		volatile SInt32 _refCount;	// 0
	};
	STATIC_ASSERT(sizeof(BSIntrusiveRefCounted) == 0x4);
}
