#pragma once

#include "RE/ActiveEffect.h"
#include "RE/ActorState.h"
#include "RE/ActorValueOwner.h"
#include "RE/ActorValues.h"
#include "RE/AITimeStamp.h"
#include "RE/BGSEntryPointPerkEntry.h"
#include "RE/BSPointerHandle.h"
#include "RE/BSTArray.h"
#include "RE/BSTEvent.h"
#include "RE/BSTList.h"
#include "RE/BSTSmartPointer.h"
#include "RE/BSTTuple.h"
#include "RE/FormTypes.h"
#include "RE/IPostAnimationChannelUpdateFunctor.h"
#include "RE/MagicTarget.h"
#include "RE/NiSmartPointer.h"
#include "RE/TESNPC.h"
#include "RE/TESObjectREFR.h"


namespace RE
{
	class ActorMagicCaster;
	class ActorMover;
	class AIProcess;
	class bhkCharacterMoveFinishEvent;
	class BSTransformDeltaEvent;
	class ExtraDataList;
	class InventoryEntryData;
	class MovementControllerNPC;
	class NiRefObject;
	class PerkEntryVisitor;


	enum class ACTOR_CRITICAL_STAGE : UInt32
	{
		kNone = 0,
		kGooStart = 1,
		kGooEnd = 2,
		kDisintegrateStart = 3,
		kDisintegrateEnd = 4,

		kTotal
	};


	struct Modifiers
	{
		struct Mods
		{
			enum Mod
			{
				kPermanent = 0,
				kTemporary,
				kDamage,

				kTotal
			};
		};
		using Mod = Mods::Mod;


		// members
		float modifiers[Mod::kTotal];	// 0
	};
	STATIC_ASSERT(sizeof(Modifiers) == 0xC);


	struct ActorValueStorage
	{
		template <class T>
		struct LocalMap
		{
			T* operator[](ActorValue8 a_actorValue)
			{
				auto akVals = reinterpret_cast<const ActorValue8*>(actorValues.data());
				if (akVals && entries) {
					UInt32 idx = 0;
					while (akVals[idx] != static_cast<ActorValue8>(0)) {
						if (akVals[idx] == a_actorValue) {
							break;
						}
						++idx;
					}
					if (akVals[idx] != static_cast<ActorValue8>(0)) {
						return &entries[idx];
					}
				}
				return 0;
			}


			T* operator[](ActorValue a_actorValue)
			{
				return operator[](static_cast<ActorValue8>(a_actorValue));
			}


			// members
			BSFixedString	actorValues;	// 00
			T*				entries;		// 08
		};
		STATIC_ASSERT(sizeof(LocalMap<float>) == 0x10);


		// members
		LocalMap<float>		baseValues;	// 00
		LocalMap<Modifiers>	modifiers;	// 10
	};
	STATIC_ASSERT(sizeof(ActorValueStorage) == 0x20);


