#pragma once

#include "skse64/GameRTTI.h"  // RTTI_GFxExternalInterface

#include "RE/GFxState.h"  // GFxState


namespace RE
{
	class GFxMovieView;
	class GFxValue;


	class GFxExternalInterface : public GFxState
	{
	public:
		inline static const void* RTTI = RTTI_GFxExternalInterface;


		constexpr GFxExternalInterface() :
			GFxState(StateType::kExternalInterface)
		{}

		virtual ~GFxExternalInterface() = default;																					// 00

		// add
		virtual void Callback(GFxMovieView* a_movieView, const char* a_methodName, const GFxValue* a_args, UInt32 a_numArgs) = 0;	// 01
	};
	STATIC_ASSERT(sizeof(GFxExternalInterface) == 0x18);
}
