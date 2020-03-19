#include "RE/AIProcess.h"

#include "RE/HighProcessData.h"
#include "RE/MiddleHighProcessData.h"
#include "RE/Offsets.h"
#include "REL/Relocation.h"
#include "SKSE/API.h"


namespace RE
{
	float AIProcess::GetCachedHeight() const
	{
		return high ? high->cachedActorHeight : static_cast<float>(-1.0);
	}


	bhkCharacterController* AIProcess::GetCharController()
	{
		return middleHigh ? middleHigh->charController.get() : nullptr;
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


	void AIProcess::Set3DUpdateFlag(RESET_3D_FLAGS a_flags)
	{
		if (middleHigh) {
			middleHigh->update3DModel |= a_flags;
		}
	}


	void AIProcess::Update3DModel(Actor* a_actor)
	{
		Update3DModel_Impl(a_actor);
		const SKSE::NiNodeUpdateEvent event(a_actor);
		auto source = SKSE::GetNiNodeUpdateEventSource();
		assert(source);	 // api failed to init
		source->SendEvent(&event);
	}


	void AIProcess::Update3DModel_Impl(Actor* a_actor)
	{
		using func_t = decltype(&AIProcess::Update3DModel_Impl);
		REL::Offset<func_t> func(Offset::AIProcess::Update3DModel);
		return func(this, a_actor);
	}
}
