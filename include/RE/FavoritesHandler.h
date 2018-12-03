#pragma once

#include "RE/MenuEventHandler.h"

class InputEvent;
class KinectEvent;


namespace RE
{
	class ButtonEvent;


	struct FavoritesHandler : public MenuEventHandler
	{
	public:
		virtual bool	CanProcess(InputEvent* a_event) override;			// 1
		virtual bool	ProcessKinect(KinectEvent* a_event) override;		// 2
		virtual bool	ProcessButton(RE::ButtonEvent* a_event) override;	// 5
	};
}
