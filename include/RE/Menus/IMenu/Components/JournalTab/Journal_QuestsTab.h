#pragma once

#include "RE/GFxValue.h"
#include "RE/JournalTab.h"


namespace RE
{
	class Journal_QuestsTab : public JournalTab
	{
	public:
		inline static constexpr auto RTTI = RTTI_Journal_QuestsTab;


		virtual ~Journal_QuestsTab();  // 00

		// override (JournalTab)
		virtual void Accept(CallbackProcessor* a_cbReg) override;  // 01


		// members
		GFxValue unk18;	 // 18
		bool	 unk30;	 // 30
		UInt8	 unk31;	 // 31
		UInt16	 unk32;	 // 32
		UInt32	 unk34;	 // 34
	};
	STATIC_ASSERT(sizeof(Journal_QuestsTab) == 0x38);
}
