#include "RE/I/IMenu.h"

#include "RE/B/BSInputDeviceManager.h"
#include "RE/B/BSUIScaleformData.h"
#include "RE/G/GFxValue.h"
#include "RE/I/InterfaceStrings.h"
#include "RE/U/UI.h"
#include "RE/U/UIMessage.h"
#include "RE/U/UIMessageQueue.h"

namespace RE
{
	void IMenu::Accept(CallbackProcessor*)
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

	void IMenu::AdvanceMovie(float, std::uint32_t a_currentTime)
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
		auto gamepad = inputManager != nullptr && inputManager->IsGamepadEnabled();
		if (uiMovie && uiMovie->IsAvailable("_root.SetPlatform")) {
			std::array<GFxValue, 2> args;
			const double            platform = gamepad ? 1.0 : 0.0;
			args[0].SetNumber(platform);
			const bool swapPS3 = false;
			args[1].SetBoolean(swapPS3);
			uiMovie->Invoke("_root.SetPlatform", nullptr, args.data(), static_cast<std::uint32_t>(args.size()));
		}

		if (UpdateUsesCursor()) {
			Message messageID;
			auto    uiStr = InterfaceStrings::GetSingleton();
			if (gamepad) {
				menuFlags.reset(Flag::kUsesCursor);
				messageID = Message::kHide;
			} else {
				menuFlags.set(Flag::kUsesCursor);
				auto ui = UI::GetSingleton();
				messageID = ui && ui->IsMenuOpen(uiStr->cursorMenu) ? Message::kUpdate : Message::kShow;
			}

			auto messageQueue = UIMessageQueue::GetSingleton();
			if (messageQueue) {
				messageQueue->AddMessage(uiStr->cursorMenu, messageID, nullptr);
			}
		}
	}
}
