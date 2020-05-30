#include "RE/BSSystemFileStorage.h"


namespace RE
{
	bool BSSystemFileStorage::IsGoodForRead() const
	{
		return goodForRead && ((attributes.lastError & Attributes::Error::kErrorMask) == Attributes::Error::kNone);
	}
}
