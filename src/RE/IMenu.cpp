#include "RE/IMenu.h"

#include <type_traits>

#include "RE/BSInputDeviceManager.h"
#include "RE/BSUIScaleformData.h"
#include "RE/GFxValue.h"
#include "RE/InterfaceStrings.h"
#include "RE/UI.h"
#include "RE/UIMessage.h"
#include "RE/UIMessageQueue.h"


namespace RE
{
	IMenu::IMenu() :
		view(0),
		menuDepth(3),
		pad19(0),
		pad20(0),
		flags(Flag::kNone),
		context(Context::kNone),
		pad24(0),
		fxDelegate(0)
	{}


	void IMenu::Accept([[maybe_unused]] CallbackProcessor* a_processor)
	{}


	void IMenu::PostCreate()
	{}


	void IMenu::Unk_03(void)
	{}


	UI_MESSAGE_RESULTS IMenu::ProcessMessage(UIMessage& a_message)
	{
		if (a_message.type != UI_MESSAGE_TYPE::kScaleformEvent) {
			return UI_MESSAGE_RESULTS::kPassOn;
		}

		if (!view) {
			return UI_MESSAGE_RESULTS::kPassOn;
		}

		const auto data = static_cast<BSUIScaleformData*>(a_message.data);
		if (!data) {
			return UI_MESSAGE_RESULTS::kPassOn;
		}

		view->HandleEvent(*data->scaleformEvent);
		return UI_MESSAGE_RESULTS::kHandled;
	}


	void IMenu::AdvanceMovie([[maybe_unused]] float a_interval, UInt32 a_currentTime)
	{
		if (view) {
			const GFxValue currentTime(static_cast<double>(a_currentTime));
			view->SetVariable("CurrentTime", currentTime, GFxMovie::SetVarType::kNormal);
			view->Advance(static_cast<float>(currentTime.GetNumber()));
		}
	}


	void IMenu::PostDisplay()
	{
		if (view) {
			view->Display();
		}
	}


	void IMenu::PreDisplay()
	{}


	void IMenu::RefreshPlatform()
	{
		using Message = UI_MESSAGE_TYPE;

		auto inputManager = BSInputDeviceManager::GetSingleton();
		auto gamepad = inputManager ? inputManager->IsGamepadEnabled() : nullptr;
		if (view && view->IsAvailable("_root.SetPlatform")) {
			GFxValue args[2];
			const double platform = gamepad ? 1.0 : 0.0;
			args[0].SetNumber(platform);
			const bool swapPS3 = false;
			args[1].SetBoolean(swapPS3);
			view->Invoke("_root.SetPlatform", nullptr, args, std::extent<decltype(args)>::value);
		}

		if (UpdateUsesCursor()) {
			Message messageID;
			auto uiStr = InterfaceStrings::GetSingleton();
			if (gamepad) {
				flags &= ~Flag::kUsesCursor;
				messageID = Message::kHide;
			} else {
				flags |= Flag::kUsesCursor;
				auto ui = UI::GetSingleton();
				messageID = ui && ui->IsMenuOpen(uiStr->cursorMenu) ? Message::kUpdate : Message::kShow;
			}

			auto messageQueue = UIMessageQueue::GetSingleton();
			if (messageQueue) {
				messageQueue->AddMessage(uiStr->cursorMenu, messageID, nullptr);
			}
		}
	}


	bool IMenu::AdvancesUnderPauseMenu() const
	{
		return (flags & Flag::kAdvancesUnderPauseMenu) != Flag::kNone;
	}


	bool IMenu::AllowSaving() const
	{
		return (flags & Flag::kAllowSaving) != Flag::kNone;
	}


	bool IMenu::AlwaysOpen() const
	{
		return (flags & Flag::kAlwaysOpen) != Flag::kNone;
	}


	bool IMenu::ApplicationMenu() const
	{
		return (flags & Flag::kApplicationMenu) != Flag::kNone;
	}


	bool IMenu::AssignCursorToRenderer() const
	{
		return (flags & Flag::kAssignCursorToRenderer) != Flag::kNone;
	}


	bool IMenu::CustomRendering() const
	{
		return (flags & Flag::kCustomRendering) != Flag::kNone;
	}


	bool IMenu::CompanionAppAllowed() const
	{
		return (flags & Flag::kCompanionAppAllowed) != Flag::kNone;
	}


	bool IMenu::DisablePauseMenu() const
	{
		return (flags & Flag::kDisablePauseMenu) != Flag::kNone;
	}


	bool IMenu::DontHideCursorWhenTopmost() const
	{
		return (flags & Flag::kDontHideCursorWhenTopmost) != Flag::kNone;
	}


	bool IMenu::FreezeFrameBackground() const
	{
		return (flags & Flag::kFreezeFrameBackground) != Flag::kNone;
	}


	bool IMenu::FreezeFramePause() const
	{
		return (flags & Flag::kFreezeFramePause) != Flag::kNone;
	}


	bool IMenu::HasButtonBar() const
	{
		return (flags & Flag::kHasButtonBar) != Flag::kNone;
	}


	bool IMenu::InventoryItemMenu() const
	{
		return (flags & Flag::kInventoryItemMenu) != Flag::kNone;
	}


	bool IMenu::IsTopButtonBar() const
	{
		return (flags & Flag::kIsTopButtonBar) != Flag::kNone;
	}


	bool IMenu::LargeScaleformRenderCacheMode() const
	{
		return (flags & Flag::kLargeScaleformRenderCacheMode) != Flag::kNone;
	}


	bool IMenu::Modal() const
	{
		return (flags & Flag::kModal) != Flag::kNone;
	}


	bool IMenu::OnStack() const
	{
		return (flags & Flag::kOnStack) != Flag::kNone;
	}


	bool IMenu::PausesGame() const
	{
		return (flags & Flag::kPausesGame) != Flag::kNone;
	}


	bool IMenu::RendersOffscreenTargets() const
	{
		return (flags & Flag::kRendersOffscreenTargets) != Flag::kNone;
	}


	bool IMenu::RendersUnderPauseMenu() const
	{
		return (flags & Flag::kRendersUnderPauseMenu) != Flag::kNone;
	}


	bool IMenu::RequiresUpdate() const
	{
		return (flags & Flag::kRequiresUpdate) != Flag::kNone;
	}


	bool IMenu::SkipRenderDuringFreezeFrameScreenshot() const
	{
		return (flags & Flag::kSkipRenderDuringFreezeFrameScreenshot) != Flag::kNone;
	}


	bool IMenu::TopmostRenderedMenu() const
	{
		return (flags & Flag::kTopmostRenderedMenu) != Flag::kNone;
	}


	bool IMenu::UsesBlurredBackground() const
	{
		return (flags & Flag::kUsesBlurredBackground) != Flag::kNone;
	}


	bool IMenu::UsesCursor() const
	{
		return (flags & Flag::kUsesCursor) != Flag::kNone;
	}


	bool IMenu::UsesMenuContext() const
	{
		return (flags & Flag::kUsesMenuContext) != Flag::kNone;
	}


	bool IMenu::UsesMovementToDirection() const
	{
		return (flags & Flag::kUsesMovementToDirection) != Flag::kNone;
	}


	bool IMenu::UpdateUsesCursor() const
	{
		return (flags & Flag::kUpdateUsesCursor) != Flag::kNone;
	}
}
