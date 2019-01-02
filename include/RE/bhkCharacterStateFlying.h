#pragma once

#include "RE/bhkCharacterState.h"  // bhkCharacterState


namespace RE
{
	class bhkCharacterStateFlying : public bhkCharacterState
	{
	public:
		virtual ~bhkCharacterStateFlying();	// 00
	};
	STATIC_ASSERT(sizeof(bhkCharacterStateFlying) == 0x10);
}
