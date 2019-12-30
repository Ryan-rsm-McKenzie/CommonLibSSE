#pragma once

#include "RE/ActorSpeedChannel.h"
#include "RE/BSFixedString.h"
#include "RE/BSIntrusiveRefCounted.h"
#include "RE/BSLock.h"
#include "RE/BSTAnimationGraphDataChannel.h"
#include "RE/BSTArray.h"
#include "RE/BSTEvent.h"
#include "RE/BSTSmartPointer.h"


namespace RE
{
	struct BSAnimationGraphEvent;
	class BShkbAnimationGraph;


	BSSmartPointer(BSAnimationGraphManager);


	class BSAnimationGraphManager :
		public BSTEventSink<BSAnimationGraphEvent>,	// 00
		public BSIntrusiveRefCounted				// 08
	{
	public:
		inline static const void* RTTI = RTTI_BSAnimationGraphManager;


		struct AnimationVariable
		{
			union Value
			{
				bool	b;
				SInt32	i;
				float	f;
			};
			STATIC_ASSERT(sizeof(Value) == 0x4);


			BSFixedString	name;	// 00
			Value*			value;	// 08
		};
		STATIC_ASSERT(sizeof(AnimationVariable) == 0x10);


		virtual ~BSAnimationGraphManager();																											// 00

		// override (BSTEventSink<BSAnimationGraphEvent>)
		virtual	BSEventNotifyControl ReceiveEvent(BSAnimationGraphEvent* a_event, BSTEventSource<BSAnimationGraphEvent>* a_eventSource) override;	// 01


		// members
		UInt32																						unk0C;				// 0C
		BSTArray<BSTSmartPointer<BSTAnimationGraphDataChannel<Actor, float, ActorSpeedChannel>>>	unk10;				// 10
		BSTArray<void*>																				unk28;				// 28 - array of smart ptrs
		BSTSmallArray<BSTSmartPointer<BShkbAnimationGraph>>											animationGraphs;	// 40
		BSTArray<void*>																				unk58;				// 58 - array of smart ptrs
		BSTArray<AnimationVariable>																	animationVariables;	// 70
		void*																						unk88;				// 88
		BShkbAnimationGraph*																		unk90;				// 90 - The active animation graph?
		UInt64																						unk98;				// 98
		mutable BSSpinLock																			unkA0;				// A0
		UInt64																						unkA8;				// A8
	};
	STATIC_ASSERT(offsetof(BSAnimationGraphManager, animationGraphs) == 0x40);
	STATIC_ASSERT(sizeof(BSAnimationGraphManager) == 0xB0);
}
