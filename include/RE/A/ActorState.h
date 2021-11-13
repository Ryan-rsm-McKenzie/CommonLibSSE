#pragma once

#include "RE/I/IMovementState.h"

namespace RE
{
	enum class ACTOR_LIFE_STATE : std::uint32_t
	{
		kAlive = 0,
		kDying = 1,
		kDead = 2,
		kUnconcious = 3,
		kReanimate = 4,
		kRecycle = 5,
		kRestrained = 6,
		kEssentialDown = 7,
		kBleedout = 8
	};

	enum class ATTACK_STATE_ENUM : std::uint32_t
	{
		kNone = 0,
		kDraw = 1,
		kSwing = 2,
		kHit = 3,
		kNextAttack = 4,
		kFollowThrough = 5,
		kBash = 6,
		kBowDraw = 8,
		kBowAttached = 9,
		kBowDrawn = 10,
		kBowReleasing = 11,
		kBowReleased = 12,
		kBowNextAttack = 13,
		kBowFollowThrough = 14,
		kFire = 15,
		kFiring = 16,
		kFired = 17
	};

	enum class FLY_STATE : std::uint32_t
	{
		kNone = 0,
		kTakeOff = 1,
		kCruising = 2,
		kHovering = 3,
		kLanding = 4,
		kPerching = 5,
		kAction = 6
	};

	enum class KNOCK_STATE_ENUM : std::uint32_t
	{
		kNormal = 0,
		kExplode = 1,
		kExplodeLeadIn = 2,
		kOut = 3,
		kOutLeadIn = 4,
		kQueued = 5,
		kGetUp = 6,
		kDown = 7,
		kWaitForTaskQueue = 8
	};

	enum class SIT_SLEEP_STATE : std::uint32_t
	{
		kNormal = 0,
		kWantToSit = 1,
		kWaitingForSitAnim = 2,

		kIsSitting = 3,
		kRidingMount = static_cast<std::underlying_type_t<SIT_SLEEP_STATE>>(kIsSitting),

		kWantToStand = 4,

		kWantToSleep = 5,
		kWaitingForSleepAnim = 6,
		kIsSleeping = 7,
		kWantToWake = 8
	};

	enum class WEAPON_STATE : std::uint32_t
	{
		kSheathed = 0,
		kWantToDraw = 1,
		kDrawing = 2,
		kDrawn = 3,
		kWantToSheathe = 4,
		kSheathing = 5
	};

	class ActorState : public IMovementState
	{
	public:
		inline static constexpr auto RTTI = RTTI_ActorState;

		struct ActorState1
		{
		public:
			// members
			std::uint32_t     movingBack: 1;        // 0:00
			std::uint32_t     movingForward: 1;     // 0:01
			std::uint32_t     movingRight: 1;       // 0:02
			std::uint32_t     movingLeft: 1;        // 0:03
			std::uint32_t     unk04: 2;             // 0:04
			std::uint32_t     walking: 1;           // 0:06
			std::uint32_t     running: 1;           // 0:07
			std::uint32_t     sprinting: 1;         // 0:08
			std::uint32_t     sneaking: 1;          // 0:09
			std::uint32_t     swimming: 1;          // 0:10
			std::uint32_t     unk11: 3;             // 0:11
			SIT_SLEEP_STATE   sitSleepState: 4;     // 0:14
			FLY_STATE         flyState: 3;          // 0:18
			ACTOR_LIFE_STATE  lifeState: 4;         // 0:21
			KNOCK_STATE_ENUM  knockState: 3;        // 0:25
			ATTACK_STATE_ENUM meleeAttackState: 4;  // 0:28
		};
		static_assert(sizeof(ActorState1) == 0x4);

		struct ActorState2
		{
		public:
			// members
			std::uint32_t talkingToPlayer: 1;  // 0:00
			std::uint32_t forceRun: 1;         // 0:01
			std::uint32_t forceSneak: 1;       // 0:02
			std::uint32_t headTracking: 1;     // 0:03
			std::uint32_t reanimating: 1;      // 0:04
			WEAPON_STATE  weaponState: 3;      // 0:05
			std::uint32_t wantBlocking: 1;     // 0:08
			std::uint32_t flightBlocked: 1;    // 0:09
			std::uint32_t recoil: 2;           // 0:10
			std::uint32_t allowFlying: 1;      // 0:12
			std::uint32_t staggered: 1;        // 0:13
			std::uint32_t unk14: 18;           // 0:14
		};
		static_assert(sizeof(ActorState2) == 0x4);

		~ActorState() override;  // 00

		// override (IMovementState)
		void Unk_01(void) override;             // 01 - { return 0; }
		void Unk_02(void) override;             // 02 - { return; }
		void Unk_03(NiPoint3* a_pos) override;  // 03 - { return; }
		void Unk_04(void) override;             // 04 - { return; }
		void Unk_05(void) override;             // 05 - { return 0.0; }
		void Unk_06(void) override;             // 06 - { return 0.0; }
		void Unk_07(void) override;             // 07 - { return; }
		void Unk_08(void) override;             // 08 - { return 0; }

		// add
		virtual void Unk_14(void);  // 14
		virtual void Unk_15(void);  // 15

		[[nodiscard]] ATTACK_STATE_ENUM GetAttackState() const noexcept { return actorState1.meleeAttackState; }
		[[nodiscard]] FLY_STATE         GetFlyState() const noexcept { return actorState1.flyState; }
		[[nodiscard]] KNOCK_STATE_ENUM  GetKnockState() const noexcept { return actorState1.knockState; }
		[[nodiscard]] ACTOR_LIFE_STATE  GetLifeState() const noexcept { return actorState1.lifeState; }
		[[nodiscard]] SIT_SLEEP_STATE   GetSitSleepState() const noexcept { return actorState1.sitSleepState; }
		[[nodiscard]] WEAPON_STATE      GetWeaponState() const noexcept { return actorState2.weaponState; }

		[[nodiscard]] bool IsBleedingOut() const noexcept
		{
			switch (GetLifeState()) {
			case ACTOR_LIFE_STATE::kEssentialDown:
			case ACTOR_LIFE_STATE::kBleedout:
				return true;
			default:
				return false;
			}
		}

		[[nodiscard]] bool IsFlying() const noexcept
		{
			switch (GetFlyState()) {
			case FLY_STATE::kNone:
			case FLY_STATE::kPerching:
				return false;
			default:
				return true;
			}
		}

		[[nodiscard]] bool IsSneaking() const noexcept { return static_cast<bool>(actorState1.sneaking); }
		[[nodiscard]] bool IsSprinting() const noexcept { return static_cast<bool>(actorState1.sprinting); }
		[[nodiscard]] bool IsSwimming() const noexcept { return static_cast<bool>(actorState1.swimming); }
		[[nodiscard]] bool IsUnconscious() const noexcept { return GetLifeState() == ACTOR_LIFE_STATE::kUnconcious; }

		[[nodiscard]] bool IsWeaponDrawn() const noexcept
		{
			switch (GetWeaponState()) {
			case WEAPON_STATE::kDrawn:
			case WEAPON_STATE::kWantToSheathe:
			case WEAPON_STATE::kSheathing:
				return true;
			default:
				return false;
			}
		}

		// members
		ActorState1 actorState1;  // 08
		ActorState2 actorState2;  // 0C
	};
	static_assert(sizeof(ActorState) == 0x10);
}
