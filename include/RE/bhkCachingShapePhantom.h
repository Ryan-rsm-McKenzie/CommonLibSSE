#pragma once

#include "RE/bhkShapePhantom.h"  // bhkShapePhantom


namespace RE
{
	class bhkCachingShapePhantom : public bhkShapePhantom
	{
	public:
		virtual ~bhkCachingShapePhantom();										// 00

		// override (bhkShapePhantom)
		virtual NiRTTI*		GetRTTI() override;									// 02
		virtual NiObject*	CreateClone(NiCloningProcess a_cloner) override;	// 17
	};
	STATIC_ASSERT(sizeof(bhkCachingShapePhantom) == 0x30);
}
