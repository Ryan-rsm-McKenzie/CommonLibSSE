#include "RE/E/ExtraCount.h"

namespace RE
{
	ExtraCount::ExtraCount() :
		ExtraCount(0)
	{}

	ExtraCount::ExtraCount(std::int16_t a_count) :
		BSExtraData(),
		count(a_count),
		pad12(0),
		pad14(0)
	{
		REL::Relocation<std::uintptr_t> vtbl{ Offset::ExtraCount::Vtbl };
		((std::uintptr_t*)this)[0] = vtbl.address();
	}

	ExtraDataType ExtraCount::GetType() const
	{
		return ExtraDataType::kCount;
	}

	bool ExtraCount::IsNotEqual(const BSExtraData* a_rhs) const
	{
		auto rhs = static_cast<const ExtraCount*>(a_rhs);
		return count != rhs->count;
	}
}
