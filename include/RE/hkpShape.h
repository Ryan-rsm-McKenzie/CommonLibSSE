#pragma once

#include "RE/hkReferencedObject.h"  // hkReferencedObject


namespace RE
{
	using hkpShapeKey = UInt32;


	class hkpShape : public hkReferencedObject
	{
	public:
		virtual ~hkpShape();				// 00

		// add
		virtual void	Unk_03(void);		// 03
		virtual void	Unk_04(void);		// 04 - { return 0; }
		virtual void	Unk_05(void);		// 05 - { return 0; }
		virtual void	Unk_06(void);		// 06 - { return -1; }
		virtual void	Unk_07(void) = 0;	// 07
		virtual void	Unk_08(void) = 0;	// 08
		virtual void	Unk_09(void) = 0;	// 09
		virtual void	Unk_0A(void);		// 0A


		// members
		UInt64	unk10;	// 10
		UInt64	unk18;	// 18
	};
	STATIC_ASSERT(sizeof(hkpShape) == 0x20);
}
