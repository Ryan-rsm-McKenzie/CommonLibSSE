#pragma once

#include "RE/FxDelegate.h"
#include "RE/FxDelegateHandler.h"
#include "RE/GFxMovieView.h"
#include "RE/GPtr.h"
#include "RE/UserEvents.h"


namespace RE
{
	class CallbackProcessor;
	class UIMessage;


	enum class UI_MENU_FLAGS : UInt32
	{
		kNone = 0,
		kPausesGame = 1 << 0,
		kAlwaysOpen = 1 << 1,
		kUsesCursor = 1 << 2,
		kUsesMenuContext = 1 << 3,
		kModal = 1 << 4,  // prevents lower movies with this flag from advancing
		kFreezeFrameBackground = 1 << 5,
		kOnStack = 1 << 6,
		kDisablePauseMenu = 1 << 7,
		kRequiresUpdate = 1 << 8,
		kTopmostRenderedMenu = 1 << 9,
		kUpdateUsesCursor = 1 << 10,
		kAllowSaving = 1 << 11,
		kRendersOffscreenTargets = 1 << 12,
		kInventoryItemMenu = 1 << 13,
		kDontHideCursorWhenTopmost = 1 << 14,
		kCustomRendering = 1 << 15,
		kAssignCursorToRenderer = 1 << 16,
		kApplicationMenu = 1 << 17,
		kHasButtonBar = 1 << 18,
		kIsTopButtonBar = 1 << 19,
		kAdvancesUnderPauseMenu = 1 << 20,
		kRendersUnderPauseMenu = 1 << 21,
		kUsesBlurredBackground = 1 << 22,
		kCompanionAppAllowed = 1 << 23,
		kFreezeFramePause = 1 << 24,
		kSkipRenderDuringFreezeFrameScreenshot = 1 << 25,
		kLargeScaleformRenderCacheMode = 1 << 26,
		kUsesMovementToDirection = 1 << 27
	};


	enum class UI_MESSAGE_RESULTS : UInt32
	{
		kHandled = 0,
		kIgnore = 1,
		kPassOn = 2
	};


	class IMenu : public FxDelegateHandler
	{
	public:
		inline static constexpr auto RTTI = RTTI_IMenu;


		using Context = UserEvents::INPUT_CONTEXT_ID;
		using Flag = UI_MENU_FLAGS;


		IMenu();
		virtual ~IMenu() = default;	 // 00

		// override (FxDelegateHandler)
		virtual void Accept(CallbackProcessor* a_processor) override;  // 01 - { return; }

		// add
		virtual void			   PostCreate();										  // 02 - { return; }
		virtual void			   Unk_03(void);										  // 03 - { return; }
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message);				  // 04
		virtual void			   AdvanceMovie(float a_interval, UInt32 a_currentTime);  // 05
		virtual void			   PostDisplay();										  // 06
		virtual void			   PreDisplay();										  // 07 - { return; } - only available if kRendersOffscreenTargets is set
		virtual void			   RefreshPlatform();									  // 08

		bool AdvancesUnderPauseMenu() const;
		bool AllowSaving() const;
		bool AlwaysOpen() const;
		bool ApplicationMenu() const;
		bool AssignCursorToRenderer() const;
		bool CustomRendering() const;
		bool CompanionAppAllowed() const;
		bool DisablePauseMenu() const;
		bool DontHideCursorWhenTopmost() const;
		bool FreezeFrameBackground() const;
		bool FreezeFramePause() const;
		bool HasButtonBar() const;
		bool InventoryItemMenu() const;
		bool IsTopButtonBar() const;
		bool LargeScaleformRenderCacheMode() const;
		bool Modal() const;
		bool OnStack() const;
		bool PausesGame() const;
		bool RendersOffscreenTargets() const;
		bool RendersUnderPauseMenu() const;
		bool RequiresUpdate() const;
		bool SkipRenderDuringFreezeFrameScreenshot() const;
		bool TopmostRenderedMenu() const;
		bool UpdateUsesCursor() const;
		bool UsesBlurredBackground() const;
		bool UsesCursor() const;
		bool UsesMenuContext() const;
		bool UsesMovementToDirection() const;


		// members
		GPtr<GFxMovieView> view;		// 10
		UInt8			   menuDepth;	// 18
		UInt8			   pad19;		// 19
		UInt16			   pad20;		// 1A
		UI_MENU_FLAGS	   flags;		// 1C
		Context			   context;		// 20
		UInt32			   pad24;		// 24
		GPtr<FxDelegate>   fxDelegate;	// 28
	};
	STATIC_ASSERT(sizeof(IMenu) == 0x30);
}
