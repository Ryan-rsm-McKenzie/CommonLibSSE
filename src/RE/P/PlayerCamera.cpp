#include "RE/P/PlayerCamera.h"

namespace RE
{
	PlayerCamera* PlayerCamera::GetSingleton()
	{
		REL::Relocation<PlayerCamera**> singleton{ Offset::PlayerCamera::Singleton };
		return *singleton;
	}

	void PlayerCamera::UpdateThirdPerson(bool a_weaponDrawn)
	{
		using func_t = decltype(&PlayerCamera::UpdateThirdPerson);
		REL::Relocation<func_t> func{ Offset::PlayerCamera::UpdateThirdPerson };
		return func(this, a_weaponDrawn);
	}
}
