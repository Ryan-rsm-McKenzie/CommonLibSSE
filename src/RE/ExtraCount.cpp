#include "RE/ExtraCount.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	ExtraCount::ExtraCount() :
		ExtraCount(0)
	{}


	ExtraCount::ExtraCount(SInt16 a_count) :
		BSExtraData(),
		count(a_count),
		pad12(0),
		pad14(0)
	{
		REL::Offset<std::uintptr_t> vtbl(Offset::ExtraCount::Vtbl);
		((std::uintptr_t*)this)[0] = vtbl.GetAddress();
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
