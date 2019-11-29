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
		return owner->Is(FormType::NPC) ? static_cast<TESNPC*>(owner) : 0;
	}


	auto TESObjectCELL::GetCoordinates()
		-> Coordinates*
	{
		return IsExteriorCell() ? lightingCoordinates.coordinates : 0;
	}


	TESFaction* TESObjectCELL::GetFactionOwner()
	{
		auto owner = GetOwner();
		return owner->Is(FormType::Faction) ? static_cast<TESFaction*>(owner) : 0;
	}


	auto TESObjectCELL::GetLighting()
		-> Lighting*
	{
		return IsInteriorCell() ? lightingCoordinates.lighting : 0;
	}


	float TESObjectCELL::GetNorthRotation()
	{
		if (IsExteriorCell()) {
			return worldSpace->northRotation;
		} else {
			auto xNorth = extraList.GetByType<ExtraNorthRotation>();
			return xNorth ? xNorth->rotation : 0.0;
		}
	}


	TESForm* TESObjectCELL::GetOwner()
	{
		auto owner = extraList.GetOwner();
		if (owner) {
			return owner;
		}

		BGSEncounterZone* zone = 0;
		if (data) {
			zone = data->encounterZone;
		} else {
			zone = extraList.GetEncounterZone();
			if (!zone && IsExteriorCell()) {
				zone = worldSpace ? worldSpace->encounterZone : 0;
			}
		}

		return zone ? zone->data.owner : 0;
	}


	bool TESObjectCELL::IsAttached() const
	{
		return attachedState == AttachedState::kAttached;
	}


	bool TESObjectCELL::IsExteriorCell() const
	{
		return !IsInteriorCell();
	}


	bool TESObjectCELL::IsInteriorCell() const
	{
		return (flags & Flag::kIsInteriorCell) != Flag::kNone;
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
			flags |= Flag::kHandChanged;
		} else {
			flags &= ~Flag::kHandChanged;
		}
		MarkChanged(1 << 1);
	}


	void TESObjectCELL::SetOwner(TESForm* a_owner)
	{
		extraList.SetOwner(a_owner);
		MarkChanged(1 << 3);
	}


	void TESObjectCELL::SetPublic(bool a_public)
	{
		if (a_public) {
			flags |= Flag::kPublicArea;
		} else {
			flags &= ~Flag::kPublicArea;
		}
		MarkChanged(1 << 1);
	}


	bool TESObjectCELL::UsesSkyLighting() const
	{
		return (flags & Flag::kUseSkyLighting) != Flag::kNone;
	}
}
