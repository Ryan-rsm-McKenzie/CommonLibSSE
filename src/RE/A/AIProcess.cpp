#include "RE/A/AIProcess.h"

#include "RE/H/HighProcessData.h"
#include "RE/M/MiddleHighProcessData.h"
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

	ActorHandle AIProcess::GetCommandingActor() const
	{
		return middleHigh ? middleHigh->commandingActor : ActorHandle{};
	}

	TESForm* AIProcess::GetEquippedLeftHand()
	{
		return equippedObjects[Hands::kLeft];
	}

	TESForm* AIProcess::GetEquippedRightHand()
	{
		return equippedObjects[Hands::kRight];
	}

	bool AIProcess::GetIsSummonedCreature() const noexcept
	{
		return middleHigh && middleHigh->summonedCreature;
	}

	ObjectRefHandle AIProcess::GetOccupiedFurniture() const
	{
		if (middleHigh) {
			return middleHigh->occupiedFurniture;
		} else {
			return {};
		}
	}

	bool AIProcess::InHighProcess() const
	{
		switch (*processLevel) {
		case PROCESS_TYPE::kHigh:
			return true;
		default:
			return false;
		}
	}

	bool AIProcess::InMiddleHighProcess() const
	{
		switch (*processLevel) {
		case PROCESS_TYPE::kHigh:
		case PROCESS_TYPE::kMiddleHigh:
			return true;
		default:
			return false;
		}
	}

	bool AIProcess::InMiddleLowProcess() const
	{
		switch (*processLevel) {
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
		switch (*processLevel) {
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
		return cachedValues && cachedValues->flags.all(CachedValues::Flags::kActorIsGhost);
	}

	void AIProcess::KnockExplosion(Actor* a_actor, const NiPoint3& a_sourceLocation, float a_magnitude)
	{
		using func_t = decltype(&AIProcess::KnockExplosion);
		REL::Relocation<func_t> func{ REL::ID(39895) };
		return func(this, a_actor, a_sourceLocation, a_magnitude);
	}

	void AIProcess::SetArrested(bool a_arrested)
	{
		if (high) {
			high->arrested = a_arrested;
		}
	}

	void AIProcess::SetActorsDetectionEvent(Actor* a_actor, const NiPoint3& a_location, std::int32_t a_soundLevel, TESObjectREFR* a_ref)
	{
		using func_t = decltype(&AIProcess::SetActorsDetectionEvent);
		REL::Relocation<func_t> func{ REL::ID(39286) };
		return func(this, a_actor, a_location, a_soundLevel, a_ref);
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
			middleHigh->update3DModel.set(a_flags);
		}
	}

	void AIProcess::Update3DModel(Actor* a_actor)
	{
		Update3DModel_Impl(a_actor);
		const SKSE::NiNodeUpdateEvent event{ a_actor };
		auto                          source = SKSE::GetNiNodeUpdateEventSource();
		if (source) {
			source->SendEvent(std::addressof(event));
		}
	}

	void AIProcess::Update3DModel_Impl(Actor* a_actor)
	{
		using func_t = decltype(&AIProcess::Update3DModel_Impl);
		REL::Relocation<func_t> func{ Offset::AIProcess::Update3DModel };
		return func(this, a_actor);
	}
}
