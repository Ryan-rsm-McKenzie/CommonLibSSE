#pragma once

#include "skse64/GameRTTI.h"  // RTTI_PlayerInputHandler

#include "RE/PlayerControls.h"  // PlayerControls::Data024


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


		virtual ~PlayerInputHandler();																	// 00

		virtual	bool	CanProcess(InputEvent* a_event) = 0;											// 01
		virtual	void	ProcessThumbstick(ThumbstickEvent* a_event, PlayerControls::Data024* a_arg2);	// 02
		virtual	void	ProcessMouseMove(MouseMoveEvent* a_event, PlayerControls::Data024* a_arg2);		// 03
		virtual	void	ProcessButton(ButtonEvent* a_event, PlayerControls::Data024* a_arg2);			// 04

		bool			IsEnabled() const;
		void			Enable(bool a_enable = true);

		// members
		UInt32			enabled;	// 08
		UInt32			pad0C;		// 08
	};
	STATIC_ASSERT(sizeof(PlayerInputHandler) == 0x10);
}
