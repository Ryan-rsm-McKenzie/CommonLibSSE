#pragma once

#include "RE/BGSPerkRankArray.h"  // BGSPerkRankArray::Entry


namespace RE
{
	class PerkRankVisitor
	{
	public:
		virtual bool operator()(const BGSPerkRankArray::Entry* a_entry) = 0;	// 00
	};
}
