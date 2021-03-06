#include "RE/B/BGSImpactDataSet.h"

namespace RE
{
	BGSImpactData* BGSImpactDataSet::GetImpactData(BGSMaterialType* a_materialType) const
	{
		using func_t = decltype(&BGSImpactDataSet::GetImpactData);
		REL::Relocation<func_t> func{ Offset::BGSImpactDataSet::GetImpactData };
		return func(this, a_materialType);
	}
}
