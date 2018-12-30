#include "RE/TESCamera.h"

#include "skse64/GameCamera.h"  // TESCamera


namespace RE
{
	UInt32 TESCamera::SetCameraState(TESCameraState* a_cameraState)
	{
		typedef UInt32 _SetCameraState_t(TESCamera* a_this, TESCameraState* a_cameraState);
		uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::TESCamera*>(this)->_SetCameraState_GetPtr());
		_SetCameraState_t* _SetCameraState = reinterpret_cast<_SetCameraState_t*>(*ptr);
		return _SetCameraState(this, a_cameraState);
	}
}