	class Actor :
		public TESObjectREFR,								// 000
		public MagicTarget,									// 098
		public ActorValueOwner,								// 0B0
		public ActorState,									// 0B8
		public BSTEventSink<BSTransformDeltaEvent>,			// 0C8
		public BSTEventSink<bhkCharacterMoveFinishEvent>,	// 0D0
		public IPostAnimationChannelUpdateFunctor			// 0D8
	{
	private:
		using EntryPoint = BGSEntryPointPerkEntry::EntryPoint;

	public:
		inline static const void* RTTI = RTTI_Actor;


		enum { kTypeID = FormType::ActorCharacter };


		struct SlotTypes
		{
			enum
			{
				kLeftHand = 0,
				kRightHand,
				kUnknown,
				kPowerOrShout,

				kTotal
			};
		};


		enum class BOOL_BITS : UInt32
		{
			kNone = 0,
			kDelayUpdateScenegraph = 1 << 0,
			kProcessMe = 1 << 1,
			kMurderAlarm = 1 << 2,
			kHasSceneExtra = 1 << 3,
			kHeadingFixed = 1 << 4,
			kSpeakingDone = 1 << 5,
			kIgnoreChangeAnimationCall = 1 << 6,
			kSoundFileDone = 1 << 7,
			kVoiceFileDone = 1 << 8,
			kInTempChangeList = 1 << 9,
			kDoNotRunSayToCallback = 1 << 10,
			kDead = 1 << 11,
			kForceGreetingPlayer = 1 << 12,
			kForceUpdateQuestTarget = 1 << 13,
			kSearchingInCombat = 1 << 14,
			kAttackOnNextTheft = 1 << 15,
			kEvpBuffered = 1 << 16,
			kResetAI = 1 << 17,
			kInWater = 1 << 18,
			kSwimming = 1 << 19,
			kVoicePausedByScript = 1 << 20,
			kWasInFrustrum = 1 << 21,
			kShouldRotateToTrack = 1 << 22,
			kSetOnDeath = 1 << 23,
			kDoNotPadVoice = 1 << 24,
			kFootIKInRange = 1 << 25,
			kPlayerTeammate = 1 << 26,
			kGivePlayerXP = 1 << 27,
			kSoundCallbackSuccess = 1 << 28,
			kUseEmotion = 1 << 29,
			kGuard = 1 << 30,
			kParalyzed = (UInt32)1 << 31
		};


		enum class BOOL_FLAGS : UInt32
		{
			kNone = 0,
			kScenePackage = 1 << 0,
			kIsAMount = 1 << 1,
			kMountPointClear = 1 << 2,
			kGettingOnOffMount = 1 << 3,
			kInRandomScene = 1 << 4,
			kNoBleedoutRecovery = 1 << 5,
			kInBleedoutAnimation = 1 << 6,
			kCanDoFavor = 1 << 7,
			kShouldAnimGraphUpdate = 1 << 8,
			kCanSpeakToEssentialDown = 1 << 9,
			kBribedByPlayer = 1 << 10,
			kAngryWithPlayer = 1 << 11,
			kIsTrespassing = 1 << 12,
			kCanSpeak = 1 << 13,
			kIsInKillMove = 1 << 14,
			kAttackOnSight = 1 << 15,
			kIsCommandedActor = 1 << 16,
			kForceOneAnimgraphUpdate = 1 << 17,
			kEssential = 1 << 18,
			kProtected = 1 << 19,
			kAttackingDisabled = 1 << 20,
			kCastingDisabled = 1 << 21,
			kSceneHeadTrackRotation = 1 << 22,
			kForceIncMinBoneUpdate = 1 << 23,
			kCrimeSearch = 1 << 24,
			kMovingIntoLoadedArea = 1 << 25,
			kDoNotShowOnStealthMeter = 1 << 26,
			kMovementBlocked = 1 << 27,
			kAllowInstantFurniturePopInPlayerCell = 1 << 28,
			kForceAnimGraphUpdate = 1 << 29,
			kCheckAddEffectDualCast = 1 << 30,
			kUnderwater = (UInt32)1 << 31
		};


		struct ChangeFlags
		{
			enum ChangeFlag : UInt32
			{
				kLifeState = 1 << 10,
				kPackageExtraData = 1 << 11,
				kMerchantContainer = 1 << 12,
				kDismemberedLimbs = 1 << 17,
				kLeveledActor = 1 << 18,
				kDispModifiers = 1 << 19,
				kTempModifiers = 1 << 20,
				kDamageModifiers = 1 << 21,
				kOverrideModifiers = 1 << 22,
				kPermanentModifiers = 1 << 23,
			};
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kStartsDead = 1 << 9,
				kPersistent = 1 << 10,
				kInitiallyDisabled = 1 << 11,
				kIgnored = 1 << 12,
				kNoAIAcquire = 1 << 25,
				kDontHavokSettle = 1 << 29
			};
		};


		virtual	~Actor();																																																												// 000

