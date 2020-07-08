#include "RE/Menus/IMenu/IMenu.h"

#include "RE/BSDevices/BSInputDeviceManager.h"
#include "RE/Menus/IUIMessageData/BSUIScaleformData.h"
#include "RE/Menus/InterfaceStrings.h"
#include "RE/Menus/UI.h"
#include "RE/Menus/UIMessage.h"
#include "RE/Menus/UIMessageQueue.h"
#include "RE/Scaleform/GFxPlayer/GFxValue.h"


namespace RE
{
	IMenu::IMenu() :
		uiMovie(nullptr),
		depthPriority(3),
		pad19(0),
		pad20(0),
		menuFlags(Flag::kNone),
		inputContext(Context::kNone),
		pad24(0),
		fxDelegate(nullptr)
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

		if (!uiMovie) {
			return UI_MESSAGE_RESULTS::kPassOn;
		}

		const auto data = static_cast<BSUIScaleformData*>(a_message.data);
		if (!data) {
			return UI_MESSAGE_RESULTS::kPassOn;
		}

		uiMovie->HandleEvent(*data->scaleformEvent);
		return UI_MESSAGE_RESULTS::kHandled;
	}


	void IMenu::AdvanceMovie([[maybe_unused]] float a_interval, UInt32 a_currentTime)
	{
		if (uiMovie) {
			const GFxValue currentTime(static_cast<double>(a_currentTime));
			uiMovie->SetVariable("CurrentTime", currentTime, GFxMovie::SetVarType::kNormal);
			uiMovie->Advance(static_cast<float>(currentTime.GetNumber()));
		}
	}


	void IMenu::PostDisplay()
	{
		if (uiMovie) {
			uiMovie->Display();
		}
	}


	void IMenu::PreDisplay()
	{}


	void IMenu::RefreshPlatform()
	{
		using Message = UI_MESSAGE_TYPE;

		auto inputManager = BSInputDeviceManager::GetSingleton();
		auto gamepad = inputManager ? inputManager->IsGamepadEnabled() : false;
		if (uiMovie && uiMovie->IsAvailable("_root.SetPlatform")) {
			std::array<GFxValue, 2> args;
			const double platform = gamepad ? 1.0 : 0.0;
			args[0].SetNumber(platform);
			const bool swapPS3 = false;
			args[1].SetBoolean(swapPS3);
			uiMovie->Invoke("_root.SetPlatform", nullptr, args.data(), args.size());
		}

		if (UpdateUsesCursor()) {
			Message messageID;
			auto uiStr = InterfaceStrings::GetSingleton();
			if (gamepad) {
				menuFlags &= ~Flag::kUsesCursor;
				messageID = Message::kHide;
			} else {
				menuFlags |= Flag::kUsesCursor;
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
		return (menuFlags & Flag::kAdvancesUnderPauseMenu) != Flag::kNone;
	}


	bool IMenu::AllowSaving() const
	{
		return (menuFlags & Flag::kAllowSaving) != Flag::kNone;
	}


	bool IMenu::AlwaysOpen() const
	{
		return (menuFlags & Flag::kAlwaysOpen) != Flag::kNone;
	}


	bool IMenu::ApplicationMenu() const
	{
		return (menuFlags & Flag::kApplicationMenu) != Flag::kNone;
	}


	bool IMenu::AssignCursorToRenderer() const
	{
		return (menuFlags & Flag::kAssignCursorToRenderer) != Flag::kNone;
	}


	bool IMenu::CustomRendering() const
	{
		return (menuFlags & Flag::kCustomRendering) != Flag::kNone;
	}


	bool IMenu::CompanionAppAllowed() const
	{
		return (menuFlags & Flag::kCompanionAppAllowed) != Flag::kNone;
	}


	bool IMenu::DisablePauseMenu() const
	{
		return (menuFlags & Flag::kDisablePauseMenu) != Flag::kNone;
	}


	bool IMenu::DontHideCursorWhenTopmost() const
	{
		return (menuFlags & Flag::kDontHideCursorWhenTopmost) != Flag::kNone;
	}


	bool IMenu::FreezeFrameBackground() const
	{
		return (menuFlags & Flag::kFreezeFrameBackground) != Flag::kNone;
	}


	bool IMenu::FreezeFramePause() const
	{
		return (menuFlags & Flag::kFreezeFramePause) != Flag::kNone;
	}


	bool IMenu::HasButtonBar() const
	{
		return (menuFlags & Flag::kHasButtonBar) != Flag::kNone;
	}


	bool IMenu::InventoryItemMenu() const
	{
		return (menuFlags & Flag::kInventoryItemMenu) != Flag::kNone;
	}


	bool IMenu::IsTopButtonBar() const
	{
		return (menuFlags & Flag::kIsTopButtonBar) != Flag::kNone;
	}


	bool IMenu::LargeScaleformRenderCacheMode() const
	{
		return (menuFlags & Flag::kLargeScaleformRenderCacheMode) != Flag::kNone;
	}


	bool IMenu::Modal() const
	{
		return (menuFlags & Flag::kModal) != Flag::kNone;
	}


	bool IMenu::OnStack() const
	{
		return (menuFlags & Flag::kOnStack) != Flag::kNone;
	}


	bool IMenu::PausesGame() const
	{
		return (menuFlags & Flag::kPausesGame) != Flag::kNone;
	}


	bool IMenu::RendersOffscreenTargets() const
	{
		return (menuFlags & Flag::kRendersOffscreenTargets) != Flag::kNone;
	}


	bool IMenu::RendersUnderPauseMenu() const
	{
		return (menuFlags & Flag::kRendersUnderPauseMenu) != Flag::kNone;
	}


	bool IMenu::RequiresUpdate() const
	{
		return (menuFlags & Flag::kRequiresUpdate) != Flag::kNone;
	}


	bool IMenu::SkipRenderDuringFreezeFrameScreenshot() const
	{
		return (menuFlags & Flag::kSkipRenderDuringFreezeFrameScreenshot) != Flag::kNone;
	}


	bool IMenu::TopmostRenderedMenu() const
	{
		return (menuFlags & Flag::kTopmostRenderedMenu) != Flag::kNone;
	}


	bool IMenu::UsesBlurredBackground() const
	{
		return (menuFlags & Flag::kUsesBlurredBackground) != Flag::kNone;
	}


	bool IMenu::UsesCursor() const
	{
		return (menuFlags & Flag::kUsesCursor) != Flag::kNone;
	}


	bool IMenu::UsesMenuContext() const
	{
		return (menuFlags & Flag::kUsesMenuContext) != Flag::kNone;
	}


	bool IMenu::UsesMovementToDirection() const
	{
		return (menuFlags & Flag::kUsesMovementToDirection) != Flag::kNone;
	}


	bool IMenu::UpdateUsesCursor() const
	{
		return (menuFlags & Flag::kUpdateUsesCursor) != Flag::kNone;
	}
}
