#pragma once

#include <string_view>
#include <type_traits>

#include "RE/BSTEvent.h"
#include "RE/BSFixedString.h"
#include "RE/BSInputDevice.h"
#include "RE/BSTArray.h"
#include "RE/BSTSingleton.h"
#include "RE/DeviceTypes.h"


namespace RE
{
	class InputEvent;


	class ControlMap :
		public BSTSingletonSDM<ControlMap>,
		public BSTEventSource<InputEvent*>
	{
	public:
		struct Contexts
		{
			enum Context : UInt32
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

				kTotal = 17,

				kInvalid = 18
			};
		};
		using Context = Contexts::Context;


		enum class ControlState : UInt32
		{
			kInvalid = static_cast<std::underlying_type_t<ControlState>>(-1),
			kNone = 0,
			kLooking = 1 << 1,
			kFlying = 1 << 6,
			kSneaking = 1 << 7,
			kMenu = 1 << 8,
			kMovement = 1 << 10 | 1 << 0
		};


		enum : UInt32 { kInvalid = static_cast<UInt8>(-1) };


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
			STATIC_ASSERT(sizeof(Mapping) == 0x18);


			BSTArray<Mapping>	keyboardMap;	// 00
			BSTArray<Mapping>	mouseMap;		// 18
			BSTArray<Mapping>	gamepadMap;		// 30
			BSTArray<Mapping>	unk48;			// 48 - kinect?
		};
		STATIC_ASSERT(sizeof(InputContext) == 0x60);


		struct ActionMapping
		{
			BSFixedString	buttonName;	// 00
			UInt32			unk08;		// 08
			UInt32			unk0C;		// 0C
			UInt32			unk10;		// 10
			UInt32			unk14;		// 14
			BSFixedString	actionName;	// 18
		};
		STATIC_ASSERT(sizeof(ActionMapping) == 0x20);


		static ControlMap*	GetSingleton();

		UInt8					AllowTextInput(bool a_allow);
		UInt32					GetMappedKey(const std::string_view& a_name, DeviceType a_deviceType, Context a_contextIdx = Context::kGameplay) const;
		const BSFixedString&	GetUserEventName(UInt32 a_buttonID, DeviceType a_deviceType, Context a_contextIdx = Context::kGameplay) const;
		bool					IsLookingControlsEnabled() const;
		bool					IsFlyingControlsEnabled() const;
		bool					IsSneakingControlsEnabled() const;
		bool					IsMenuControlsEnabled() const;
		bool					IsMovementControlsEnabled() const;


		// members
		InputContext*			context[Context::kTotal];	// 060
		BSTArray<ActionMapping>	actionMap;					// 0E8
		BSTArray<void*>			unk100;						// 100
		ControlState			controlState;				// 118
		UInt32					unk11C;						// 11C
		UInt8					allowTextInput;				// 120
		UInt8					unk121;						// 121
		UInt8					unk122;						// 122
		UInt8					unk123;						// 123
		UInt32					unk124;						// 124
	};
	STATIC_ASSERT(offsetof(ControlMap, context) == 0x060);
	STATIC_ASSERT(sizeof(ControlMap) == 0x128);
}
