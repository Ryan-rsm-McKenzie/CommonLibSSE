#pragma once

#include "RE/bhkShape.h"  // bhkShape


namespace RE
{
	class bhkShapeCollection : public bhkShape
	{
	public:
		virtual ~bhkShapeCollection();		// 00

		// override (bhkShape)
		virtual NiRTTI*	GetRTTI() override;	// 02

		// add
		virtual void	Unk_36(void);		// 36 - pure
	};
	STATIC_ASSERT(sizeof(bhkShapeCollection) == 0x28);
}
