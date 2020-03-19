#pragma once


namespace RE
{
	class TESObjectCELL;


	struct TESCellFullyLoadedEvent
	{
	public:
		// members
		TESObjectCELL* cell;
	};
	STATIC_ASSERT(sizeof(TESCellFullyLoadedEvent) == 0x8);
}
