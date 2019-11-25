#pragma once

#include "RE/BGSPerkRankArray.h"


namespace RE
{
	class PerkRankVisitor
	{
	public:
		inline static const void* RTTI = RTTI_PerkRankVisitor;


		virtual bool operator()(const BGSPerkRankArray::Entry* a_entry) = 0;	// 00
	};
}
