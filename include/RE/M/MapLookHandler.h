#pragma once

#include "RE/M/MapInputHandler.h"

namespace RE
{
	class MapLookHandler : public MapInputHandler
	{
	public:
		inline static constexpr auto RTTI = RTTI_MapLookHandler;

		~MapLookHandler() override;  // 00

		// override (MapInputHandler)
		bool ProcessThumbstick(ThumbstickEvent* a_event) override;  // 03
		bool ProcessMouseMove(MouseMoveEvent* a_event) override;    // 04
		bool ProcessButton(ButtonEvent* a_event) override;          // 05

		// members
		std::uint64_t unk18;  // 18
	};
	static_assert(sizeof(MapLookHandler) == 0x20);
}
