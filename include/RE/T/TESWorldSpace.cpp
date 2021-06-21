#include "RE/T/TESWorldSpace.h"

namespace RE
{
	bool TESWorldSpace::HasMaxHeightData() const
	{
		return maxHeightData != nullptr;
	}

	TESObjectCELL* TESWorldSpace::GetSkyCell()
	{
		using func_t = decltype(&TESWorldSpace::GetSkyCell);
		REL::Relocation<func_t> func{ REL::ID(20095) };
		return func(this);
	}

	float TESWorldSpace::GetWaterHeight() const
	{
		auto world = this;
		while (world->parentWorld && world->parentUseFlags.any(ParentUseFlag::kUseLandData)) {
			world = world->parentWorld;
		}
		return world->defaultWaterHeight;
	}
}
