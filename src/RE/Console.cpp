#include "RE/Console.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	RefHandle Console::GetSelectedRef()
	{
		REL::Offset<RefHandle*> selectedRef(Offset::Console::SelectedRef);
		return *selectedRef;
	}


	void Console::SetSelectedRef(RefHandle& a_handle)
	{
		using func_t = function_type_t<decltype(&Console::SetSelectedRef)>;
		REL::Offset<func_t*> func(RE::Offset::Console::SetSelectedRef);
		return func(this, a_handle);
	}
}
