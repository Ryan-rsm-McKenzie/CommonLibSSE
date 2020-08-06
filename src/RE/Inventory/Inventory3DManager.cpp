#include "RE/Inventory/Inventory3DManager.h"


namespace RE
{
	Inventory3DManager* Inventory3DManager::GetSingleton()
	{
		REL::Relocation<Inventory3DManager**> singleton{ REL::ID(517051) };
		return *singleton;
	}
}
