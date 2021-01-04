#pragma once

#include "RE/C/ConcreteFormFactory.h"

namespace RE
{
	template <class T, FormType FORM_TYPE, OBJECT_TYPE OBJ_TYPE, OBJECT_CATEGORY_TYPE OBJ_CATEGORY_TYPE>
	class ConcreteObjectFormFactory : public ConcreteFormFactory<T, FORM_TYPE>
	{
	public:
		virtual ~ConcreteObjectFormFactory();  // 00

		// override (ConcreteFormFactory)
		virtual const char*			 GetObjectName() const override;	  // 04 - { return _name; }
		virtual OBJECT_TYPE			 GetObjectType() const override;	  // 05 - { return OBJ_TYPE; }
		virtual OBJECT_CATEGORY_TYPE GetObjectCategory() const override;  // 06 - { return OBJ_CATEGORY_TYPE; }
	};
	static_assert(sizeof(ConcreteObjectFormFactory<TESForm, FormType::None, static_cast<OBJECT_TYPE>(0), static_cast<OBJECT_CATEGORY_TYPE>(0)>) == 0x10);
}
