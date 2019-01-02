#pragma once

#include "RE/bhkPhantom.h"  // bhkPhantom


namespace RE
{
	class bhkShapePhantom : public bhkPhantom
	{
	public:
		virtual ~bhkShapePhantom();			// 00

		// override (bhkPhantom)
		virtual NiRTTI*	GetRTTI() override;	// 02
	};
	STATIC_ASSERT(sizeof(bhkShapePhantom) == 0x30);
}
