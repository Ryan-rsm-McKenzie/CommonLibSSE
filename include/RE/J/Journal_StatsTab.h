#pragma once

#include "RE/J/JournalTab.h"

namespace RE
{
	class Journal_StatsTab : public JournalTab
	{
	public:
		inline static constexpr auto RTTI = RTTI_Journal_StatsTab;

		~Journal_StatsTab() override;  // 00

		// override (JournalTab)
		void Accept(CallbackProcessor* a_cbReg) override;  // 01
	};
	static_assert(sizeof(Journal_StatsTab) == 0x18);
}
