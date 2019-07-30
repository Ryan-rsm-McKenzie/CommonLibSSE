#include "RE/ExtraSoul.h"

#include "skse64/GameExtraData.h"  // s_ExtraSoulVtbl


namespace RE
{
	ExtraSoul::ExtraSoul() :
		BSExtraData(),
		level(SoulLevel::kNone),
		pad11(0),
		pad12(0),
		pad14(0)
	{
		((std::uintptr_t*)this)[0] = s_ExtraSoulVtbl.GetUIntPtr();
	}


	ExtraSoul::ExtraSoul(SoulLevel a_level) :
		BSExtraData(),
		level(a_level),
		pad11(0),
		pad12(0),
		pad14(0)
	{
		((std::uintptr_t*)this)[0] = s_ExtraSoulVtbl.GetUIntPtr();
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
