#pragma once

#include "RE/BSTArray.h"  // BSTArray
#include "RE/BSTEvent.h"  // BSTEventSink
#include "RE/BSTSingleton.h"  // BSTSingletonSDM
#include "RE/MovementData.h"  // MovementData


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
		public BSTEventSink<InputEvent*>,			// 000
		public BSTEventSink<MenuOpenCloseEvent>,	// 008
		public BSTEventSink<MenuModeChangeEvent>,	// 010
		public BSTSingletonSDM<PlayerControls>,		// 020
		public BSTEventSink<TESFurnitureEvent>		// 018
	{
	public:
		PlayerControls();
		virtual	~PlayerControls();	// 00

		static PlayerControls* GetSingleton();


		// members
		MovementData					movementData;		// 024
		BSTArray<PlayerInputHandler*>	handlers;			// 058
		BSTArray<void*>					unk070;				// 070
		BSTArray<void*>					unk088;				// 088
		UInt8							unk0A0[8];			// 0A0
		UInt64							unk0A8;				// 0A8
		float							unk0B0[8];			// 0B0
		UInt32							unk0D0[10];			// 0D0
		UInt8							unk0F8[8];			// 0F8
		float							unk100[20];			// 100
		BSTArray<void*>					unk150;				// 150
		UInt64							unk168;				// 168
		MovementHandler*				movementHandler;	// 170
		LookHandler*					lookHandler;		// 178
		SprintHandler*					sprintHandler;		// 180
		ReadyWeaponHandler*				readyWeaponHandler; // 188
		AutoMoveHandler*				autoMoveHandler;	// 190
		ToggleRunHandler*				toggleRunHandler;	// 198
		ActivateHandler*				activateHandler;	// 1A0
		JumpHandler*					jumpHandler;		// 1A8
		ShoutHandler*					shoutHandler;		// 1B0
		AttackBlockHandler*				attackBlockHandler; // 1B8
		RunHandler*						runHandler;			// 1C0
		SneakHandler*					sneakHandler;		// 1C8
		TogglePOVHandler*				togglePOVHandler;	// 1D0
		UInt64							unk1D8;				// 1D8

	private:
		PlayerControls* Ctor_Internal();
	};
	STATIC_ASSERT(sizeof(PlayerControls) == 0x1E0);
}
