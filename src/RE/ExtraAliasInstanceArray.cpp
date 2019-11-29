#include "RE/ExtraAliasInstanceArray.h"

#include "RE/Offsets.h"
#include "RE/TESMemoryManager.h"
#include "REL/Relocation.h"


namespace RE
{
	ExtraAliasInstanceArray::ExtraAliasInstanceArray() :
		BSExtraData(),
		aliasInfoArr(),
		unk28(0),
		unk2C(0)
	{
		REL::Offset<std::uintptr_t> vtbl(Offset::ExtraAliasInstanceArray::Vtbl);
		((std::uintptr_t*)this)[0] = vtbl.GetAddress();
	}


	ExtraAliasInstanceArray::~ExtraAliasInstanceArray()
	{
		for (auto& aliasInfo : aliasInfoArr) {
			free(aliasInfo);
		}
	}


	ExtraDataType ExtraAliasInstanceArray::GetType() const
	{
		return ExtraDataType::kAliasInstanceArray;
	}
}
