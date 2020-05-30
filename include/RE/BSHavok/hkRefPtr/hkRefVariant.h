#pragma once

#include "RE/BSHavok/hkRefPtr/hkRefPtr.h"
#include "RE/BSHavok/hkBaseObject/hkReferencedObject/hkReferencedObject.h"


namespace RE
{
	class hkRefVariant : public hkRefPtr<hkReferencedObject>
	{
	public:
	};
	STATIC_ASSERT(sizeof(hkRefVariant) == 0x8);
}
