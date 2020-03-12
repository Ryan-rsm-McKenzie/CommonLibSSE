#pragma once

#include "RE/hkReferencedObject.h"
#include "RE/hkpCharacterState.h"


namespace RE
{
	class hkpCharacterStateManager : public hkReferencedObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpCharacterStateManager;


		virtual ~hkpCharacterStateManager();  // 00


		// members
		hkpCharacterState* registeredState[hkpCharacterStateType::kTotal];	// 00
	};
	STATIC_ASSERT(sizeof(hkpCharacterStateManager) == 0x68);
}
