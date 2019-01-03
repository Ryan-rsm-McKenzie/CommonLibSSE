#pragma once

#include "RE/BSShader.h"  // BSShader
#include "RE/ImageSpaceEffect.h"  // ImageSpaceEffect


namespace RE
{
	class BSImagespaceShader :
		public BSShader,		// 000
		public ImageSpaceEffect	// 090
	{
	public:
		virtual ~BSImagespaceShader();	// 00

		// add
		virtual void	Unk_0A(void);	// 0A - {}
		virtual void	Unk_0B(void);	// 0B - {}
		virtual void	Unk_0C(void);	// 0C
		virtual void	Unk_0D(void);	// 0D
		virtual void	Unk_0E(void);	// 0E


		// members
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
		UInt64	unk1A0;	// 1A0
	};
	STATIC_ASSERT(sizeof(BSImagespaceShader) == 0x1A8);
}
