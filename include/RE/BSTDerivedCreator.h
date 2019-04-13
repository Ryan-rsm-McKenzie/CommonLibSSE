#pragma once

#include "RE/IBSTCreator.h"  // IBSTCreator


namespace RE
{
	// 08
	template <class Derived, class Parent>
	struct BSTDerivedCreator : public IBSTCreator<Parent>
	{
	public:
		virtual ~BSTDerivedCreator();					// 00

	protected:
		// override (IBSTCreator<Parent>)
		virtual Parent*	CreateImpl() override;			// 01

	public:
		virtual void	Return(Parent* a_val) override;	// 02

		Derived*		Create();
	};


	template <class Derived, class Parent>
	inline Derived* BSTDerivedCreator<Derived, Parent>::Create()
	{
		return static_cast<Derived*>(CreateImpl());
	}
}
