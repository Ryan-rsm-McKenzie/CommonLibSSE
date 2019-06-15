#pragma once

#include "skse64/GameRTTI.h"  // RTTI_bhkShapeCollection

#include "RE/bhkShape.h"  // bhkShape


namespace RE
{
	class bhkShapeCollection : public bhkShape
	{
	public:
		inline static const void* RTTI = RTTI_bhkShapeCollection;


		virtual ~bhkShapeCollection();		// 00

		// override (bhkShape)
		virtual NiRTTI*	GetRTTI() override;	// 02

		// add
		virtual void	Unk_36(void);		// 36 - pure
	};
	STATIC_ASSERT(sizeof(bhkShapeCollection) == 0x28);
}
