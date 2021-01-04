#pragma once

#include "RE/H/hkRefPtr.h"
#include "RE/H/hkReferencedObject.h"

namespace RE
{
	class hkRefVariant : public hkRefPtr<hkReferencedObject>
	{
	public:
	};
	static_assert(sizeof(hkRefVariant) == 0x8);
}
