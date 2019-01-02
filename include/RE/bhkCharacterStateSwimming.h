#pragma once

#include "RE/bhkCharacterState.h"  // bhkCharacterState


namespace RE
{
	class bhkCharacterStateSwimming : public bhkCharacterState
	{
	public:
		virtual ~bhkCharacterStateSwimming();	// 00
	};
	STATIC_ASSERT(sizeof(bhkCharacterStateSwimming) == 0x10);
}
