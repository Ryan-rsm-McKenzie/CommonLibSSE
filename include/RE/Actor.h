#pragma once

#include "skse64/GameRTTI.h"  // RTTI_Actor

#include <minwinbase.h>  // CRITICAL_SECTION

#include "RE/ActiveEffect.h"  // ActiveEffect
#include "RE/ActorProcessManager.h"  // ActorProcessManager
#include "RE/ActorState.h"  // ActorState
#include "RE/ActorValueOwner.h"  // ActorValueOwner
#include "RE/ActorValues.h"  // ActorValue, ActorValue8
#include "RE/BGSEntryPointPerkEntry.h"  // BGSEntryPointPerkEntry
#include "RE/BSTArray.h"  // BSTSmallArray
#include "RE/BSTEvent.h"  // BSTEventSink
#include "RE/BSTList.h"  // BSSimpleList
#include "RE/FormTypes.h"  // BGSPerk, TESRace, TESFaction
#include "RE/IPostAnimationChannelUpdateFunctor.h"  // IPostAnimationChannelUpdateFunctor
#include "RE/MagicTarget.h"  // MagicTarget
#include "RE/NiSmartPointer.h"  // NiPointer
#include "RE/TESNPC.h"  // TESNPC
#include "RE/TESObjectREFR.h"  // TESObjectREFR


namespace RE
{
	class ActorMover;
	class BaseExtraList;
	class bhkCharacterMoveFinishEvent;
	class BSTransformDeltaEvent;
	class InventoryEntryData;
	class MovementControllerNPC;
	class NiRefObject;
	class PerkEntryVisitor;


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

