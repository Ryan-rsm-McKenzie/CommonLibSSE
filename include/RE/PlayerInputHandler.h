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

		bool IsInputEventHandlingEnabled() const;
		void SetInputEventHandlingEnabled(bool a_enabled);


		// members
		bool   inputEventHandlingEnabled;  // 08
		UInt8  pad09;					   // 09
		UInt16 pad0A;					   // 0A
		UInt32 pad0C;					   // 0C
	};
	STATIC_ASSERT(sizeof(PlayerInputHandler) == 0x10);
}
