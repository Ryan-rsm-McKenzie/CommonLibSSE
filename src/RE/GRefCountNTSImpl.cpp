#include "RE/GRefCountNTSImpl.h"


namespace RE
{
	void GRefCountNTSImpl::AddRef()
	{
		++refCount;
	}


	void GRefCountNTSImpl::Release()
	{
		if (--refCount == 0) {
			delete this;
		}
	}
}
