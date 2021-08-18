#include "RE/B/BooksRead.h"

namespace RE
{
	BSTEventSource<BooksRead::Event>* BooksRead::GetEventSource()
	{
		using func_t = decltype(&BooksRead::GetEventSource);
		REL::Relocation<func_t> func{ REL::ID(17470) };
		return func();
	}
}
