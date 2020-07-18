#include "RE/FormComponents/Components/ActorCause.h"


namespace RE
{
	std::int32_t ActorCause::DecRefCount()
	{
		return InterlockedDecrement(&refCount);
	}


	std::int32_t ActorCause::IncRefCount()
	{
		return InterlockedIncrement(&refCount);
	}


	std::int32_t ActorCause::GetRefCount() const
	{
		return refCount;
	}
}
