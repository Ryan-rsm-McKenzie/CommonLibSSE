#include "RE/IMenu.h"

#include <type_traits>

#include "RE/BSUIScaleformData.h"
#include "RE/GFxValue.h"
#include "RE/InputManager.h"
#include "RE/MenuManager.h"
#include "RE/UIManager.h"
#include "RE/UIMessage.h"
#include "RE/UIStringHolder.h"


namespace RE
{
	IMenu::IMenu() :
		view(0),
		menuDepth(3),
		pad19(0),
		pad20(0),
		flags(Flag::kNone),
		context(Context::kInvalid),
		pad24(0),
		fxDelegate(0)
	{}


	void IMenu::Accept(CallbackProcessor* a_processor)
	{}


	void IMenu::OnOpen()
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


	void IMenu::NextFrame(float a_arg1, UInt32 a_currentTime)
	{
		if (view) {
			GFxValue currentTime(static_cast<double>(a_currentTime));
			view->SetVariable("CurrentTime", &currentTime, GFxMovie::SetVarType::kNormal);
			view->Advance(currentTime.GetNumber());
		}
	}


	void IMenu::Render()
	{
		if (view) {
			view->Display();
		}
	}


	void IMenu::Unk_07(void)
	{}


	void IMenu::InitMovie()
	{
		using Message = UIMessage::Message;

		auto inputManager = InputManager::GetSingleton();
		auto gamepad = inputManager->IsGamepadEnabled();
		if (view && view->IsAvailable("_root.SetPlatform")) {
			GFxValue args[2];
			double platform = gamepad ? 1.0 : 0.0;
			args[0].SetNumber(platform);
			bool swapPS3 = false;
			args[1].SetBoolean(swapPS3);
			view->Invoke("_root.SetPlatform", 0, args, std::extent<decltype(args)>::value);
		}

		if (TriesToShowCursor()) {
			Message messageID;
			auto uiStrHolder = UIStringHolder::GetSingleton();
			if (gamepad) {
				flags &= ~Flag::kShowCursor;
				messageID = Message::kClose;
			} else {
				flags |= Flag::kShowCursor;
				auto mm = MenuManager::GetSingleton();
				messageID = mm->IsMenuOpen(uiStrHolder->cursorMenu) ? Message::kRefresh : Message::kOpen;
			}
			auto uiManager = UIManager::GetSingleton();
			uiManager->AddMessage(uiStrHolder->cursorMenu, messageID, 0);
		}
	}


	bool IMenu::DeletesOnClose() const
	{
		return (flags & Flag::kDoNotDeleteOnClose) == Flag::kNone;
	}


	bool IMenu::HasFlag0008() const
	{
		return (flags & Flag::kUnk0008) != Flag::kNone;
	}


	bool IMenu::HasFlag0100() const
	{
		return (flags & Flag::kUnk0100) != Flag::kNone;
	}


	bool IMenu::HasFlag1000() const
	{
		return (flags & Flag::kUnk1000) != Flag::kNone;
	}


	bool IMenu::HasFlag8000() const
	{
		return (flags & Flag::kUnk8000) != Flag::kNone;
	}


	bool IMenu::HasFlag10000() const
	{
		return (flags & Flag::kUnk10000) != Flag::kNone;
	}


	bool IMenu::HidesOtherMenus() const
	{
		return (flags & Flag::kHideOther) != Flag::kNone;
	}


	bool IMenu::IsItemMenu() const
	{
		return (flags & Flag::kItemMenu) != Flag::kNone;
	}


	bool IMenu::IsModal() const
	{
		return (flags & Flag::kModal) != Flag::kNone;
	}


	bool IMenu::IsOpen() const
	{
		return (flags & Flag::kOpen) != Flag::kNone;
	}


	bool IMenu::PausesGame() const
	{
		return (flags & Flag::kPauseGame) != Flag::kNone;
	}


	bool IMenu::PreventsGameLoad() const
	{
		return (flags & Flag::kPreventGameLoad) != Flag::kNone;
	}


	bool IMenu::PreventsGameSave() const
	{
		return (flags & Flag::kDoNotPreventGameSave) == Flag::kNone;
	}


	bool IMenu::ShowsCursor() const
	{
		return (flags & Flag::kShowCursor) != Flag::kNone;
	}


	bool IMenu::StopsCrosshairUpdates() const
	{
		return (flags & Flag::kStopCrosshairUpdate) != Flag::kNone;
	}


	bool IMenu::StopsDrawingWorld() const
	{
		return (flags & Flag::kStopDrawingWorld) != Flag::kNone;
	}


	bool IMenu::TriesToShowCursor() const
	{
		return (flags & Flag::kTryShowCursor) != Flag::kNone;
	}
}
