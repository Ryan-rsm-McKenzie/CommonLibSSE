#pragma once

#include "RE/FormTypes.h"  // BGSPerk


namespace RE
{
	class BGSEntryPointFunctionData;
	class TESFile;


	class BGSPerkEntry
	{
	public:
		enum class EntryPointType : UInt8
		{
			kCalculate_Weapon_Damage,
			kCalculate_My_Critical_Hit_Chance,
			kCalculate_My_Critical_Hit_Damage,
			kCalculate_Mine_Explode_Chance,
			kAdjust_Limb_Damage,
			kAdjust_Book_Skill_Points,
			kModify_Recovered_Health,
			kGet_Should_Attack,
			kModify_Buy_Prices,
			kAdd_Leveled_List_On_Death,
			kGet_Max_Carry_Weight,
			kModify_Addiction_Chance,
			kModify_Addiction_Duration,
			kModify_Positive_Chem_Duration,
			kActivate,
			kIgnore_Running_During_Detection,
			kIgnore_Broken_Lock,
			kModify_Enemy_Critical_Hit_Chance,
			kModify_Sneak_Attack_Mult,
			kModify_Max_Placeable_Mines,
			kModify_Bow_Zoom,
			kModify_Recover_Arrow_Chance,
			kModify_Skill_Use,
			kModify_Telekinesis_Distance,
			kModify_Telekinesis_Damage_Mult,
			kModify_Telekinesis_Damage,
			kMod_Bashing_Damage,
			kMod_Power_Attack_Stamina,
			kMod_Power_Attack_Damage,
			kMod_Spell_Magnitude,
			kMod_Spell_Duration,
			kMod_Secondary_Value_Weight,
			kMod_Armor_Weight,
			kMod_Incoming_Stagger,
			kMod_Target_Stagger,
			kMod_Attack_Damage,
			kMod_Incoming_Damage,
			kMod_Target_Damage_Resistance,
			kMod_Spell_Cost,
			kMod_Percent_Blocked,
			kMod_Shield_Deflect_Arrow_Chance,
			kMod_Incoming_Spell_Magnitude,
			kMod_Incoming_Spell_Duration,
			kMod_Player_Intimidation,
			kMod_Player_Reputation,
			kMod_Favor_Points,
			kMod_Bribe_Amount,
			kMod_Detection_Light,
			kMod_Detection_Movement,
			kMod_Soul_Gem_Recharge,
			kSet_Sweep_Attack,
			kApply_Combat_Hit_Spell,
			kApply_Bashing_Spell,
			kApply_Reanimate_Spell,
			kSet_Boolean_Graph_Variable,
			kMod_Spell_Casting_Sound_Event,
			kModify_Pickpocket_Chance,
			kModify_Detection_Sneak_Skill,
			kModify_Falling_Damage,
			kModify_Lockpick_Sweet_Spot,
			kModify_Sell_Prices,
			kCan_Pickpocket_Equipped_Item,
			kModify_Lockpick_level_allowed,
			kSet_Lockpick_Starting_Arc,
			kSet_Progression_Picking,
			kMake_lockpicks_unbreakable_,
			kModify_Alchemy_Effectiveness,
			kApply_Weapon_Swing_Spell,
			kModify_Commanded_Actor_Limit,
			kApply_Sneaking_Spell,
			kModify_Player_Magic_Slowdown,
			kModify_Ward_Magicka_Absorption_Pct,
			kModify_Initial_Ingredient_Effects_Learned,
			kPurify_Alchemy_Ingredients,
			kFilter_Activation,
			kCan_dual_cast_spell,
			kModify_Tempering_Health,
			kModify_Enchantment_Power,
			kModify_Soul_Pct_Captured_to_Weapon,
			kMod_Soul_Gem_Enchanting,
			kMod_applied_enchantments_allowed,
			kSet_Activate_Label,
			kMod_Shout_OK,
			kMod_Poison_Dose_Count,
			kShould_Apply_Placed_Item,
			kModify_Armor_Rating,
			kModify_lockpicking_crime_chance,
			kModify_ingredients_harvested,
			kModify_Spell_Range_Target_Loc,
			kModify_Potions_Created,
			kModify_lockpicking_key_reward_chance,
			kAllow_Mount_Actor,

			kNumPerkEntryPoints
		};


		virtual bool						CanProcess(UInt32 a_numArgs, void* a_args);	// 00 - { return false; }
		virtual EntryPointType				GetType() const;							// 01 - { return 0; }
		virtual BGSEntryPointFunctionData*	GetFunctionData() const;					// 02 - { return 0; }

		virtual ~BGSPerkEntry();														// 03

		virtual UInt32						GetNumConditions() const = 0;				// 04
		virtual void						ReleaseRefs();								// 05 - { return; }
		virtual void						Unk_06(void);								// 06 - { return; }
		virtual bool						Load(TESFile* a_mod);						// 07 - { return true; }
		virtual void						SetPerk(BGSPerk* a_perk);					// 08 - { return; }
		virtual void						Unk_09(void);								// 09 - { return 0xFFFF; }
		virtual void						Unk_0A(void);								// 0A - pure
		virtual void						Unk_0B(void);								// 0B - pure


		// members
		UInt8	rank;		// 08
		UInt8	priority;	// 09
		UInt16	type;		// 0A
		UInt32	pad0C;		// 0C
	};
	STATIC_ASSERT(sizeof(BGSPerkEntry) == 0x10);
}
