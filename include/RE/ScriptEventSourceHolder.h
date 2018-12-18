#pragma once

#include "skse64/GameEvents.h"  // TESActiveEffectApplyRemoveEvent, TESCellAttachDetachEvent, TESCombatEvent, TESContainerChangedEvent, TESDeathEvent, TESInitScriptEvent, TESObjectLoadedEvent, TESUniqueIDChangeEvent

#include "RE/BSTEvent.h"  // BSTEventSource
#include "RE/TESEquipEvent.h"  // TESEquipEvent
#include "RE/TESMagicEffectApplyEvent.h"  // TESMagicEffectApplyEvent
#include "RE/TESObjectREFR.h"  // TESObjectREFRPtr


namespace RE
{
	struct BGSEventProcessedEvent;
	struct TESActivateEvent;
	struct TESActorLocationChangeEvent;
	struct TESBookReadEvent;
	struct TESCellFullyLoadedEvent;
	struct TESCellReadyToApplyDecalsEvent;
	struct TESDestructionStageChangedEvent;
	struct TESEnterBleedoutEvent;
	struct TESFormDeleteEvent;
	struct TESFurnitureEvent;
	struct TESGrabReleaseEvent;
	struct TESHitEvent;
	struct TESLoadGameEvent;
	struct TESLockChangedEvent;
	struct TESMagicWardHitEvent;
	struct TESMoveAttachDetachEvent;
	struct TESObjectREFRTranslationEvent;
	struct TESOpenCloseEvent;
	struct TESPackageEvent;
	struct TESPerkEntryRunEvent;
	struct TESQuestInitEvent;
	struct TESQuestStageEvent;
	struct TESQuestStageItemDoneEvent;
	struct TESQuestStartStopEvent;
	struct TESResetEvent;
	struct TESResolveNPCTemplatesEvent;
	struct TESSceneEvent;
	struct TESSceneActionEvent;
	struct TESScenePhaseEvent;
	struct TESSellEvent;
	struct TESSleepStartEvent;
	struct TESSleepStopEvent;
	struct TESSpellCastEvent;
	struct TESPlayerBowShotEvent;
	struct TESTopicInfoEvent;
	struct TESTrackedStatsEvent;
	struct TESTrapHitEvent;
	struct TESTriggerEvent;
	struct TESTriggerEnterEvent;
	struct TESTriggerLeaveEvent;


	class ScriptEventSourceHolder
	{
	public:
		static ScriptEventSourceHolder*	GetSingleton();
		void							SendActivateEvent(TESObjectREFRPtr& a_target, TESObjectREFRPtr& a_caster);


