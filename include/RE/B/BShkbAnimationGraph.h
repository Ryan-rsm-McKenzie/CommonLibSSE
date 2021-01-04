#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSIRagdollDriver.h"
#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/H/hkbCharacter.h"

namespace RE
{
	class bhkWorld;
	class BSFadeNode;
	class BShkFloatController;
	class BSTransformDeltaEvent;
	class hkbBehaviorGraph;
	struct BSAnimationGraphEvent;

	namespace BSResource
	{
		struct ID;
	}

	BSSmartPointer(BShkbAnimationGraph);

	class BShkbAnimationGraph :
		public BSIRagdollDriver,					   // 000
		public BSIntrusiveRefCounted,				   // 008
		public BSTEventSource<BSTransformDeltaEvent>,  // 010
		public BSTEventSource<BSAnimationGraphEvent>   // 068
	{
	public:
		inline static constexpr auto RTTI = RTTI_BShkbAnimationGraph;

		virtual ~BShkbAnimationGraph();	 // 00

		// override (BSIRagdollDriver)
		virtual void Unk_01(void) override;					// 01
		virtual void Unk_02(void) override;					// 02
		virtual void Unk_03(void) override;					// 03
		virtual void SetWorld(bhkWorld* a_world) override;	// 04 - { world = a_world; }
		virtual void Unk_05(void) override;					// 05
		virtual void Unk_06(void) override;					// 06
		virtual void Unk_07(void) override;					// 07
		virtual void Unk_08(void) override;					// 08
		virtual void Unk_09(void) override;					// 09
		virtual void Unk_0A(void) override;					// 0A
		virtual void Unk_0B(void) override;					// 0B
		virtual void Unk_0C(void) override;					// 0C
		virtual void Unk_0D(void) override;					// 0D

		template <class T>
		[[nodiscard]] inline BSTEventSource<T>* GetEventSource()
		{
			return static_cast<BSTEventSource<T>*>(this);
		}

		template <class T>
		inline void AddEventSink(BSTEventSink<T>* a_eventSink)
		{
			GetEventSource<T>()->AddEventSink(a_eventSink);
		}

		template <class T>
		inline void RemoveEventSink(BSTEventSink<T>* a_eventSink)
		{
			GetEventSource<T>()->RemoveEventSink(a_eventSink);
		}

		// members
		hkbCharacter				   characterInstance;			 // 0C0
		BSTArray<void*>				   unk160;						 // 160
		BSTArray<BShkFloatController*> unk178;						 // 178
		BSTArray<void*>				   unk190;						 // 190
		BSTSmallArray<void*>		   unk1A8;						 // 1A8
		BSTSmallArray<std::uint8_t>	   unk1C0;						 // 1C0
		std::uint64_t				   unk1D8;						 // 1D8
		std::uint64_t				   unk1E0;						 // 1E0
		float						   interpolationTimeOffsets[2];	 // 1E8
		BSFixedString				   projectName;					 // 1F0
		BSResource::ID*				   unk1F8;						 // 1F8
		void*						   unk200;						 // 200 - BShkbHkxDB::ProjectDBData*
		hkbBehaviorGraph*			   behaviourGraph;				 // 208
		std::uint64_t				   unk210;						 // 210
		BSFadeNode*					   unk218;						 // 218
		std::uint64_t				   unk220;						 // 220
		std::uint64_t				   unk228;						 // 228
		std::uint64_t				   unk230;						 // 230
		bhkWorld*					   physicsWorld;				 // 238
		std::uint32_t				   unk240;						 // 240
		std::uint16_t				   unk244;						 // 244
		std::uint8_t				   unk246;						 // 246
		std::uint8_t				   unk247;						 // 247
		std::uint16_t				   unk248;						 // 248
		std::uint16_t				   unk24A;						 // 24A
		std::uint32_t				   unk24C;						 // 24C
	};
	static_assert(sizeof(BShkbAnimationGraph) == 0x250);
}
