#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BShkbAnimationGraph

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSIntrusiveRefCounted.h"  // BSIntrusiveRefCounted
#include "RE/BSIRagdollDriver.h"  // BSIRagdollDriver
#include "RE/BSTArray.h"  // BSTArray
#include "RE/BSTEvent.h"  // BSTEventSource
#include "RE/BSTSmartPointer.h"  // BSSmartPointer
#include "RE/FileHash.h"  // FileHash
#include "RE/hkbCharacter.h"  // hkbCharacter


namespace RE
{
	class bhkWorld;
	class BSFadeNode;
	class BShkFloatController;
	class BSTransformDeltaEvent;
	class hkbBehaviorGraph;
	struct BSAnimationGraphEvent;


	BSSmartPointer(BShkbAnimationGraph);


	class BShkbAnimationGraph :
		public BSIRagdollDriver,						// 000
		public BSIntrusiveRefCounted,					// 008
		public BSTEventSource<BSTransformDeltaEvent>,	// 010
		public BSTEventSource<BSAnimationGraphEvent>	// 068
	{
	public:
		inline static const void* RTTI = RTTI_BShkbAnimationGraph;


		virtual ~BShkbAnimationGraph();							// 00

		// override (BSIRagdollDriver)
		virtual void	Unk_01(void) override;					// 01
		virtual void	Unk_02(void) override;					// 02
		virtual void	Unk_03(void) override;					// 03
		virtual void	SetWorld(bhkWorld* a_world) override;	// 04 - { world = a_world; }
		virtual void	Unk_05(void) override;					// 05
		virtual void	Unk_06(void) override;					// 06
		virtual void	Unk_07(void) override;					// 07
		virtual void	Unk_08(void) override;					// 08
		virtual void	Unk_09(void) override;					// 09
		virtual void	Unk_0A(void) override;					// 0A
		virtual void	Unk_0B(void) override;					// 0B
		virtual void	Unk_0C(void) override;					// 0C
		virtual void	Unk_0D(void) override;					// 0D

		BSTEventSource<BSTransformDeltaEvent>*	GetBSTransformDeltaEventSource();
		BSTEventSource<BSAnimationGraphEvent>*	GetBSAnimationGraphEventSource();


		// members
		hkbCharacter					unk0C0;			// 0C0
		BSTArray<void*>					unk160;			// 160
		BSTArray<BShkFloatController*>	unk178;			// 178
		BSTArray<void*>					unk190;			// 190
		UInt64							unk1A8;			// 1A8
		UInt64							unk1B0;			// 1B0
		UInt64							unk1B8;			// 1B8
		BSTSmallArray<UInt8>			unk1C0;			// 1C0
		UInt64							unk1D8;			// 1D8
		UInt64							unk1E0;			// 1E0
		UInt64							unk1E8;			// 1E8
		BSFixedString					unk1F0;			// 1F0
		FileHash*						unk1F8;			// 1F8
		void*							unk200;			// 200 - BShkbHkxDB::ProjectDBData*
		hkbBehaviorGraph*				behaviourGraph;	// 208
		UInt64							unk210;			// 210
		BSFadeNode*						unk218;			// 218
		UInt64							unk220;			// 220
		UInt64							unk228;			// 228
		UInt64							unk230;			// 230
		bhkWorld*						world;			// 238
		UInt64							unk240;			// 240
		UInt64							unk248;			// 248
	};
	STATIC_ASSERT(sizeof(BShkbAnimationGraph) == 0x250);
}
