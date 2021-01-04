#pragma once

#include "RE/M/MapInputHandler.h"

namespace RE
{
	class MapMoveHandler : public MapInputHandler
	{
	public:
		inline static constexpr auto RTTI = RTTI_MapMoveHandler;

		virtual ~MapMoveHandler();	// 00

		// override (MapInputHandler)
		virtual bool CanProcess(InputEvent* a_event) override;				// 01
		virtual bool ProcessThumbstick(ThumbstickEvent* a_event) override;	// 03

		// members
		std::uint64_t unk18;  // 18
	};
	static_assert(sizeof(MapMoveHandler) == 0x20);
}
