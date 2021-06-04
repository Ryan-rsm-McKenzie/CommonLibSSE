#pragma once

#include "RE/A/AutoRegisterFactory.h"
#include "RE/B/BSTDerivedCreator.h"

namespace RE
{
	// 08
	template <class Derived, class Manager>
	struct AutoRegisterCreator : public AutoRegisterFactory<BSTDerivedCreator<Derived, typename Manager::mapped_type>, Manager>
	{
	public:
		virtual ~AutoRegisterCreator();  // 00
	};
}
