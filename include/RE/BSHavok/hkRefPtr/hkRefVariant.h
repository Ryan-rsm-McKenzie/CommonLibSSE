#pragma once

#include "RE/hkRefPtr.h"
#include "RE/hkReferencedObject.h"


namespace RE
{
	class hkRefVariant : public hkRefPtr<hkReferencedObject>
	{
	public:
	};
	STATIC_ASSERT(sizeof(hkRefVariant) == 0x8);
}
