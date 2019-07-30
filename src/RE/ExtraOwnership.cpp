#include "RE/ExtraOwnership.h"

#include "skse64/GameExtraData.h"  // s_ExtraOwnershipVtbl


namespace RE
{
	ExtraOwnership::ExtraOwnership() :
		BSExtraData(),
		owner(0)
	{
		((std::uintptr_t*)this)[0] = s_ExtraOwnershipVtbl.GetUIntPtr();
	}


	ExtraOwnership::ExtraOwnership(TESForm* a_owner) :
		BSExtraData(),
		owner(a_owner)
	{
		((std::uintptr_t*)this)[0] = s_ExtraOwnershipVtbl.GetUIntPtr();
	}


	ExtraDataType ExtraOwnership::GetType() const
	{
		return ExtraDataType::kOwnership;
	}


	bool ExtraOwnership::IsNotEqual(const BSExtraData* a_rhs) const
	{
		auto rhs = static_cast<const ExtraOwnership*>(a_rhs);
		return owner != rhs->owner;
	}
}
