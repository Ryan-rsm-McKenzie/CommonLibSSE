#include "RE/GRefCountNTSImpl.h"


namespace RE
{
	void GRefCountNTSImpl::AddRef()
	{
		++_refCount;
	}


	void GRefCountNTSImpl::Release()
	{
		if (--_refCount == 0) {
			delete this;
		}
	}
}
