#include "RE/ExtraRank.h"

#include "skse64/GameExtraData.h"  // s_ExtraRankVtbl


namespace RE
{
	ExtraRank::ExtraRank() :
		BSExtraData(),
		rank(0),
		pad14(0)
	{
		((std::uintptr_t*)this)[0] = s_ExtraRankVtbl.GetUIntPtr();
	}


	ExtraRank::ExtraRank(UInt32 a_rank) :
		BSExtraData(),
		rank(a_rank),
		pad14(0)
	{
		((std::uintptr_t*)this)[0] = s_ExtraRankVtbl.GetUIntPtr();
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
