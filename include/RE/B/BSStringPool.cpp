#include "RE/B/BSStringPool.h"

namespace RE
{
	BucketTable* BucketTable::GetSingleton()
	{
		using func_t = decltype(&BucketTable::GetSingleton);
		REL::Relocation<func_t> func{ Offset::BucketTable::GetSingleton };
		return func();
	}
}
