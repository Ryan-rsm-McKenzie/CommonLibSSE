#include "RE/Camera/TESCamera/TESCamera.h"


namespace RE
{
	void TESCamera::SetState(TESCameraState* a_state)
	{
		using func_t = decltype(&TESCamera::SetState);
		REL::Offset<func_t> func(Offset::TESCamera::SetState);
		return func(this, a_state);
	}
}
