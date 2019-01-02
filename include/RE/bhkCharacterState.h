#pragma once

#include "RE/hkpCharacterState.h"  // hkpCharacterState


namespace RE
{
	class bhkCharacterState : public hkpCharacterState
	{
	public:
		virtual ~bhkCharacterState();	// 00

		// add
		virtual void Unk_08(void);		// 08 - pure
	};
	STATIC_ASSERT(sizeof(bhkCharacterState) == 0x10);
}
