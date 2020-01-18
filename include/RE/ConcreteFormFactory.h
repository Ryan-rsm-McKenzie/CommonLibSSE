#pragma once

#include "RE/IFormFactory.h"
#include "RE/TESForm.h"


namespace RE
{
	template <class T, FormType FORM_TYPE>
	class ConcreteFormFactory : public IFormFactory
	{
	public:
		virtual ~ConcreteFormFactory();						// 00

	protected:
		// override (IFormFactory)
		virtual TESForm*	CreateImpl() override;			// 01

	public:
		virtual const char*	GetFormName() const override;	// 02 - { return _name; }
		virtual FormType	GetFormType() const override;	// 03 - { return FORM_TYPE; }

		T* Create();

	protected:
		// members
		const char* _name;	// 08
	};
	STATIC_ASSERT(sizeof(ConcreteFormFactory<TESForm, FormType::None>) == 0x10);


	template <class T, FormType FORM_TYPE>
	inline T* ConcreteFormFactory<T, FORM_TYPE>::Create()
	{
		return static_cast<T*>(CreateImpl());
	}


	template <class T>
	inline ConcreteFormFactory<T, static_cast<FormType>(T::kTypeID)>* IFormFactory::GetConcreteFormFactoryByType()
	{
		return static_cast<ConcreteFormFactory<T, static_cast<FormType>(T::kTypeID)>*>(GetFormFactoryByType(static_cast<FormType>(T::kTypeID)));
	}
}
