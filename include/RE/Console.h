#pragma once

#include <string_view>

#include "RE/BSPointerHandle.h"
#include "RE/IMenu.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class TESObjectREFR;


	// menuDepth = 12
	// flags = kPausesGame | kAlwaysOpen | kUsesCursor | kAllowSaving
	// context = kConsole
	class Console : public IMenu
	{
	public:
		inline static constexpr auto	  RTTI = RTTI_Console;
		constexpr static std::string_view MENU_NAME = "Console";


		virtual ~Console();	 // 00

		// override (IMenu)
		virtual void			   Accept(CallbackProcessor* a_processor) override;	 // 01
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;	 // 04

		static NiPointer<TESObjectREFR> GetSelectedRef();
		static ObjectRefHandle			GetSelectedRefHandle();

		void SetSelectedRef(NiPointer<TESObjectREFR> a_refPtr);
		void SetSelectedRef(TESObjectREFR* a_ref);
		void SetSelectedRef(ObjectRefHandle a_handle);


		// members
		void*  opcode;	// 30
		UInt64 unk38;	// 38
		UInt64 unk40;	// 40
		UInt64 unk48;	// 48
		UInt64 unk50;	// 50

	protected:
		void SetSelectedRef_Impl(ObjectRefHandle& a_handle);
	};
	STATIC_ASSERT(sizeof(Console) == 0x58);
}
