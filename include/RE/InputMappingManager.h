#pragma once

#include "skse64/GameInput.h"  // InputManager

#include "RE/BSTEvent.h"  // BSTEventSource
#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSInputDevice.h"  // BSInputDevice
#include "RE/BSTArray.h"  // BSTArray
#include "RE/BSTSingleton.h"  // BSTSingletonSDM
#include "RE/DeviceTypes.h"  // DeviceType


namespace RE
{
	class InputMappingManager :
		public BSTSingletonSDM<InputMappingManager>,
		public BSTEventSource<InputEvent*>
	{
	public:
		enum class Context : UInt32
		{
			kGameplay = 0,
			kMenuMode,
			kConsole,
			kItemMenu,
			kInventory,
			kDebugText,
			kFavorites,
			kMap,
			kStats,
			kCursor,
			kBook,
			kDebugOverlay,
			kJournal,
			kTFCMode,
			kMapDebug,
			kLockpicking,
			kFavor,
			kCount = 17,

			kInvalid = 18
		};


		enum class ControlState : UInt32
		{
			kInvalid = 0xFFFFFFFF,
			kNone = 0x0,
			kLooking = 0x002,
			kFlying = 0x040,
			kSneaking = 0x080,
			kMenu = 0x100,
			kMovement = 0x401
		};


		struct InputContext
		{
			struct Mapping
			{
				BSFixedString	name;		// 00 - User Event Name
				UInt16			buttonID;	// 08
				UInt16			modifier;	// 0A
				UInt32			sortIndex;	// 0C
				UInt32			flags;		// 10 - User Event Binary Flag
				UInt32			pad14;		// 14
			};


			BSTArray<Mapping>	keyboardMap;
			BSTArray<Mapping>	mouseMap;
			BSTArray<Mapping>	gamepadMap;
		};


		static InputMappingManager*	GetSingleton();
		UInt8						AllowTextInput(bool a_allow);

		UInt32						GetMappedKey(const BSFixedString& a_name, DeviceType a_deviceType, Context a_contextIdx = Context::kGameplay) const;
		const BSFixedString&		GetUserEventName(UInt32 a_buttonID, DeviceType a_deviceType, Context a_contextIdx = Context::kGameplay) const;
		bool						IsLookingControlsEnabled() const;
		bool						IsFlyingControlsEnabled() const;
		bool						IsSneakingControlsEnabled() const;
		bool						IsMenuControlsEnabled() const;
		bool						IsMovementControlsEnabled() const;


		// members
		InputContext*	context[to_underlying(Context::kCount)];	// 060
		BSTArray<void*>	unk0E8;										// 0E8
		BSTArray<void*>	unk100;										// 100
		ControlState	controlState;								// 118 - init'd to kInvalid
		UInt32			unk11C;										// 11C - init'd to 0x80000000
		UInt8			allowTextInput;								// 120 - init'd to 0
		UInt8			unk121;										// 121 - init'd to 0
		UInt8			unk122;										// 122 - init'd to 0
		UInt8			pad[5];										// 123
	};
	STATIC_ASSERT(offsetof(InputMappingManager, context) == 0x060);
	STATIC_ASSERT(sizeof(InputMappingManager) == 0x128);
}
