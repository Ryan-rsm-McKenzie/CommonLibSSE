#include "RE/ExtraSoul.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	ExtraSoul::ExtraSoul() :
		ExtraSoul(SOUL_LEVEL::kNone)
	{}


	ExtraSoul::ExtraSoul(SOUL_LEVEL a_level) :
		BSExtraData(),
		soul(a_level),
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
		return soul != rhs->soul;
	}


	SOUL_LEVEL ExtraSoul::GetContainedSoul() const
	{
		return soul;
	}
}
