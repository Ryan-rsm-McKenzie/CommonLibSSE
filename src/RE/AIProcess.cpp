#include "RE/AIProcess.h"

#include "RE/HighProcessData.h"
#include "RE/Offsets.h"
#include "REL/Relocation.h"
#include "SKSE/API.h"


namespace RE
{
	float AIProcess::GetCachedHeight() const
	{
		return high ? high->cachedActorHeight : -1.0;
	}


	TESForm* AIProcess::GetEquippedLeftHand()
	{
		return equippedObjects[Hands::kLeft];
	}


	TESForm* AIProcess::GetEquippedRightHand()
	{
		return equippedObjects[Hands::kRight];
	}


	bool AIProcess::InHighProcess() const
	{
		switch (processLevel) {
		case PROCESS_TYPE::kHigh:
			return true;
		default:
			return false;
		}
	}


	bool AIProcess::InMiddleHighProcess() const
	{
		switch (processLevel) {
		case PROCESS_TYPE::kHigh:
		case PROCESS_TYPE::kMiddleHigh:
			return true;
		default:
			return false;
		}
	}


	bool AIProcess::InMiddleLowProcess() const
	{
		switch (processLevel) {
		case PROCESS_TYPE::kHigh:
		case PROCESS_TYPE::kMiddleHigh:
		case PROCESS_TYPE::kMiddleLow:
			return true;
		default:
			return false;
		}
	}


	bool AIProcess::InLowProcess() const
	{
		switch (processLevel) {
		case PROCESS_TYPE::kHigh:
		case PROCESS_TYPE::kMiddleHigh:
		case PROCESS_TYPE::kMiddleLow:
		case PROCESS_TYPE::kLow:
			return true;
		default:
			return false;
		}
	}


	bool AIProcess::IsArrested() const
	{
		return high && high->arrested;
	}


	bool AIProcess::IsGhost() const
	{
		return cachedValues && (cachedValues->flags & CachedValues::Flags::kActorIsGhost) != CachedValues::Flags::kNone;
	}


	void AIProcess::SetArrested(bool a_arrested)
	{
		if (high) {
			high->arrested = a_arrested;
		}
	}


	void AIProcess::SetCachedHeight(float a_height)
	{
		if (high) {
			high->cachedActorHeight = a_height;
		}
	}


	void AIProcess::SetEquipFlag(Flag a_flag)
	{
		using func_t = function_type_t<decltype(&AIProcess::SetEquipFlag)>;
		REL::Offset<func_t*> func(Offset::AIProcess::SetEquipFlag);
		return func(this, a_flag);
	}


	void AIProcess::UpdateEquipment(Actor* a_actor)
	{
		UpdateEquipment_Internal(a_actor);
		SKSE::NiNodeUpdateEvent event(a_actor);
		auto source = SKSE::GetNiNodeUpdateEventSource();
		source->SendEvent(&event);
	}


	void AIProcess::UpdateEquipment_Internal(Actor* a_actor)
	{
		using func_t = function_type_t<decltype(&AIProcess::UpdateEquipment_Internal)>;
		REL::Offset<func_t*> func(Offset::AIProcess::UpdateEquipment);
		return func(this, a_actor);
	}
}
