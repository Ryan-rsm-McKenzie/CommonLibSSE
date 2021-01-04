#include "RE/T/TESQuest.h"

#include "RE/B/BGSStoryTeller.h"
#include "SKSE/Logger.h"

namespace RE
{
	TESQuestStage::operator bool() const
	{
		return *reinterpret_cast<const std::uintptr_t*>(this) != 0;
	}

	bool TESQuest::EnsureQuestStarted(bool& a_result, bool a_startNow)
	{
		using func_t = decltype(&TESQuest::EnsureQuestStarted);
		REL::Relocation<func_t> func{ Offset::TESQuest::EnsureQuestStarted };
		return func(this, a_result, a_startNow);
	}

	std::uint16_t TESQuest::GetCurrentStageID() const
	{
		return currentStage;
	}

	bool TESQuest::IsActive() const
	{
		return data.flags.all(QuestFlag::kActive);
	}

	bool TESQuest::IsCompleted() const
	{
		return data.flags.all(QuestFlag::kCompleted);
	}

	bool TESQuest::IsEnabled() const
	{
		return data.flags.all(QuestFlag::kEnabled);
	}

	bool TESQuest::IsRunning() const
	{
		return !IsStopping() && !promoteTask;
	}

	bool TESQuest::IsStarting() const
	{
		return IsEnabled() && (data.flags == QuestFlag::kStopStart || promoteTask);
	}

	bool TESQuest::IsStopped() const
	{
		return data.flags.none(QuestFlag::kEnabled, QuestFlag::kStageWait);
	}

	bool TESQuest::IsStopping() const
	{
		return !IsEnabled() && data.flags == QuestFlag::kStopStart;
	}

	void TESQuest::Reset()
	{
		using func_t = decltype(&TESQuest::Reset);
		REL::Relocation<func_t> func{ Offset::TESQuest::ResetQuest };
		return func(this);
	}

	void TESQuest::ResetAndUpdate()
	{
		Reset();

		auto enabled = IsEnabled();
		if (enabled != StartsEnabled()) {
			auto storyTeller = BGSStoryTeller::GetSingleton();
			if (storyTeller) {
				if (enabled) {
					storyTeller->BeginStartUpQuest(this);
				} else {
					storyTeller->BeginShutDownQuest(this);
				}
			}
		}
	}

	void TESQuest::SetEnabled(bool a_set)
	{
		if (a_set) {
			data.flags.set(QuestFlag::kEnabled);
		} else {
			data.flags.reset(QuestFlag::kEnabled);
		}
		AddChange(ChangeFlags::kQuestFlags);
	}

	bool TESQuest::Start()
	{
		if (eventID != QuestEvent::kNone) {
			SKSE::log::debug("Attempting to start event scoped quest outside of story manager");
			return false;
		}

		bool result;
		return EnsureQuestStarted(result, true);
	}

	bool TESQuest::StartsEnabled() const
	{
		return data.flags.all(QuestFlag::kStartsEnabled);
	}

	void TESQuest::Stop()
	{
		if (IsEnabled()) {
			SetEnabled(false);
		}
	}
}
