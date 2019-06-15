#pragma once

#include "skse64/GameRTTI.h"  // RTTI_hkpCharacterStateManager

#include "RE/hkReferencedObject.h"  // hkReferencedObject
#include "RE/hkpCharacterState.h"  // hkpCharacterState, hkpCharacterStateType


namespace RE
{
	class hkpCharacterStateManager : public hkReferencedObject
	{
	public:
		inline static const void* RTTI = RTTI_hkpCharacterStateManager;


		virtual ~hkpCharacterStateManager();	// 00


		// members
		hkpCharacterState* registeredState[hkpCharacterStateType::kTotal];	// 00
	};
	STATIC_ASSERT(sizeof(hkpCharacterStateManager) == 0x68);
}
