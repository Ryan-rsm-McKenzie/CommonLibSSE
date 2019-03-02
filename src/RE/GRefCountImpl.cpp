#include "RE/GRefCountImpl.h"

#include "skse64_common/Relocation.h"  // RelocAddr

#include "RE/Offsets.h"

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
