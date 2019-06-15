#pragma once

#include "skse64/GameRTTI.h"  // RTTI_bhkShapePhantom

#include "RE/bhkPhantom.h"  // bhkPhantom


namespace RE
{
	class bhkShapePhantom : public bhkPhantom
	{
	public:
		inline static const void* RTTI = RTTI_bhkShapePhantom;


		virtual ~bhkShapePhantom();			// 00

		// override (bhkPhantom)
		virtual NiRTTI*	GetRTTI() override;	// 02
	};
	STATIC_ASSERT(sizeof(bhkShapePhantom) == 0x30);
}