		// override (TESObjectREFR)
		virtual void							SaveGame(BGSSaveFormBuffer* a_buf) override;																																											// 00E
		virtual void							LoadGame(BGSLoadFormBuffer* a_buf) override;																																											// 00F
		virtual void							InitLoadGame(void* a_arg1) override;																																													// 010
		virtual void							FinishLoadGame(void* a_arg1) override;																																													// 011
		virtual void							Revert(void* a_arg1) override;																																															// 012
		virtual void							InitItemImpl() override;																																																// 013
		virtual void							SetDelete(bool a_set) override;																																															// 023
		virtual void							Predestroy() override;																																																	// 03B
		virtual BGSLocation*					GetEditorLocation() override;																																															// 03C - { return editorLocation; }
		virtual bool							GetEditorLocation(NiPoint3& a_outPos, NiPoint3& a_outRot, TESForm*& a_outWorldOrCell, TESObjectCELL* a_veryRarelyUsedFallback) override;																				// 03D
		virtual void							ForceEditorLocation(BGSLocation* a_location) override;																																									// 03E - { editorLocation = a_location; }
		virtual void							Update3DPosition(bool a_arg1) override;																																													// 03F
		virtual void							UpdateSoundCallBack() override;																																															// 040
		virtual void							SetDialoguewithPlayer(void) override;																																													// 041
		virtual void							GetSequencer(void) override;																																															// 045 - { return aiProcess->highProcess->unk50; }
		virtual bool							HasKeywordHelper(BGSKeyword* a_keyword) override;																																										// 048
		virtual void							CheckForCurrentAliasPackage(void) override;																																												// 049 - { return 0; }
		virtual BGSScene*						GetCurrentScene() const override;																																														// 04A
		virtual void							SetCurrentScene(BGSScene* a_scene) override;																																											// 04B
		virtual void							UpdateInDialogue(void) override;																																														// 04C
		virtual void*							GetExclusiveBranch() override;																																															// 04D - { return exclusiveBranch; }
		virtual void							SetExclusiveBranch(void* a_branch) override;																																											// 04E - { exclusiveBranch = a_arg1; }
		virtual void							PauseCurrentDialogue(void) override;																																													// 04F
		virtual NiPoint3*						GetStartingAngle(NiPoint3& a_angle) const override;																																										// 052
		virtual NiPoint3*						GetStartingLocation(NiPoint3& a_location) const override;																																								// 053
		virtual ObjectRefHandle&				RemoveItem(ObjectRefHandle& a_dropHandle, TESBoundObject* a_item, SInt32 a_count, ITEM_REMOVE_REASON a_reason, ExtraDataList* a_extraList, TESObjectREFR* a_moveToRef, void* a_arg7 = 0, void* a_arg8 = 0) override;	// 056
		virtual bool							AddWornItem(TESBoundObject* a_item, SInt32 a_count, bool a_arg3, UInt32 a_arg4, UInt32 a_arg5) override;																												// 057
		virtual void							DoTrap(void* a_arg1) override;																																															// 058
		virtual void							DoTrap(void* a_arg1, void* a_arg2) override;																																											// 059
		virtual void							AddItem(TESBoundObject* a_item, ExtraDataList* a_extraList, SInt32 a_count, TESObjectREFR* a_fromRefr) override;																										// 05A
		virtual NiPoint3*						GetLookingAtLocation(NiPoint3& a_location) const override;																																								// 05B
		virtual MagicCaster*					GetMagicCaster(UInt32 a_slot) override;																																													// 05C
		virtual MagicTarget*					GetMagicTarget() override;																																																// 05D - { return static_cast<MagicTarget*>(this); }
		virtual bool							IsChild() const override;																																																// 05E - { return false; }
		virtual BSFaceGenAnimationData*			GetFaceGenAnimationData() override;																																														// 063
		virtual bool							DetachHavok() override;																																																	// 065
		virtual void							InitHavok() override;																																																	// 066
		virtual void							Unk_67(void) override;																																																	// 067 - related to vampire lord cape
		virtual void							Unk_68(void) override;																																																	// 068
		virtual void							Unk_69(void) override;																																																	// 069
		virtual void							Load3D(bool a_arg1) override;																																															// 06A
		virtual void							Set3D(NiAVObject* a_root, UInt32 a_arg2 = 1) override;																																									// 06C
		virtual void							PopulateGraphProjectsToLoad(void) override;																																												// 072
		virtual NiPoint3*						GetBoundMin(NiPoint3& a_min) const override;																																											// 073
		virtual NiPoint3*						GetBoundMax(NiPoint3& a_max) const override;																																											// 074
		virtual void							Unk_75(void) override;																																																	// 075 - "ActorValue GetWeaponSkill()"? really weird call, only works for right hand, and defaults to 1
		virtual void							Unk_78(void) override;																																																	// 078
		virtual void							ModifyAnimationUpdateData(void) override;																																												// 079
		virtual bool							ShouldSaveAnimationOnUnloading(void) override;																																											// 07A - { return false; }
		virtual bool							ShouldSaveAnimationOnSaving(void) override;																																												// 07B
		virtual bool							ShouldPerformRevert(void) override;																																														// 07C
		virtual void							UpdateAnimation(void) override;																																															// 07D
		virtual void							Unk_82(void) override;																																																	// 082
		virtual void							SetObjectReference(TESBoundObject* a_object) override;																																									// 084
		virtual void							MoveHavok(bool a_arg1) override;																																														// 085
		virtual NiPoint3*						GetLinearVelocity(NiPoint3& a_velocity) const override;																																									// 086
		virtual void							SetActionComplete(void) override;																																														// 087
		virtual void							Disable() override;																																																		// 089
		virtual void							ResetInventory(bool a_regenerate) override;																																												// 08A
		virtual void							Unk_8B(void) override;																																																	// 08B
		virtual void							Unk_8C(void) override;																																																	// 08C
		virtual bool							OnAddCellPerformQueueReference(TESObjectCELL* a_cell) const override;																																					// 090
		virtual void							DoMoveToHigh() override;																																																// 091
		virtual void							TryMoveToMiddleLow() override;																																															// 092
		virtual bool							TryChangeSkyCellActorsProcessLevel() override;																																											// 093
		virtual void							Unk_95(void) override;																																																	// 095
		virtual void							Unk_96(void) override;																																																	// 096
		virtual void							Unk_98(void) override;																																																	// 098
		virtual bool							IsDead(bool a_noDying = true) override;																																													// 099
		virtual void							Unk_9C(void) override;																																																	// 09C
		virtual void							Unk_9D(void) override;																																																	// 09D
		virtual void							Unk_9E(void) override;																																																	// 09E
		virtual void							UnequipItem(UInt64 a_arg1, TESBoundObject* a_item) override;																																							// 0A1

