#pragma once

#include "skse64/GameRTTI.h"  // RTTI_Console

#include "RE/IMenu.h"  // IMenu


namespace RE
{
	class Console : public IMenu
	{
	public:
		inline static const void* RTTI = RTTI_Console;


		virtual ~Console();														// 00

		// override (IMenu)
		virtual void		Accept(CallbackProcessor* a_processor) override;	// 01
		virtual Result		ProcessMessage(UIMessage* a_message) override;		// 04

		static RefHandle	GetSelectedRef();

		void				SetSelectedRef(RefHandle& a_handle);


		// members
		void*	opcode;	// 30
		UInt64	unk38;	// 38
		UInt64	unk40;	// 40
		UInt64	unk48;	// 48
		UInt64	unk50;	// 50
	};
	STATIC_ASSERT(sizeof(Console) == 0x58);
}
