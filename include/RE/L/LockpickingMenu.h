#pragma once

#include "RE/B/BSSoundHandle.h"
#include "RE/B/BSTEvent.h"
#include "RE/I/IMenu.h"
#include "RE/M/MenuEventHandler.h"
#include "RE/N/NiMatrix3.h"

namespace RE
{
	class MenuOpenCloseEvent;
	class NiAVObject;
	class NiControllerManager;
	class NiControllerSequence;
	class TESObjectREFR;

	class ModelData
	{
	public:
		std::uint64_t unk00;   // 00
		std::uint64_t unk08;   // 08
		std::uint64_t unk10;   // 10
		std::uint64_t unk18;   // 00
		std::uint64_t unk20;   // 00
		NiAVObject*   object;  // 28
	};

	// menuDepth = 3
	// flags = kPausesGame | kDisablePauseMenu | kRequiresUpdate
	// context = kLockpicking
	class LockpickingMenu :
		public IMenu,                            // 00
		public MenuEventHandler,                 // 30
		public BSTEventSink<MenuOpenCloseEvent>  // 40
	{
	public:
		inline static constexpr auto      RTTI = RTTI_LockpickingMenu;
		constexpr static std::string_view MENU_NAME = "Lockpicking Menu";

		~LockpickingMenu() override;  // 00

		// override (IMenu)
		UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;  // 04

		// override (MenuEventHandler)
		bool CanProcess(InputEvent* a_event) override;              // 01
		bool ProcessThumbstick(ThumbstickEvent* a_event) override;  // 03
		bool ProcessMouseMove(MouseMoveEvent* a_event) override;    // 04
		bool ProcessButton(ButtonEvent* a_event) override;          // 05

		// override (BSTEventSink<MenuOpenCloseEvent>)
		BSEventNotifyControl ProcessEvent(const MenuOpenCloseEvent* a_event, BSTEventSource<MenuOpenCloseEvent>* a_eventSource) override;  // 01

		[[nodiscard]] static TESObjectREFR* GetTargetReference();

		// members
		ModelData*            lockpickShiv;         // 048
		ModelData*            lockpick;             // 050
		NiMatrix3             unk058;               // 058
		NiPoint3              lockRotCenter;        // 07C
		NiControllerManager*  shivController;       // 088
		NiControllerSequence* shivIntro;            // 090
		NiControllerSequence* shivRotate;           // 098
		NiControllerManager*  pickController;       // 0A0
		NiControllerSequence* pickIntro;            // 0A8
		NiControllerSequence* pickDamage;           // 0B0
		NiControllerSequence* pickBreak;            // 0B8
		NiControllerSequence* currentPickSequence;  // 0C0
		float                 pickKeyTime;          // 0C8
		std::uint32_t         unk0CC;               // 0CC
		NiControllerSequence* currentShivSequence;  // 0D0
		float                 shivKeyTime;          // 0D8
		std::uint32_t         unk0DC;               // 0DC
		float                 currentAngle;         // 0E0
		float                 lockAngle;            // 0E4
		std::uint32_t         unk0E8;               // 0E8
		BSSoundHandle         unk0EC;               // 0EC
		std::uint32_t         unk0F8;               // 0F8
		std::uint32_t         unk0FC;               // 0FC
		std::uint32_t         unk100;               // 100
		std::uint32_t         unk104;               // 104
		std::uint16_t         unk108;               // 108
		std::uint8_t          unk10A;               // 10A
		std::uint8_t          unk10B;               // 10B
		std::uint8_t          unk10C;               // 10C
		std::uint8_t          unk10D;               // 10D
		std::uint8_t          unk10E;               // 10E
		std::uint8_t          pad10F;               // 10F
	};
	static_assert(sizeof(LockpickingMenu) == 0x110);
}
