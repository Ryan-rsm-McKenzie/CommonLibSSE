#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/S/SimpleAnimationGraphManagerHolder.h"

namespace RE
{
	struct BSAnimationGraphEvent;

	class StatsNode :
		public SimpleAnimationGraphManagerHolder,   // 00
		public BSIntrusiveRefCounted,               // 20
		public BSTEventSink<BSAnimationGraphEvent>  // 18
	{
	public:
		inline static constexpr auto RTTI = RTTI_StatsNode;

		~StatsNode() override;  // 00

		// override (SimpleAnimationGraphManagerHolder)
		bool SetupAnimEventSinks(const BSTSmartPointer<BShkbAnimationGraph>& a_animGraph) override;  // 08
		void Unk_0C(void) override;                                                                  // 0C

		// override (BSTEventSink<BSAnimationGraphEvent>)
		BSEventNotifyControl ProcessEvent(const BSAnimationGraphEvent* a_event, BSTEventSource<BSAnimationGraphEvent>* a_eventSource) override;  // 01 - runs PlaySound on BSAnimationGraphEvent::optionalStr

		// members
		std::uint32_t                                    unk24;  // 24
		BSTArray<BSTSmartPointer<BSIntrusiveRefCounted>> unk28;  // 28
		std::uint64_t                                    unk40;  // 40
		std::uint64_t                                    unk48;  // 48
		BSTSmartPointer<BSIntrusiveRefCounted>           unk50;  // 50
		BSTSmartPointer<BSIntrusiveRefCounted>           unk58;  // 58
		std::uint64_t                                    unk60;  // 60
	};
	static_assert(sizeof(StatsNode) == 0x68);
}
