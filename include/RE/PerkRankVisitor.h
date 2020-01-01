#pragma once

#include "RE/BGSPerkRankArray.h"


namespace RE
{
	struct PerkRankData;


	class PerkRankVisitor
	{
	public:
		inline static const void* RTTI = RTTI_PerkRankVisitor;


		virtual bool operator()(const PerkRankData* a_entry) = 0;	// 00
	};
}
