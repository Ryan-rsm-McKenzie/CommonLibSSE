#include "RE/ButtonEvent.h"

#include "skse64_common/Relocation.h"  // RelocAddr
#include "skse64/GameAPI.h"  // Heap_Allocate

#include <cstring>  // memset

#include "RE/Offsets.h"


namespace RE
{
	bool ButtonEvent::IsPressed() const
	{
		return pressure > 0;
	}


	bool ButtonEvent::IsRepeating() const
	{
		return timer > 0.0f;
	}


	bool ButtonEvent::IsDown() const
	{
		return (pressure > 0) && (timer == 0.0f);
	}


	bool ButtonEvent::IsHeld() const
	{
		return (pressure > 0) && (timer > 0.0f);
	}


	bool ButtonEvent::IsUp() const
	{
		return (pressure == 0) && (timer > 0.0f);
	}
}
