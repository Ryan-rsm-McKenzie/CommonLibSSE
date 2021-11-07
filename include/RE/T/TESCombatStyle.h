#pragma once

#include "RE/F/FormTypes.h"
#include "RE/T/TESForm.h"

namespace RE
{
	struct CombatStyleGeneralData  // CSGD
	{
		float offensiveMult;       // 00
		float defensiveMult;       // 04
		float groupOffensiveMult;  // 08
		float meleeScoreMult;      // 0C
		float magicScoreMult;      // 10
		float rangedScoreMult;     // 14
		float shoutScoreMult;      // 18
		float unarmedScoreMult;    // 1C
		float staffScoreMult;      // 20
		float avoidThreatChance;   // 24
	};
	static_assert(sizeof(CombatStyleGeneralData) == 0x28);

	struct CombatStyleMeleeData  // CSME
	{
		float attackIncapacitatedMult;       // 00
		float powerAttackIncapacitatedMult;  // 04
		float powerAttackBlockingMult;       // 08
		float bashMult;                      // 0C
		float bashRecoilMult;                // 10
		float bashAttackMult;                // 14
		float bashPowerAttackMult;           // 18
		float specialAttackMult;             // 1C
	};
	static_assert(sizeof(CombatStyleMeleeData) == 0x20);

	struct CombatStyleCloseRangeData  // CSCR
	{
		float circleMult;         // 00
		float fallbackMult;       // 04
		float flankDistanceMult;  // 08
		float stalkTimeMult;      // 0C
	};
	static_assert(sizeof(CombatStyleCloseRangeData) == 0x10);

	struct CombatStyleLongRangeData  // CSLR
	{
		float strafeMult;  // 0
	};
	static_assert(sizeof(CombatStyleLongRangeData) == 0x4);

	struct CombatStyleFlightData  // CSFL
	{
		float hoverChance;           // 00
		float diveBombChance;        // 04
		float groundAttackChance;    // 08
		float hoverTimeMult;         // 0C
		float groundAttackTimeMult;  // 10
		float perchAttackChance;     // 14
		float perchAttackTimeMult;   // 18
		float flyingAttackChance;    // 1C
	};
	static_assert(sizeof(CombatStyleFlightData) == 0x20);

	class TESCombatStyle : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESCombatStyle;
		inline static constexpr auto VTABLE = VTABLE_TESCombatStyle;
		inline static constexpr auto FORMTYPE = FormType::CombatStyle;

		enum class FLAG  // DATA
		{
			kNone = 0,
			kDuelingStyle = 1 << 0,
			kFlankingStyle = 1 << 1,
			kAllowDualWielding = 1 << 2
		};

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12,
				kAllowDualWielding = 1 << 19
			};
		};

		~TESCombatStyle() override;  // 00

		// override (TESForm)
		void InitializeData() override;      // 04
		bool Load(TESFile* a_mod) override;  // 06
		void InitItemImpl() override;        // 13

		// members
		CombatStyleGeneralData                generalData;     // 20 - CSGD
		CombatStyleMeleeData                  meleeData;       // 48 - CSME
		CombatStyleCloseRangeData             closeRangeData;  // 68 - CSCR
		CombatStyleLongRangeData              longRangeData;   // 78 - CSLR
		CombatStyleFlightData                 flightData;      // 7C - CSFL
		stl::enumeration<FLAG, std::uint32_t> flags;           // 9C - DATA
	};
	static_assert(sizeof(TESCombatStyle) == 0xA0);
}
