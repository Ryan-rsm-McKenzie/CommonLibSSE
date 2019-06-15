#pragma once

#include "skse64/GameRTTI.h"  // RTTI_bhkPhantom

#include "RE/bhkWorldObject.h"  // bhkWorldObject


namespace RE
{
	class bhkPhantom : public bhkWorldObject
	{
	public:
		inline static const void* RTTI = RTTI_bhkPhantom;


		virtual ~bhkPhantom();				// 00

		// override (bhkWorldObject)
		virtual NiRTTI*	GetRTTI() override;	// 02


		// members
		UInt64 unk28;	// 28
	};
	STATIC_ASSERT(sizeof(bhkPhantom) == 0x30);
}
