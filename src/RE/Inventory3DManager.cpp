#include "RE/Inventory3DManager.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	Inventory3DManager* Inventory3DManager::GetSingleton()
	{
		REL::Offset<Inventory3DManager**> singleton = REL::ID(517051);
		return *singleton;
	}

	
	void Inventory3DManager::UpdateItem3D(InventoryEntryData* a_obj)
	{
		using func_t = decltype(&Inventory3DManager::UpdateItem3D);
		REL::Offset<func_t> func = REL::ID(50884);
		return func(this, a_obj);
	}

	
	void Inventory3DManager::UpdateMagic3D(TESForm* a_form, UInt32 a_unk1)
	{
		using func_t = decltype(&Inventory3DManager::UpdateMagic3D);
		REL::Offset<func_t> func = REL::ID(50885);
		return func(this, a_form, a_unk1);
	}

	
	void Inventory3DManager::Clear3D()
	{
		using func_t = decltype(&Inventory3DManager::Clear3D);
		REL::Offset<func_t> func = REL::ID(50886);
		return func(this);
	}

	
	UInt32 Inventory3DManager::Render()
	{
		using func_t = decltype(&Inventory3DManager::Render);
		REL::Offset<func_t> func = REL::ID(50882);
		return func(this);
	}
}