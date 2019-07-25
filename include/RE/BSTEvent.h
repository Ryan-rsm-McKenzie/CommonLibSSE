#pragma once

#include "skse64/GameEvents.h"  // EventDispatcher

#include "RE/BSLock.h"  // BSUniqueLock
#include "RE/BSTArray.h"  // BSTArray


namespace RE
{
	template <class T> class BSTEventSink;


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
			using func_t = function_type_t<decltype(&BSTEventSource::AddEventSink)>;
			func_t* func = unrestricted_cast<func_t*>(&::EventDispatcher<Event>::AddEventSink);
			return func(this, a_eventSink);
		}


		void RemoveEventSink(Sink* a_eventSink)
		{
			using func_t = function_type_t<decltype(&BSTEventSource::RemoveEventSink)>;
			func_t* func = unrestricted_cast<func_t*>(&::EventDispatcher<Event>::RemoveEventSink);
			return func(this, a_eventSink);
		}


		void SendEvent(Event* a_event)
		{
			using func_t = function_type_t<decltype(&BSTEventSource::SendEvent)>;
			func_t* func = unrestricted_cast<func_t*>(&::EventDispatcher<Event>::SendEvent);
			return func(this, a_event);
		}


		void operator()(Event* a_event)
		{
			return AddEventSink(a_event);
		}


		// members
		BSTArray<Sink*>			eventSinks;		// 00
		BSTArray<Sink*>			addBuffer;		// 18
		BSTArray<Sink*>			removeBuffer;	// 30
		mutable BSUniqueLock	lock;			// 48
		bool					stateFlag;		// 50
		UInt8					pad51;			// 51
		UInt16					pad52;			// 52
		UInt32					pad54;			// 54
	};
	STATIC_ASSERT(sizeof(BSTEventSource<void*>) == 0x58);


	enum class EventResult
	{
		kContinue = 0,
		kAbort
	};


	template <class Event>
	class BSTEventSink
	{
	public:
		virtual ~BSTEventSink() = default;															// 00
		virtual	EventResult	ReceiveEvent(Event* a_event, BSTEventSource<Event>* a_eventSource) = 0;	// 01
	};
	STATIC_ASSERT(sizeof(BSTEventSink<void*>) == 0x8);
}
