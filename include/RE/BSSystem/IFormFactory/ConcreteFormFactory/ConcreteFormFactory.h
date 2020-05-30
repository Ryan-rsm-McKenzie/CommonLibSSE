#pragma once

#include "RE/IFormFactory.h"
#include "RE/TESForm.h"


namespace RE
{
	template <class T, FormType FORM_TYPE>
	class ConcreteFormFactory : public IFormFactory
	{
	public:
		virtual ~ConcreteFormFactory();	 // 00

	protected:
		// override (IFormFactory)
		virtual TESForm* CreateImpl() override;	 // 01

	public:
		virtual const char* GetFormName() const override;  // 02 - { return _name; }
		virtual FormType	GetFormType() const override;  // 03 - { return FORM_TYPE; }

		inline T* Create()
		{
			return static_cast<T*>(CreateImpl());
		}

	protected:
		// members
		const char* _name;	// 08
	};
	STATIC_ASSERT(sizeof(ConcreteFormFactory<TESForm, FormType::None>) == 0x10);


	template <class T>
	inline ConcreteFormFactory<T, T::FORMTYPE>* IFormFactory::GetConcreteFormFactoryByType()
	{
		return static_cast<ConcreteFormFactory<T, T::FORMTYPE>*>(GetFormFactoryByType(T::FORMTYPE));
	}
}
