#pragma once

#include "skse64/GameRTTI.h"  // RTTI_HUDObject

#include "RE/GFxValue.h"  // GFxValue
#include "RE/GPtr.h"  // GPtr
#include "RE/TESMemoryManager.h"  // TES_HEAP_REDEFINE_NEW


namespace RE
{
	class FxDelegateArgs;
	class GFxMovieView;
	class UIMessage;


	class HUDObject
	{
	public:
		inline static const void* RTTI = RTTI_HUDObject;


		HUDObject(GFxMovieView* a_view);
		virtual ~HUDObject() = default;									// 00

		// add
		virtual void	Update() = 0;									// 01
		virtual bool	ProcessMessage(UIMessage* a_message);			// 02 - { return false; }
		virtual void	RegisterHUDComponent(FxDelegateArgs& a_params);	// 03 - { root = a_params[0]; }
		virtual void	CleanUp();										// 04 - { return; }

		TES_HEAP_REDEFINE_NEW();


		// members
		GPtr<GFxMovieView>	view;	// 08
		GFxValue			root;	// 10 - kDisplayObject - "_level0.HUDMovieBaseInstance"
	};
	STATIC_ASSERT(sizeof(HUDObject) == 0x28);
}
