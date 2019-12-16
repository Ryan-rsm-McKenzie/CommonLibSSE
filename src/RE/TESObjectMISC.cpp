#include "RE/TESObjectMISC.h"

#include "RE/BGSDefaultObjectManager.h"


namespace RE
{
	TESObjectMISC* TESObjectMISC::GetGoldForm()
	{
		using Object = BGSDefaultObjectManager::DefaultObject;

		auto dobj = BGSDefaultObjectManager::GetSingleton();
		return dobj->GetObject<TESObjectMISC>(Object::kCaps001);
	}
}
