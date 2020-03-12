#pragma once


namespace RE
{
	class ButtonEvent;
	class InputEvent;
	class MouseMoveEvent;
	class PlayerControlsData;
	class ThumbstickEvent;


	class PlayerInputHandler
	{
	public:
		inline static constexpr auto RTTI = RTTI_PlayerInputHandler;


		virtual ~PlayerInputHandler();	// 00

		virtual bool CanProcess(InputEvent* a_event) = 0;									   // 01
		virtual void ProcessThumbstick(ThumbstickEvent* a_event, PlayerControlsData* a_data);  // 02 - { return; }
		virtual void ProcessMouseMove(MouseMoveEvent* a_event, PlayerControlsData* a_data);	   // 03 - { return; }
		virtual void ProcessButton(ButtonEvent* a_event, PlayerControlsData* a_data);		   // 04 - { return; }

		bool IsEnabled() const;
		void SetEnabled(bool a_enable = true);


		// members
		UInt32 enabled;	 // 08
		UInt32 pad0C;	 // 08
	};
	STATIC_ASSERT(sizeof(PlayerInputHandler) == 0x10);
}
