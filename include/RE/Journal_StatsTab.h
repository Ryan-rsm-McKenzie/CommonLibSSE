#pragma once

#include "skse64/GameRTTI.h"  // RTTI_Journal_StatsTab

#include "RE/JournalTab.h"  // JournalTab


namespace RE
{
	class Journal_StatsTab : public JournalTab
	{
	public:
		inline static const void* RTTI = RTTI_Journal_StatsTab;


		virtual ~Journal_StatsTab();								// 00

		// override (JournalTab)
		virtual void Accept(CallbackProcessor* a_cbReg) override;	// 01
	};
	STATIC_ASSERT(sizeof(Journal_StatsTab) == 0x18);
}
