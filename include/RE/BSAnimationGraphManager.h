#pragma once

#include "RE/BSAtomic.h"
#include "RE/BSFixedString.h"
#include "RE/BSIntrusiveRefCounted.h"
#include "RE/BSTArray.h"
#include "RE/BSTEvent.h"
#include "RE/BSTSmartPointer.h"


namespace RE
{
	struct BSAnimationGraphEvent;
	class BShkbAnimationGraph;


	union hkbVariableValue
	{
		bool   b;
		SInt32 i;
		float  f;
	};
	STATIC_ASSERT(sizeof(hkbVariableValue) == 0x4);


	struct AnimVariableCacheInfo
	{
	public:
		// members
		BSFixedString	  variableName;	 // 00
		hkbVariableValue* variable;		 // 08
	};
	STATIC_ASSERT(sizeof(AnimVariableCacheInfo) == 0x10);


	struct BSAnimationGraphVariableCache
	{
	public:
		// members
		BSTArray<AnimVariableCacheInfo> variableCache;	// 00
		void*							unk18;			// 18
		void*							unk20;			// 20 - smart ptr
	};
	STATIC_ASSERT(sizeof(BSAnimationGraphVariableCache) == 0x28);


	BSSmartPointer(BSAnimationGraphManager);


	class BSAnimationGraphManager :
		public BSTEventSink<BSAnimationGraphEvent>,	 // 00
		public BSIntrusiveRefCounted				 // 08
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSAnimationGraphManager;


		struct AnimationVariable
		{
		public:
			union Value
			{
				bool   b;
				SInt32 i;
				float  f;
			};
			STATIC_ASSERT(sizeof(Value) == 0x4);


			// members
			BSFixedString name;	  // 00
			Value*		  value;  // 08
		};
		STATIC_ASSERT(sizeof(AnimationVariable) == 0x10);


		virtual ~BSAnimationGraphManager();	 // 00

		// override (BSTEventSink<BSAnimationGraphEvent>)
		virtual BSEventNotifyControl ProcessEvent(const BSAnimationGraphEvent* a_event, BSTEventSource<BSAnimationGraphEvent>* a_eventSource) override;	 // 01


		// members
		UInt32												pad0C;				   // 0C
		BSTArray<BSTSmartPointer<BSAnimationGraphChannel>>	boundChannels;		   // 10
		BSTArray<BSTSmartPointer<BSAnimationGraphChannel>>	bumpedChannels;		   // 28
		BSTSmallArray<BSTSmartPointer<BShkbAnimationGraph>> graphs;				   // 40
		BSTArray<BSAnimationGraphManagerPtr>				subManagers;		   // 58
		BSAnimationGraphVariableCache						variableCache;		   // 70
		mutable BSSpinLock									updateLock;			   // 98
		mutable BSSpinLock									dependentManagerLock;  // A0
		UInt32												activeGraph;		   // A8
		UInt32												generateDepth;		   // A8
	};
	STATIC_ASSERT(sizeof(BSAnimationGraphManager) == 0xB0);
}
