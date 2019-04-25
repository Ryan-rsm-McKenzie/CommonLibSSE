#pragma once

#include "RE/GFxLogConstants.h"  // GFxLogConstants


namespace RE
{
	template <class Derived>
	class GFxLogBase : public GFxLogConstants
	{
	public:
		virtual ~GFxLogBase() {}									// 00

		// add
		virtual bool IsVerboseActionErrors() const { return true; }	// 01
	};
	STATIC_ASSERT(sizeof(GFxLogBase<void*>) == 0x8);
}
