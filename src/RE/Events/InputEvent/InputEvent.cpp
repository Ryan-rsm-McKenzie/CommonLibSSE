#include "RE/Events/InputEvent/InputEvent.h"

#include "RE/Events/InputEvent/IDEvent/ButtonEvent.h"
#include "RE/Events/InputEvent/IDEvent/IDEvent.h"

namespace RE
{
	ButtonEvent* InputEvent::AsButtonEvent()
	{
		return GetEventType() == INPUT_EVENT_TYPE::kButton ? static_cast<ButtonEvent*>(this) : nullptr;
	}


	const ButtonEvent* InputEvent::AsButtonEvent() const
	{
		return GetEventType() == INPUT_EVENT_TYPE::kButton ? static_cast<const ButtonEvent*>(this) : nullptr;
	}


	IDEvent* InputEvent::AsIDEvent()
	{
		return HasIDCode() ? static_cast<IDEvent*>(this) : nullptr;
	}


	const IDEvent* InputEvent::AsIDEvent() const
	{
		return HasIDCode() ? static_cast<const IDEvent*>(this) : nullptr;
	}
}
