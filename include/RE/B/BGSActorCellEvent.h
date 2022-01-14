#pragma once

#include "RE/B/BGSActorEvent.h"

namespace RE
{
	struct BGSActorCellEvent : public BGSActorEvent
	{
		enum class CellFlag
		{
			kEnter = 0,
			kLeave = 1
		};

		FormID                                    cellID;
		stl::enumeration<CellFlag, std::uint32_t> flags;
	};
	static_assert(sizeof(BGSActorCellEvent) == 0xC);
}
