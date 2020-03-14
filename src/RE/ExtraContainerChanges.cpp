#include "RE/ExtraContainerChanges.h"

#include "RE/InventoryChanges.h"
#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	ExtraContainerChanges::ExtraContainerChanges() :
		ExtraContainerChanges(nullptr)
	{}


	ExtraContainerChanges::ExtraContainerChanges(InventoryChanges* a_changes) :
		BSExtraData(),
		changes(a_changes)
	{
		REL::Offset<std::uintptr_t> vtbl(Offset::ExtraContainerChanges::Vtbl);
		((std::uintptr_t*)this)[0] = vtbl.GetAddress();
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
