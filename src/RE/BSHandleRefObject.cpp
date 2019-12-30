#include "RE/BSHandleRefObject.h"


namespace RE
{
	BSHandleRefObject::~BSHandleRefObject()
	{
		_refCount &= kMask_RefCount;
		InterlockedDecrement(&GetTotalObjectCount());
	}


	void BSHandleRefObject::DecHandleRefCount()
	{
		if ((InterlockedDecrement(&_refCount) & kMask_RefCount) == 0) {
			DeleteThis();
		}
	}


	void BSHandleRefObject::DecRefCount()
	{
		if ((InterlockedDecrement(&_refCount) & kMask_RefCount) == 0) {
			DeleteThis();
		}
	}


	UInt32 BSHandleRefObject::GetHandleRefCount() const
	{
		return _refCount & kMask_RefCount;
	}


	UInt32 BSHandleRefObject::GetRefCount() const
	{
		return _refCount & kMask_RefCount;
	}
}
