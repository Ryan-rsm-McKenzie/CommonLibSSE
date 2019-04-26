#pragma once

#include "skse64_common/Utilities.h"  // GetFnAddr
#include "skse64/GameEvents.h"  // EventDispatcher

#include "RE/BSTArray.h"  // BSTArray


namespace RE
{
	template <class T> class BSTEventSink;


	template <class EventT>
	class BSTEventSource
	{
	public:
		using SinkT = BSTEventSink<EventT>;


		BSTEventSource() :
			stateFlag(false)
		{}


		void AddEventSink(SinkT* a_eventSink)
		{
			using func_t = function_type_t<decltype(&BSTEventSource::AddEventSink)>;
			func_t* func = unrestricted_cast<func_t*>(&::EventDispatcher<EventT>::AddEventSink);
			return func(this, a_eventSink);
		}


		void RemoveEventSink(SinkT* a_eventSink)
		{
			using func_t = function_type_t<decltype(&BSTEventSource::RemoveEventSink)>;
			func_t* func = unrestricted_cast<func_t*>(&::EventDispatcher<EventT>::RemoveEventSink);
			return func(this, a_eventSink);
		}


		void SendEvent(EventT* a_event)
		{
			using func_t = function_type_t<decltype(&BSTEventSource::SendEvent)>;
			func_t* func = unrestricted_cast<func_t*>(&::EventDispatcher<EventT>::SendEvent);
			return func(this, a_event);
		}


		void operator()(EventT* a_event)
		{
			using func_t = function_type_t<decltype(&BSTEventSource::operator())>;
			func_t* func = unrestricted_cast<func_t*>(&::EventDispatcher<EventT>::SendEvent);
			return func(this, a_event);
		}


		// members
		BSTArray<SinkT*>	eventSinks;		// 00
		BSTArray<SinkT*>	addBuffer;		// 18 - schedule for add
		BSTArray<SinkT*>	removeBuffer;	// 30 - schedule for remove
		SimpleLock			lock;			// 48
		bool				stateFlag;		// 50 - some internal state changed while sending
		UInt8				pad51;			// 51
		UInt16				pad52;			// 52
		UInt32				pad54;			// 54
	};
	STATIC_ASSERT(sizeof(BSTEventSource<void*>) == 0x58);


	enum class EventResult
	{
		kContinue = 0,
		kAbort
	};


	template <class EventT>
	class BSTEventSink
	{
	public:
		virtual ~BSTEventSink() = default;																// 00
		virtual	EventResult	ReceiveEvent(EventT* a_event, BSTEventSource<EventT>* a_eventSource) = 0;	// 01
	};
	STATIC_ASSERT(sizeof(BSTEventSink<void*>) == 0x8);
}
