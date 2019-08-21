#pragma once

#include "RE/BSScript/CompiledScriptLoader.h"  // BSScript::CompiledScriptLoader
#include "RE/BSScript/IFreezeQuery.h"  // BSScript::IFreezeQuery
#include "RE/BSScript/IStackCallbackSaveInterface.h"  // BSScript::IStackCallbackSaveInterface
#include "RE/BSScript/SimpleAllocMemoryPagePolicy.h"  // BSScript::SimpleAllocMemoryPagePolicy
#include "RE/SkyrimScript/DelayFunctor.h"  // SkyrimScript::DelayFunctor
#include "RE/SkyrimScript/HandlePolicy.h"  // SkyrimScript::HandlePolicy
#include "RE/SkyrimScript/Logger.h"  // SkyrimScript::Logger
#include "RE/SkyrimScript/Profiler.h"  // SkyrimScript::Profiler
#include "RE/SkyrimScript/SavePatcher.h"  // SkyrimScript::SavePatcher
#include "RE/SkyrimScript/ObjectBindPolicy.h"  // SkyrimScript::ObjectBindPolicy
#include "RE/SkyrimScript/Store.h"  // SkyrimScript::Store
#include "RE/BSLock.h"
#include "RE/BSTEvent.h"  // BSTEvent
#include "RE/BSTFreeList.h"  // BSTStaticFreeList
#include "RE/BSTHashMap.h"  // BSTHashMap
#include "RE/BSTMessageQueue.h"  // BSTCommonLLMessageQueue
#include "RE/BSTSingleton.h"  // BSTSingletonSDM
#include "RE/BSTSmartPointer.h"  // BSTSmartPointer


namespace RE
{
	namespace BSScript
	{
		class IVirtualMachine;
		class IVMDebugInterface;
		class IVMSaveLoadInterface;
		struct StatsEvent;
	}


	struct PositionPlayerEvent;
	struct TESActivateEvent;
	struct TESActiveEffectApplyRemoveEvent;
	struct TESActorLocationChangeEvent;
	struct TESBookReadEvent;
	struct TESCellAttachDetachEvent;
	struct TESCellFullyLoadedEvent;
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


