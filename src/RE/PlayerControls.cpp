#include "RE/PlayerControls.h"

#include "RE/Offsets.h"
#include "RE/PlayerInputHandler.h"
#include "REL/Relocation.h"


namespace RE
{
	PlayerControls::PlayerControls()
	{
		Ctor();
	}


	PlayerControls* PlayerControls::GetSingleton()
	{
		REL::Offset<PlayerControls**> singleton(Offset::PlayerControls::Singleton);
		return *singleton;
	}


	PlayerControls* PlayerControls::Ctor()
	{
		using func_t = function_type_t<decltype(&PlayerControls::Ctor)>;
		REL::Offset<func_t*> func(Offset::PlayerControls::Ctor);
		return func(this);
	}
}
