#include "RE/G/GFxState.h"

namespace RE
{
	GFxState::GFxState(StateType a_st) :
		GRefCountBase<GFxState, GStatGroups::kGStat_Default_Mem>(),
		stateType(a_st),
		pad14(0)
	{}

	auto GFxState::GetStateType() const
		-> StateType
	{
		return stateType;
	}
}
