#include "RE/PlayerControls.h"

#include "skse64/GameInput.h"  // PlayerControls


namespace RE
{
	PlayerControls* PlayerControls::GetSingleton()
	{
		typedef PlayerControls* _GetSingleton_t();
		static _GetSingleton_t* _GetSingleton = reinterpret_cast<_GetSingleton_t*>(GetFnAddr(&::PlayerControls::GetSingleton));
		return _GetSingleton();
	}


	PlayerControls* PlayerControls::ctor_Hook()
	{
		typedef PlayerControls* _ctor_Hook_t(PlayerControls* a_this);
		static _ctor_Hook_t* _ctor_Hook = reinterpret_cast<_ctor_Hook_t*>(GetFnAddr(&::PlayerControls::ctor_Hook));
		return _ctor_Hook(this);
	}


	PlayerControls* PlayerControls::ctor()
	{
		typedef PlayerControls* _ctor_t(PlayerControls* a_this);
		static uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::PlayerControls*>(this)->_ctor_GetPtr());
		static _ctor_t* _ctor = reinterpret_cast<_ctor_t*>(*ptr);
		return _ctor(this);
	}
}
