#include "RE/ExtraRank.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	ExtraRank::ExtraRank() :
		ExtraRank(0)
	{}


	ExtraRank::ExtraRank(SInt32 a_rank) :
		BSExtraData(),
		rank(a_rank),
		pad14(0)
	{
		REL::Offset<std::uintptr_t> vtbl(Offset::ExtraRank::Vtbl);
		((std::uintptr_t*)this)[0] = vtbl.GetAddress();
	}


	ExtraDataType ExtraRank::GetType() const
	{
		return ExtraDataType::kRank;
	}


	bool ExtraRank::IsNotEqual(const BSExtraData* a_rhs) const
	{
		auto rhs = static_cast<const ExtraRank*>(a_rhs);
		return rank != rhs->rank;
	}
}
