#pragma once

#include "RE/FormTypes.h"  // TESObjectCELL


namespace RE
{
	struct TESCellFullyLoadedEvent
	{
		TESObjectCELL* cell;
	};
	STATIC_ASSERT(sizeof(TESCellFullyLoadedEvent) == 0x8);
}
