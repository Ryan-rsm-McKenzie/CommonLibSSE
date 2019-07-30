#include "RE/ExtraUniqueID.h"

#include "skse64/GameExtraData.h"  // s_ExtraEnchantmentVtbl


namespace RE
{
	ExtraUniqueID::ExtraUniqueID() :
		BSExtraData(),
		owner(0),
		uniqueID(0),
		pad16(0)
	{
		((std::uintptr_t*)this)[0] = s_ExtraUniqueIdVtbl.GetUIntPtr();
	}


	ExtraUniqueID::ExtraUniqueID(FormID a_owner, UInt16 a_uniqueID) :
		BSExtraData(),
		owner(a_owner),
		uniqueID(a_uniqueID),
		pad16(0)
	{
		((std::uintptr_t*)this)[0] = s_ExtraUniqueIdVtbl.GetUIntPtr();
	}


	ExtraDataType ExtraUniqueID::GetType() const
	{
		return ExtraDataType::kUniqueID;
	}


	bool ExtraUniqueID::IsNotEqual(const BSExtraData* a_rhs) const
	{
		auto rhs = static_cast<const ExtraUniqueID*>(a_rhs);
		return rhs->uniqueID != rhs->uniqueID || owner != rhs->owner;
	}
}
