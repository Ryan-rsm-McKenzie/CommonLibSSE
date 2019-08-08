#pragma once

#include "RE/BSTEvent.h"  // BSTEventSource
#include "RE/NiSmartPointer.h"  // NiPointer


namespace RE
{
	class TESObjectREFR;
	struct BGSEventProcessedEvent;
	struct TESActivateEvent;
	struct TESActiveEffectApplyRemoveEvent;
	struct TESActorLocationChangeEvent;
	struct TESBookReadEvent;
	struct TESCellAttachDetachEvent;
	struct TESCellFullyLoadedEvent;
	struct TESCellReadyToApplyDecalsEvent;
	struct TESCombatEvent;
	struct TESContainerChangedEvent;
	struct TESDeathEvent;
	struct TESDestructionStageChangedEvent;
	struct TESEnterBleedoutEvent;
	struct TESEquipEvent;
	struct TESFastTravelEndEvent;
	struct TESFormDeleteEvent;
	struct TESFurnitureEvent;
	struct TESGrabReleaseEvent;
	struct TESHitEvent;
	struct TESInitScriptEvent;
	struct TESLoadGameEvent;
	struct TESLockChangedEvent;
	struct TESMagicEffectApplyEvent;
	struct TESMagicWardHitEvent;
	struct TESMoveAttachDetachEvent;
	struct TESObjectLoadedEvent;
	struct TESObjectREFRTranslationEvent;
	struct TESOpenCloseEvent;
	struct TESPackageEvent;
	struct TESPerkEntryRunEvent;
	struct TESPlayerBowShotEvent;
	struct TESQuestInitEvent;
	struct TESQuestStageEvent;
	struct TESQuestStageItemDoneEvent;
	struct TESQuestStartStopEvent;
	struct TESResetEvent;
	struct TESResolveNPCTemplatesEvent;
	struct TESSceneActionEvent;
	struct TESSceneEvent;
	struct TESScenePhaseEvent;
	struct TESSellEvent;
	struct TESSleepStartEvent;
	struct TESSleepStopEvent;
	struct TESSpellCastEvent;
	struct TESSwitchRaceCompleteEvent;
	struct TESTopicInfoEvent;
	struct TESTrackedStatsEvent;
	struct TESTrapHitEvent;
	struct TESTriggerEnterEvent;
	struct TESTriggerEvent;
	struct TESTriggerLeaveEvent;
	struct TESUniqueIDChangeEvent;
	struct TESWaitStartEvent;
	struct TESWaitStopEvent;


	class ScriptEventSourceHolder :
		public BSTEventSource<BGSEventProcessedEvent>,			// 0000
		public BSTEventSource<TESActivateEvent>,				// 0058
		public BSTEventSource<TESActiveEffectApplyRemoveEvent>,	// 00B0
		public BSTEventSource<TESActorLocationChangeEvent>,		// 0108
		public BSTEventSource<TESBookReadEvent>,				// 0160
		public BSTEventSource<TESCellAttachDetachEvent>,		// 01B8
		public BSTEventSource<TESCellFullyLoadedEvent>,			// 0210
		public BSTEventSource<TESCellReadyToApplyDecalsEvent>,	// 0268
		public BSTEventSource<TESCombatEvent>,					// 02C0
		public BSTEventSource<TESContainerChangedEvent>,		// 0318
		public BSTEventSource<TESDeathEvent>,					// 0370
		public BSTEventSource<TESDestructionStageChangedEvent>,	// 03C8
		public BSTEventSource<TESEnterBleedoutEvent>,			// 0420
		public BSTEventSource<TESEquipEvent>,					// 0478
		public BSTEventSource<TESFormDeleteEvent>,				// 04D0
		public BSTEventSource<TESFurnitureEvent>,				// 0528
		public BSTEventSource<TESGrabReleaseEvent>,				// 0580
		public BSTEventSource<TESHitEvent>,						// 05D8
		public BSTEventSource<TESInitScriptEvent>,				// 0630
		public BSTEventSource<TESLoadGameEvent>,				// 0688
		public BSTEventSource<TESLockChangedEvent>,				// 06E0
		public BSTEventSource<TESMagicEffectApplyEvent>,		// 0738
		public BSTEventSource<TESMagicWardHitEvent>,			// 0790
		public BSTEventSource<TESMoveAttachDetachEvent>,		// 07E8
		public BSTEventSource<TESObjectLoadedEvent>,			// 0840
		public BSTEventSource<TESObjectREFRTranslationEvent>,	// 0898
		public BSTEventSource<TESOpenCloseEvent>,				// 08F0
		public BSTEventSource<TESPackageEvent>,					// 0948
		public BSTEventSource<TESPerkEntryRunEvent>,			// 09A0
		public BSTEventSource<TESQuestInitEvent>,				// 09F8
		public BSTEventSource<TESQuestStageEvent>,				// 0A50
		public BSTEventSource<TESQuestStageItemDoneEvent>,		// 0AA8
		public BSTEventSource<TESQuestStartStopEvent>,			// 0B00
		public BSTEventSource<TESResetEvent>,					// 0B58
		public BSTEventSource<TESResolveNPCTemplatesEvent>,		// 0BB0
		public BSTEventSource<TESSceneEvent>,					// 0C08
		public BSTEventSource<TESSceneActionEvent>,				// 0C60
		public BSTEventSource<TESScenePhaseEvent>,				// 0CB8
		public BSTEventSource<TESSellEvent>,					// 0D10
		public BSTEventSource<TESSleepStartEvent>,				// 0D68
		public BSTEventSource<TESSleepStopEvent>,				// 0DC0
		public BSTEventSource<TESSpellCastEvent>,				// 0E18
		public BSTEventSource<TESPlayerBowShotEvent>,			// 0E70
		public BSTEventSource<TESTopicInfoEvent>,				// 0EC8
		public BSTEventSource<TESTrackedStatsEvent>,			// 0F20
		public BSTEventSource<TESTrapHitEvent>,					// 0F78
		public BSTEventSource<TESTriggerEvent>,					// 0FD0
		public BSTEventSource<TESTriggerEnterEvent>,			// 1028
		public BSTEventSource<TESTriggerLeaveEvent>,			// 1080
		public BSTEventSource<TESUniqueIDChangeEvent>,			// 10D8
		public BSTEventSource<TESWaitStartEvent>,				// 1130 - ?
		public BSTEventSource<TESWaitStopEvent>,				// 1188 - ?
		public BSTEventSource<TESSwitchRaceCompleteEvent>,		// 11E0
		public BSTEventSource<TESFastTravelEndEvent>			// 1238
	{
	public:
		static ScriptEventSourceHolder* GetSingleton();

		void									SendActivateEvent(NiPointer<TESObjectREFR>& a_target, NiPointer<TESObjectREFR>& a_caster);
		template <class T> BSTEventSource<T>*	GetEventSource();
		template <class T> void					AddEventSink(BSTEventSink<T>* a_sink);
		template <class T> void					SendEvent(T* a_event);
	};
	STATIC_ASSERT(sizeof(ScriptEventSourceHolder) == 0x1290);


	template <class T>
	BSTEventSource<T>* ScriptEventSourceHolder::GetEventSource()
	{
		return static_cast<BSTEventSource<T>*>(this);
	}


	template <class T>
	void ScriptEventSourceHolder::AddEventSink(BSTEventSink<T>* a_sink)
	{
		GetEventSource<T>()->AddEventSink(a_sink);
	}


	template <class T>
	void ScriptEventSourceHolder::SendEvent(T* a_event)
	{
		GetEventSource<T>()->SendEvent(a_event);
	}
}
