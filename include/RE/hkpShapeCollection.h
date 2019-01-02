#pragma once

#include "RE/hkpShape.h"  // hkpShape
#include "RE/hkpShapeContainer.h"  // hkpShapeContainer


namespace RE
{
	class hkpShapeCollection :
		public hkpShape,			// 00
		public hkpShapeContainer,	// 20
	{
	public:
		virtual ~hkpShapeCollection();	// 00

		// add
		virtual void	Unk_0B(void);	// 0B - { return 0; }
		virtual void	Unk_0C(void);	// 0C - { return 0; }


		// members
		UInt64 unk28;	// 28
	};
	STATIC_ASSERT(sizeof(hkpShapeCollection) == 0x30);
}
