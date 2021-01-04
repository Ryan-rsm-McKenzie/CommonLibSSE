#include "RE/B/BSHandleRefObject.h"

namespace RE
{
	BSHandleRefObject::~BSHandleRefObject()
	{
		_refCount &= kRefCountMask;
		stl::atomic_ref totalObjects{ *GetTotalObjectCount() };
		--totalObjects;
	}

	void BSHandleRefObject::DecRefCount()
	{
		stl::atomic_ref myRefCount{ _refCount };
		if (((--myRefCount) & kRefCountMask) == 0) {
			DeleteThis();
		}
	}

	void BSHandleRefObject::IncRefCount()
	{
		stl::atomic_ref myRefCount{ _refCount };
		++myRefCount;
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
