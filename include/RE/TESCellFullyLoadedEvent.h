#pragma once


namespace RE
{
	class TESObjectCELL;


	struct TESCellFullyLoadedEvent
	{
		// members
		TESObjectCELL* cell;
	};
	STATIC_ASSERT(sizeof(TESCellFullyLoadedEvent) == 0x8);
}
