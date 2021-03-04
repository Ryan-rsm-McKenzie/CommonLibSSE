#include "RE/T/TES.h"

namespace RE
{
	TES* TES::GetSingleton()
	{
		REL::Relocation<TES**> singleton{ Offset::TES::Singleton };
		return *singleton;
	}

	std::uint32_t TES::GetMaterialID(NiPoint3* a_position) const
	{
		using func_t = decltype(&TES::GetMaterialID);
		REL::Relocation<func_t> func{ Offset::TES::GetMaterialID };
		return func(this, a_position);
	}
}
