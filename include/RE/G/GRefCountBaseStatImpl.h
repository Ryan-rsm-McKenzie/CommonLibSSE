#pragma once

#include "RE/G/GMemory.h"

#define GFC_REFCOUNTALLOC_CHECK_DELETE(class_name, p)

namespace RE
{
	// Adds new/delete overrides
	// Base must be one of RefCountImpl classes
	template <class Base, std::uint32_t StatType>
	class GRefCountBaseStatImpl : public Base
	{
	public:
		GFC_MEMORY_REDEFINE_NEW_IMPL(Base, GFC_REFCOUNTALLOC_CHECK_DELETE, StatType);
	};
}
