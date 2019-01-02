#pragma once

#include "RE/bhkCharacterState.h"  // bhkCharacterState


namespace RE
{
	class bhkCharacterStateInAir : public bhkCharacterState
	{
	public:
		virtual ~bhkCharacterStateInAir();	// 00


		// members
		UInt64 unk10;	// 10
	};
	STATIC_ASSERT(sizeof(bhkCharacterStateInAir) == 0x18);
}
