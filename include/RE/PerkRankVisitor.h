#pragma once

#include "skse64/GameRTTI.h"  // RTTI_PerkRankVisitor

#include "RE/BGSPerkRankArray.h"  // BGSPerkRankArray::Entry


namespace RE
{
	class PerkRankVisitor
	{
	public:
		inline static const void* RTTI = RTTI_PerkRankVisitor;


		virtual bool operator()(const BGSPerkRankArray::Entry* a_entry) = 0;	// 00
	};
}
