#pragma once

#include "RE/BSHavok/hkBaseObject/hkReferencedObject/hkReferencedObject.h"
#include "RE/BSHavok/hkRefPtr/hkRefPtr.h"


namespace RE
{
	class hkRefVariant : public hkRefPtr<hkReferencedObject>
	{
	public:
	};
	STATIC_ASSERT(sizeof(hkRefVariant) == 0x8);
}
