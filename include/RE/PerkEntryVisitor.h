#pragma once

#include "skse64/GameRTTI.h"  // RTTI_PerkEntryVisitor


namespace RE
{
	class BGSPerkEntry;


	class PerkEntryVisitor
	{
	public:
		inline static const void* RTTI = RTTI_PerkEntryVisitor;


		enum class ReturnType : UInt32
		{
			kBreak,
			kContinue
		};


		virtual ReturnType Visit(BGSPerkEntry* a_perkEntry) = 0;	// 00
	};
}
