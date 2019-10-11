#pragma once

#include "skse64/GameRTTI.h"  // RTTI_Journal_QuestsTab

#include "RE/GFxValue.h"  // GFxValue
#include "RE/JournalTab.h"  // JournalTab


namespace RE
{
	class Journal_QuestsTab : public JournalTab
	{
	public:
		inline static const void* RTTI = RTTI_Journal_QuestsTab;


		virtual ~Journal_QuestsTab();								// 00

		// override (JournalTab)
		virtual void Accept(CallbackProcessor* a_cbReg) override;	// 01


		// members
		GFxValue	unk18;	// 18
		bool		unk30;	// 30
		UInt8		unk31;	// 31
		UInt16		unk32;	// 32
		UInt32		unk34;	// 34
	};
	STATIC_ASSERT(sizeof(Journal_QuestsTab) == 0x38);
}
