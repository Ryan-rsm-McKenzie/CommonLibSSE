#pragma once

#include "RE/hkpShapeCollection.h"  // hkpShapeCollection


namespace RE
{
	class hkpListShape : public hkpShapeCollection
	{
	public:
		virtual ~hkpListShape();	// 00


		// members
		UInt64	unk30;	// 30
		UInt64	unk38;	// 38
		UInt64	unk40;	// 40
		UInt64	unk48;	// 48
		UInt64	unk50;	// 50
		UInt64	unk58;	// 58
		UInt64	unk60;	// 60
		UInt64	unk68;	// 68
		UInt64	unk70;	// 70
		UInt64	unk78;	// 78
		UInt64	unk80;	// 80
		UInt64	unk88;	// 88
	};
	STATIC_ASSERT(sizeof(hkpListShape) == 0x90);
}
