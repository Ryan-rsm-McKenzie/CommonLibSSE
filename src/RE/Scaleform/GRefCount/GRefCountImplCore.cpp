#include "RE/Scaleform/GRefCount/GRefCountImplCore.h"


namespace RE
{
	GRefCountImplCore::GRefCountImplCore() :
		_refCount(1),
		_pad0C(0)
	{}


	void GRefCountImplCore::CheckInvalidDelete(GRefCountImplCore*)
	{}


	std::int32_t GRefCountImplCore::GetRefCount() const
	{
		return _refCount;
	}
}
