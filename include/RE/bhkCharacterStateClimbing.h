#pragma once

#include "RE/bhkCharacterState.h"  // bhkCharacterState


namespace RE
{
	class bhkCharacterStateClimbing : public bhkCharacterState
	{
	public:
		virtual ~bhkCharacterStateClimbing();	// 00
	};
	STATIC_ASSERT(sizeof(bhkCharacterStateClimbing) == 0x10);
}
