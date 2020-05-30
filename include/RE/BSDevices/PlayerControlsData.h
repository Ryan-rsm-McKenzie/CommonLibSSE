#pragma once

#include "RE/NiPoint2.h"


namespace RE
{
	class PlayerControlsData
	{
	public:
		// members
		NiPoint2 moveInputVec;	 // 00
		NiPoint2 lookInputVec;	 // 08
		NiPoint2 prevMoveVec;	 // 10
		NiPoint2 prevLookVec;	 // 18
		UInt32	 unk20;			 // 20
		bool	 autoMove;		 // 24
		bool	 running;		 // 25
		UInt8	 unk26;			 // 26
		bool	 fovSlideMode;	 // 27
		bool	 povScriptMode;	 // 28
		bool	 povBeastMode;	 // 29
		UInt8	 unk2A;			 // 2A
		UInt8	 unk2B;			 // 2B
		bool	 remapMode;		 // 2C
		UInt8	 unk2D;			 // 2D
		UInt16	 unk2E;			 // 2E
	};
	STATIC_ASSERT(sizeof(PlayerControlsData) == 0x30);
}
