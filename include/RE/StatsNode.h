#pragma once

#include "RE/BSIntrusiveRefCounted.h"  // BSIntrusiveRefCounted
#include "RE/BSTArray.h"  // BSTArray
#include "RE/BSTEvent.h"  // BSTEventSink
#include "RE/SimpleAnimationGraphManagerHolder.h"  // SimpleAnimationGraphManagerHolder


namespace RE
{
	struct BSAnimationGraphEvent;


	class StatsNode :
		public SimpleAnimationGraphManagerHolder,	// 00
		public BSIntrusiveRefCounted,				// 20
		public BSTEventSink<BSAnimationGraphEvent>	// 18
	{
	public:
		virtual ~StatsNode();																												// 00

		// override (SimpleAnimationGraphManagerHolder)
		virtual void		SinkAnimationGraphEvent(BSTSmartPointer<BShkbAnimationGraph>& a_animGraph) override;							// 08
		virtual void		Unk_0C(void) override;																							// 0C

		// override (BSTEventSink<BSAnimationGraphEvent>)
		virtual	EventResult	ReceiveEvent(BSAnimationGraphEvent* a_event, BSTEventSource<BSAnimationGraphEvent>* a_eventSource) override;	// 01 - runs PlaySound on BSAnimationGraphEvent::optionalStr


		// members
		UInt32												unk24;	// 24
		BSTArray<BSTSmartPointer<BSIntrusiveRefCounted>>	unk28;	// 28
		UInt64												unk40;	// 40
		UInt64												unk48;	// 48
		BSTSmartPointer<BSIntrusiveRefCounted>				unk50;	// 50
		BSTSmartPointer<BSIntrusiveRefCounted>				unk58;	// 58
		UInt64												unk60;	// 60
	};
	STATIC_ASSERT(sizeof(StatsNode) == 0x68);
}
