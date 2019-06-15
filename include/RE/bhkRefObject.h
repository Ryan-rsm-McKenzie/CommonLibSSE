#pragma once

#include "skse64/GameRTTI.h"  // RTTI_bhkRefObject

#include "RE/NiObject.h" // NiObject


namespace RE
{
	class hkReferencedObject;


	class bhkRefObject : public NiObject
	{
	public:
		inline static const void* RTTI = RTTI_bhkRefObject;


		virtual ~bhkRefObject();			// 00

		// override(NiObject)
		virtual NiRTTI*	GetRTTI() override;	// 02

		// add
		virtual void	Unk_25(void);		// 25
		virtual void	Unk_26(void);		// 26


		// members
		hkReferencedObject* referencedObject;	// 10
	};
	STATIC_ASSERT(sizeof(bhkRefObject) == 0x18);
}
