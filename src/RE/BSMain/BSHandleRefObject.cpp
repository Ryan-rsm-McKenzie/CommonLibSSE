#include "RE/BSMain/BSHandleRefObject.h"


namespace RE
{
	BSHandleRefObject::~BSHandleRefObject()
	{
		_refCount &= kRefCountMask;
		InterlockedDecrement(&GetTotalObjectCount());
	}


	void BSHandleRefObject::DecRefCount()
	{
		if ((InterlockedDecrement(&_refCount) & kRefCountMask) == 0) {
			DeleteThis();
		}
	}


	void BSHandleRefObject::IncRefCount()
	{
		InterlockedIncrement(&_refCount);
	}


	bool BSHandleRefObject::IsHandleValid() const
	{
		return _refCount & kHandleValid;
	}


	std::uint32_t BSHandleRefObject::QRefCount() const
	{
		return _refCount & kRefCountMask;
	}
}
