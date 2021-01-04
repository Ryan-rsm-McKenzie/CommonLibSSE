#pragma once

#include "RE/I/IBSTCreator.h"

namespace RE
{
	// 08
	template <class Derived, class Parent>
	struct BSTDerivedCreator : public IBSTCreator<Parent>
	{
	public:
		virtual ~BSTDerivedCreator();  // 00

	protected:
		// override (IBSTCreator<Parent>)
		virtual Parent* CreateImpl() const override;  // 01

	public:
		virtual void Destroy(const Parent* a_val) const override;  // 02

		Derived* Create() const
		{
			return static_cast<Derived*>(CreateImpl());
		}
	};
}
