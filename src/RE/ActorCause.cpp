#include "RE/ActorCause.h"


namespace RE
{
	SInt32 ActorCause::DecRefCount()
	{
		return InterlockedDecrement(&refCount);
	}


	SInt32 ActorCause::IncRefCount()
	{
		return InterlockedIncrement(&refCount);
	}


	SInt32 ActorCause::GetRefCount() const
	{
		return refCount;
	}
}
