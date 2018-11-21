#pragma once

#include "skse64/GameEvents.h"  // BSTEventSource
#include "skse64/GameInput.h"  // InputManager
#include "skse64/GameTypes.h"  // BSFixedString, tArray

#include "RE/BSInputDevice.h"  // BSInputDevice
#include "RE/BSTSingleton.h"  // BSTSingletonSDM


namespace RE
{
	class InputManager :
		public BSTSingletonSDM<InputManager>,
		public BSTEventSource<InputEvent*>
	{
	private:
		typedef RE::BSInputDevice::InputDevice InputDevice;

	public:
		enum Context : UInt32
		{
			kContext_Gameplay = 0,
			kContext_MenuMode,
			kContext_Console,
			kContext_ItemMenu,
			kContext_Inventory,
			kContext_DebugText,
			kContext_Favorites,
			kContext_Map,
			kContext_Stats,
			kContext_Cursor,
			kContext_Book,
			kContext_DebugOverlay,
			kContext_Journal,
			kContext_TFCMode,
			kContext_MapDebug,
			kContext_Lockpicking,
			kContext_Favor,
			kContext_Count = 17,

			kContext_Invalid = 18
		};


		enum ControlState
		{
			kControlState_Looking	= 0x002,
			kControlState_Flying	= 0x040,
			kControlState_Sneaking	= 0x080,
			kControlState_Menu		= 0x100,
			kControlState_Movement	= 0x401
		};


		enum
		{
			kInvalid = 0xFFFFFFFF
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


			tArray<Mapping>	keyboardMap;
			tArray<Mapping>	mouseMap;
			tArray<Mapping>	gamepadMap;
		};


		static InputManager*	GetSingleton();
		UInt8					AllowTextInput(bool a_allow);

		UInt32					GetMappedKey(const BSFixedString& a_name, InputDevice a_deviceType, Context a_contextIdx = kContext_Gameplay) const;
		const BSFixedString&	GetUserEventName(UInt32 a_buttonID, InputDevice a_deviceType, Context a_contextIdx = kContext_Gameplay) const;
		bool					IsLookingControlsEnabled() const;
		bool					IsFlyingControlsEnabled() const;
		bool					IsSneakingControlsEnabled() const;
		bool					IsMenuControlsEnabled() const;
		bool					IsMovementControlsEnabled() const;


		// members
		InputContext*	context[kContext_Count];	// 060
		tArray<void*>	unk0E8;						// 0E8
		tArray<void*>	unk100;						// 100
		SInt32			controlState;				// 118 - init'd to -1
		UInt32			unk11C;						// 11C - init'd to 0x80000000
		UInt8			allowTextInput;				// 120 - init'd to 0
		UInt8			unk121;						// 121 - init'd to 0
		UInt8			unk122;						// 122 - init'd to 0
		UInt8			pad[5];						// 123
	};
	STATIC_ASSERT(offsetof(InputManager, context) == 0x060);
	STATIC_ASSERT(sizeof(InputManager) == 0x128);
}
