#pragma once

#include "RE/BSLock.h"  // BSUniqueLock


namespace RE
{
	class TESPackage;


	class PackageData
	{
	public:
		// members
		mutable BSUniqueLock	lock;		// 00
		TESPackage*				package;	// 08
		void*					unk10;		// 10
		float					timer;		// 18
		UInt32					unk1C;		// 1C
		float					unk20;		// 20
		UInt32					unk24;		// 24
		UInt16					unk28;		// 28
		UInt8					unk2A;		// 2A
		UInt8					unk2B;		// 2B
		UInt32					pad2C;		// 2C
	};
	STATIC_ASSERT(sizeof(PackageData) == 0x30);
}
