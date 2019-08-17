#pragma once

#include "RE/BSLock.h"  // BSUniqueLock
#include "RE/BSTArray.h"  // BSTArray


namespace RE
{
	template <class T> class BSTEventSink;


	enum class EventResult
	{
		kContinue = 0,
		kAbort
	};


	template <class Event>
	class BSTEventSource
	{
	public:
		using Sink = BSTEventSink<Event>;


		BSTEventSource() :
			eventSinks(),
			addBuffer(),
			removeBuffer(),
			lock(),
			stateFlag(false),
			pad51(0),
			pad52(0),
			pad54(0)
		{}


		void AddEventSink(Sink* a_eventSink)
		{
			if (!a_eventSink) {
				return;
			}

			RE::BSUniqueLockGuard locker(lock);

			if (sinksLocked) {
				if (std::find(addBuffer.begin(), addBuffer.end(), a_eventSink) == addBuffer.end()) {
					addBuffer.push_back(a_eventSink);
				}
			} else {
				if (std::find(eventSinks.begin(), eventSinks.end(), a_eventSink) == eventSinks.end()) {
					eventSinks.push_back(a_eventSink);
				}
			}

			auto it = std::find(removeBuffer.begin(), removeBuffer.end(), a_eventSink);
			if (it != removeBuffer.end()) {
				removeBuffer.erase(it);
			}
		}


		void RemoveEventSink(Sink* a_eventSink)
		{
			if (!a_eventSink) {
				return;
			}

			RE::BSUniqueLockGuard locker(lock);

			if (sinksLocked) {
				if (std::find(removeBuffer.begin(), removeBuffer.end(), a_eventSink) == removeBuffer.end()) {
					removeBuffer.push_back(a_eventSink);
				}
			} else {
				auto it = std::find(eventSinks.begin(), eventSinks.end(), a_eventSink);
				if (it != eventSinks.end()) {
					eventSinks.erase(it);
				}
			}

			auto it = std::find(addBuffer.begin(), addBuffer.end(), a_eventSink);
			if (it != addBuffer.end()) {
				addBuffer.erase(it);
			}
		}


		void SendEvent(Event* a_event)
		{
			RE::BSUniqueLockGuard locker(lock);

			auto wasLocked = sinksLocked;
			sinksLocked = true;
			if (!wasLocked && !addBuffer.empty()) {
				for (auto& toAdd : addBuffer) {
					if (std::find(eventSinks.begin(), eventSinks.end(), toAdd) == eventSinks.end()) {
						eventSinks.push_back(toAdd);
					}
				}
				addBuffer.clear();
			}

			for (auto& sink : eventSinks) {
				if (std::find(removeBuffer.begin(), removeBuffer.end(), sink) == removeBuffer.end()) {
					if (sink->ReceiveEvent(a_event, this) == EventResult::kAbort) {
						break;
					}
				}
			}

			sinksLocked = wasLocked;
			if (!wasLocked && !removeBuffer.empty()) {
				for (auto& toRemove : removeBuffer) {
					auto it = std::find(eventSinks.begin(), eventSinks.end(), toRemove);
					if (it != eventSinks.end()) {
						eventSinks.erase(it);
					}
				}
				removeBuffer.clear();
			}
		}


		void operator()(Event* a_event)
		{
			return SendEvent(a_event);
		}


		// members
		BSTArray<Sink*>			eventSinks;		// 00
		BSTArray<Sink*>			addBuffer;		// 18
		BSTArray<Sink*>			removeBuffer;	// 30
		mutable BSUniqueLock	lock;			// 48
		bool					sinksLocked;	// 50
		UInt8					pad51;			// 51
		UInt16					pad52;			// 52
		UInt32					pad54;			// 54
	};
	STATIC_ASSERT(sizeof(BSTEventSource<void*>) == 0x58);


	template <class Event>
	class BSTEventSink
	{
	public:
		virtual ~BSTEventSink() = default;															// 00
		virtual	EventResult	ReceiveEvent(Event* a_event, BSTEventSource<Event>* a_eventSource) = 0;	// 01
	};
	STATIC_ASSERT(sizeof(BSTEventSink<void*>) == 0x8);
}
