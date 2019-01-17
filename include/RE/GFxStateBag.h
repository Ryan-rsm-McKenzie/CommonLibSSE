#pragma once

#include "RE/GFxFileConstants.h"  // RE::GFxFileConstants
#include "RE/GFxState.h"  // RE::GFxState::StateType


namespace RE
{
	// StateBag collects accessor methods for properties that can be inherited from Loader to MovieDef and from MovieDef to Movie. These properties can be overwritten in any one of above mentioned instances.
	class GFxStateBag : public GFxFileConstants
	{
	protected:
		virtual	GFxStateBag*	GetStateBagImpl(void) const;

	public:
		virtual	~GFxStateBag();																									// 00

		// add
		virtual void		SetState(GFxState::StateType a_stateType, GFxState* a_state);										// 01 - SetState sets an interface to State. The state type is passed to SetState so that we can know which state is being cleared when null is passed
		virtual GFxState*	GetStateAddRef(GFxState::StateType a_state) const;													// 02 - GetStateAddRef obtains one or more State pointers based on the specified state type
		virtual void		GetStatesAddRef(GFxState** a_stateList, const GFxState::StateType* a_states, UInt32 a_count) const;	// 03 - GetStatesAddRef fills in a set of states with one call. Initial array a_stateList must contain null pointers

		template <typename T>
		T* GetStateAddRef(GFxState::StateType a_state) const
		{
			return static_cast<T*>(GetStateAddRef(a_state));
		}
	};
}
