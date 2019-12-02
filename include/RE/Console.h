#pragma once

#include "RE/IMenu.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class TESObjectREFR;


	class Console : public IMenu
	{
	public:
		inline static const void* RTTI = RTTI_Console;


		virtual ~Console();														// 00

		// override (IMenu)
		virtual void		Accept(CallbackProcessor* a_processor) override;	// 01
		virtual Result		ProcessMessage(UIMessage* a_message) override;		// 04

		static NiPointer<TESObjectREFR>	GetSelectedRef();
		static RefHandle				GetSelectedRefHandle();

		void	SetSelectedRef(NiPointer<TESObjectREFR> a_refPtr);
		void	SetSelectedRef(TESObjectREFR* a_ref);
		void	SetSelectedRef(RefHandle a_handle);


		// members
		void*	opcode;	// 30
		UInt64	unk38;	// 38
		UInt64	unk40;	// 40
		UInt64	unk48;	// 48
		UInt64	unk50;	// 50

	protected:
		void SetSelectedRef_Impl(RefHandle& a_handle);
	};
	STATIC_ASSERT(sizeof(Console) == 0x58);
}
