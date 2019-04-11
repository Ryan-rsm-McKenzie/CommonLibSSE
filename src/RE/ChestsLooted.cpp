#include "RE/ChestsLooted.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	BSTEventSource<ChestsLooted::Event>* ChestsLooted::GetEventSource()
	{
		using func_t = function_type_t<decltype(&ChestsLooted::GetEventSource)>;
		REL::Offset<func_t*> func(Offset::ChestsLooted::GetEventSource);
		return func();
	}


	void ChestsLooted::SendEvent()
	{
		Event e = { 0 };
		auto source = GetEventSource();
		source->SendEvent(&e);
	}
}
