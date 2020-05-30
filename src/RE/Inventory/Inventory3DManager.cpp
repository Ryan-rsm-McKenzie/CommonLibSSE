#include "RE/Inventory/Inventory3DManager.h"


namespace RE
{
	Inventory3DManager* Inventory3DManager::GetSingleton()
	{
		REL::Offset<Inventory3DManager**> singleton = REL::ID(517051);
		return *singleton;
	}
}
