#pragma once

#include "RE/HeldStateHandler.h"  // HeldStateHandler


namespace RE
{
	struct AttackBlockHandler : public HeldStateHandler
	{
	public:
		virtual ~AttackBlockHandler();																	// 00

		// override (PlayerInputHandler)
		virtual	bool	CanProcess(InputEvent* a_event) override;										// 01
		virtual	void	ProcessButton(ButtonEvent* a_event, PlayerControls::Data024* a_arg2) override;	// 04


		// members
		UInt64	unk10;	// 10
		UInt64	unk18;	// 18
		UInt64	unk20;	// 20
		UInt64	unk28;	// 28
		UInt64	unk30;	// 30
		UInt64	unk38;	// 38
		UInt64	unk40;	// 40
	};
	STATIC_ASSERT(sizeof(AttackBlockHandler) == 0x48);
}
