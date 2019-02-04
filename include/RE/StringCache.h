#pragma once

#include "RE/BSSpinLock.h"  // BSSpinLock


namespace RE
{
	// 80808
	class StringCache
	{
	public:
		struct Entry
		{
			union State
			{
				struct
				{
					UInt16	refCount;	// invalid if 0x8000 is set
					UInt16	hash;
				};
				UInt32	refCountAndHash;
			};
			STATIC_ASSERT(sizeof(State) == 0x4);


			void*	next;		// 00
			State	state;		// 08
			UInt32	pad0C;		// 0C
			UInt32	length;		// 10
			UInt32	pad14;		// 14
			char	data[1];	// 18
		};
		STATIC_ASSERT(sizeof(Entry) == 0x20);


		// 10
		struct Lock
		{
			BSSpinLock	lock;	// 00
			UInt64		unk08;	// 08
		};
		STATIC_ASSERT(sizeof(Lock) == 0x10);


		// members
		Entry*	table[0x10000];	// 00000
		Lock	locks[0x80];	// 80000
		UInt8	isInit;			// 80800
	};
	STATIC_ASSERT(sizeof(StringCache) == 0x80808);
}
