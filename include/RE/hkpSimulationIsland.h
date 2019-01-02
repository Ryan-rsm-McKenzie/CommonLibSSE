#pragma once

#include "RE/hkpConstraintOwner.h"  // hkpConstraintOwner


namespace RE
{
	class hkpSimulationIsland : public hkpConstraintOwner
	{
	public:
		virtual ~hkpSimulationIsland();	// 00


		// members
		UInt64	unk20;	// 20
		UInt64	unk28;	// 28
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
		UInt64	unk90;	// 90
		UInt64	unk98;	// 98
		UInt64	unkA0;	// A0
		UInt64	unkA8;	// A8
		UInt64	unkB0;	// B0
	};
	STATIC_ASSERT(sizeof(hkpSimulationIsland) == 0xB8);
}
