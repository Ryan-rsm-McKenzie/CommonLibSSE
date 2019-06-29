#pragma once

#include "skse64/GameRTTI.h"  // RTTI_PlayerInputHandler

#include "RE/MovementData.h"  // MovementData


namespace RE
{
	class ButtonEvent;
	class InputEvent;
	class MouseMoveEvent;
	class ThumbstickEvent;


	class PlayerInputHandler
	{
	public:
		inline static const void* RTTI = RTTI_PlayerInputHandler;


		virtual ~PlayerInputHandler();																// 00

		virtual	bool	CanProcess(InputEvent* a_event) = 0;										// 01
		virtual	void	ProcessThumbstick(ThumbstickEvent* a_event, MovementData* a_movementData);	// 02 - { return; }
		virtual	void	ProcessMouseMove(MouseMoveEvent* a_event, MovementData* a_movementData);	// 03 - { return; }
		virtual	void	ProcessButton(ButtonEvent* a_event, MovementData* a_movementData);			// 04 - { return; }

		bool			IsEnabled() const;
		void			Enable(bool a_enable = true);

		// members
		UInt32			enabled;	// 08
		UInt32			pad0C;		// 08
	};
	STATIC_ASSERT(sizeof(PlayerInputHandler) == 0x10);
}
