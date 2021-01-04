#pragma once

#include "RE/F/FxDelegate.h"
#include "RE/F/FxDelegateHandler.h"
#include "RE/G/GFxMovieView.h"
#include "RE/G/GPtr.h"
#include "RE/U/UserEvents.h"

namespace RE
{
	class CallbackProcessor;
	class UIMessage;

	enum class UI_MENU_FLAGS
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

	enum class UI_MESSAGE_RESULTS
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

		virtual ~IMenu() = default;	 // 00

		// override (FxDelegateHandler)
		virtual void Accept(CallbackProcessor* a_processor) override;  // 01 - { return; }

		// add
		virtual void			   PostCreate();												 // 02 - { return; }
		virtual void			   Unk_03(void);												 // 03 - { return; }
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message);						 // 04
		virtual void			   AdvanceMovie(float a_interval, std::uint32_t a_currentTime);	 // 05
		virtual void			   PostDisplay();												 // 06
		virtual void			   PreDisplay();												 // 07 - { return; } - only available if kRendersOffscreenTargets is set
		virtual void			   RefreshPlatform();											 // 08

		[[nodiscard]] constexpr bool AdvancesUnderPauseMenu() const noexcept { return menuFlags.all(Flag::kAdvancesUnderPauseMenu); }
		[[nodiscard]] constexpr bool AllowSaving() const noexcept { return menuFlags.all(Flag::kAllowSaving); }
		[[nodiscard]] constexpr bool AlwaysOpen() const noexcept { return menuFlags.all(Flag::kAlwaysOpen); }
		[[nodiscard]] constexpr bool ApplicationMenu() const noexcept { return menuFlags.all(Flag::kApplicationMenu); }
		[[nodiscard]] constexpr bool AssignCursorToRenderer() const noexcept { return menuFlags.all(Flag::kAssignCursorToRenderer); }
		[[nodiscard]] constexpr bool CustomRendering() const noexcept { return menuFlags.all(Flag::kCustomRendering); }
		[[nodiscard]] constexpr bool CompanionAppAllowed() const noexcept { return menuFlags.all(Flag::kCompanionAppAllowed); }
		[[nodiscard]] constexpr bool DisablePauseMenu() const noexcept { return menuFlags.all(Flag::kDisablePauseMenu); }
		[[nodiscard]] constexpr bool DontHideCursorWhenTopmost() const noexcept { return menuFlags.all(Flag::kDontHideCursorWhenTopmost); }
		[[nodiscard]] constexpr bool FreezeFrameBackground() const noexcept { return menuFlags.all(Flag::kFreezeFrameBackground); }
		[[nodiscard]] constexpr bool FreezeFramePause() const noexcept { return menuFlags.all(Flag::kFreezeFramePause); }
		[[nodiscard]] constexpr bool HasButtonBar() const noexcept { return menuFlags.all(Flag::kHasButtonBar); }
		[[nodiscard]] constexpr bool InventoryItemMenu() const noexcept { return menuFlags.all(Flag::kInventoryItemMenu); }
		[[nodiscard]] constexpr bool IsTopButtonBar() const noexcept { return menuFlags.all(Flag::kIsTopButtonBar); }
		[[nodiscard]] constexpr bool LargeScaleformRenderCacheMode() const noexcept { return menuFlags.all(Flag::kLargeScaleformRenderCacheMode); }
		[[nodiscard]] constexpr bool Modal() const noexcept { return menuFlags.all(Flag::kModal); }
		[[nodiscard]] constexpr bool OnStack() const noexcept { return menuFlags.all(Flag::kOnStack); }
		[[nodiscard]] constexpr bool PausesGame() const noexcept { return menuFlags.all(Flag::kPausesGame); }
		[[nodiscard]] constexpr bool RendersOffscreenTargets() const noexcept { return menuFlags.all(Flag::kRendersOffscreenTargets); }
		[[nodiscard]] constexpr bool RendersUnderPauseMenu() const noexcept { return menuFlags.all(Flag::kRendersUnderPauseMenu); }
		[[nodiscard]] constexpr bool RequiresUpdate() const noexcept { return menuFlags.all(Flag::kRequiresUpdate); }
		[[nodiscard]] constexpr bool SkipRenderDuringFreezeFrameScreenshot() const noexcept { return menuFlags.all(Flag::kSkipRenderDuringFreezeFrameScreenshot); }
		[[nodiscard]] constexpr bool TopmostRenderedMenu() const noexcept { return menuFlags.all(Flag::kTopmostRenderedMenu); }
		[[nodiscard]] constexpr bool UpdateUsesCursor() const noexcept { return menuFlags.all(Flag::kUsesBlurredBackground); }
		[[nodiscard]] constexpr bool UsesBlurredBackground() const noexcept { return menuFlags.all(Flag::kUsesCursor); }
		[[nodiscard]] constexpr bool UsesCursor() const noexcept { return menuFlags.all(Flag::kUsesMenuContext); }
		[[nodiscard]] constexpr bool UsesMenuContext() const noexcept { return menuFlags.all(Flag::kUsesMovementToDirection); }
		[[nodiscard]] constexpr bool UsesMovementToDirection() const noexcept { return menuFlags.all(Flag::kUpdateUsesCursor); }

		// members
		GPtr<GFxMovieView>							   uiMovie{ nullptr };				// 10
		std::int8_t									   depthPriority{ 3 };				// 18
		std::uint8_t								   pad19{ 0 };						// 19
		std::uint16_t								   pad20{ 0 };						// 1A
		stl::enumeration<UI_MENU_FLAGS, std::uint32_t> menuFlags{ Flag::kNone };		// 1C
		stl::enumeration<Context, std::uint32_t>	   inputContext{ Context::kNone };	// 20
		std::uint32_t								   pad24{ 0 };						// 24
		GPtr<FxDelegate>							   fxDelegate{ nullptr };			// 28
	};
	static_assert(sizeof(IMenu) == 0x30);
}
