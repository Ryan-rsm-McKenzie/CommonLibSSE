#include "RE/B/BGSMaterialType.h"

namespace RE
{
	BGSMaterialType* BGSMaterialType::GetMaterialType(std::uint32_t a_materialID)
	{
		using func_t = decltype(&BGSMaterialType::GetMaterialType);
		REL::Relocation<func_t> func{ REL::ID(20529) };
		return func(a_materialID);
	}
}
