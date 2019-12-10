#pragma once

#include "RE/BSIntrusiveRefCounted.h"


namespace RE
{
	class SyncQueueObj : public BSIntrusiveRefCounted
	{
	public:
		inline static const void* RTTI = RTTI_SyncQueueObj;


		virtual ~SyncQueueObj();		// 00

		// add
		virtual void Unk_01(void) = 0;	// 01


		// members
		UInt32 unk0C;	// 0C
	};
	STATIC_ASSERT(sizeof(SyncQueueObj) == 0x10);
}
