#pragma once

#include "RE/bhkCharacterState.h"  // bhkCharacterState


namespace RE
{
	class bhkCharacterStateJumping : public bhkCharacterState
	{
	public:
		virtual ~bhkCharacterStateJumping();	// 00
	};
	STATIC_ASSERT(sizeof(bhkCharacterStateJumping) == 0x10);
}
