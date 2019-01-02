#pragma once

#include "RE/bhkCharacterState.h"  // bhkCharacterState


namespace RE
{
	class bhkCharacterStateOnGround : public bhkCharacterState
	{
	public:
		virtual ~bhkCharacterStateOnGround();	// 00


		// members
		UInt64 unk10;	// 10
	};
	STATIC_ASSERT(sizeof(bhkCharacterStateOnGround) == 0x18);
}
