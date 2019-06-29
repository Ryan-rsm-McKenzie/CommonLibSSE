#pragma once

#include "skse64/GameRTTI.h"  // RTTI_AttackBlockHandler

#include "RE/HeldStateHandler.h"  // HeldStateHandler


namespace RE
{
	struct AttackBlockHandler : public HeldStateHandler
	{
	public:
		inline static const void* RTTI = RTTI_AttackBlockHandler;


		virtual ~AttackBlockHandler();																// 00

		// override (PlayerInputHandler)
		virtual	bool	CanProcess(InputEvent* a_event) override;									// 01
		virtual	void	ProcessButton(ButtonEvent* a_event, MovementData* a_movementData) override;	// 04
		virtual void	Unk_05(void) override;														// 05
		virtual void	SetHeldState(bool a_held) override;											// 06


		// members
		UInt64	unk18;	// 18
		UInt64	unk20;	// 20
		UInt64	unk28;	// 28
		UInt64	unk30;	// 30
		UInt64	unk38;	// 38
		UInt64	unk40;	// 40
	};
	STATIC_ASSERT(sizeof(AttackBlockHandler) == 0x48);
}