		// override (MagicTarget)
		virtual Actor*							GetTargetStatsObject() override;																																														// 002 - { return this; }
		virtual bool							MagicTargetIsActor() const override;																																													// 003 - { return true; }
		virtual BSSimpleList<ActiveEffect*>*	GetActiveEffectList() override;																																															// 007

		// add
		virtual void							Unk_A2(void);																																																			// 0A2
		virtual void							PlayPickUpSound(TESBoundObject* a_item, bool a_pickup, bool a_consume);																																					// 0A3
		virtual float							GetHeading(bool a_ignoreRaceSettings);																																													// 0A4
		virtual void							SetAvoidanceDisabled(void);																																																// 0A5 - { return; }
		virtual void							DrawWeaponMagicHands(bool a_draw);																																														// 0A6
		virtual void							Unk_A7(void);																																																			// 0A7
		virtual void							Unk_A8(void);																																																			// 0A8
		virtual void							SetPosition(NiPoint3& a_pos);																																															// 0A9
		virtual void							KillDying();																																																			// 0AA
		virtual void							Resurrect(bool a_arg1);																																																	// 0AB
		virtual void							PutActorOnMountQuick();																																																	// 0AC
		virtual void							Update(void);																																																			// 0AD
		virtual void							UpdateNoAI(void);																																																		// 0AE - { return UpdateActor3DPosition(); }
		virtual void							UpdateCharacterControllerSimulationSettings(void);																																										// 0AF
		virtual void							PotentiallyFixRagdollState();																																															// 0B0
		virtual void							UpdateNonRenderSafe(float a_arg1);																																														// 0B1
		virtual void							OnItemEquipped(bool a_playAnim);																																														// 0B2
		virtual void							Unk_B3(void);																																																			// 0B3 - { return 1; }
		virtual void							Unk_B4(void);																																																			// 0B4
		virtual void							SetCrimeGoldValue(TESFaction* a_faction, bool a_violent, SInt32 a_amount);																																				// 0B5
		virtual void							ModCrimeGoldValue(TESFaction* a_faction, bool a_violent, SInt32 a_amount);																																				// 0B6
		virtual void							RemoveCrimeGoldValue(TESFaction* a_faction, SInt32 a_amount, bool a_violent);																																			// 0B7
		virtual SInt32							GetCrimeGoldValue(const TESFaction* a_faction) const;																																									// 0B8
		virtual void							GoToPrison(TESFaction* a_faction, bool a_removeInventory, bool a_realJail);																																				// 0B9 - { return; }
		virtual void							ServePrisonTime(void);																																																	// 0BA - { return; }
		virtual void							PayFine(TESFaction* a_faction, bool a_goToJail, bool a_removeStolenItems);																																				// 0BB - { return; }
		virtual bool							GetCannibal();																																																			// 0BC - { return false; }
		virtual void							SetCannibal(void);																																																		// 0BD - { return; }
		virtual bool							GetVampireFeed();																																																		// 0BE - { return false; }
		virtual void							SetVampireFeed(void);																																																	// 0BF - { return; }
		virtual void							InitiateVampireFeedPackage(void);																																														// 0C0 - { return; }
		virtual void							InitiateCannibalPackage(void);																																															// 0C1 - { return; }
		virtual void							GetEyeVector(NiPoint3& a_vector);																																														// 0C2
		virtual void							SetRefraction(bool a_arg1, float a_refraction);																																											// 0C3
		virtual void							Unk_C4(void);																																																			// 0C4 - { return; }
		virtual void							Unk_C5(void);																																																			// 0C5 - { return 1; }
		virtual void							Unk_C6(void) = 0;																																																		// 0C6
		virtual float							GetAcrobatics();																																																		// 0C7 - { return 1.0; }
		virtual void							Unk_C8(void);																																																			// 0C8
		virtual void							Unk_C9(void);																																																			// 0C9
		virtual void							OnArmorActorValueChanged();																																																// 0CA - { return; }
		virtual void							DropObject(ObjectRefHandle& a_droppedItemHandle, TESBoundObject* a_object, ExtraDataList* a_extraList, UInt32 a_count, void* a_arg5 = 0, void* a_arg6 = 0);																// 0CB
		virtual void							PickUpObject(TESObjectREFR* a_object, UInt32 a_count, bool a_arg3 = false, bool a_playSound = true);																													// 0CC
		virtual void							AttachArrow(void);																																																		// 0CD
		virtual void							DetachArrow(void);																																																		// 0CE
		virtual bool							AddShout(TESShout* a_shout);																																															// 0CF
		virtual void							Unk_D0(void);																																																			// 0D0 - { return; }
		virtual void							Unk_D1(void);																																																			// 0D1
		virtual void							Unk_D2(void);																																																			// 0D2
		virtual bool							CalculateCachedOwnerIsInCombatantFaction();																																												// 0D3
		virtual void							GetCombatGroup(void);																																																	// 0D4
		virtual void							SetCombatGroup(void);																																																	// 0D5
		virtual void							CheckValidTarget(void);																																																	// 0D6
		virtual void							Unk_D7(void);																																																			// 0D7 - { return 0; }
		virtual void							InitiateDialogue(void);																																																	// 0D8
		virtual void							Unk_D9(void);																																																			// 0D9
		virtual void							EndDialogue(void);																																																		// 0DA
		virtual void							SetUpTalkingActivatorActor(void);																																														// 0DB
		virtual void							Unk_DC(void);																																																			// 0DC - { return; }
		virtual void							InitiateFlee(void);																																																		// 0DD
		virtual void							InitiateGetUpPackage(void);																																																// 0DE
		virtual void							PutCreatedPackage(void);																																																// 0DF
		virtual void							UpdateAlpha();																																																			// 0E0
		virtual void							SetAlpha(float a_alpha = 1.0);																																															// 0E1
		virtual float							GetAlpha() const;																																																		// 0E2
		virtual bool							IsInCombat() const;																																																		// 0E3
		virtual void							UpdateCombat();																																																			// 0E4
		virtual void							StopCombat();																																																			// 0E5
		virtual void							Unk_E6(void);																																																			// 0E6 - { return 0.0; }
		virtual void							Unk_E7(void);																																																			// 0E7 - { return 0.0; }
		virtual void							Unk_E8(void);																																																			// 0E8 - { return 0; }
		virtual void							Unk_E9(void);																																																			// 0E9 - { return 0; }
		virtual void							Unk_EA(void);																																																			// 0EA - { return 0; }
		virtual void							Unk_EB(void);																																																			// 0EB
		virtual void							Unk_EC(void);																																																			// 0EC
		virtual void							Unk_ED(void);																																																			// 0ED
		virtual void							Unk_EE(void);																																																			// 0EE
		virtual void							WeaponSwingCallBack();																																																	// 0EF
		virtual void							SetActorStartingPosition(void);																																															// 0F0
		virtual void							Unk_F1(void);																																																			// 0F1
		virtual void							Unk_F2(void);																																																			// 0F2
		virtual void							Unk_F3(void);																																																			// 0F3
		virtual void							Unk_F4(void);																																																			// 0F4
		virtual bool							HasBeenAttacked() const;																																																// 0F5
		virtual void							SetBeenAttacked(bool a_attacked);																																														// 0F6
		virtual void							UseSkill(ActorValue a_skillID, float a_points, UInt32 a_arg3, UInt32 a_arg4);																																			// 0F7 - { return; }
		virtual void							IsAtPoint(void);																																																		// 0F8
		virtual bool							IsInFaction(TESFaction* faction);																																														// 0F9
		virtual void							ForEachPerk(PerkEntryVisitor& a_visitor);																																												// 0FA
		virtual void							AddPerk(BGSPerk* a_perk, UInt32 a_rank = 0);																																											// 0FB - { return; }
		virtual void							RemovePerk(BGSPerk* a_perk);																																															// 0FC - { return; }
		virtual void							Unk_FD(void);																																																			// 0FD - { return; }
		virtual void							Unk_FE(void);																																																			// 0FE - { return; }
		virtual bool							HasPerkEntries(EntryPoint a_entryType);																																													// 0FF
		virtual void							ForEachPerkEntry(EntryPoint a_entryType, PerkEntryVisitor& a_visitor);																																					// 100
		virtual void							ApplyPerksFromBase();																																																	// 101
		virtual void							StartPowerAttackCoolDown(void);																																															// 102 - { return; }
		virtual bool							IsPowerAttackCoolingDown() const;																																														// 103 - { return false; }
		virtual void							HandleHealthDamage(UInt32 a_unk1, float a_currentHealth);																																								// 104
		virtual void							Unk_105(void);																																																			// 105
		virtual void							Unk_106(void);																																																			// 106 - { return; }
		virtual bool							QSpeakingDone() const;																																																	// 107 - { return ~(unk0E0 >> 5) & 1; }
		virtual void							SetSpeakingDone(bool a_done);																																															// 108
		virtual void							CreateMovementController(void);																																															// 109
		virtual void							Unk_10A(void);																																																			// 10A - { return unk16C; }
		virtual void							Unk_10B(void);																																																			// 10B - { unk16C = a_arg1; }
		virtual void							Unk_10C(void);																																																			// 10C - { return unk170; }
		virtual void							Unk_10D(void);																																																			// 10D - { unk170 = a_arg1; }
		virtual void							KillImpl(void);																																																			// 10E
		virtual void							Unk_10F(void);																																																			// 10F
		virtual void							CheckCast(void);																																																		// 110
		virtual void							CheckTempModifiers(void);																																																// 111 - { return; }
		virtual SInt32							GetCurrentShoutLevel();																																																	// 112 - return -1 on error
		virtual void							SetLastRiddenMount(ActorHandle a_horseRefHandle);																																										// 113 - { return; }
		virtual ActorHandle&					QLastRiddenMount(ActorHandle& a_outHandle);																																												// 114 - { a_outHandle = *g_invalidHandle; }
		virtual void							CalculateCachedOwnerIsUndead(void);																																														// 115
		virtual bool							CalculateCachedOwnerIsNPC();																																															// 116
		virtual void							Unk_117(void);																																																			// 117 - { return; }
		virtual void							Unk_118(void);																																																			// 118
		virtual const BSFixedString&			GetResponseType();																																																		// 119 - { return "ActorResponse"; } - retrieved from a global table of anim variables
		virtual void							Unk_11A(void);																																																			// 11A
		virtual void							UpdateCombatControllerSettings(void);																																													// 11B
		virtual void							UpdateFadeSettings(void);																																																// 11C
		virtual void							ComputeMotionFeedbackSpeedAndDirection(void);																																											// 11D
		virtual void							UpdateFeedbackGraphSpeedAndDirection(void);																																												// 11E
		virtual void							UpdateActor3DPosition(void);																																															// 11F
		virtual void							PrecacheData(void);																																																		// 120
		virtual void							WornArmorChanged(void);																																																	// 121
		virtual void							ProcessTracking(void);																																																	// 122
		virtual void							Unk_123(void);																																																			// 123
		virtual void							CreateActorMover(void);																																																	// 124
		virtual void							DestroyActorMover(void);																																																// 125
		virtual bool							ShouldRespondToActorCollision(void* a_arg1, Actor* a_target);																																							// 126
		virtual float							CheckClampDamageModifier(ActorValue a_avIndex, float a_avChangeBy);																																						// 127

