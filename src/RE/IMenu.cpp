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


	void IMenu::Accept(CallbackProcessor* a_processor)
	{}


	void IMenu::PostCreate()
	{}


	void IMenu::Unk_03(void)
	{}


	auto IMenu::ProcessMessage(UIMessage* a_message)
		-> Result
	{
		if (a_message->message != UIMessage::Message::kScaleform) {
			return Result::kNotProcessed;
		}

		if (!view) {
			return Result::kNotProcessed;
		}

		auto data = static_cast<BSUIScaleformData*>(a_message->objData);
		if (!data) {
			return Result::kNotProcessed;
		}

		view->HandleEvent(*data->event);
		return Result::kProcessed;
	}


	void IMenu::AdvanceMovie(float a_arg1, UInt32 a_currentTime)
	{
		if (view) {
			GFxValue currentTime(static_cast<double>(a_currentTime));
			view->SetVariable("CurrentTime", &currentTime, GFxMovie::SetVarType::kNormal);
			view->Advance(currentTime.GetNumber());
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
		using Message = UIMessage::Message;

		auto inputManager = BSInputDeviceManager::GetSingleton();
		auto gamepad = inputManager->IsGamepadEnabled();
		if (view && view->IsAvailable("_root.SetPlatform")) {
			GFxValue args[2];
			double platform = gamepad ? 1.0 : 0.0;
			args[0].SetNumber(platform);
			bool swapPS3 = false;
			args[1].SetBoolean(swapPS3);
			view->Invoke("_root.SetPlatform", 0, args, std::extent<decltype(args)>::value);
		}

		if (UpdateUsesCursor()) {
			Message messageID;
			auto uiStr = InterfaceStrings::GetSingleton();
			if (gamepad) {
				flags &= ~Flag::kUsesCursor;
				messageID = Message::kClose;
			} else {
				flags |= Flag::kUsesCursor;
				auto ui = UI::GetSingleton();
				messageID = ui->IsMenuOpen(uiStr->cursorMenu) ? Message::kRefresh : Message::kOpen;
			}
			auto messageQueue = UIMessageQueue::GetSingleton();
			messageQueue->AddMessage(uiStr->cursorMenu, messageID, 0);
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
