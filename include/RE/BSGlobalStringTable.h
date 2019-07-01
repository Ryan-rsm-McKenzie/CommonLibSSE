#pragma once

#include "RE/BSSpinLock.h"  // BSSpinLock


namespace RE
{
	using GlobalStringHandle = char*;


	class BSGlobalStringTable
	{
	public:
		struct Entry
		{
			enum
			{
				kLengthMask = 0xFFFFFF
			};


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


			Entry*	next;		// 00
			State	state;		// 08
			UInt32	unk0C;		// 0C
			UInt64	length;		// 10
			char	data[1];	// 18
		};
		STATIC_ASSERT(sizeof(Entry) == 0x20);


		struct Lock
		{
			BSSpinLock	lock;	// 00
			UInt64		unk08;	// 08
		};
		STATIC_ASSERT(sizeof(Lock) == 0x10);


		// members
		Entry*	table[0x10000];	// 00000
		Lock	locks[0x80];	// 80000
		bool	isInit;			// 80800
		UInt8	pad80801;		// 80801
		UInt16	pad80802;		// 80802
		UInt32	pad80804;		// 80804
	};
	STATIC_ASSERT(sizeof(BSGlobalStringTable) == 0x80808);
}
