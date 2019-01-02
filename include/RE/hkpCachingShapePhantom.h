#pragma once

#include "RE/hkpShapePhantom.h"  // hkpShapePhantom


namespace RE
{
	class hkpCachingShapePhantom : hkpShapePhantom
	{
	public:
		virtual ~hkpCachingShapePhantom();	// 00


		// members
		UInt64	unk1A0;	// 1A0
		UInt64	unk1A8;	// 1A8
		UInt64	unk1B0;	// 1B0
		UInt64	unk1B8;	// 1B8
	};
	STATIC_ASSERT(sizeof(hkpCachingShapePhantom) == 0x1C0);
}
