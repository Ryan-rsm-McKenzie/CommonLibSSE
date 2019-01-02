#pragma once

#include "RE/hkpPhantom.h"  // hkpPhantom


namespace RE
{
	class hkpShapePhantom : public hkpPhantom
	{
	public:
		virtual ~hkpShapePhantom();	// 00

		// add
		virtual void	Unk_0F(void);	// 0F
		virtual void	Unk_10(void);	// 10
		virtual void	Unk_11(void);	// 11
		virtual void	Unk_12(void);	// 12


		// members
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
	};
	STATIC_ASSERT(sizeof(hkpShapePhantom) == 0x1A0);
}
