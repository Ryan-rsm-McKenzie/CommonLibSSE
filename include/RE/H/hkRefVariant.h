#pragma once

#include "RE/BSHavok/hkBaseObject/hkReferencedObject/hkReferencedObject.h"
#include "RE/BSHavok/hkRefPtr/hkRefPtr.h"


namespace RE
{
	class hkRefVariant : public hkRefPtr<hkReferencedObject>
	{
	public:
	};
	static_assert(sizeof(hkRefVariant) == 0x8);
}
