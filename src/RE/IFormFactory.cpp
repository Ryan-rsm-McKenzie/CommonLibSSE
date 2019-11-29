#include "RE/IFormFactory.h"

#include "RE/GlobalLookupInfo.h"


namespace RE
{
	IFormFactory* IFormFactory::GetFormFactoryByType(FormType a_formType)
	{
		auto lookup = GlobalLookupInfo::GetSingleton();
		return lookup->formFactoriesInit ? lookup->formFactories[static_cast<UInt32>(a_formType)] : 0;
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
