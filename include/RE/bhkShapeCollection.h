#pragma once

#include "skse64/GameRTTI.h"  // RTTI_bhkShapeCollection

#include "RE/bhkShape.h"  // bhkShape


namespace RE
{
	class bhkShapeCollection : public bhkShape
	{
	public:
		inline static const void* RTTI = RTTI_bhkShapeCollection;


		virtual ~bhkShapeCollection();						// 00

		// override (bhkShape)
		virtual const NiRTTI*	GetRTTI() const override;	// 02
		virtual void			Unk_34(void) override;		// 34 - { return this; }
		virtual void			Unk_35(void) override;		// 35

		// add
		virtual void			Unk_36(void) = 0;			// 36
	};
	STATIC_ASSERT(sizeof(bhkShapeCollection) == 0x28);
}
