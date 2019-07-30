#pragma once

#include "RE/GMemory.h"  // GFC_MEMORY_REDEFINE_NEW_IMPL

#define GFC_REFCOUNTALLOC_CHECK_DELETE(class_name, p)


namespace RE
{
	// Adds new/delete overrides
	// Base must be one of RefCountImpl classes
	template <class Base, UInt32 StatType>
	class GRefCountBaseStatImpl : public Base
	{
	public:
		GRefCountBaseStatImpl() = default;


		GFC_MEMORY_REDEFINE_NEW_IMPL(Base, GFC_REFCOUNTALLOC_CHECK_DELETE, StatType);
	};
}
