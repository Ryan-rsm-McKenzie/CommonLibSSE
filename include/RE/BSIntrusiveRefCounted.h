#pragma once

#include "RE/Memory.h"  // TES_HEAP_REDEFINE_NEW


namespace RE
{
	struct BSIntrusiveRefCounted
	{
	protected:
		template <class T>
		friend struct BSTSmartPointerIntrusiveRefCount;

	public:
		BSIntrusiveRefCounted();

		TES_HEAP_REDEFINE_NEW();

	protected:
		SInt32	IncRefCount();
		SInt32	DecRefCount();


		// members
		volatile SInt32	_refCount;	// 0
		UInt32			pad04;		// 4
	};
	STATIC_ASSERT(sizeof(BSIntrusiveRefCounted) == 0x8);
}
