#pragma once

#include "RE/IMenu.h"


namespace RE
{
	class MessageBoxMenu : public IMenu
	{
	public:
		virtual ~MessageBoxMenu();											// 00

		// override (IMenu)
		virtual void	Accept(CallbackProcessor* a_processor) override;	// 01
		virtual Result	ProcessMessage(UIMessage* a_message) override;		// 04


		// members
		UInt64 unk30;	// 30
	};
	STATIC_ASSERT(sizeof(MessageBoxMenu) == 0x38);
}
