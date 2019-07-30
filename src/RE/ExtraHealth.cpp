#include "RE/ExtraHealth.h"

#include "skse64/GameExtraData.h"  // s_ExtraHealthVtbl


namespace RE
{
	ExtraHealth::ExtraHealth() :
		BSExtraData(),
		health(1.0),
		pad14(0.0)
	{
		((std::uintptr_t*)this)[0] = s_ExtraHealthVtbl.GetUIntPtr();
	}


	ExtraHealth::ExtraHealth(float a_health) :
		BSExtraData(),
		health(a_health),
		pad14(0.0)
	{
		((std::uintptr_t*)this)[0] = s_ExtraHealthVtbl.GetUIntPtr();
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
