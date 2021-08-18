#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSingleton.h"
#include "RE/P/PlayerControlsData.h"

namespace RE
{
	class InputEvent;
	class MenuModeChangeEvent;
	class MenuOpenCloseEvent;
	class PlayerInputHandler;
	struct ActivateHandler;
	struct AttackBlockHandler;
	struct AutoMoveHandler;
	struct JumpHandler;
	struct LookHandler;
	struct MovementHandler;
	struct ReadyWeaponHandler;
	struct RunHandler;
	struct ShoutHandler;
	struct SneakHandler;
	struct SprintHandler;
	struct TESFurnitureEvent;
	struct TogglePOVHandler;
	struct ToggleRunHandler;

	class PlayerControls :
		public BSTEventSink<InputEvent*>,          // 000
		public BSTEventSink<MenuOpenCloseEvent>,   // 008
		public BSTEventSink<MenuModeChangeEvent>,  // 010
		public BSTSingletonSDM<PlayerControls>,    // 020
		public BSTEventSink<TESFurnitureEvent>     // 018
	{
	public:
		inline static constexpr auto RTTI = RTTI_PlayerControls;

		PlayerControls();
		~PlayerControls() override = default;  // 00

		static PlayerControls* GetSingleton();

		constexpr ActivateHandler* GetActivateHandler() const noexcept { return activateHandler; }

		// members
		std::uint8_t                  pad021;                 // 021
		std::uint16_t                 pad022;                 // 022
		PlayerControlsData            data;                   // 024
		std::uint32_t                 pad054;                 // 054
		BSTArray<PlayerInputHandler*> handlers;               // 058
		BSTArray<void*>               unk070;                 // 070
		BSTArray<void*>               unk088;                 // 088
		std::uint8_t                  unk0A0[8];              // 0A0
		std::uint64_t                 unk0A8;                 // 0A8
		float                         unk0B0[8];              // 0B0
		std::uint32_t                 unk0D0[10];             // 0D0
		std::uint8_t                  unk0F8[8];              // 0F8
		float                         unk100[20];             // 100
		BSTArray<ActorHandle>         actionInterestedActor;  // 150
		mutable BSSpinLock            actorArrayLock;         // 168
		MovementHandler*              movementHandler;        // 170
		LookHandler*                  lookHandler;            // 178
		SprintHandler*                sprintHandler;          // 180
		ReadyWeaponHandler*           readyWeaponHandler;     // 188
		AutoMoveHandler*              autoMoveHandler;        // 190
		ToggleRunHandler*             toggleRunHandler;       // 198
		ActivateHandler*              activateHandler;        // 1A0
		JumpHandler*                  jumpHandler;            // 1A8
		ShoutHandler*                 shoutHandler;           // 1B0
		AttackBlockHandler*           attackBlockHandler;     // 1B8
		RunHandler*                   runHandler;             // 1C0
		SneakHandler*                 sneakHandler;           // 1C8
		TogglePOVHandler*             togglePOVHandler;       // 1D0
		bool                          notifyingHandlers;      // 1D8
		bool                          blockPlayerInput;       // 1D9
		std::uint16_t                 unk1DA;                 // 1DA
		std::uint32_t                 unk1DC;                 // 1DC

	private:
		PlayerControls* Ctor();
	};
	static_assert(sizeof(PlayerControls) == 0x1E0);
}