		// members
		BSTEventSource<BGSEventProcessedEvent>			eventProcessedEventSource;			// 0000 - sink offset 000
		BSTEventSource<TESActivateEvent>				activateEventSource;				// 0058 - sink offset 008
		BSTEventSource<TESActiveEffectApplyRemoveEvent>	activeEffectApplyRemoveEventSource;	// 00B0 - sink offset 010
		BSTEventSource<TESActorLocationChangeEvent>		actorLocationChangeEventSource;		// 0108 - sink offset 018
		BSTEventSource<TESBookReadEvent>				bookReadEventSource;				// 0160 - sink offset 020
		BSTEventSource<TESCellAttachDetachEvent>		cellAttachDetachEventSource;		// 01B8 - sink offset 028
		BSTEventSource<TESCellFullyLoadedEvent>			cellFullyLoadedEventSource;			// 0210 - sink offset 030
		BSTEventSource<TESCellReadyToApplyDecalsEvent>	cellReadyToApplyDecalsEventSource;	// 0268 - sink offset 038
		BSTEventSource<TESCombatEvent>					combatEventSource;					// 02C0 - sink offset 040
		BSTEventSource<TESContainerChangedEvent>		containerChangedEventSource;		// 0318 - sink offset 048
		BSTEventSource<TESDeathEvent>					deathEventSource;					// 0370 - sink offset 050
		BSTEventSource<TESDestructionStageChangedEvent>	destructionStageChangedEventSource;	// 03C8 - sink offset 058
		BSTEventSource<TESEnterBleedoutEvent>			enterBleedoutEventSource;			// 0420 - sink offset 060
		BSTEventSource<TESEquipEvent>					equipEventSource;					// 0478 - sink offset 078
		BSTEventSource<TESFormDeleteEvent>				formDeleteEventSource;				// 04D0 - sink offset 080
		BSTEventSource<TESFurnitureEvent>				furnitureEventSource;				// 0528 - sink offset 088
		BSTEventSource<TESGrabReleaseEvent>				grabReleaseEventSource;				// 0580 - sink offset 090
		BSTEventSource<TESHitEvent>						hitEventSource;						// 05D8 - sink offset 098
		BSTEventSource<TESInitScriptEvent>				initScriptEventSource;				// 0630 - sink offset 0A0
		BSTEventSource<TESLoadGameEvent>				loadGameEventSource;				// 0688 - sink offset 0A8
		BSTEventSource<TESLockChangedEvent>				lockChangedEventSource;				// 06E0 - sink offset 0B0
		BSTEventSource<TESMagicEffectApplyEvent>		magicEffectApplyEventSource;		// 0738 - sink offset 0B8
		BSTEventSource<TESMagicWardHitEvent>			magicWardHitEventSource;			// 0790 - sink offset 0C0
		BSTEventSource<TESMoveAttachDetachEvent>		moveAttachDetachEventSource;		// 07E8 - sink offset 0C8
		BSTEventSource<TESObjectLoadedEvent>			objectLoadedEventSource;			// 0840 - sink offset 0D0
		BSTEventSource<TESObjectREFRTranslationEvent>	objectREFRTranslationEventSource;	// 0898 - sink offset 0D8
		BSTEventSource<TESOpenCloseEvent>				openCloseEventSource;				// 08F0 - sink offset 0E0
		BSTEventSource<TESPackageEvent>					packageEventSource;					// 0948 - sink offset 0E8
		BSTEventSource<TESPerkEntryRunEvent>			perkEntryRunEventSource;			// 09A0 - sink offset 0F0
		BSTEventSource<TESQuestInitEvent>				questInitEventSource;				// 09F8 - sink offset 0F8
		BSTEventSource<TESQuestStageEvent>				questStageEventSource;				// 0A50 - sink offset 100
		BSTEventSource<TESQuestStageItemDoneEvent>		questStageItemDoneEventSource;		// 0AA8 - sink offset 108
		BSTEventSource<TESQuestStartStopEvent>			questStartStopEventSource;			// 0B00 - sink offset 110
		BSTEventSource<TESResetEvent>					resetEventSource;					// 0B58 - sink offset 118
		BSTEventSource<TESResolveNPCTemplatesEvent>		resolveNPCTemplatesEventSource;		// 0BB0 - sink offset 120
		BSTEventSource<TESSceneEvent>					sceneEventSource;					// 0C08 - sink offset 128
		BSTEventSource<TESSceneActionEvent>				sceneActionEventSource;				// 0C60 - sink offset 130
		BSTEventSource<TESScenePhaseEvent>				scenePhaseEventSource;				// 0CB8 - sink offset 138
		BSTEventSource<TESSellEvent>					sellEventSource;					// 0D10 - sink offset 140
		BSTEventSource<TESSleepStartEvent>				sleepStartEventSource;				// 0D68 - sink offset 148
		BSTEventSource<TESSleepStopEvent>				sleepStopEventSource;				// 0DC0 - sink offset 150
		BSTEventSource<TESSpellCastEvent>				spellCastEventSource;				// 0E18 - sink offset 158
		BSTEventSource<TESPlayerBowShotEvent>			playerBowShotEventSource;			// 0E70 - sink offset 160
		BSTEventSource<TESTopicInfoEvent>				topicInfoEventSource;				// 0EC8 - sink offset 168
		BSTEventSource<TESTrackedStatsEvent>			trackedStatsEventSource;			// 0F20 - sink offset 170
		BSTEventSource<TESTrapHitEvent>					trapHitEventSource;					// 0F78 - sink offset 178
		BSTEventSource<TESTriggerEvent>					triggerEventSource;					// 0FD0 - sink offset 180
		BSTEventSource<TESTriggerEnterEvent>			triggerEnterEventSource;			// 1028 - sink offset 188
		BSTEventSource<TESTriggerLeaveEvent>			triggerLeaveEventSource;			// 1080 - sink offset 190
		BSTEventSource<TESUniqueIDChangeEvent>			uniqueIDChangeEventSource;			// 10D8 - sink offset 198
		BSTEventSource<TESWaitStartEvent>				waitStartEventSource;				// 1130 - sink offset 1A0
		BSTEventSource<TESWaitStopEvent>				waitStopEventSource;				// 1188 - sink offset 1A8
		BSTEventSource<TESSwitchRaceCompleteEvent>		switchRaceCompleteEventSource;		// 11E0 - sink offset 1B0
		BSTEventSource<void>							unk1238;							// 1238 - sink offset 1B8 - new in SE?
	};
	STATIC_ASSERT(sizeof(ScriptEventSourceHolder) == 0x1290);
}
