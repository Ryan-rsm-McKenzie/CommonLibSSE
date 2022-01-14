#pragma once

#include "RE/A/AITimer.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSTArray.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class CombatAimController;
	class CombatAreaStandard;
	class CombatGroup;
	class CombatInventory;
	class CombatTargetSelectorStandard;
	class CombatState;
	class TESCombatStyle;

	class CombatController
	{
	public:
		struct Data18;
		struct Data20;

		// members
		CombatGroup*                            combatGroup;             // 00
		CombatState*                            state;                   // 08
		CombatInventory*                        inventory;               // 10
		Data18*                                 data18;                  // 18
		Data20*                                 data20;                  // 20
		ActorHandle                             actorHandle;             // 28
		ActorHandle                             currentTargetHandle;     // 2C
		ActorHandle                             target;                  // 30
		std::uint8_t                            unk34;                   // 34
		bool                                    startedCombat;           // 35
		std::uint8_t                            unk36;                   // 36
		std::uint8_t                            unk37;                   // 37
		TESCombatStyle*                         combatStyle;             // 38
		bool                                    stoppedCombat;           // 40
		bool                                    unk41;                   // 41
		bool                                    ignoringCombat;          // 42
		bool                                    notInCombat;             // 43
		AITimer                                 unk44;                   // 44
		float                                   unk4C;                   // 4C
		BSTArray<CombatAimController*>          aimControllers;          // 50
		CombatAimController*                    currentAimController;    // 68
		CombatAimController*                    previousAimController;   // 70
		BSTArray<CombatAreaStandard*>           areas;                   // 78
		CombatAreaStandard*                     currentArea;             // 90
		BSTArray<CombatTargetSelectorStandard*> targetSelectors;         // 98
		CombatTargetSelectorStandard*           currentTargetSelector;   // B0
		CombatTargetSelectorStandard*           previousTargetSelector;  // B8
		std::uint32_t                           unkC0;                   // C0
		std::int32_t                            unkC4;                   // C4
		NiPointer<Actor>                        actor;                   // C8
		NiPointer<Actor>                        currentTarget;           // D0
	};
	static_assert(sizeof(CombatController) == 0xD8);
}
