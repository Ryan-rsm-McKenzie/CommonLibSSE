#include "RE/PlayerCamera.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	PlayerCamera* PlayerCamera::GetSingleton()
	{
		REL::Offset<PlayerCamera**> singleton(Offset::PlayerCamera::Singleton);
		return *singleton;
	}


	void PlayerCamera::UpdateThirdPerson(bool a_weaponDrawn)
	{
		using func_t = decltype(&PlayerCamera::UpdateThirdPerson);
		REL::Offset<func_t> func(Offset::PlayerCamera::UpdateThirdPerson);
		return func(this, a_weaponDrawn);
	}
}
