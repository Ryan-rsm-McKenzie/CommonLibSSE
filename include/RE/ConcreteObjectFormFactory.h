#pragma once

#include "RE/ConcreteFormFactory.h"  // ConcreteFormFactory


namespace RE
{
	template <class T, FormType FORM_TYPE, UInt32 NUM1, UInt32 NUM2>
	class ConcreteObjectFormFactory : public ConcreteFormFactory<T, FORM_TYPE>
	{
	public:
		virtual ~ConcreteObjectFormFactory();				// 00

		// override (ConcreteFormFactory)
		virtual const char*	GetObjectName() const override;	// 04 - { return _name; }
		virtual UInt32		GetNum1() const override;		// 05 - { return NUM1; }
		virtual UInt32		GetNum2() const override;		// 06 - { return NUM2; }
	};
	STATIC_ASSERT(sizeof(ConcreteObjectFormFactory<TESForm, FormType::None, 0, 0>) == 0x10);
}
