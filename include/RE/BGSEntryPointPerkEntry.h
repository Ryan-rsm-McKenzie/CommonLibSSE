#pragma once

#include "RE/BGSPerkEntry.h"  // RE::BGSPerkEntry

class BGSPerk;
class Condition;


namespace RE
{
	class BGSEntryPointFunctionData;
	class TESObjectREFR;


	class BGSEntryPointPerkEntry : public BGSPerkEntry
	{
	public:
		enum EntryPointType : UInt8
		{
			kEntryPoint_Calculate_Weapon_Damage,
			kEntryPoint_Calculate_My_Critical_Hit_Chance,
			kEntryPoint_Calculate_My_Critical_Hit_Damage,
			kEntryPoint_Calculate_Mine_Explode_Chance,
			kEntryPoint_Adjust_Limb_Damage,
			kEntryPoint_Adjust_Book_Skill_Points,
			kEntryPoint_Modify_Recovered_Health,
			kEntryPoint_Get_Should_Attack,
			kEntryPoint_Modify_Buy_Prices,
			kEntryPoint_Add_Leveled_List_On_Death,
			kEntryPoint_Get_Max_Carry_Weight,
			kEntryPoint_Modify_Addiction_Chance,
			kEntryPoint_Modify_Addiction_Duration,
			kEntryPoint_Modify_Positive_Chem_Duration,
			kEntryPoint_Activate,
			kEntryPoint_Ignore_Running_During_Detection,
			kEntryPoint_Ignore_Broken_Lock,
			kEntryPoint_Modify_Enemy_Critical_Hit_Chance,
			kEntryPoint_Modify_Sneak_Attack_Mult,
			kEntryPoint_Modify_Max_Placeable_Mines,
			kEntryPoint_Modify_Bow_Zoom,
			kEntryPoint_Modify_Recover_Arrow_Chance,
			kEntryPoint_Modify_Skill_Use,
			kEntryPoint_Modify_Telekinesis_Distance,
			kEntryPoint_Modify_Telekinesis_Damage_Mult,
			kEntryPoint_Modify_Telekinesis_Damage,
			kEntryPoint_Mod_Bashing_Damage,
			kEntryPoint_Mod_Power_Attack_Stamina,
			kEntryPoint_Mod_Power_Attack_Damage,
			kEntryPoint_Mod_Spell_Magnitude,
			kEntryPoint_Mod_Spell_Duration,
			kEntryPoint_Mod_Secondary_Value_Weight,
			kEntryPoint_Mod_Armor_Weight,
			kEntryPoint_Mod_Incoming_Stagger,
			kEntryPoint_Mod_Target_Stagger,
			kEntryPoint_Mod_Attack_Damage,
			kEntryPoint_Mod_Incoming_Damage,
			kEntryPoint_Mod_Target_Damage_Resistance,
			kEntryPoint_Mod_Spell_Cost,
			kEntryPoint_Mod_Percent_Blocked,
			kEntryPoint_Mod_Shield_Deflect_Arrow_Chance,
			kEntryPoint_Mod_Incoming_Spell_Magnitude,
			kEntryPoint_Mod_Incoming_Spell_Duration,
			kEntryPoint_Mod_Player_Intimidation,
			kEntryPoint_Mod_Player_Reputation,
			kEntryPoint_Mod_Favor_Points,
			kEntryPoint_Mod_Bribe_Amount,
			kEntryPoint_Mod_Detection_Light,
			kEntryPoint_Mod_Detection_Movement,
			kEntryPoint_Mod_Soul_Gem_Recharge,
			kEntryPoint_Set_Sweep_Attack,
			kEntryPoint_Apply_Combat_Hit_Spell,
			kEntryPoint_Apply_Bashing_Spell,
			kEntryPoint_Apply_Reanimate_Spell,
			kEntryPoint_Set_Boolean_Graph_Variable,
			kEntryPoint_Mod_Spell_Casting_Sound_Event,
			kEntryPoint_Modify_Pickpocket_Chance,
			kEntryPoint_Modify_Detection_Sneak_Skill,
			kEntryPoint_Modify_Falling_Damage,
			kEntryPoint_Modify_Lockpick_Sweet_Spot,
			kEntryPoint_Modify_Sell_Prices,
			kEntryPoint_Can_Pickpocket_Equipped_Item,
			kEntryPoint_Modify_Lockpick_level_allowed,
			kEntryPoint_Set_Lockpick_Starting_Arc,
			kEntryPoint_Set_Progression_Picking,
			kEntryPoint_Make_lockpicks_unbreakable_,
			kEntryPoint_Modify_Alchemy_Effectiveness,
			kEntryPoint_Apply_Weapon_Swing_Spell,
			kEntryPoint_Modify_Commanded_Actor_Limit,
			kEntryPoint_Apply_Sneaking_Spell,
			kEntryPoint_Modify_Player_Magic_Slowdown,
			kEntryPoint_Modify_Ward_Magicka_Absorption_Pct,
			kEntryPoint_Modify_Initial_Ingredient_Effects_Learned,
			kEntryPoint_Purify_Alchemy_Ingredients,
			kEntryPoint_Filter_Activation,
			kEntryPoint_Can_dual_cast_spell,
			kEntryPoint_Modify_Tempering_Health,
			kEntryPoint_Modify_Enchantment_Power,
			kEntryPoint_Modify_Soul_Pct_Captured_to_Weapon,
			kEntryPoint_Mod_Soul_Gem_Enchanting,
			kEntryPoint_Mod_applied_enchantments_allowed,
			kEntryPoint_Set_Activate_Label,
			kEntryPoint_Mod_Shout_OK,
			kEntryPoint_Mod_Poison_Dose_Count,
			kEntryPoint_Should_Apply_Placed_Item,
			kEntryPoint_Modify_Armor_Rating,
			kEntryPoint_Modify_lockpicking_crime_chance,
			kEntryPoint_Modify_ingredients_harvested,
			kEntryPoint_Modify_Spell_Range_Target_Loc,
			kEntryPoint_Modify_Potions_Created,
			kEntryPoint_Modify_lockpicking_key_reward_chance,
			kEntryPoint_Allow_Mount_Actor,

			kNumPerkEntryPoints
		};


		virtual bool						CanProcess(UInt32 a_numArgs, void* a_args) override;	// 0
		virtual UInt8						GetType() const override;								// 1 { return this->unk11; }
		virtual BGSEntryPointFunctionData*	GetFunctionData() const override;						// 2 { return this->functionData; }

		virtual ~BGSEntryPointPerkEntry();															// 3
		// more

		bool								HasType(EntryPointType a_type);


		// members
		EntryPointType				type;				// 10
		UInt8						unk11;				// 11
		UInt8						numArgs;			// 12
		UInt8						pad13;				// 13
		UInt32						pad14;				// 14
		BGSEntryPointFunctionData*	functionData;		// 18
		Condition*					conditions;			// 20 - numConditions = *(void*)(conditions - 1);
		BGSPerk*					perk;				// 28
	};
}
