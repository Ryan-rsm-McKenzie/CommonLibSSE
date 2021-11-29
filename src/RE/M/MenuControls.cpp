#include "RE/M/MenuControls.h"

#include "RE/M/MenuEventHandler.h"

namespace RE
{
	MenuControls::QueuedReg::QueuedReg(MenuEventHandler* a_handler, bool a_add) :
		handler(a_handler),
		add(a_add),
		pad08(0),
		pad09(0),
		pad0A(0)
	{}

	MenuControls* MenuControls::GetSingleton()
	{
		REL::Relocation<MenuControls**> singelton{ Offset::MenuControls::Singleton };
		return *singelton;
	}

	void MenuControls::AddHandler(MenuEventHandler* a_handler)
	{
		return RegisterHandler(a_handler);
	}

	void MenuControls::RegisterHandler(MenuEventHandler* a_handler)
	{
		if (!a_handler) {
			return;
		}

		if (isProcessing) {
			auto pos = std::find_if(regBuffer.begin(), regBuffer.end(), [a_handler](const QueuedReg& a_elem) -> bool {
				return a_elem.handler == a_handler;
			});

			if (pos == regBuffer.end()) {
				QueuedReg reg(a_handler, true);
				regBuffer.push_back(std::move(reg));
			} else {
				pos->add = true;
			}
		} else {
			a_handler->registered = true;
			if (std::find(handlers.begin(), handlers.end(), a_handler) == handlers.end()) {
				handlers.push_back(a_handler);
			}
		}
	}

	void MenuControls::RemoveHandler(MenuEventHandler* a_handler)
	{
		return UnregisterHandler(a_handler);
	}

	void MenuControls::UnregisterHandler(MenuEventHandler* a_handler)
	{
		if (!a_handler) {
			return;
		}

		if (isProcessing) {
			a_handler->registered = false;
			auto pos = std::find_if(regBuffer.begin(), regBuffer.end(), [a_handler](const QueuedReg& a_elem) -> bool {
				return a_elem.handler == a_handler;
			});

			if (pos == regBuffer.end()) {
				QueuedReg reg(a_handler, false);
				regBuffer.push_back(std::move(reg));
			} else {
				pos->add = false;
			}
		} else {
			auto pos = std::find(handlers.begin(), handlers.end(), a_handler);
			if (pos != handlers.end()) {
				handlers.erase(pos);
			}
		}
	}
}