	class SkyrimVM :
		public BSTSingletonSDM<SkyrimVM>,						// 01A0
		public BSScript::IFreezeQuery,							// 0000
		public BSScript::IStackCallbackSaveInterface,			// 0008
		public BSTEventSink<TESActivateEvent>,					// 0010
		public BSTEventSink<TESActiveEffectApplyRemoveEvent>,	// 0018
		public BSTEventSink<TESActorLocationChangeEvent>,		// 0020
		public BSTEventSink<TESBookReadEvent>,					// 0028
		public BSTEventSink<TESCellAttachDetachEvent>,			// 0030
		public BSTEventSink<TESCellFullyLoadedEvent>,			// 0038
		public BSTEventSink<TESCombatEvent>,					// 0040
		public BSTEventSink<TESContainerChangedEvent>,			// 0048
		public BSTEventSink<TESDeathEvent>,						// 0050
		public BSTEventSink<TESDestructionStageChangedEvent>,	// 0058
		public BSTEventSink<TESEnterBleedoutEvent>,				// 0060
		public BSTEventSink<TESEquipEvent>,						// 0068
		public BSTEventSink<TESFormDeleteEvent>,				// 0070
		public BSTEventSink<TESFurnitureEvent>,					// 0078
		public BSTEventSink<TESGrabReleaseEvent>,				// 0080
		public BSTEventSink<TESHitEvent>,						// 0088
		public BSTEventSink<TESInitScriptEvent>,				// 0090
		public BSTEventSink<TESLoadGameEvent>,					// 0098
		public BSTEventSink<TESLockChangedEvent>,				// 00A0
		public BSTEventSink<TESMagicEffectApplyEvent>,			// 00A8
		public BSTEventSink<TESMagicWardHitEvent>,				// 00B0
		public BSTEventSink<TESMoveAttachDetachEvent>,			// 00B8
		public BSTEventSink<TESObjectLoadedEvent>,				// 00C0
		public BSTEventSink<TESObjectREFRTranslationEvent>,		// 00C8
		public BSTEventSink<TESOpenCloseEvent>,					// 00D0
		public BSTEventSink<TESPackageEvent>,					// 00D8
		public BSTEventSink<TESPerkEntryRunEvent>,				// 00E0
		public BSTEventSink<TESQuestInitEvent>,					// 00E8
		public BSTEventSink<TESQuestStageEvent>,				// 00F0
		public BSTEventSink<TESResetEvent>,						// 00F8
		public BSTEventSink<TESResolveNPCTemplatesEvent>,		// 0100
		public BSTEventSink<TESSceneEvent>,						// 0108
		public BSTEventSink<TESSceneActionEvent>,				// 0110
		public BSTEventSink<TESScenePhaseEvent>,				// 0118
		public BSTEventSink<TESSellEvent>,						// 0120
		public BSTEventSink<TESSleepStartEvent>,				// 0128
		public BSTEventSink<TESSleepStopEvent>,					// 0130
		public BSTEventSink<TESSpellCastEvent>,					// 0138
		public BSTEventSink<TESTopicInfoEvent>,					// 0140
		public BSTEventSink<TESTrackedStatsEvent>,				// 0148
		public BSTEventSink<TESTrapHitEvent>,					// 0150
		public BSTEventSink<TESTriggerEvent>,					// 0158
		public BSTEventSink<TESTriggerEnterEvent>,				// 0160
		public BSTEventSink<TESTriggerLeaveEvent>,				// 0168
		public BSTEventSink<TESUniqueIDChangeEvent>,			// 0170
		public BSTEventSink<TESSwitchRaceCompleteEvent>,		// 0178
		public BSTEventSink<TESPlayerBowShotEvent>,				// 0180
		public BSTEventSink<TESFastTravelEndEvent>,				// 0188
		public BSTEventSink<PositionPlayerEvent>,				// 0190
		public BSTEventSink<BSScript::StatsEvent>,				// 0198
		public BSTEventSource<BSScript::StatsEvent>				// 01A8
	{
	public:
		virtual ~SkyrimVM();	// 00

		static SkyrimVM* GetSingleton();


		// members
		BSScript::IVirtualMachine*												virtualMachine;					// 0200
		BSScript::IVMSaveLoadInterface*											saveLoadInterface;				// 0208
		BSScript::IVMDebugInterface*											debugInterface;					// 0210
		BSScript::SimpleAllocMemoryPagePolicy									simpleAllocMemoryPagePolicy;	// 0218
		BSScript::CompiledScriptLoader											compiledScriptLoader;			// 0240
		SkyrimScript::Logger													logger;							// 0278
		SkyrimScript::HandlePolicy												handlePolicy;					// 0328
		SkyrimScript::ObjectBindPolicy											objectBindPolicy;				// 0398
		SkyrimScript::Store*													store;							// 0470
		BSTHashMap<UnkKey, UnkValue>											unk0478;						// 0478
		UInt64																	unk04A8;						// 04A8
		BSTHashMap<UnkKey, UnkValue>											unk04B0;						// 04B0
		UInt64																	unk04E0;						// 04E0
		BSTHashMap<UnkKey, UnkValue>											unk04E8;						// 04E8
		UInt64																	unk0518;						// 0518
		BSTHashMap<UnkKey, UnkValue>											unk0520;						// 0520
		UInt64																	unk0550;						// 0550
		BSTHashMap<UnkKey, UnkValue>											unk0558;						// 0558
		UInt64																	unk0588;						// 0588
		SkyrimScript::Profiler													profiler;						// 0590
		SkyrimScript::SavePatcher												savePatcher;					// 0670
		UInt64																	unk0678;						// 0678
		UInt64																	unk0680;						// 0680
		UInt64																	unk0688;						// 0688
		UInt64																	unk0690;						// 0690
		UInt64																	unk0698;						// 0698
		UInt64																	unk06A0;						// 06A0
		BSTArray<void*>															unk06A8;						// 06A8
		BSTArray<void*>															unk06C0;						// 06C0
		BSTArray<void*>															unk06D8;						// 06D8
		UInt64																	unk06F0;						// 06F0
		BSTArray<void*>															unk06F8;						// 06F8
		UInt64																	unk0710;						// 0710
		UInt64																	unk0718;						// 0718
		BSTArray<void*>															unk0720;						// 0720
		BSTArray<void*>															unk0738;						// 0738
		UInt64																	unk0750;						// 0750
		UInt64																	unk0758;						// 0758
		BSTHashMap<UnkKey, UnkValue>											unk0760;						// 0760
		UInt64																	unk0790;						// 0790
		BSTHashMap<UnkKey, UnkValue>											unk0798;						// 0798
		BSTStaticFreeList<BSTSmartPointer<SkyrimScript::DelayFunctor>, 512>		unk07C8;						// 07C8
		BSTCommonLLMessageQueue<BSTSmartPointer<SkyrimScript::DelayFunctor>>	unk27E0;						// 27E0
		BSTStaticFreeList<BSTSmartPointer<SkyrimScript::DelayFunctor>, 512>		unk2808;						// 2808
		BSTCommonLLMessageQueue<BSTSmartPointer<SkyrimScript::DelayFunctor>>	unk4820;						// 4820
		BSTStaticFreeList<BSTSmartPointer<SkyrimScript::DelayFunctor>, 512>		unk4848;						// 4848
		BSTCommonLLMessageQueue<BSTSmartPointer<SkyrimScript::DelayFunctor>>	unk6860;						// 6860
		BSTStaticFreeList<BSTSmartPointer<SkyrimScript::DelayFunctor>, 512>		unk6888;						// 6888
		BSTCommonLLMessageQueue<BSTSmartPointer<SkyrimScript::DelayFunctor>>	unk88A0;						// 88A0
		UInt64																	unk88C8;						// 88C8
		BSTCommonLLMessageQueue<BSTSmartPointer<SkyrimScript::DelayFunctor>>*	unk88D0;						// 88D0
		BSTCommonLLMessageQueue<BSTSmartPointer<SkyrimScript::DelayFunctor>>*	unk88D8;						// 88D8
		mutable BSUniqueLock													unk88E0;						// 88E0
		BSTCommonLLMessageQueue<BSTSmartPointer<SkyrimScript::DelayFunctor>>*	unk88E8;						// 88E8
		BSTCommonLLMessageQueue<BSTSmartPointer<SkyrimScript::DelayFunctor>>*	unk88F0;						// 88F0
		UInt64																	unk88F8;						// 88F8
		BSTHashMap<UnkKey, UnkValue>											unk8900;						// 8900
		UInt64																	unk8930;						// 8930
		UInt64																	unk8938;						// 8938
		UInt64																	unk8940;						// 8940
		BSTHashMap<UnkKey, UnkValue>											unk8948;						// 8948
	};
	STATIC_ASSERT(sizeof(SkyrimVM) == 0x8978);
}
