#include "RE/GRefCountImpl.h"

#include "skse64_common/Relocation.h"  // RelocAddr

#include "RE/Offsets.h"


namespace RE
{
	GRefCountImpl::~GRefCountImpl()
	{}


	void GRefCountImpl::AddRef()
	{
		InterlockedIncrement(&refCount);
	}


	void GRefCountImpl::Release()
	{
		typedef void _Release_t(GRefCountImpl* a_this);
		RelocAddr<_Release_t*> _Release(G_REF_COUNT_RELEASE);
		_Release(this);
	}
}
