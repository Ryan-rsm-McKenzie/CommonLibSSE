#pragma once

#include "RE/GFxState.h"


namespace RE
{
	class GFxMovieView;
	class GFxValue;


	class GFxExternalInterface : public GFxState
	{
	public:
		inline static constexpr auto RTTI = RTTI_GFxExternalInterface;


		GFxExternalInterface() :
			GFxState(StateType::kExternalInterface)
		{}

		virtual ~GFxExternalInterface() = default;	// 00

		// add
		virtual void Callback(GFxMovieView* a_movieView, const char* a_methodName, const GFxValue* a_args, UInt32 a_numArgs) = 0;  // 01
	};
	STATIC_ASSERT(sizeof(GFxExternalInterface) == 0x18);
}
