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
		REL::Relocation<std::uintptr_t> vtbl{ Offset::ExtraContainerChanges::Vtbl };
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
}
