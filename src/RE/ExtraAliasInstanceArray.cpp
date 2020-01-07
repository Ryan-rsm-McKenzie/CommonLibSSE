#include "RE/ExtraAliasInstanceArray.h"

#include "RE/MemoryManager.h"
#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	ExtraAliasInstanceArray::ExtraAliasInstanceArray() :
		BSExtraData(),
		aliases(),
		lock()
	{
		REL::Offset<std::uintptr_t> vtbl(Offset::ExtraAliasInstanceArray::Vtbl);
		((std::uintptr_t*)this)[0] = vtbl.GetAddress();
	}


	ExtraAliasInstanceArray::~ExtraAliasInstanceArray()
	{
		for (auto& alias : aliases) {
			free(alias);
		}
	}


	ExtraDataType ExtraAliasInstanceArray::GetType() const
	{
		return ExtraDataType::kAliasInstanceArray;
	}
}
