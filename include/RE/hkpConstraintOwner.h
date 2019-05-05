#pragma once

#include "RE/hkReferencedObject.h"  // hkReferencedObject


namespace RE
{
	class hkpConstraintOwner : public hkReferencedObject
	{
	public:
		virtual ~hkpConstraintOwner();	// 00

		// add
		virtual void	Unk_03(void);	// 03 - { return; }
		virtual void	Unk_04(void);	// 04 - { return; }
		virtual void	Unk_05(void);	// 05 - { return; }
		virtual void	Unk_06(void);	// 06 - { return; }


		// members
		UInt64	unk10;	// 10
		UInt64	unk18;	// 18
	};
	STATIC_ASSERT(sizeof(hkpConstraintOwner) == 0x20);
}
