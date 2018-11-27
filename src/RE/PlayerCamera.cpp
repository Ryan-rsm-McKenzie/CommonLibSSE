#include "RE/PlayerCamera.h"

#include "skse64_common/Relocation.h"  // RelocAddr
#include "skse64/GameCamera.h"  // PlayerCamera


namespace RE
{
	PlayerCamera* PlayerCamera::GetSingleton()
	{
		typedef PlayerCamera* _GetSingleton_t();
		static _GetSingleton_t* _GetSingleton = reinterpret_cast<_GetSingleton_t*>(GetFnAddr(&::PlayerCamera::GetSingleton));
		return _GetSingleton();
	}


	void PlayerCamera::UpdateThirdPerson(bool a_weaponDrawn)
	{
		typedef void _UpdateThirdPerson_t(PlayerCamera* a_this, bool a_weaponDrawn);
		static uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::PlayerCamera*>(this)->_UpdateThirdPerson_GetPtr());
		static _UpdateThirdPerson_t* _UpdateThirdPerson = reinterpret_cast<_UpdateThirdPerson_t*>(*ptr);
		return _UpdateThirdPerson(this, a_weaponDrawn);
	}
}
