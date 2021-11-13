#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/I/IMovementControllerRegisterInterface.h"
#include "RE/I/IMovementSelectIdle.h"
#include "RE/I/IMovementDirectControl.h"
#include "RE/I/IMovementPlannerDirectControl.h"
#include "RE/I/IMovementMotionDrivenControl.h"
#include "RE/I/IMovementMessageInterface.h"
#include "RE/I/IMovementSetGoal.h"
#include "RE/I/IMovementQueryPathingState.h"
#include "RE/I/IMovementPlannerSetArbitration.h"
#include "RE/I/IMovementSetTweener.h"
#include "RE/I/IMovementQueryTweener.h"

namespace RE
{
	class IMovementControllerDataTracker;

	class MovementControllerAI :
		public IMovementControllerRegisterInterface,  // 000
		public BSIntrusiveRefCounted                  // 008
	{
	public:
		inline static constexpr auto RTTI = RTTI_MovementControllerAI;

		~MovementControllerAI() override;  // 00

		// override (IMovementControllerRegisterInterface)
		void Unk_01(void) override;  // 01
		void Unk_02(void) override;  // 02
		IMovementInterface* GetMovementInterface(const BSFixedString& a_name) override;  // 03
		void Unk_04(void) override;  // 04

		// add
		virtual void Unk_05(void);  // 05
		virtual void Unk_06(void);  // 06 - { return; }
		virtual void Unk_07(void);  // 07
		virtual void Unk_08(void);  // 08
		virtual void Unk_09(void);  // 09 - { return 1; }

		// members
		std::uint32_t                   unk00C;                            // 00C
		std::uint32_t                   movementArbitersCount1;            // 010
		std::uint32_t                   unk014;                            // 014
		std::uint64_t                   movementArbitersObfuscatedList;    // 018
		std::uint64_t                   unk020;                            // 020
		std::uint32_t                   movementArbitersCount2;            // 028
		std::uint32_t                   unk02C;                            // 02C
		std::uint64_t                   unk030;                            // 030
		std::uint64_t                   unk038;                            // 038
		std::uint64_t                   unk040;                            // 040
		std::uint64_t                   unk048;                            // 048
		std::uint64_t                   unk050;                            // 050
		ActorState*                     actorState;                        // 058
		BSFixedString                   movementSelectIdleStr;             // 060 - "IMovementSelectIdle"
		IMovementSelectIdle*            movementSelectIdle;                // 068
		BSFixedString                   movementDirectControlStr;          // 070 - "IMovementDirectControl"
		IMovementDirectControl*         movementDirectControl;             // 078
		BSFixedString                   movementPlannerDirectControlStr;   // 080 - "IMovementPlannerDirectControl"
		IMovementPlannerDirectControl*  movementPlannerDirectControl;      // 088
		BSFixedString                   movementMotionDrivenControlStr;    // 090 - "IMovementMotionDrivenControl"
		IMovementMotionDrivenControl*   movementMotionDrivenControl;       // 098
		BSFixedString                   movementMessageInterfaceStr;       // 0A0 - "IMovementMessageInterface"
		IMovementMessageInterface*      movementMessageInterface;          // 0A8
		BSFixedString                   movementSetGoalStr;                // 0B0 - "IMovementSetGoal"
		IMovementSetGoal*               movementSetGoal;                   // 0B8
		BSFixedString                   movementQueryPathingStateStr;      // 0C0 - "IMovementQueryPathingState"
		IMovementQueryPathingState*     movementQueryPathingState;         // 0C8
		BSFixedString                   movementPlannerSetArbitrationStr;  // 0D0 - "IMovementPlannerSetArbitration"
		IMovementPlannerSetArbitration* movementPlannerSetArbitration;     // 0D8
		BSFixedString                   movementSetTweenerStr;             // 0E0 - "IMovementSetTweener"
		IMovementSetTweener*            movementSetTweener;                // 0E8
		BSFixedString                   movementQueryTweenerStr;           // 0F0 - "IMovementQueryTweener"
		IMovementQueryTweener*          movementQueryTweener;              // 0F8
		std::uint64_t                   unk100;                            // 100
		std::uint64_t                   unk108;                            // 108
		std::uint64_t                   unk110;                            // 110
		IMovementControllerDataTracker* movementControllerDataTracker;     // 118
	};
	static_assert(sizeof(MovementControllerAI) == 0x120);
}
