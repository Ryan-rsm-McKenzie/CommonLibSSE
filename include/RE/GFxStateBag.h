#pragma once

#include "RE/GFxFileConstants.h"  // GFxFileConstants
#include "RE/GFxState.h"  // GFxState::StateType


namespace RE
{
	// StateBag collects accessor methods for properties that can be inherited from Loader to MovieDef and from MovieDef to Movie. These properties can be overwritten in any one of above mentioned instances.
	class GFxStateBag : public GFxFileConstants
	{
	protected:
		// add
		virtual	GFxStateBag*	GetStateBagImpl() const;																				// 00

	public:
		virtual	~GFxStateBag();																											// 01

		virtual void			SetState(GFxState::StateType a_stateType, GFxState* a_state);											// 02 - SetState sets an interface to State. The state type is passed to SetState so that we can know which state is being cleared when null is passed
		virtual GFxState*		GetStateAddRef(GFxState::StateType a_stateType) const;													// 03 - GetStateAddRef obtains one or more State pointers based on the specified state type
		virtual void			GetStatesAddRef(GFxState** a_stateList, const GFxState::StateType* a_stateTypes, UInt32 a_count) const;	// 04 - GetStatesAddRef fills in a set of states with one call. Initial array a_stateList must contain null pointers

		template <class T>
		T* GetStateAddRef(GFxState::StateType a_state) const
		{
			return static_cast<T*>(GetStateAddRef(a_state));
		}
	};
	STATIC_ASSERT(sizeof(GFxStateBag) == 0x8);
}
