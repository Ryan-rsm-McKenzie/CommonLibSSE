#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSThread


namespace RE
{
	class BSThread
	{
	public:
		inline static const void* RTTI = RTTI_BSThread;


		virtual ~BSThread();			// 00

		// add
		virtual void	Unk_01(void);	// 01 - { return 0; }
		virtual void	Unk_02(void);	// 02 - { return; }


		// members
		CRITICAL_SECTION	lock;			// 08
		HANDLE				thread;			// 30
		HANDLE				ownerThread;	// 38
		UInt32				threadID;		// 40
		UInt32				ownerThreadID;	// 44
		bool				initialized;	// 48
		UInt8				pad49;			// 49
		UInt16				pad4A;			// 4A
		UInt32				pad4C;			// 4C
	};
	STATIC_ASSERT(sizeof(BSThread) == 0x50);
}
