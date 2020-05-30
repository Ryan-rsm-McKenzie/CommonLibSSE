#include "RE/TESObjectCELL.h"

#include "RE/BGSEncounterZone.h"
#include "RE/ExtraNorthRotation.h"
#include "RE/TESFaction.h"
#include "RE/TESNPC.h"
#include "RE/TESWorldSpace.h"


namespace RE
{
	TESNPC* TESObjectCELL::GetActorOwner()
	{
		auto owner = GetOwner();
		return owner && owner->Is(FormType::NPC) ? static_cast<TESNPC*>(owner) : nullptr;
	}


	EXTERIOR_DATA* TESObjectCELL::GetCoordinates()
	{
		return IsExteriorCell() ? cellData.exterior : nullptr;
	}


	TESFaction* TESObjectCELL::GetFactionOwner()
	{
		auto owner = GetOwner();
		return owner && owner->Is(FormType::Faction) ? static_cast<TESFaction*>(owner) : nullptr;
	}


	INTERIOR_DATA* TESObjectCELL::GetLighting()
	{
		return IsInteriorCell() ? cellData.interior : nullptr;
	}


	float TESObjectCELL::GetNorthRotation()
	{
		if (IsExteriorCell()) {
			return worldSpace->northRotation;
		} else {
			auto xNorth = extraList.GetByType<ExtraNorthRotation>();
			return xNorth ? xNorth->northRot : static_cast<float>(0.0);
		}
	}


	TESForm* TESObjectCELL::GetOwner()
	{
		auto owner = extraList.GetOwner();
		if (owner) {
			return owner;
		}

		BGSEncounterZone* zone = nullptr;
		if (loadedData) {
			zone = loadedData->encounterZone;
		} else {
			zone = extraList.GetEncounterZone();
			if (!zone && IsExteriorCell()) {
				zone = worldSpace ? worldSpace->encounterZone : nullptr;
			}
		}

		return zone ? zone->data.zoneOwner : nullptr;
	}


	bool TESObjectCELL::IsAttached() const
	{
		return cellState == CellState::kAttached;
	}


	bool TESObjectCELL::IsExteriorCell() const
	{
		return !IsInteriorCell();
	}


	bool TESObjectCELL::IsInteriorCell() const
	{
		return (cellFlags & Flag::kIsInteriorCell) != Flag::kNone;
	}


	void TESObjectCELL::SetActorOwner(TESNPC* a_owner)
	{
		SetOwner(a_owner);
	}


	void TESObjectCELL::SetFactionOwner(TESFaction* a_owner)
	{
		SetOwner(a_owner);
	}


	void TESObjectCELL::SetFogColor(Color a_near, Color a_far)
	{
		if (!UsesSkyLighting()) {
			auto lighting = GetLighting();
			if (lighting) {
				lighting->fogColorNear = a_near;
				lighting->fogColorFar = a_far;
			}
		}
	}


	void TESObjectCELL::SetFogPlanes(float a_near, float a_far)
	{
		if (!UsesSkyLighting()) {
			auto lighting = GetLighting();
			if (lighting) {
				lighting->fogNear = a_near;
				lighting->fogFar = a_far;
			}
		}
	}


	void TESObjectCELL::SetFogPower(float a_power)
	{
		if (!UsesSkyLighting()) {
			auto lighting = GetLighting();
			if (lighting) {
				lighting->fogPower = a_power;
			}
		}
	}


	void TESObjectCELL::SetHandChanged(bool a_changed)
	{
		if (a_changed) {
			cellFlags |= Flag::kHandChanged;
		} else {
			cellFlags &= ~Flag::kHandChanged;
		}
		AddChange(ChangeFlags::kFlags);
	}


	void TESObjectCELL::SetOwner(TESForm* a_owner)
	{
		extraList.SetOwner(a_owner);
		AddChange(ChangeFlags::kOwnership);
	}


	void TESObjectCELL::SetPublic(bool a_public)
	{
		if (a_public) {
			cellFlags |= Flag::kPublicArea;
		} else {
			cellFlags &= ~Flag::kPublicArea;
		}
		AddChange(ChangeFlags::kFlags);
	}


	bool TESObjectCELL::UsesSkyLighting() const
	{
		return (cellFlags & Flag::kUseSkyLighting) != Flag::kNone;
	}
}