				kNumSlots
			};
		};


		enum class Flag1 : UInt32
		{
			kNone = 0,
			kAIEnabled = 1 << 1,
			kIsPlayerTeammate = 1 << 26,
			kIsGuard = 1 << 30
		};


		enum class Flag2 : UInt32
		{
			kNone = 0,
			kHasInteraction = 1 << 1,
			kNoBleedoutRecovery = 1 << 5,
			kCanDoFavor = 1 << 7,
			kAllowBleedoutDialogue = 1 << 9,
			kIsTrespassing = 1 << 12,
			kIsInKillMove = 1 << 14,
			kAttackMeOnSight = 1 << 15,
			kIsCommandedActor = 1 << 16,
			kIsEssential = 1 << 18,
			kIsProtected = 1 << 19,
			kDontShowOnStealthMeter = 1 << 26,
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


		struct ActorValueModifiers
		{
			struct Modifiers
			{
				enum
				{
					kPermanent = 0,
					kTemporary,
					kDamage,

					kTotal
				};
			};


			// members
			float modifiers[Modifiers::kTotal];	// 0
		};
		STATIC_ASSERT(sizeof(ActorValueModifiers) == 0xC);


		struct WeaponStrikeData
		{
			enum class Flag : UInt32
			{
				kNone = 0,
				kCriticalStrike = 1 << 3,
				kSneakAttack = 1 << 11,
				kPowerAttack = 1 << 16,
				kLeftHand = 1 << 17
			};


			// members
			float					unk00;		// 00
			float					unk04;		// 04
			float					unk08;		// 08
			float					unk0C;		// 0C
			float					unk10;		// 10
			float					unk14;		// 14
			RefHandle				unk18;		// 18
			UInt32					unk1C;		// 1C
			RefHandle				unk20;		// 20
			UInt32					unk24;		// 24
			NiPointer<NiRefObject>	unk28;		// 28
			TESObjectWEAP*			unk30;		// 30
			UInt64					unk38;		// 38
			UInt64					unk40;		// 40
			UInt64					unk48;		// 48
			UInt32					unk50;		// 50
			UInt32					unk54;		// 54
			UInt64					unk58;		// 58
			UInt64					unk60;		// 60
			float					unk68;		// 68
			float					unk6C;		// 6C
			float					damageMult;	// 70
			UInt32					unk74;		// 74
			float					unk78;		// 78
			UInt32					unk7C;		// 7C
			Flag					flags;		// 80
			UInt32					unk84;		// 84
			SInt32					unk88;		// 88
			SInt32					unk8C;		// 8C
		};
		STATIC_ASSERT(sizeof(WeaponStrikeData) == 0x90);


		struct ActorValueMap
		{
			template <class T>
			struct LocalMap
			{
				T* operator[](ActorValue8 a_actorValue)
				{
					ActorValue8* akVals = actorValues.data();
					if (akVals && entries) {
						UInt32 idx = 0;
						while (akVals[idx] != (ActorValue8)0) {
							if (akVals[idx] == a_actorValue) {
								break;
							}
							++idx;
						}
						if (akVals[idx] != (ActorValue8)0) {
							return &entries[idx];
						}
					}
					return 0;
				}


				// members
				BSFixedString	actorValues;	// 00
				T*				entries;		// 08
			};
			STATIC_ASSERT(sizeof(LocalMap<float>) == 0x10);


			// members
			LocalMap<float>					baseValues;	// 00
			LocalMap<ActorValueModifiers>	modifiers;	// 10
		};
		STATIC_ASSERT(sizeof(ActorValueMap) == 0x20);


		virtual	~Actor();																																																							// 000

		// override (TESObjectREFR)
		virtual void							SaveBuffer(BGSSaveFormBuffer* a_buf) override;																																						// 00E
		virtual void							LoadBuffer(BGSLoadFormBuffer* a_buf) override;																																						// 00F
		virtual void							Unk_10(void) override;																																												// 010
		virtual void							Unk_11(void) override;																																												// 011
		virtual void							Unk_12(void) override;																																												// 012
		virtual void							InitItem() override;																																												// 013
		virtual void							SetFlag00000020(bool a_set) override;																																								// 023
		virtual void							Unk_3B(void) override;																																												// 03B
		virtual BGSLocation*					GetStartingLocation() override;																																										// 03C - { return startingLocation; }
		virtual bool							GetStartingData(NiPoint3& a_outPos, NiPoint3& a_outRot, TESForm*& a_outWorldOrCell, TESObjectCELL* a_veryRarelyUsedFallback) override;																// 03D
		virtual void							SetStartingLocation(BGSLocation* a_location) override;																																				// 03E - { startingLocation = a_location; }
		virtual void							Unk_3F(void) override;																																												// 03F
		virtual void							SayQueuedDialogue() override;																																										// 040
		virtual void							Unk_41(void) override;																																												// 041
		virtual void							Unk_45(void) override;																																												// 045
		virtual bool							HasKeyword(BGSKeyword* a_keyword) override;																																							// 048
		virtual void							Unk_49(void) override;																																												// 049 - { return 0; }
		virtual BGSScene*						GetCurrentScene() const override;																																									// 04A
		virtual void							SetCurrentScene(BGSScene* a_scene) override;																																						// 04B
		virtual void							Unk_4C(void) override;																																												// 04C
		virtual void							Unk_4D(void) override;																																												// 04D - { return unk220; }
		virtual void							Unk_4E(void) override;																																												// 04E - { unk220 = a_arg1; }
		virtual void							Unk_4F(void) override;																																												// 04F
		virtual void							GetStartingRotation(NiPoint3& a_rotation) override;																																					// 052
		virtual void							GetStartingPosition(NiPoint3& a_position) override;																																					// 053
		virtual RefHandle&						RemoveItem(RefHandle& a_dropHandle, TESForm* a_item, SInt32 a_count, RemoveType a_mode, BaseExtraList* a_extraList, TESObjectREFR* a_moveToRef, void* a_arg7 = 0, void* a_arg8 = 0) override;		// 056
		virtual bool							EquipItem(TESForm* a_item, SInt32 a_count, bool a_arg3, UInt32 a_arg4, UInt32 a_arg5) override;																										// 057
		virtual void							Unk_58(void) override;																																												// 058 - attack target?
		virtual void							Unk_59(void) override;																																												// 059
		virtual void							AddItem(TESForm* a_item, BaseExtraList* a_extraList, SInt32 a_count, TESObjectREFR* a_fromRefr) override;																							// 05A
		virtual void							GetMarkerPosition(NiPoint3& a_pos) override;																																						// 05B
		virtual MagicCaster*					GetMagicCaster(UInt32 a_slot) const override;																																						// 05C
		virtual MagicTarget*					GetMagicTarget() const override;																																									// 05D - { return static_cast<MagicTarget*>(this); }
		virtual bool							IsChild() const override;																																											// 05E - { return false; }
		virtual BSFaceGenAnimationData*			GetFaceGenAnimationData() override;																																									// 063
		virtual void							Unk_65(void) override;																																												// 065
		virtual void							Unk_66(void) override;																																												// 066
		virtual void							Unk_67(void) override;																																												// 067 - related to vampire lord cape
		virtual void							Unk_68(void) override;																																												// 068
		virtual void							Unk_69(void) override;																																												// 069
		virtual void							Unk_6A(void) override;																																												// 06A
		virtual void							Unk_6C(void) override;																																												// 06C
		virtual void							Unk_72(void) override;																																												// 072
		virtual NiPoint3*						GetBoundLeftFrontBottom(NiPoint3& a_out) const override;																																			// 073
		virtual NiPoint3*						GetBoundRightBackTop(NiPoint3& a_out) const override;																																				// 074
		virtual void							Unk_75(void) override;																																												// 075 - "ActorValue GetWeaponSkill()"? really weird call, only works for right hand, and defaults to 1
		virtual void							Unk_78(void) override;																																												// 078
		virtual void							Unk_79(void) override;																																												// 079
		virtual void							Unk_7A(void) override;																																												// 07A - { return 0; }
		virtual void							Unk_7B(void) override;																																												// 07B
		virtual void							Unk_7C(void) override;																																												// 07C
		virtual void							Unk_7D(void) override;																																												// 07D
		virtual void							Unk_82(void) override;																																												// 082
		virtual void							SetBaseForm(TESBoundObject* a_object) override;																																						// 084
		virtual void							Unk_85(void) override;																																												// 085
		virtual void							Unk_86(void) override;																																												// 086
		virtual void							Unk_87(void) override;																																												// 087
		virtual void							Disable() override;																																													// 089
		virtual void							ResetInventory(bool a_regenerate) override;																																							// 08A
		virtual void							Unk_8B(void) override;																																												// 08B
		virtual void							Unk_8C(void) override;																																												// 08C
		virtual void							Unk_90(void) override;																																												// 090
		virtual void							Unk_91(void) override;																																												// 091
		virtual void							Unk_92(void) override;																																												// 092
		virtual void							Unk_93(void) override;																																												// 093
		virtual void							Unk_95(void) override;																																												// 095
		virtual void							Unk_96(void) override;																																												// 096
		virtual void							Unk_98(void) override;																																												// 098
		virtual bool							IsDead(bool a_bleedout = true) override;																																							// 099
		virtual void							Unk_9C(void) override;																																												// 09C
		virtual void							Unk_9D(void) override;																																												// 09D
		virtual void							Unk_9E(void) override;																																												// 09E
		virtual void							UnequipItem(UInt64 a_arg1, TESForm* a_item) override;																																				// 0A1

		// override (MagicTarget)
		virtual Actor*							GetMagicTargetActor() const override;																																								// 002 - { return this; }
		virtual bool							IsActorMagicTarget() const override;																																								// 003 - { return true; }
		virtual BSSimpleList<ActiveEffect*>*	GetActiveEffects() override;																																										// 007

		// add
		virtual void							Unk_A2(void);																																														// 0A2
		virtual void							PlaySounds(TESBoundObject* a_item, bool a_pickup, bool a_consume);																																	// 0A3
		virtual void							Unk_A4(void);																																														// 0A4
		virtual void							Unk_A5(void);																																														// 0A5 - { return; }
		virtual void							DrawSheatheWeapon(bool a_draw);																																										// 0A6
		virtual void							Unk_A7(void);																																														// 0A7
		virtual void							Unk_A8(void);																																														// 0A8
		virtual void							Unk_A9(void);																																														// 0A9
		virtual void							Unk_AA(void);																																														// 0AA
		virtual void							Unk_AB(void);																																														// 0AB
		virtual void							Unk_AC(void);																																														// 0AC
		virtual void							Unk_AD(void);																																														// 0AD
		virtual void							Unk_AE(void);																																														// 0AE - { return unk11F(); }
		virtual void							Unk_AF(void);																																														// 0AF
		virtual void							Unk_B0(void);																																														// 0B0
		virtual void							Unk_B1(void);																																														// 0B1
		virtual void							OnItemEquipped(bool a_playAnim);																																									// 0B2
		virtual void							Unk_B3(void);																																														// 0B3 - { return 1; }
		virtual void							Unk_B4(void);																																														// 0B4
		virtual void							SetBounty(TESFaction* a_faction, bool a_bViolent, SInt32 a_gold);																																	// 0B5
		virtual void							ModBounty(TESFaction* a_faction, bool a_bViolent, SInt32 a_gold);																																	// 0B6
		virtual void							AddCrimeGold(UInt32 a_gold, bool a_bViolent, TESFaction* a_faction);																																// 0B7
		virtual UInt32							GetBounty(TESFaction* a_faction);																																									// 0B8
		virtual void							Unk_B9(void);																																														// 0B9 - { return; }
		virtual void							ServeJailTime();																																													// 0BA - { return; }
		virtual void							PayBounty(TESFaction* a_faction, bool a_removeStolenItems, bool a_goToJail);																														// 0BB - { return; }
		virtual UInt32							IsCannibalizing();																																													// 0BC - { return 0; }
		virtual void							Unk_BD(void);																																														// 0BD - { return; }
		virtual UInt32							IsVampireFeeding();																																													// 0BE - { return 0; }
		virtual void							Unk_BF(void);																																														// 0BF - { return; }
		virtual void							Unk_C0(void);																																														// 0C0 - { return; }
		virtual void							Unk_C1(void);																																														// 0C1 - { return; }
		virtual void							Unk_C2(void);																																														// 0C2
		virtual void							Unk_C3(void);																																														// 0C3
		virtual void							Unk_C4(void);																																														// 0C4 - { return; }
		virtual void							Unk_C5(void);																																														// 0C5 - { return 1; }
		virtual void							Unk_C6(void) = 0;																																													// 0C6
		virtual void							Unk_C7(void);																																														// 0C7 - { return 1.0; }
		virtual void							Unk_C8(void);																																														// 0C8
		virtual void							Unk_C9(void);																																														// 0C9
		virtual void							OnArmorActorValueChanged();																																											// 0CA - { return; }
		virtual void							DropItem(RefHandle& a_droppedItemHandle, TESForm* a_item, BaseExtraList* a_extraList, UInt32 a_count, void* a_arg5 = 0, void* a_arg6 = 0);															// 0CB
		virtual void							PickUpItem(TESObjectREFR* a_item, UInt32 a_count, bool a_arg3 = false, bool a_playSound = true);																									// 0CC
		virtual void							Unk_CD(void);																																														// 0CD
		virtual void							Unk_CE(void);																																														// 0CE
		virtual void							Unk_CF(void);																																														// 0CF
		virtual void							Unk_D0(void);																																														// 0D0 - { return; }
		virtual void							Unk_D1(void);																																														// 0D1
		virtual void							Unk_D2(void);																																														// 0D2
		virtual void							Unk_D3(void);																																														// 0D3
		virtual void							Unk_D4(void);																																														// 0D4
		virtual void							Unk_D5(void);																																														// 0D5
		virtual void							Unk_D6(void);																																														// 0D6
		virtual void							Unk_D7(void);																																														// 0D7 - { return 0; }
		virtual void							Unk_D8(void);																																														// 0D8
		virtual void							Unk_D9(void);																																														// 0D9
		virtual void							Unk_DA(void);																																														// 0DA
		virtual void							Unk_DB(void);																																														// 0DB
		virtual void							Unk_DC(void);																																														// 0DC - { return; }
		virtual void							Unk_DD(void);																																														// 0DD
		virtual void							Unk_DE(void);																																														// 0DE
		virtual void							Unk_DF(void);																																														// 0DF
		virtual void							Unk_E0(void);																																														// 0E0
		virtual void							Unk_E1(void);																																														// 0E1
		virtual void							Unk_E2(void);																																														// 0E2
		virtual bool							IsInCombat();																																														// 0E3
		virtual void							Unk_E4(void);																																														// 0E4
		virtual void							Unk_E5(void);																																														// 0E5
		virtual void							Unk_E6(void);																																														// 0E6 - { return 0.0; }
		virtual void							Unk_E7(void);																																														// 0E7 - { return 0.0; }
		virtual void							Unk_E8(void);																																														// 0E8 - { return 0; }
		virtual void							Unk_E9(void);																																														// 0E9 - { return 0; }
		virtual void							Unk_EA(void);																																														// 0EA - { return 0; }
		virtual void							Unk_EB(void);																																														// 0EB
		virtual void							Unk_EC(void);																																														// 0EC
		virtual void							Unk_ED(void);																																														// 0ED
		virtual void							Unk_EE(void);																																														// 0EE
		virtual void							OnWeaponSwing();																																													// 0EF
		virtual void							Unk_F0(void);																																														// 0F0
		virtual void							Unk_F1(void);																																														// 0F1
		virtual void							Unk_F2(void);																																														// 0F2
		virtual void							Unk_F3(void);																																														// 0F3
		virtual void							Unk_F4(void);																																														// 0F4
		virtual void							Unk_F5(void);																																														// 0F5
		virtual void							Unk_F6(void);																																														// 0F6
		virtual void							AdvanceSkill(ActorValue a_skillID, float a_points, UInt32 a_arg3, UInt32 a_arg4);																													// 0F7 - { return; }
		virtual void							Unk_F8(void);																																														// 0F8
		virtual bool							IsInFaction(TESFaction* faction);																																									// 0F9
		virtual void							VisitPerks(PerkEntryVisitor& a_visitor);																																							// 0FA
		virtual void							AddPerk(BGSPerk* a_perk, UInt32 a_rank = 0);																																						// 0FB - { return; }
		virtual void							RemovePerk(BGSPerk* a_perk);																																										// 0FC - { return; }
		virtual void							Unk_FD(void);																																														// 0FD - { return; }
		virtual void							Unk_FE(void);																																														// 0FE - { return; }
		virtual bool							CanProcessEntryPointPerkEntry(EntryPoint a_entryType);																																				// 0FF
		virtual void							VisitEntryPointPerkEntries(EntryPoint a_entryType, PerkEntryVisitor& a_visitor);																													// 100
		virtual void							Unk_101(void);																																														// 101 - related to ApplyPerksVisitor
		virtual void							Unk_102(void);																																														// 102 - { return; }
		virtual void							Unk_103(void);																																														// 103 - { return 0; }
		virtual void							KillIfNoHealth(UInt32 a_unk1, float a_currentHealth);																																				// 104
		virtual void							Unk_105(void);																																														// 105
		virtual void							Unk_106(void);																																														// 106 - { return; }
		virtual void							Unk_107(void);																																														// 107 - { return ~(unk0E0 >> 5) & 1; }
		virtual void							Unk_108(void);																																														// 108
		virtual void							Unk_109(void);																																														// 109
		virtual void							Unk_10A(void);																																														// 10A - { return unk16C; }
		virtual void							Unk_10B(void);																																														// 10B - { unk16C = a_arg1; }
		virtual void							Unk_10C(void);																																														// 10C - { return unk170; }
		virtual void							Unk_10D(void);																																														// 10D - { unk170 = a_arg1; }
		virtual void							Unk_10E(void);																																														// 10E - related to attacking
		virtual void							Unk_10F(void);																																														// 10F
		virtual void							Unk_110(void);																																														// 110
		virtual void							Unk_111(void);																																														// 111 - { return; }
		virtual SInt32							GetCurrentShoutLevel();																																												// 112 - return -1 on error
		virtual void							SetLastRiddenHorseHandle(RefHandle a_horseRefHandle);																																				// 113 - { return; }
		virtual RefHandle&						GetLastRiddenHorseHandle(RefHandle& a_outHandle);																																					// 114 - { a_outHandle = *g_invalidHandle; }
		virtual void							Unk_115(void);																																														// 115
		virtual bool							IsNPCType();																																														// 116 - used for soulgems
		virtual void							Unk_117(void);																																														// 117 - { return; }
		virtual const BSFixedString&			GetResponseType();																																													// 118 - { return "ActorResponse"; } - retrieved from a global table of anim variables
		virtual void							Unk_119(void);																																														// 119
		virtual void							Unk_11A(void);																																														// 11A
		virtual void							Unk_11B(void);																																														// 11B
		virtual void							Unk_11C(void);																																														// 11C
		virtual void							Unk_11D(void);																																														// 11D
		virtual void							Unk_11E(void);																																														// 11E
		virtual void							Unk_11F(void);																																														// 11F
		virtual void							Unk_120(void);																																														// 120
		virtual void							Unk_121(void);																																														// 121
		virtual void							Unk_122(void);																																														// 122
		virtual void							Unk_123(void);																																														// 123
		virtual void							Unk_124(void);																																														// 124
		virtual void							Unk_125(void);																																														// 125
		virtual void							Unk_126(void);																																														// 126
		virtual float							IncerceptActorValueChange(UInt32 a_avIndex, float a_avChangeBy);																																	// 127

		bool						AddSpell(SpellItem* a_spell);
		SInt32						CalcEntryValue(InventoryEntryData* a_entryData, UInt32 a_numItems, bool a_multiplyValueByRemainingItems) const;
		void						DispelWornItemEnchantments();
		TESNPC*						GetActorBase() const;
		InventoryEntryData*			GetAttackingWeapon();
		const InventoryEntryData*	GetAttackingWeapon() const;
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
		bool						IsBeingRidden() const;
		bool						IsCommandedActor() const;
		bool						IsEssential() const;
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
		void						ResetAI(bool a_arg1, bool a_arg2);
		void						SendStealAlarm(TESObjectREFR* a_refItemOrContainer, TESForm* a_stolenItem, SInt32 a_numItems, UInt32 a_value, TESForm* a_owner, bool a_allowGetBackStolenItemPackage);
		void						SetRace(TESRace* a_race, bool a_isPlayer);
		void						UpdateArmorAbility(TESForm* a_armor, BaseExtraList* a_extraData);
		void						UpdateHairColor();
		void						UpdateSkinColor();
		void						UpdateWeaponAbility(TESForm* a_weapon, BaseExtraList* a_extraData, bool a_leftHand);
		bool						VisitFactions(llvm::function_ref<bool(RE::TESFaction* a_faction, SInt8 a_rank)> a_visitor);


		// members
		Flag1						flags1;										// 0E0
		float						unk0E4;										// 0E4
		UInt32						unk0E8;										// 0E8
		UInt32						pad0EC;										// 0EC
		ActorProcessManager*		processManager;								// 0F0
		RefHandle					dialogueTarget;								// 0F8
		RefHandle					combatTarget;								// 0FC
		RefHandle					killer;										// 100
		UInt32						unk104;										// 104
		float						unk108;										// 108 - init'd to -1
		UInt32						unk10C;										// 10C
		UInt32						unk110;										// 110
		UInt32						unk114;										// 114
		UInt32						unk118;										// 118
		UInt32						unk11C;										// 11C
		NiPoint3					startingPos;								// 120
		float						startingRotZ;								// 12C
		void*						unk130;										// 130
		BGSLocation*				startingLocation;							// 138
		ActorMover*					unk140;										// 140
		MovementControllerNPC*		unk148;										// 148
		void*						unk150;										// 150
		void*						unk158;										// 158
		UInt64						unk160;										// 160
		float						unk168;										// 168
		UInt32						unk16C;										// 16C
		UInt32						unk170;										// 170
		UInt32						unk174;										// 174 - init'd to 50
		UInt32						unk178;										// 178
		UInt32						unk17C;										// 17C - init'd to 7FFFFFFF
		UInt64						unk180;										// 180
		BSTSmallArray<SpellItem*>	addedSpells;								// 188
		MagicCaster*				magicCaster[SlotTypes::kNumSlots];			// 1A0
		MagicCaster*				equippingMagicItems[SlotTypes::kNumSlots];	// 1C0
		TESForm*					equippedShout;								// 1E0
		UInt32						unk1E8;										// 1E8
		UInt32						pad1EC;										// 1EC
		TESRace*					race;										// 1F0
		float						unk1F8;										// 1F8 - init'd to -1
		Flag2						flags2;										// 1FC
		ActorValueMap				avMap;										// 200
		UInt64						unk220;										// 220
		ActorValueModifiers			avHealth;									// 228
		ActorValueModifiers			avMagicka;									// 234
		ActorValueModifiers			avStamina;									// 240
		ActorValueModifiers			avVoicePoints;								// 24C
		float						unk258;										// 258 - init'd to -1
		UInt32						unk25C;										// 25C
		Biped*						smallBiped;									// 260
		float						unk268;										// 268 - related to armor rating
		float						unk26C;										// 26C - related to armor rating
		UInt16						unk270;										// 270
		UInt8						unk272;										// 272
		UInt8						unk273;										// 273
		UInt32						unk274;										// 274
		UInt64						unk278;										// 278
		UInt64						unk280;										// 280
		CRITICAL_SECTION			unk288;										// 288
	};
	STATIC_ASSERT(offsetof(Actor, addedSpells) == 0x188);
	STATIC_ASSERT(sizeof(Actor) == 0x2B0);
}
