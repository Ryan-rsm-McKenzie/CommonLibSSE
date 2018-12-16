#pragma once

#include "skse64_common/Utilities.h"  // GetFnAddr
#include "skse64/GameEvents.h"  // EventDispatcher

#include "RE/BSTArray.h"  // BSTArray


namespace RE
{
	template <typename T> class BSTEventSink;


	enum class EventResult
	{
		kContinue = 0,
		kAbort
	};


	template <typename EventT>
	class BSTEventSource
	{
	public:
		typedef BSTEventSink<EventT> SinkT;


		BSTEventSource() :
			stateFlag(false)
		{}


		void AddEventSink(SinkT* a_eventSink)
		{
			typedef void _AddEventSink_Internal_t(BSTEventSource<EventT>* a_this, SinkT* a_eventSink);
			static _AddEventSink_Internal_t* _AddEventSink_Internal = reinterpret_cast<_AddEventSink_Internal_t*>(GetFnAddr(&::EventDispatcher<EventT>::AddEventSink));
			_AddEventSink_Internal(this, a_eventSink);
		}


		void RemoveEventSink(SinkT* a_eventSink)
		{
			typedef void _RemoveEventSink_Internal_t(BSTEventSource<EventT>* a_this, SinkT* a_eventSink);
			static _RemoveEventSink_Internal_t* _RemoveEventSink_Internal = reinterpret_cast<_RemoveEventSink_Internal_t*>(GetFnAddr(&::EventDispatcher<EventT>::RemoveEventSink));
			_RemoveEventSink_Internal(this, a_eventSink);
		}


		void SendEvent(EventT* a_event)
		{
			typedef void _SendEvent_Internal_t(BSTEventSource<EventT>* a_this, EventT* a_event);
			static _SendEvent_Internal_t* _SendEvent_Internal = reinterpret_cast<_SendEvent_Internal_t*>(GetFnAddr(&::EventDispatcher<EventT>::SendEvent));
			_SendEvent_Internal(this, a_event);
		}


		void operator()(EventT* a_event)
		{
			typedef void _SendEvent_Internal_t(BSTEventSource<EventT>* a_this, EventT* a_event);
			static _SendEvent_Internal_t* _SendEvent_Internal = reinterpret_cast<_SendEvent_Internal_t*>(GetFnAddr(&::EventDispatcher<EventT>::SendEvent));
			_SendEvent_Internal(this, a_event);
		}


		// members
		BSTArray<SinkT*>	eventSinks;		// 00
		BSTArray<SinkT*>	addBuffer;		// 18 - schedule for add
		BSTArray<SinkT*>	removeBuffer;	// 30 - schedule for remove
		SimpleLock			lock;			// 48
		bool				stateFlag;		// 50 - some internal state changed while sending
		UInt8				pad51[0x7];		// 51
	};
	STATIC_ASSERT(sizeof(BSTEventSource<void*>) == 0x58);


	template <typename EventT>
	class BSTEventSink
	{
	public:
		virtual ~BSTEventSink() {}
		virtual	EventResult	ReceiveEvent(EventT* a_event, BSTEventSource<EventT>* a_eventSource) = 0;
	};
}
