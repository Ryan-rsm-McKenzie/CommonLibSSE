#include "RE/GRefCountImplCore.h"


namespace RE
{
	GRefCountImplCore::GRefCountImplCore() :
		_refCount(1),
		_pad0C(0)
	{}


	void GRefCountImplCore::CheckInvalidDelete(GRefCountImplCore*)
	{}


	SInt32 GRefCountImplCore::GetRefCount() const
	{
		return _refCount;
	}
}
