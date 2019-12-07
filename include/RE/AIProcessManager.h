#pragma once

#include "RE/BSTArray.h"
#include "RE/BSTSingleton.h"


namespace RE
{
	class AIProcessManager : public BSTSingletonSDM<AIProcessManager>
	{
	public:
		// members
		UInt8					unk001;							// 001
		UInt8					unk002;							// 002
		UInt8					pad003;							// 003
		UInt32					unk004;							// 004
		UInt32					unk008;							// 008
		UInt16					unk00C;							// 00C
		UInt8					unk00E;							// 00E
		UInt8					pad00F;							// 00F
		UInt64					unk010;							// 010
		UInt32					unk018;							// 018
		float					removeExcessComplexDeadTime;	// 01C
		HANDLE					semaphore;						// 020
		UInt32					unk028;							// 028
		UInt32					pad02C;							// 02C
		BSTArray<RefHandle>		unk030;							// 030
		BSTArray<void*>			unk048;							// 048
		BSTArray<void*>			unk060;							// 060
		BSTArray<void*>			unk078;							// 078
		BSTArray<RefHandle>*	unk090;							// 090 - ptr to unk030
		BSTArray<void*>*		unk098;							// 098 - ptr to unk060
		BSTArray<void*>*		unk0A0;							// 0A0 - ptr to unk078
		BSTArray<void*>*		unk0A8;							// 0A8 - ptr to unk048
		UInt64					unk0B0;							// 0B0
		UInt64					unk0B8;							// 0B8
		UInt64					unk0C0;							// 0C0
		UInt64					unk0C8;							// 0C8
		UInt64					unk0D0;							// 0D0
		UInt64					unk0D8;							// 0D8
		UInt64					unk0E0;							// 0E0
		BSTArray<void*>			unk0E8;							// 0E8
		UInt64					unk100;							// 100
		BSTArray<void*>			unk108;							// 108
		UInt64					unk120;							// 120
		BSTArray<void*>			unk128;							// 128
		UInt64					unk140;							// 140
		UInt64					unk148;							// 148
		UInt64					unk150;							// 150
		BSTArray<RefHandle>		unk158;							// 158
		UInt32					unk170;							// 170
		UInt32					pad174;							// 174
		UInt64					unk178;							// 178
		BSTArray<void*>			unk180;							// 180
		mutable BSUniqueLock	unk198;							// 198
		BSTArray<void*>			unk1A0;							// 1A0
		BSTArray<void*>			unk1B8;							// 1B8
		float					unk1D0;							// 1D0
		float					unk1D4;							// 1D4
		UInt64					unk1D8;							// 1D8
		UInt32					unk1E0;							// 1E0
		UInt8					unk1E4;							// 1E4
		UInt8					unk1E5;							// 1E5
		UInt8					unk1E6;							// 1E6
		UInt8					unk1E7;							// 1E7
		UInt64					unk1E8;							// 1E8
	};
	STATIC_ASSERT(sizeof(AIProcessManager) == 0x1F0);
}

