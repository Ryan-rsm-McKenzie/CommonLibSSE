#include "RE/GRefCountImpl.h"

#include <winnt.h>  // InterlockedIncrement, InterlockedDecrement


namespace RE
{
	void GRefCountImpl::AddRef()
	{
		InterlockedIncrement(&refCount);
	}


	void GRefCountImpl::Release()
	{
		if (InterlockedDecrement(&refCount) == 0) {
			delete this;
		}
	}
}
