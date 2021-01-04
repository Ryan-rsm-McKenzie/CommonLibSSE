#include "RE/G/GRefCountImpl.h"

namespace RE
{
	void GRefCountImpl::AddRef()
	{
		stl::atomic_ref myRefCount{ _refCount };
		++myRefCount;
	}

	void GRefCountImpl::Release()
	{
		stl::atomic_ref myRefCount{ _refCount };
		if (--myRefCount == 0) {
			delete this;
		}
	}
}
