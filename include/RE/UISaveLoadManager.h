#pragma once

#include "RE/BSFixedString.h"  // BSFixedString

class NiSourceTexture;


namespace RE
{
	class UISaveLoadManager
	{
	public:
		enum State : UInt64
		{
			kState_Load = 0x8,
			kState_Save = 0x9
		};


		void*				unk08;		// 08 - singleton
		UInt64				unk10;		// 10
		NiSourceTexture*	texture;	// 18
		UInt64				unk20;		// 20
		UInt64				unk28;		// 28
		void*				unk30;		// 30
		UInt64				unk38;		// 38 - 0x47
		void*				unk40;		// 40
		BSFixedString		menuName;	// 48 - "Journal Menu"
		State				state;		// 50
		UInt32				time;		// 58 - some timer in ms
		UInt32				unk5C;		// 5C
		UInt64				unk60;		// 60 - 0xB - numArgs?
		UInt64				unk68;		// 68
	};
	STATIC_ASSERT(sizeof(UISaveLoadManager) == 0x68);
}
