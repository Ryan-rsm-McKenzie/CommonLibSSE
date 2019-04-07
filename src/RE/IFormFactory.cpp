#include "RE/IFormFactory.h"

#include "skse64/GameForms.h"  // IFormFactory


namespace RE
{
	IFormFactory* IFormFactory::GetFormFactoryByType(FormType a_formType)
	{
		return reinterpret_cast<IFormFactory*>(::IFormFactory::GetFactoryForType(static_cast<UInt32>(a_formType)));
	}


	FormType IFormFactory::GetFormType() const
	{
		return static_cast<FormType>(GetFormTypeImpl());
	}


	TESForm* IFormFactory::Create() const
	{
		return CreateImpl();
	}
}
