#pragma once

#include "RE/hkReferencedObject.h"  // hkReferencedObject
#include "RE/hkRefPtr.h"  // hkRefPtr


namespace RE
{
	class hkRefVariant : public hkRefPtr<hkReferencedObject>
	{
	public:
	};
	STATIC_ASSERT(sizeof(hkRefVariant) == 0x8);
}
