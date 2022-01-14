#include "RE/E/ExtraContainerChanges.h"

#include "RE/I/InventoryChanges.h"

namespace RE
{
	ExtraContainerChanges::ExtraContainerChanges() :
		ExtraContainerChanges(nullptr)
	{}

	ExtraContainerChanges::ExtraContainerChanges(InventoryChanges* a_changes) :
		BSExtraData(),
		changes(a_changes)
	{
		REL::Relocation<std::uintptr_t> vtbl{ VTABLE[0] };
		((std::uintptr_t*)this)[0] = vtbl.address();
	}

	ExtraContainerChanges::~ExtraContainerChanges()
	{
		delete changes;
	}

	ExtraDataType ExtraContainerChanges::GetType() const
	{
		return ExtraDataType::kContainerChanges;
	}

	void* ExtraContainerChanges::AddInventoryItem(TESBoundObject* a_object, void* a_arg2, std::int32_t a_count, void* a_arg4)
	{
		using func_t = decltype(&ExtraContainerChanges::AddInventoryItem);
		REL::Relocation<func_t> func{ REL::ID(16053) };
		return func(this, a_object, a_arg2, a_count, a_arg4);
	}
}
