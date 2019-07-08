#include "RE/Console.h"

#include "skse64/GameAPI.h"  // g_consoleHandle

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	RefHandle Console::GetSelectedRef()
	{
		return *unrestricted_cast<RefHandle*>(g_consoleHandle.GetUIntPtr());
	}


	void Console::SetSelectedRef(RefHandle& a_handle)
	{
		using func_t = function_type_t<decltype(&Console::SetSelectedRef)>;
		REL::Offset<func_t*> func(RE::Offset::Console::SetSelectedRef);
		return func(this, a_handle);
	}
}
