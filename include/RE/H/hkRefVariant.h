#pragma once

#include "RE/H/hkReferencedObject.h"
#include "RE/H/hkRefPtr.h"


namespace RE
{
	class hkRefVariant : public hkRefPtr<hkReferencedObject>
	{
	public:
	};
	static_assert(sizeof(hkRefVariant) == 0x8);
}
