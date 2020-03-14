#include "RE/ExtraHealth.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	ExtraHealth::ExtraHealth() :
		ExtraHealth(1.0)
	{}


	ExtraHealth::ExtraHealth(float a_health) :
		BSExtraData(),
		health(a_health),
		pad14(0)
	{
		REL::Offset<std::uintptr_t> vtbl(Offset::ExtraHealth::Vtbl);
		((std::uintptr_t*)this)[0] = vtbl.GetAddress();
	}


	ExtraDataType ExtraHealth::GetType() const
	{
		return ExtraDataType::kHealth;
	}


	bool ExtraHealth::IsNotEqual(const BSExtraData* a_rhs) const
	{
		auto rhs = static_cast<const ExtraHealth*>(a_rhs);
		return health != rhs->health;
	}
}
