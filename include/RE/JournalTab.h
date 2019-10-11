#pragma once

#include "skse64/GameRTTI.h"  // RTTI_JournalTab

#include "RE/FxDelegateHandler.h"  // FxDelegateHandler
#include "RE/GPtr.h"  // GPtr


namespace RE
{
	class GFxMovieView;


	class JournalTab : public FxDelegateHandler
	{
	public:
		inline static const void* RTTI = RTTI_JournalTab;


		virtual ~JournalTab();			// 00

		// add
		virtual void	Unk_02(void);	// 02 - { return; }
		virtual void	Unk_03(void);	// 03 - { return; }


		// members
		GPtr<GFxMovieView> view;	// 10
	};
	STATIC_ASSERT(sizeof(JournalTab) == 0x18);
}
