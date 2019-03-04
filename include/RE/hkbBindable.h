#pragma once

#include "RE/hkReferencedObject.h"  // hkReferencedObject


namespace RE
{
	class hkbBindable : public hkReferencedObject
	{
	public:
		virtual ~hkbBindable();			// 00

		// add
		virtual void	Unk_03(void);	// 03


		// members
		UInt64	unk10;	// 10
		UInt64	unk18;	// 18
		UInt64	unk20;	// 20
		UInt64	unk28;	// 28
	};
	STATIC_ASSERT(sizeof(hkbBindable) == 0x30);
}
