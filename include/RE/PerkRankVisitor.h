#pragma once

#include "skse64/GameFormComponents.h"  // BGSPerkRankArray::Data


namespace RE
{
	class PerkRankVisitor
	{
	public:
		virtual bool operator()(const BGSPerkRankArray::Data* a_entry) = 0;	// 0
	};
}
