#pragma once

#include "RE/GFxState.h"  // GFxState


namespace RE
{
	class GFxTranslator : public GFxState
	{
	public:
		virtual ~GFxTranslator();		// 00

		// add
		virtual void	Unk_01(void);						// 01 - { return 0; }
		virtual void	GetTranslation(wchar_t*& a_key);	// 02 - { return; }
		virtual void	Unk_03(void);						// 03


		// members
		UInt64 unk18;	// 18
	};
	STATIC_ASSERT(sizeof(GFxTranslator) == 0x20);
}
