#pragma once

#include "RE/GStats.h"  // GStat


namespace RE
{
	template <class Base, GStat StatType>
	class GRefCountBaseStatImpl : public Base
	{
	public:
		virtual ~GRefCountBaseStatImpl()	// 00
		{}
	};
}
