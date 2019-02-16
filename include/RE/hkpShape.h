#pragma once

#include "RE/hkReferencedObject.h"  // hkReferencedObject


namespace RE
{
	class hkpShape : public hkReferencedObject
	{
	public:
		virtual ~hkpShape();			// 00

		// add
		virtual void	Unk_03(void);	// 03
		virtual void	Unk_04(void);	// 04 - { return 0; }
		virtual void	Unk_05(void);	// 05 - { return 0; }
		virtual void	Unk_06(void);	// 06 - { return -1; }
		virtual void	Unk_07(void);	// 07 - pure
		virtual void	Unk_08(void);	// 08 - pure
		virtual void	Unk_09(void);	// 09 - pure
		virtual void	Unk_0A(void);	// 0A


		// members
		UInt64	unk10;	// 10
		UInt64	unk18;	// 18
	};
	STATIC_ASSERT(sizeof(hkpShape) == 0x20);
}
