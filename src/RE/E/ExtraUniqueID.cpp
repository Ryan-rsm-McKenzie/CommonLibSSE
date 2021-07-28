#include "RE/E/ExtraUniqueID.h"

namespace RE
{
	ExtraUniqueID::ExtraUniqueID() :
		ExtraUniqueID(0, 0)
	{}

	ExtraUniqueID::ExtraUniqueID(FormID a_baseID, std::uint16_t a_uniqueID) :
		BSExtraData(),
		baseID(a_baseID),
		uniqueID(a_uniqueID),
		pad16(0)
	{
		REL::Relocation<std::uintptr_t> vtbl{ Offset::ExtraUniqueID::Vtbl };
		((std::uintptr_t*)this)[0] = vtbl.address();
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
