#pragma once

#include "RE/GStats.h"  // GStat


namespace RE
{
	// Adds new/delete overrides
	// Base must be one of RefCountImpl classes
	template <class Base, GStat StatType>
	class GRefCountBaseStatImpl : public Base
	{
	public:
		virtual ~GRefCountBaseStatImpl()	// 00
		{}
	};
}
