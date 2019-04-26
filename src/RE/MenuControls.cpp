#include "RE/MenuControls.h"

#include "skse64/GameInput.h"  // MenuControls

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	MenuControls* MenuControls::GetSingleton()
	{
		using func_t = function_type_t<decltype(&MenuControls::GetSingleton)>;
		func_t* func = unrestricted_cast<func_t*>(&::MenuControls::GetSingleton);
		return func();
	}


	void MenuControls::RegisterHandler(MenuEventHandler* a_handler)
	{
		using func_t = function_type_t<decltype(&MenuControls::RegisterHandler)>;
		REL::Offset<func_t*> func(Offset::MenuControls::RegisterHandler);
		return func(this, a_handler);
	}


	void MenuControls::RemoveHandler(MenuEventHandler* a_handler)
	{
		using func_t = function_type_t<decltype(&MenuControls::RegisterHandler)>;
		REL::Offset<func_t*> func(Offset::MenuControls::RemoveHandler);
		return func(this, a_handler);
	}
}
