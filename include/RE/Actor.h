#pragma once

#include "skse64/GameEvents.h"  // BSTEventSink
#include "skse64/GameReferences.h"  // IPostAnimationChannelUpdateFunctor, SpellArray, Actor
#include "skse64/GameTypes.h"  // tList

#include "RE/ActiveEffect.h"  // ActiveEffect
#include "RE/ActorProcessManager.h"  // ActorProcessManager
#include "RE/ActorState.h"  // ActorState
#include "RE/ActorValueOwner.h"  // ActorValueOwner
#include "RE/BGSEntryPointPerkEntry.h"  // BGSEntryPointPerkEntry
#include "RE/bhkCharacterMoveFinishEvent.h"  // bhkCharacterMoveFinishEvent
#include "RE/BSTransformDeltaEvent.h"  // BSTransformDeltaEvent
#include "RE/MagicTarget.h"  // MagicTarget
#include "RE/TESNPC.h"  // TESNPC
#include "RE/TESObjectREFR.h"  // TESObjectREFR

class BaseExtraList;
class BGSPerk;
class SpellItem;
class TESForm;
class TESRace;


namespace RE
{
	class BaseExtraList;
	class PerkEntryVisitor;
	class TESRace;
	class TESFaction;


	class Actor :
		public TESObjectREFR,
		public MagicTarget,
		public ActorValueOwner,
		public ActorState,
		public BSTEventSink<BSTransformDeltaEvent>,
		public BSTEventSink<bhkCharacterMoveFinishEvent>,
		public IPostAnimationChannelUpdateFunctor
	{
	private:
		enum Flags1 : UInt32
		{
			kFlags1_AIEnabled			= 1 << 1,
			kFlags1_IsPlayerTeammate	= 1 << 26,
			kFlags1_IsGuard				= 1 << 30
		};


		enum Flags2 : UInt32
		{
			kFlags2_HasInteraction			= 1 << 1,
			kFlags2_NoBleedoutRecovery		= 1 << 5,
			kFlags2_CanDoFavor				= 1 << 7,
			kFlags2_AllowBleedoutDialogue	= 1 << 9,
			kFlags2_IsTrespassing			= 1 << 12,
			kFlags2_IsInKillMove			= 1 << 14,
			kFlags2_AttackMeOnSight			= 1 << 15,
			kFlags2_IsCommandedActor		= 1 << 16,
			kFlags2_IsEssential				= 1 << 18,
			kFlags2_IsProtected				= 1 << 19,
			kFlags2_DontShowOnStealthMeter	= 1 << 26,
		};

	public:
		enum { kTypeID = kFormType_Character };


		enum SlotType : UInt32
		{
			kSlotType_LeftHand = 0,
			kSlotType_RightHand,
			kSlotType_Unknown,
			kSlotType_PowerOrShout,

			kNumSlots
		};


		struct Data228
		{
			UInt32	unk0;
			UInt32	unk4;
			UInt32	unk8;
		};


		class FactionVisitor
		{
		public:
			virtual bool Accept(TESFaction* a_faction, SInt8 a_rank) = 0;
		};


		// override (MagicTarget)
		virtual Actor*					GetMagicTargetActor() const override;																								// 2
		virtual bool					IsActorMagicTarget() const override;																								// 3
		virtual tList<ActiveEffect>*	GetActiveEffects() override;																										// 7

		// add
		virtual	~Actor();

		virtual void					PlaySounds(TESForm* a_item, bool a_isPickup, bool a_unk);																			// A3
		virtual void					Unk_A4(void);																														// A4
		virtual void					Unk_A5(void);																														// A5
		virtual void					DrawSheatheWeapon(bool a_draw);																										// A6
		virtual void					Unk_A7(void);																														// A7
		virtual void					Unk_A8(void);																														// A8
		virtual void					Unk_A9(void);																														// A9
		virtual void					Unk_AA(void);																														// AA
		virtual void					Unk_AB(void);																														// AB
		virtual void					Unk_AC(void);																														// AC
		virtual void					Unk_AD(void);																														// AD
		virtual void					Unk_AE(void);																														// AE
		virtual void					Unk_AF(void);																														// AF
		virtual void					Unk_B0(void);																														// B0
		virtual void					Unk_B1(void);																														// B1
		virtual void					Unk_B2(void);																														// B2
		virtual void					Unk_B3(void);																														// B3
		virtual void					Unk_B4(void);																														// B4
		virtual void					SetBounty(TESFaction* a_faction, bool a_bViolent, SInt32 a_gold);																	// B5
		virtual void					ModBounty(TESFaction* a_faction, bool a_bViolent, SInt32 a_gold);																	// B6
		virtual void					AddCrimeGold(UInt32 a_gold, bool a_bViolent, TESFaction* a_faction);																// B7
		virtual UInt32					GetBounty(TESFaction* a_faction);																									// B8
		virtual void					Unk_B9(void);																														// B9
		virtual void					ServeJailTime();																													// BA
		virtual void					PayBounty(TESFaction* a_faction, bool a_removeStolenItems, bool a_goToJail);														// BB
		virtual UInt32					IsCannibalizing();																													// BC
		virtual void					Unk_BD(void);																														// BD
		virtual UInt32					IsVampireFeeding();																													// BE
		virtual void					Unk_BF(void);																														// BF
		virtual void					Unk_C0(void);																														// C0
		virtual void					Unk_C1(void);																														// C1
		virtual void					Unk_C2(void);																														// C2
		virtual void					Unk_C3(void);																														// C3
		virtual void					Unk_C4(void);																														// C4
		virtual void					Unk_C5(void);																														// C5
		virtual void					Unk_C6(void);																														// C6
		virtual void					Unk_C7(void);																														// C7
		virtual void					Unk_C8(void);																														// C8
		virtual void					Unk_C9(void);																														// C9
		virtual void					OnArmorActorValueChanged();																											// CA
		virtual void					DropItem(UInt32* a_droppedItemHandle, TESForm* a_akItem, BaseExtraList* a_extraList, UInt32 a_count, UInt32 a_arg5, UInt32 a_arg6);	// CB
		virtual void					PickUpItem(TESObjectREFR* a_item, UInt32 a_count, bool a_arg3, bool a_playSound);													// CC
		virtual void					Unk_CD(void);																														// CD
		virtual void					Unk_CE(void);																														// CE
		virtual void					Unk_CF(void);																														// CF
		virtual void					Unk_D0(void);																														// D0
		virtual void					Unk_D1(void);																														// D1
		virtual void					Unk_D2(void);																														// D2
		virtual void					Unk_D3(void);																														// D3
		virtual void					Unk_D4(void);																														// D4
		virtual void					Unk_D5(void);																														// D5
		virtual void					Unk_D6(void);																														// D6
		virtual void					Unk_D7(void);																														// D7
		virtual void					Unk_D8(void);																														// D8
		virtual void					Unk_D9(void);																														// D9
		virtual void					Unk_DA(void);																														// DA
		virtual void					Unk_DB(void);																														// DB
		virtual void					Unk_DC(void);																														// DC
		virtual void					Unk_DD(void);																														// DD
		virtual void					Unk_DE(void);																														// DE
		virtual void					Unk_DF(void);																														// DF
		virtual void					Unk_E0(void);																														// E0
		virtual void					Unk_E1(void);																														// E1
		virtual void					Unk_E2(void);																														// E2
		virtual bool					IsInCombat();																														// E3
		virtual void					Unk_E4(void);																														// E4
		virtual void					Unk_E5(void);																														// E5
		virtual void					Unk_E6(void);																														// E6
		virtual void					Unk_E7(void);																														// E7
		virtual void					Unk_E8(void);																														// E8
		virtual void					Unk_E9(void);																														// E9
		virtual void					Unk_EA(void);																														// EA
		virtual void					Unk_EB(void);																														// EB
		virtual void					Unk_EC(void);																														// EC
		virtual void					Unk_ED(void);																														// ED
		virtual void					Unk_EE(void);																														// EE
		virtual void					OnWeaponSwing();																													// EF
		virtual void					Unk_F0(void);																														// F0
		virtual void					Unk_F1(void);																														// F1
		virtual void					Unk_F2(void);																														// F2
		virtual void					Unk_F3(void);																														// F3
		virtual void					Unk_F4(void);																														// F4
		virtual void					Unk_F5(void);																														// F5
		virtual void					Unk_F6(void);																														// F6
		virtual void					AdvanceSkill(UInt32 a_skillId, float a_points, UInt32 a_unk1, UInt32 a_unk2);														// F7
		virtual void					Unk_F8(void);																														// F8
		virtual bool					IsInFaction(TESFaction* faction);																									// F9
		virtual void					VisitPerks(void);																													// FA
		virtual void					AddPerk(BGSPerk* a_perk, UInt32 a_unk1);																							// FB
		virtual void					RemovePerk(BGSPerk* a_perk);																										// FC
		virtual void					Unk_FD(void);																														// FD
		virtual void					Unk_FE(void);																														// FE
		virtual bool					CanProcessEntryPointPerkEntry(BGSEntryPointPerkEntry::EntryPointType a_entryType);													// FF
		virtual void					VisitEntryPointPerkEntries(BGSEntryPointPerkEntry::EntryPointType a_entryType, PerkEntryVisitor& a_visitor);						// 100
		virtual void					Unk_101(void);																														// 101
		virtual void					Unk_102(void);																														// 102
		virtual void					Unk_103(void);																														// 103
		virtual void					KillIfNoHealth(UInt32 a_unk1, float a_currentHealth);																				// 104
		virtual void					Unk_105(void);																														// 105
		virtual void					Unk_106(void);																														// 106
		virtual void					Unk_107(void);																														// 107
		virtual void					Unk_108(void);																														// 108
		virtual void					Unk_109(void);																														// 109
		virtual void					Unk_10A(void);																														// 10A
		virtual void					Unk_10B(void);																														// 10B
		virtual void					Unk_10C(void);																														// 10C
		virtual void					Unk_10D(void);																														// 10D
		virtual void					Unk_10E(void);																														// 10E
		virtual void					Unk_10F(void);																														// 10F
		virtual void					Unk_110(void);																														// 110
		virtual void					Unk_111(void);																														// 111
		virtual SInt32					GetCurrentShoutVariation();																											// 112
		virtual void					SetLastRiddenHorseHandle(UInt32 a_horseRefHandle);																					// 113
		virtual UInt32					GetLastRiddenHorseHandle(UInt32& a_outHandle);																						// 114
		virtual void					Unk_115(void);																														// 115
		virtual void					Unk_116(void);																														// 116
		virtual void					Unk_117(void);																														// 117
		virtual void					Unk_118(void);																														// 118
		virtual void					Unk_119(void);																														// 119
		virtual void					Unk_11A(void);																														// 11A
		virtual void					Unk_11B(void);																														// 11B
		virtual void					Unk_11C(void);																														// 11C
		virtual void					Unk_11D(void);																														// 11D
		virtual void					Unk_11E(void);																														// 11E
		virtual void					Unk_11F(void);																														// 11F
		virtual void					Unk_120(void);																														// 120
		virtual void					Unk_121(void);																														// 121
		virtual void					Unk_122(void);																														// 122
		virtual void					Unk_123(void);																														// 123
		virtual void					Unk_124(void);																														// 124
		virtual void					Unk_125(void);																														// 125
		virtual void					Unk_126(void);																														// 126
		virtual void					Unk_127(void);																														// 127
		virtual float					IncerceptActorValueChange(UInt32 a_avIndex, float a_avChangeBy);																	// 128


		TESForm*		GetEquippedObject(bool a_abLeftHand);
		void			UpdateSkinColor();
		void			UpdateHairColor();
		void			QueueNiNodeUpdate(bool a_updateWeight);
		bool			HasPerk(BGSPerk* a_perk);
		UInt16			GetLevel();
		void			SetRace(TESRace* a_race, bool a_isPlayer);
		void			UpdateWeaponAbility(TESForm* a_weapon, BaseExtraList* a_extraData, bool a_bLeftHand);
		void			UpdateArmorAbility(TESForm* a_armor, BaseExtraList* a_extraData);
		bool			IsHostileToActor(Actor* a_actor);
		void			ResetAI(UInt32 a_unk1, UInt32 a_unk2);

		bool			VisitFactions(FactionVisitor& a_visitor);
		TESNPC*			GetActorBase();
		TESRace*		GetRace();
		bool			IsBeingRidden();
		bool			IsCommandedActor() const;
		bool			IsEssential() const;
		bool			IsGuard() const;
		bool			IsInKillMove() const;
		bool			IsAIEnabled() const;
		bool			IsOnMount();
		bool			IsPlayerTeammate() const;
		bool			IsSneaking();
		bool			IsTrespassing() const;
		void			DispelWornItemEnchantments();
		void			SendStealAlarm(TESObjectREFR* a_refItemOrContainer, TESForm* a_stolenItem, UInt32 a_numItems, UInt32 a_value, TESForm* a_owner, bool a_unk);
		SInt32			CalcEntryValue(InventoryEntryData* a_entryData, UInt32 a_numItems, bool a_unk);
		SInt32			GetDetectionLevel(Actor* a_target, UInt32 a_flag);
		bool			IsGhost();
		bool			IsSummoned();


		// members
		Flags1					flags1;						// 0E0
		float					unk0E4;						// 0E4
		UInt32					unk0E8;						// 0E8
		UInt32					pad0EC;						// 0EC
		ActorProcessManager*	processManager;				// 0F0
		UInt32					refHandleDialogueTarget;	// 0F8
		UInt32					refHandleCombatTarget;		// 0FC
		UInt32					refHandleKiller;			// 100
		UInt32					unk104;						// 104
		float					unk108;						// 108 - init'd to -1
		UInt32					unk10C;						// 10C
		UInt32					unk110;						// 110
		UInt32					unk114;						// 114
		UInt32					unk118;						// 118
		UInt32					unk11C;						// 11C
		NiPoint3				unk120;						// 120
		UInt32					unk12C;						// 12C
		void*					unk130;						// 130
		void*					unk138;						// 138 - BGSLocation*
		void*					unk140;						// 140 - ActorMover*
		void*					unk148;						// 148 - MovementControllerNPC*
		void*					unk150;						// 150
		void*					unk158;						// 158
		UInt64					unk160;						// 160
		float					unk168;						// 168
		UInt32					unk16C;						// 16C
		UInt32					unk170;						// 170
		UInt32					unk174;						// 174 - init'd to 50
		UInt32					unk178;						// 178
		UInt32					unk17C;						// 17C - init'd to 7FFFFFFF
		UInt64					unk180;						// 180
		::Actor::SpellArray		addedSpells;				// 188
		void*					unk1A0;						// 1A0 - ActorMagicCaster*
		void*					unk1A8;						// 1A8 - ActorMagicCaster*
		UInt64					unk1B0;						// 1B0
		void*					unk1B8;						// 1B8 - ActorMagicCaster*
		SpellItem*				leftHandSpell;				// 1C0
		SpellItem*				rightHandSpell;				// 1C8
		UInt64					unk1D0;						// 1D0
		UInt64					unk1D8;						// 1D8
		TESForm*				equippedShout;				// 1E0
		UInt32					unk1E8;						// 1E8
		UInt32					pad1EC;						// 1EC
		TESRace*				race;						// 1F0
		float					unk1F8;						// 1F8 - init'd to -1
		Flags2					flags2;						// 1FC
		BSString				unk200;						// 200
		BSString				unk210;						// 210
		UInt64					unk220;						// 220
		Data228					unk228;						// 228
		Data228					unk234;						// 234
		Data228					unk240;						// 240
		Data228					unk24C;						// 24C
		float					unk258;						// 258 - init'd to -1
		UInt32					unk25C;						// 25C
		UInt64					unk260;						// 260
		float					unk268;						// 268
		float					unk26C;						// 26C
		UInt32					unk270;						// 270
		UInt32					unk274;						// 274
		UInt64					unk278;						// 278
		UInt64					unk280;						// 280
		UInt64					unk288;						// 288
		UInt64					unk290;						// 290
		UInt64					unk298;						// 298
		UInt64					unk2A0;						// 2A0
		UInt64					unk2A8;						// 2A8

	private:
		typedef void _DispelWornItemEnchantments_t(Actor* a_this);
		static RelocAddr<_DispelWornItemEnchantments_t*> _DispelWornItemEnchantments;

		typedef void _SendStealAlarm_t(Actor* a_this, TESObjectREFR* a_refItemOrContainer, TESForm* a_stolenItem, UInt32 a_numItems, UInt32 a_value, TESForm* a_owner, bool a_unk);
		static RelocAddr<_SendStealAlarm_t*> _SendStealAlarm;

		typedef SInt32 _CalcEntryValue_t(Actor* a_this, InventoryEntryData* a_entryData, UInt32 a_numItems, bool a_unk);
		static RelocAddr<_CalcEntryValue_t*> _CalcEntryValue;

		typedef SInt32 _GetDetectionLevel_t(Actor* a_this, Actor* a_target, UInt32 a_flag);
		static RelocAddr<_GetDetectionLevel_t*> _GetDetectionLevel;

		typedef bool _IsGhost_t(Actor* a_this);
		static RelocAddr<_IsGhost_t*> _IsGhost;
	};
	STATIC_ASSERT(offsetof(Actor, addedSpells) == 0x188);
	STATIC_ASSERT(sizeof(Actor) == 0x2B0);
}
