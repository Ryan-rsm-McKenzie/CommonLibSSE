#pragma once

#include "RE/G/GFxState.h"

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

		~GFxExternalInterface() override = default;  // 00

		// add
		virtual void Callback(GFxMovieView* a_movieView, const char* a_methodName, const GFxValue* a_args, std::uint32_t a_numArgs) = 0;  // 01
	};
	static_assert(sizeof(GFxExternalInterface) == 0x18);
}
