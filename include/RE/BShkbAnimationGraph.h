#pragma once

#include "RE/BSAnimationGraphEvent.h"  // BSAnimationGraphEvent
#include "RE/BSIRagdollDriver.h"  // BSIRagdollDriver
#include "RE/BSTEvent.h"  // BSTEventSource


namespace RE
{
	class BSTransformDeltaEvent;


	class BShkbAnimationGraph :
		public BSIRagdollDriver,						// 000
		public BSTEventSource<BSTransformDeltaEvent>,	// 010
		public BSTEventSource<BSAnimationGraphEvent>	// 068
	{
	public:
		virtual ~BShkbAnimationGraph();	// 00

		BSTEventSource<BSTransformDeltaEvent>*	GetBSTransformDeltaEventSource();
		BSTEventSource<BSAnimationGraphEvent>*	GetBSAnimationGraphEventSource();


		// members
		UInt64	unk0C0;	// 0C0
		UInt64	unk0C8;	// 0C8
		UInt64	unk0D0;	// 0D0
		UInt64	unk0D8;	// 0D8
		UInt64	unk0E0;	// 0E0
		UInt64	unk0E8;	// 0E8
		UInt64	unk0F0;	// 0F0
		UInt64	unk0F8;	// 0F8
		UInt64	unk100;	// 100
		UInt64	unk108;	// 108
		UInt64	unk110;	// 110
		UInt64	unk118;	// 118
		UInt64	unk120;	// 120
		UInt64	unk128;	// 128
		UInt64	unk130;	// 130
		UInt64	unk138;	// 138
		UInt64	unk140;	// 140
		UInt64	unk148;	// 148
		UInt64	unk150;	// 150
		UInt64	unk158;	// 158
		UInt64	unk160;	// 160
		UInt64	unk168;	// 168
		UInt64	unk170;	// 170
		UInt64	unk178;	// 178
		UInt64	unk180;	// 180
		UInt64	unk188;	// 188
		UInt64	unk190;	// 190
		UInt64	unk198;	// 198
		UInt64	unk1A0;	// 1A0
		UInt64	unk1A8;	// 1A8
		UInt64	unk1B0;	// 1B0
		UInt64	unk1B8;	// 1B8
		UInt64	unk1C0;	// 1C0
		UInt64	unk1C8;	// 1C8
		UInt64	unk1D0;	// 1D0
		UInt64	unk1D8;	// 1D8
		UInt64	unk1E0;	// 1E0
		UInt64	unk1E8;	// 1E8
		UInt64	unk1F0;	// 1F0
		UInt64	unk1F8;	// 1F8
		UInt64	unk200;	// 200
		UInt64	unk208;	// 208
		UInt64	unk210;	// 210
		UInt64	unk218;	// 218
		UInt64	unk220;	// 220
		UInt64	unk228;	// 228
		UInt64	unk230;	// 230
		UInt64	unk238;	// 238
		UInt64	unk240;	// 240
		UInt64	unk248;	// 248
	};
	STATIC_ASSERT(sizeof(BShkbAnimationGraph) == 0x250);
}
