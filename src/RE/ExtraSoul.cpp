#include "RE/ExtraSoul.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	ExtraSoul::ExtraSoul() :
		ExtraSoul(SoulLevel::kNone)
	{}


	ExtraSoul::ExtraSoul(SoulLevel a_level) :
		BSExtraData(),
		level(a_level),
		pad11(0),
		pad12(0),
		pad14(0)
	{
		REL::Offset<std::uintptr_t> vtbl(Offset::ExtraSoul::Vtbl);
		((std::uintptr_t*)this)[0] = vtbl.GetAddress();
	}


	ExtraDataType ExtraSoul::GetType() const
	{
		return ExtraDataType::kSoul;
	}


	bool ExtraSoul::IsNotEqual(const BSExtraData* a_rhs) const
	{
		auto rhs = static_cast<const ExtraSoul*>(a_rhs);
		return level != rhs->level;
	}
}
