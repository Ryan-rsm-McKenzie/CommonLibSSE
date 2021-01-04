#pragma once

#include "RE/B/BSAtomic.h"
#include "RE/B/BSTArray.h"

namespace RE
{
	template <class T>
	class BSTEventSink;

	enum class BSEventNotifyControl
	{
		kContinue = 0,
		kStop = 1
	};

	struct BSContainer
	{
		enum class ForEachResult
		{
			kContinue = 0,
			kStop = 1
		};
	};

	template <class Event>
	class BSTEventSource
	{
	public:
		using Sink = BSTEventSink<Event>;

		BSTEventSource() :
			sinks(),
			pendingRegisters(),
			pendingUnregisters(),
			lock(),
			notifying(false),
			pad51(0),
			pad52(0),
			pad54(0)
		{}

		void AddEventSink(Sink* a_eventSink)
		{
			if (!a_eventSink) {
				return;
			}

			BSSpinLockGuard locker(lock);

			if (notifying) {
				if (std::find(pendingRegisters.begin(), pendingRegisters.end(), a_eventSink) == pendingRegisters.end()) {
					pendingRegisters.push_back(a_eventSink);
				}
			} else {
				if (std::find(sinks.begin(), sinks.end(), a_eventSink) == sinks.end()) {
					sinks.push_back(a_eventSink);
				}
			}

			auto it = std::find(pendingUnregisters.begin(), pendingUnregisters.end(), a_eventSink);
			if (it != pendingUnregisters.end()) {
				pendingUnregisters.erase(it);
			}
		}

		void RemoveEventSink(Sink* a_eventSink)
		{
			if (!a_eventSink) {
				return;
			}

			BSSpinLockGuard locker(lock);

			if (notifying) {
				if (std::find(pendingUnregisters.begin(), pendingUnregisters.end(), a_eventSink) == pendingUnregisters.end()) {
					pendingUnregisters.push_back(a_eventSink);
				}
			} else {
				auto it = std::find(sinks.begin(), sinks.end(), a_eventSink);
				if (it != sinks.end()) {
					sinks.erase(it);
				}
			}

			auto it = std::find(pendingRegisters.begin(), pendingRegisters.end(), a_eventSink);
			if (it != pendingRegisters.end()) {
				pendingRegisters.erase(it);
			}
		}

		void SendEvent(const Event* a_event)
		{
			BSSpinLockGuard locker(lock);

			const auto wasNotifying = notifying;
			notifying = true;
			if (!wasNotifying && !pendingRegisters.empty()) {
				for (auto& toAdd : pendingRegisters) {
					if (std::find(sinks.begin(), sinks.end(), toAdd) == sinks.end()) {
						sinks.push_back(toAdd);
					}
				}
				pendingRegisters.clear();
			}

			for (auto& sink : sinks) {
				if (std::find(pendingUnregisters.begin(), pendingUnregisters.end(), sink) == pendingUnregisters.end()) {
					if (sink->ProcessEvent(a_event, this) == BSEventNotifyControl::kStop) {
						break;
					}
				}
			}

			notifying = wasNotifying;
			if (!wasNotifying && !pendingUnregisters.empty()) {
				for (auto& toRemove : pendingUnregisters) {
					auto it = std::find(sinks.begin(), sinks.end(), toRemove);
					if (it != sinks.end()) {
						sinks.erase(it);
					}
				}
				pendingUnregisters.clear();
			}
		}

		void operator()(const Event* a_event)
		{
			return SendEvent(a_event);
		}

		// members
		BSTArray<Sink*>	   sinks;				// 00
		BSTArray<Sink*>	   pendingRegisters;	// 18
		BSTArray<Sink*>	   pendingUnregisters;	// 30
		mutable BSSpinLock lock;				// 48
		bool			   notifying;			// 50
		std::uint8_t	   pad51;				// 51
		std::uint16_t	   pad52;				// 52
		std::uint32_t	   pad54;				// 54
	};
	static_assert(sizeof(BSTEventSource<void*>) == 0x58);

	template <class Event>
	class BSTEventSink
	{
	public:
		virtual ~BSTEventSink() = default;																			// 00
		virtual BSEventNotifyControl ProcessEvent(const Event* a_event, BSTEventSource<Event>* a_eventSource) = 0;	// 01
	};
	static_assert(sizeof(BSTEventSink<void>) == 0x8);
}
