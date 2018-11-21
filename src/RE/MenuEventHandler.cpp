#include "RE/MenuEventHandler.h"


namespace RE
{
	MenuEventHandler::MenuEventHandler() :
		unk08(0),
		unk09(0)
	{}


	bool MenuEventHandler::ProcessKinect(KinectEvent* a_event)
	{
		return false;
	}


	bool MenuEventHandler::ProcessThumbstick(ThumbstickEvent* a_event)
	{
		return false;
	}


	bool MenuEventHandler::ProcessMouseMove(MouseMoveEvent* a_event)
	{
		return false;
	}


	bool MenuEventHandler::ProcessButton(RE::ButtonEvent* a_event)
	{
		return false;
	}
}
