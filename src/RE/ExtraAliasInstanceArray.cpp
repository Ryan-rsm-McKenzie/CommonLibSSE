#include "RE/ExtraAliasInstanceArray.h"

#include "skse64/GameExtraData.h"  // s_ExtraAliasInstanceArrayVtbl

#include "RE/TESMemoryManager.h"  // free


namespace RE
{
	ExtraAliasInstanceArray::ExtraAliasInstanceArray() :
		BSExtraData(),
		aliasInfoArr(),
		unk28(0),
		unk2C(0)
	{
		((std::uintptr_t*)this)[0] = s_ExtraAliasInstanceArrayVtbl.GetUIntPtr();
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
