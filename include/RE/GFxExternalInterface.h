#pragma once

#include "RE/GFxState.h"  // GFxState

class GFxValue;


namespace RE
{
	class GFxMovieView;


	class GFxExternalInterface : public GFxState
	{
	public:
		constexpr GFxExternalInterface() :
			GFxState(StateType::kExternalInterface)
		{}

		virtual ~GFxExternalInterface()																								// 00
		{}

		// add
		virtual void Callback(GFxMovieView* a_movieView, const char* a_methodName, const GFxValue* a_args, UInt32 a_numArgs) = 0;	// 01
	};
	STATIC_ASSERT(sizeof(GFxExternalInterface) == 0x18);
}
