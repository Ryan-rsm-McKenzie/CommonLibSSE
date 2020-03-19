#pragma once

#include "RE/BSPointerHandle.h"
#include "RE/BSTArray.h"
#include "RE/BSTEvent.h"
#include "RE/BSTSingleton.h"
#include "RE/PlayerControlsData.h"


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
		public BSTEventSink<InputEvent*>,		   // 000
		public BSTEventSink<MenuOpenCloseEvent>,   // 008
		public BSTEventSink<MenuModeChangeEvent>,  // 010
		public BSTSingletonSDM<PlayerControls>,	   // 020
		public BSTEventSink<TESFurnitureEvent>	   // 018
	{
	public:
		inline static constexpr auto RTTI = RTTI_PlayerControls;


		PlayerControls();
		virtual ~PlayerControls() = default;  // 00

		static PlayerControls* GetSingleton();

		bool IsActivateControlsEnabled() const;
		void ToggleActivateControls(bool a_enable) const;


		// members
		UInt8						  pad021;				  // 021
		UInt16						  pad022;				  // 022
		PlayerControlsData			  data;					  // 024
		UInt32						  pad054;				  // 054
		BSTArray<PlayerInputHandler*> handlers;				  // 058
		BSTArray<void*>				  unk070;				  // 070
		BSTArray<void*>				  unk088;				  // 088
		UInt8						  unk0A0[8];			  // 0A0
		UInt64						  unk0A8;				  // 0A8
		float						  unk0B0[8];			  // 0B0
		UInt32						  unk0D0[10];			  // 0D0
		UInt8						  unk0F8[8];			  // 0F8
		float						  unk100[20];			  // 100
		BSTArray<ActorHandle>		  actionInterestedActor;  // 150
		mutable BSSpinLock			  actorArrayLock;		  // 168
		MovementHandler*			  movementHandler;		  // 170
		LookHandler*				  lookHandler;			  // 178
		SprintHandler*				  sprintHandler;		  // 180
		ReadyWeaponHandler*			  readyWeaponHandler;	  // 188
		AutoMoveHandler*			  autoMoveHandler;		  // 190
		ToggleRunHandler*			  toggleRunHandler;		  // 198
		ActivateHandler*			  activateHandler;		  // 1A0
		JumpHandler*				  jumpHandler;			  // 1A8
		ShoutHandler*				  shoutHandler;			  // 1B0
		AttackBlockHandler*			  attackBlockHandler;	  // 1B8
		RunHandler*					  runHandler;			  // 1C0
		SneakHandler*				  sneakHandler;			  // 1C8
		TogglePOVHandler*			  togglePOVHandler;		  // 1D0
		bool						  notifyingHandlers;	  // 1D8
		bool						  blockPlayerInput;		  // 1D9
		UInt16						  unk1DA;				  // 1DA
		UInt32						  unk1DC;				  // 1DC

	private:
		PlayerControls* Ctor();
	};
	STATIC_ASSERT(sizeof(PlayerControls) == 0x1E0);
}
