#include "RE/TESObjectCELL.h"

#include "skse64/GameForms.h"  // TESObjectCELL


namespace RE
{
	double TESObjectCELL::GetNorthRotation()
	{
		using func_t = function_type_t<decltype(&TESObjectCELL::GetNorthRotation)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::TESObjectCELL, GetNorthRotation, func_t*);
		return func(this);
	}


	bool TESObjectCELL::IsInteriorCell() const
	{
		return (flags & Flag::kIsInteriorCell) != Flag::kNone;
	}


	bool TESObjectCELL::IsExteriorCell() const
	{
		return !IsInteriorCell();
	}


	auto TESObjectCELL::GetLighting()
		-> Lighting*
	{
		return IsInteriorCell() ? lightingCoordinates.lighting : 0;
	}


	auto TESObjectCELL::GetCoordinates()
		-> Coordinates*
	{
		return IsExteriorCell() ? lightingCoordinates.coordinates : 0;
	}
}
