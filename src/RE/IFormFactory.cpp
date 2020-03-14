#include "RE/IFormFactory.h"

#include "RE/GlobalLookupInfo.h"


namespace RE
{
	IFormFactory* IFormFactory::GetFormFactoryByType(FormType a_formType)
	{
		auto lookup = GlobalLookupInfo::GetSingleton();
		return lookup->formFactoriesInitialized ? lookup->formFactories[static_cast<UInt32>(a_formType)] : nullptr;
	}


	TESForm* IFormFactory::Create()
	{
		return CreateImpl();
	}
}