		static NiPointer<Actor>	LookupByHandle(RefHandle a_refHandle);
		static bool				LookupByHandle(RefHandle a_refHandle, NiPointer<Actor>& a_refrOut);

		bool						AddSpell(SpellItem* a_spell);
		void						AllowBleedoutDialogue(bool a_canTalk);
		void						AllowPCDialogue(bool a_talk);
		SInt32						CalcEntryValue(InventoryEntryData* a_entryData, UInt32 a_numItems, bool a_multiplyValueByRemainingItems) const;
		bool						CanFlyHere() const;
		void						ClearArrested();
		void						ClearExpressionOverride();
		void						ClearExtraArrows();
		ActorHandle					CreateRefHandle();
		void						DispelWornItemEnchantments();
		TESNPC*						GetActorBase();
		const TESNPC*				GetActorBase() const;
		InventoryEntryData*			GetAttackingWeapon();
		const InventoryEntryData*	GetAttackingWeapon() const;
		TESFaction*					GetCrimeFaction();
		const TESFaction*			GetCrimeFaction() const;
		SInt32						GetDetectionLevel(Actor* a_target, UInt32 a_idx = 3);
		InventoryEntryData*			GetEquippedEntryData(bool a_leftHand);
		const InventoryEntryData*	GetEquippedEntryData(bool a_leftHand) const;
		TESForm*					GetEquippedObject(bool a_leftHand) const;
		SInt32						GetGoldAmount();
		float						GetHeight();
		UInt16						GetLevel() const;
		TESRace*					GetRace() const;
		bool						HasPerk(BGSPerk* a_perk) const;
		bool						IsAIEnabled() const;
		bool						IsAMount() const;
		bool						IsBeingRidden() const;
		bool						IsCommandedActor() const;
		bool						IsEssential() const;
		bool						IsFactionInCrimeGroup(const TESFaction* a_faction) const;
		bool						IsGhost() const;
		bool						IsGuard() const;
		bool						IsHostileToActor(Actor* a_actor) const;
		bool						IsInKillMove() const;
		bool						IsOnMount() const;
		bool						IsPlayerTeammate() const;
		bool						IsRunning() const;
		bool						IsSneaking() const;
		bool						IsSummoned() const;
		bool						IsTrespassing() const;
		void						QueueNiNodeUpdate(bool a_updateWeight);
		void						ResetAI(UInt32 a_arg1 = 0, UInt32 a_arg2 = 0);
		void						SendStealAlarm(TESObjectREFR* a_refItemOrContainer, TESForm* a_stolenItem, SInt32 a_numItems, UInt32 a_value, TESForm* a_owner, bool a_allowGetBackStolenItemPackage);
		void						SetRace(TESRace* a_race, bool a_isPlayer);
		void						UpdateArmorAbility(TESForm* a_armor, ExtraDataList* a_extraData);
		void						UpdateHairColor();
		void						UpdateSkinColor();
		void						UpdateWeaponAbility(TESForm* a_weapon, ExtraDataList* a_extraData, bool a_leftHand);
		bool						VisitFactions(llvm::function_ref<bool(TESFaction* a_faction, SInt8 a_rank)> a_visitor);


