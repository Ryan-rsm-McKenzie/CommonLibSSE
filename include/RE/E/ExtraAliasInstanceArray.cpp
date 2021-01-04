#include "RE/E/ExtraAliasInstanceArray.h"

#include "RE/M/MemoryManager.h"

namespace RE
{
	ExtraAliasInstanceArray::ExtraAliasInstanceArray() :
		BSExtraData(),
		aliases(),
		lock()
	{
		REL::Relocation<std::uintptr_t> vtbl{ Offset::ExtraAliasInstanceArray::Vtbl };
		((std::uintptr_t*)this)[0] = vtbl.address();
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
