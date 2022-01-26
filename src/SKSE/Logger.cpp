#include "SKSE/Logger.h"

#include "RE/V/VirtualMachine.h"
#include "SKSE/API.h"

#include <ShlObj.h>

namespace SKSE
{
	namespace Impl
	{
		class LogEventHandler : public RE::BSTEventSink<RE::BSScript::LogEvent>
		{
		public:
			using EventResult = RE::BSEventNotifyControl;

			[[nodiscard]] static inline LogEventHandler* GetSingleton()
			{
				static LogEventHandler singleton;
				return std::addressof(singleton);
			}

			inline void SetFilter(std::regex a_filter) { _filter = std::move(a_filter); }

			EventResult ProcessEvent(const RE::BSScript::LogEvent* a_event, RE::BSTEventSource<RE::BSScript::LogEvent>*) override
			{
				using Severity = RE::BSScript::ErrorLogger::Severity;

				if (a_event && a_event->errorMsg && std::regex_search(a_event->errorMsg, _filter)) {
					switch (a_event->severity) {
					case Severity::kInfo:
						log::info("{}"sv, a_event->errorMsg);
						break;
					case Severity::kWarning:
						log::warn("{}"sv, a_event->errorMsg);
						break;
					case Severity::kError:
						log::error("{}"sv, a_event->errorMsg);
						break;
					case Severity::kFatal:
						log::critical("{}"sv, a_event->errorMsg);
						break;
					}
				}

				return EventResult::kContinue;
			}

		private:
			LogEventHandler() = default;
			LogEventHandler(const LogEventHandler&) = delete;
			LogEventHandler(LogEventHandler&&) = delete;
			~LogEventHandler() override = default;

			LogEventHandler& operator=(const LogEventHandler&) = delete;
			LogEventHandler& operator=(LogEventHandler&&) = delete;

			std::regex _filter;
		};
	}

	void add_papyrus_sink(std::regex a_filter)
	{
		auto handler = Impl::LogEventHandler::GetSingleton();
		handler->SetFilter(std::move(a_filter));

		SKSE::RegisterForAPIInitEvent([]() {
			auto papyrus = SKSE::GetPapyrusInterface();
			if (papyrus) {
				papyrus->Register([](RE::BSScript::IVirtualMachine* a_vm) {
					auto handler = Impl::LogEventHandler::GetSingleton();
					a_vm->RegisterForLogEvent(handler);
					return true;
				});
			}
		});
	}

	void remove_papyrus_sink()
	{
		SKSE::RegisterForAPIInitEvent([]() {
			auto papyrus = SKSE::GetPapyrusInterface();
			if (papyrus) {
				papyrus->Register([](RE::BSScript::IVirtualMachine* a_vm) {
					auto handler = Impl::LogEventHandler::GetSingleton();
					a_vm->UnregisterForLogEvent(handler);
					return true;
				});
			}
		});
	}

	namespace log
	{
		std::optional<std::filesystem::path> log_directory()
		{
			wchar_t*                                               buffer{ nullptr };
			const auto                                             result = ::SHGetKnownFolderPath(::FOLDERID_Documents, ::KNOWN_FOLDER_FLAG::KF_FLAG_DEFAULT, nullptr, std::addressof(buffer));
			std::unique_ptr<wchar_t[], decltype(&::CoTaskMemFree)> knownPath(buffer, ::CoTaskMemFree);
			if (!knownPath || result != S_OK) {
				error("failed to get known folder path"sv);
				return std::nullopt;
			}

			std::filesystem::path path = knownPath.get();
			path /= "My Games/Skyrim Special Edition/SKSE"sv;
			return path;
		}
	}
}
