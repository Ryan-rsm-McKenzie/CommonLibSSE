#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTSingleton.h"

namespace RE
{
	class UserEvents : public BSTSingletonSDM<UserEvents>
	{
	public:
		struct INPUT_CONTEXT_IDS
		{
			enum INPUT_CONTEXT_ID : std::uint32_t
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

				kNone = 18
			};
		};
		using INPUT_CONTEXT_ID = INPUT_CONTEXT_IDS::INPUT_CONTEXT_ID;

		enum class USER_EVENT_FLAG
		{
			kNone = 0,
			kMovement = 1 << 0,
			kLooking = 1 << 1,
			kActivate = 1 << 2,
			kMenu = 1 << 3,
			kConsole = 1 << 4,
			kPOVSwitch = 1 << 5,
			kFighting = 1 << 6,
			kSneaking = 1 << 7,
			kMainFour = 1 << 8,
			kWheelZoom = 1 << 9,
			kJumping = 1 << 10,
			kVATS = 1 << 11,
			kInvalid = 1 << 31,

			kAll = static_cast<std::underlying_type_t<USER_EVENT_FLAG>>(-1)
		};

		static UserEvents* GetSingleton();

		// members
		std::uint8_t  pad001;             // 001
		std::uint16_t pad002;             // 002
		std::uint32_t pad004;             // 004
		BSFixedString forward;            // 008 - "Forward"
		BSFixedString back;               // 010 - "Back"
		BSFixedString strafeLeft;         // 018 - "Strafe Left"
		BSFixedString strafeRight;        // 020 - "Strafe Right"
		BSFixedString move;               // 028 - "Move"
		BSFixedString look;               // 030 - "Look"
		BSFixedString activate;           // 038 - "Activate"
		BSFixedString leftAttack;         // 040 - "Left Attack/Block"
		BSFixedString rightAttack;        // 048 - "Right Attack/Block"
		BSFixedString dualAttack;         // 050 - "Dual Attack"
		BSFixedString forceRelease;       // 058 - "ForceRelease"
		BSFixedString pause;              // 060 - "Pause"
		BSFixedString readyWeapon;        // 068 - "Ready Weapon"
		BSFixedString togglePOV;          // 070 - "Toggle POV"
		BSFixedString jump;               // 078 - "Jump"
		BSFixedString journal;            // 080 - "Journal"
		BSFixedString sprint;             // 088 - "Sprint"
		BSFixedString sneak;              // 090 - "Sneak"
		BSFixedString shout;              // 098 - "Shout"
		BSFixedString kinectShout;        // 0A0 - "KinectShout"
		BSFixedString grab;               // 0A8 - "Grab"
		BSFixedString run;                // 0B0 - "Run"
		BSFixedString toggleRun;          // 0B8 - "Toggle Always Run"
		BSFixedString autoMove;           // 0C0 - "Auto-Move"
		BSFixedString quicksave;          // 0C8 - "Quicksave"
		BSFixedString quickload;          // 0D0 - "Quickload"
		BSFixedString newSave;            // 0D8 - "NewSave"
		BSFixedString inventory;          // 0E0 - "Inventory"
		BSFixedString stats;              // 0E8 - "Stats"
		BSFixedString map;                // 0F0 - "Map"
		BSFixedString screenshot;         // 0F8 - "Screenshot"
		BSFixedString multiScreenshot;    // 100 - "Multi-Screenshot"
		BSFixedString console;            // 108 - "Console"
		BSFixedString cameraPath;         // 110 - "CameraPath"
		BSFixedString tweenMenu;          // 118 - "Tween Menu"
		BSFixedString takeAll;            // 120 - "Take All"
		BSFixedString accept;             // 128 - "Accept"
		BSFixedString cancel;             // 130 - "Cancel"
		BSFixedString up;                 // 138 - "Up"
		BSFixedString down;               // 140 - "Down"
		BSFixedString left;               // 148 - "Left"
		BSFixedString right;              // 150 - "Right"
		BSFixedString pageUp;             // 158 - "PageUp"
		BSFixedString pageDown;           // 160 - "PageDown"
		BSFixedString pick;               // 168 - "Pick"
		BSFixedString pickNext;           // 170 - "PickNext"
		BSFixedString pickPrevious;       // 178 - "PickPrevious"
		BSFixedString cursor;             // 180 - "Cursor"
		BSFixedString kinect;             // 188 - "Kinect"
		BSFixedString sprintStart;        // 190 - "SprintStart"
		BSFixedString sprintStop;         // 198 - "SprintStop"
		BSFixedString sneakStart;         // 1A0 - "sneakStart"
		BSFixedString sneakStop;          // 1A8 - "sneakStop"
		BSFixedString blockStart;         // 1B0 - "blockStart"
		BSFixedString blockStop;          // 1B8 - "blockStop"
		BSFixedString blockBash;          // 1C0 - "blockBash"
		BSFixedString attackStart;        // 1C8 - "attackStart"
		BSFixedString attackPowerStart;   // 1D0 - "attackPowerStart"
		BSFixedString reverseDirection;   // 1D8 - "reverseDirection"
		BSFixedString unequip;            // 1E0 - "Unequip"
		BSFixedString zoomIn;             // 1E8 - "Zoom In"
		BSFixedString zoomOut;            // 1F0 - "Zoom Out"
		BSFixedString rotateItem;         // 1F8 - "RotateItem"
		BSFixedString leftStick;          // 200 - "Left Stick"
		BSFixedString prevPage;           // 208 - "PrevPage"
		BSFixedString nextPage;           // 210 - "NextPage"
		BSFixedString prevSubPage;        // 218 - "PrevSubPage"
		BSFixedString nextSubPage;        // 220 - "NextSubPage"
		BSFixedString leftEquip;          // 228 - "LeftEquip"
		BSFixedString rightEquip;         // 230 - "RightEquip"
		BSFixedString toggleFavorite;     // 238 - "ToggleFavorite"
		BSFixedString favorites;          // 240 - "Favorites"
		BSFixedString hotkey1;            // 248 - "Hotkey1"
		BSFixedString hotkey2;            // 250 - "Hotkey2"
		BSFixedString hotkey3;            // 258 - "Hotkey3"
		BSFixedString hotkey4;            // 260 - "Hotkey4"
		BSFixedString hotkey5;            // 268 - "Hotkey5"
		BSFixedString hotkey6;            // 270 - "Hotkey6"
		BSFixedString hotkey7;            // 278 - "Hotkey7"
		BSFixedString hotkey8;            // 280 - "Hotkey8"
		BSFixedString quickInventory;     // 288 - "Quick Inventory"
		BSFixedString quickMagic;         // 290 - "Quick Magic"
		BSFixedString quickStats;         // 298 - "Quick Stats"
		BSFixedString quickMap;           // 2A0 - "Quick Map"
		BSFixedString toggleCursor;       // 2A8 - "ToggleCursor"
		BSFixedString wait;               // 2B0 - "Wait"
		BSFixedString click;              // 2B8 - "Click"
		BSFixedString mapLookMode;        // 2C0 - "MapLookMode"
		BSFixedString equip;              // 2C8 - "Equip"
		BSFixedString dropItem;           // 2D0 - "DropItem"
		BSFixedString rotate;             // 2D8 - "Rotate"
		BSFixedString nextFocus;          // 2E0 - "NextFocus"
		BSFixedString prevFocus;          // 2E8 - "PreviousFocus"
		BSFixedString setActiveQuest;     // 2F0 - "SetActiveQuest"
		BSFixedString placePlayerMarker;  // 2F8 - "PlacePlayerMarker"
		BSFixedString xButton;            // 300 - "XButton"
		BSFixedString yButton;            // 308 - "YButton"
		BSFixedString chargeItem;         // 310 - "ChargeItem"
		BSFixedString unk318;             // 318 - ""
		BSFixedString playerPosition;     // 320 - "PlayerPosition"
		BSFixedString localMap;           // 328 - "LocalMap"
		BSFixedString localMapMoveMode;   // 330 - "LocalMapMoveMode"
		BSFixedString itemZoom;           // 338 - "Item Zoom"
	};
	static_assert(sizeof(UserEvents) == 0x340);
}
