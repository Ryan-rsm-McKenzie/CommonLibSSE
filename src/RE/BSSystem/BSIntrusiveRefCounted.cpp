#include "RE/BSIntrusiveRefCounted.h"


namespace RE
{
	BSIntrusiveRefCounted::BSIntrusiveRefCounted() :
		_refCount(0)
	{}


	UInt32 BSIntrusiveRefCounted::IncRef()
	{
		return InterlockedIncrement(&_refCount);
	}


	UInt32 BSIntrusiveRefCounted::DecRef()
	{
		return InterlockedDecrement(&_refCount);
	}
}
