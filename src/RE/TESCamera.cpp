#include "RE/TESCamera.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	UInt32 TESCamera::SetCameraState(TESCameraState* a_cameraState)
	{
		using func_t = function_type_t<decltype(&TESCamera::SetCameraState)>;
		REL::Offset<func_t*> func(Offset::TESCamera::SetCameraState);
		return func(this, a_cameraState);
	}
}
