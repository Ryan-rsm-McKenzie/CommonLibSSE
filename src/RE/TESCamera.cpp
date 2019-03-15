#include "RE/TESCamera.h"

#include "skse64/GameCamera.h"  // TESCamera


namespace RE
{
	UInt32 TESCamera::SetCameraState(TESCameraState* a_cameraState)
	{
		using func_t = function_type_t<decltype(&TESCamera::SetCameraState)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::TESCamera, SetCameraState, func_t*);
		return func(this, a_cameraState);
	}
}
