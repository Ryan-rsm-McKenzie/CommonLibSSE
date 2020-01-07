#include "RE/ExtraUniqueID.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	ExtraUniqueID::ExtraUniqueID() :
		ExtraUniqueID(0, 0)
	{}


	ExtraUniqueID::ExtraUniqueID(FormID a_baseID, UInt16 a_uniqueID) :
		BSExtraData(),
		baseID(a_baseID),
		uniqueID(a_uniqueID),
		pad16(0)
	{
		REL::Offset<std::uintptr_t> vtbl(Offset::ExtraUniqueID::Vtbl);
		((std::uintptr_t*)this)[0] = vtbl.GetAddress();
	}


	ExtraDataType ExtraUniqueID::GetType() const
	{
		return ExtraDataType::kUniqueID;
	}


	bool ExtraUniqueID::IsNotEqual(const BSExtraData* a_rhs) const
	{
		auto rhs = static_cast<const ExtraUniqueID*>(a_rhs);
		return rhs->uniqueID != rhs->uniqueID || baseID != rhs->baseID;
	}
}
