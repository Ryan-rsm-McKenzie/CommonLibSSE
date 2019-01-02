#pragma once

#include "RE/hkReferencedObject.h"  // hkReferencedObject


namespace RE
{
	class hkpConstraintOwner : public hkReferencedObject
	{
	public:
		virtual ~hkpConstraintOwner();	// 00

		// add
		virtual void	Unk_03(void);	// 03 - {}
		virtual void	Unk_04(void);	// 04 - {}
		virtual void	Unk_05(void);	// 05 - {}
		virtual void	Unk_06(void);	// 06 - {}


		// members
		UInt64	unk10;	// 10
		UInt64	unk18;	// 18
	};
	STATIC_ASSERT(sizeof(hkpConstraintOwner) == 0x20);
}
