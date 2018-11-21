#include "RE/GFxState.h"


namespace RE
{
	GFxState::GFxState(StateType st) :
		SType(st)
	{}


	GFxState::StateType GFxState::GetStateType() const
	{
		return SType;
	}
}