		// members
		BOOL_BITS								boolBits;							// 0E0
		float									updateTargetTimer;					// 0E4
		ACTOR_CRITICAL_STAGE					criticalStage;						// 0E8
		UInt32									pad0EC;								// 0EC
		AIProcess*								currentProcess;						// 0F0
		ObjectRefHandle							dialogueItemTarget;					// 0F8
		ActorHandle								currentCombatTarget;				// 0FC
		ActorHandle								myKiller;							// 100
		float									checkMyDeadBodyTimer;				// 104
		float									voiceTimer;							// 108
		float									underWaterTimer;					// 10C
		SInt32									thiefCrimeStamp;					// 110
		SInt32									actionValue;						// 114
		float									timerOnAction;						// 118
		UInt32									unk11C;								// 11C
		NiPoint3								editorLocCoord;						// 120
		float									editorLocRot;						// 12C
		TESForm*								editorLocForm;						// 130
		BGSLocation*							editorLocation;						// 138
		ActorMover*								actorMover;							// 140
		BSTSmartPointer<MovementControllerNPC>	movementController;					// 148
		void*									unk150;								// 150
		void*									unk158;								// 158
		TESFaction*								vendorFaction;						// 160
		AITimeStamp								calculateVendorFactionTimer;		// 168
		UInt32									unk16C;								// 16C
		UInt32									unk170;								// 170
		UInt32									unk174;								// 174
		UInt32									unk178;								// 178
		UInt32									intimidateBribeDayStamp;			// 17C
		UInt64									unk180;								// 180
		BSTSmallArray<SpellItem*>				addedSpells;						// 188
		ActorMagicCaster*						magicCasters[SlotTypes::kTotal];	// 1A0
		MagicItem*								selectedSpells[SlotTypes::kTotal];	// 1C0
		TESForm*								selectedPower;						// 1E0
		UInt32									unk1E8;								// 1E8
		UInt32									pad1EC;								// 1EC
		TESRace*								race;								// 1F0
		float									equippedWeight;						// 1F8
		BOOL_FLAGS								boolFlags;							// 1FC
		ActorValueStorage						avStorage;							// 200
		BGSDialogueBranch*						exclusiveBranch;					// 220
		Modifiers								healthModifiers;					// 228
		Modifiers								magickaModifiers;					// 234
		Modifiers								staminaModifiers;					// 240
		Modifiers								voicePointsModifiers;				// 24C
		float									lastUpdate;							// 258
		UInt32									lastSeenTime;						// 25C
		BSTSmartPointer<BipedAnim>				biped;								// 260
		float									armorRating;						// 268
		float									armorBaseFactorSum;					// 26C
		UInt8									soundCallBackSet;					// 271
		UInt8									unk271;								// 270
		UInt8									unk272;								// 272
		UInt8									unk273;								// 273
		UInt32									unk274;								// 274
		UInt64									unk278;								// 278
		UInt64									unk280;								// 280
		CRITICAL_SECTION						unk288;								// 288 - havok related
	};
	STATIC_ASSERT(sizeof(Actor) == 0x2B0);
}
