#include "RE/BSIntrusiveRefCounted.h"


namespace RE
{
	BSIntrusiveRefCounted::BSIntrusiveRefCounted() :
		_refCount(0)
	{}


	SInt32 BSIntrusiveRefCounted::IncRefCount()
	{
		return InterlockedIncrement(&_refCount);
	}


	SInt32 BSIntrusiveRefCounted::DecRefCount()
	{
		return InterlockedDecrement(&_refCount);
	}
}
