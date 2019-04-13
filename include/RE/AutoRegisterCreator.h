#pragma once

#include "RE/AutoRegisterFactory.h"  // AutoRegisterFactory
#include "RE/BSTDerivedCreator.h"  // BSTDerivedCreator


namespace RE
{
	// 08
	template <class Derived, class Manager>
	struct AutoRegisterCreator : public AutoRegisterFactory<BSTDerivedCreator<Derived, typename Manager::mapped_type>, Manager>
	{
	public:
		virtual ~AutoRegisterCreator();	// 00
	};
}
