#include "RE/GRefCountImpl.h"


namespace RE
{
	void GRefCountImpl::AddRef()
	{
		InterlockedIncrement(&_refCount);
	}


	void GRefCountImpl::Release()
	{
		if (InterlockedDecrement(&_refCount) == 0) {
			delete this;
		}
	}
}
