#pragma once

#include "RE/hkReferencedObject.h"  // hkReferencedObject


namespace RE
{
	class hkpCharacterStateManager;


	class hkpCharacterContext : public hkReferencedObject
	{
	public:
		virtual ~hkpCharacterContext();	// 00


		// members
		UInt64						unk10;					// 10
		hkpCharacterStateManager*	characterStateManager;	// 18
		UInt64						unk20;					// 20
		UInt64						unk28;					// 28
		float						unk30;					// 30
		float						unk34;					// 34
	};
	STATIC_ASSERT(sizeof(hkpCharacterContext) == 0x38);
}
