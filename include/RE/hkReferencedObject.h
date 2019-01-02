#pragma once

#include "RE/hkBaseObject.h"  // hkBaseObject


namespace RE
{
	class hkReferencedObject : public hkBaseObject
	{
	public:
		virtual ~hkReferencedObject();	// 00

		// add
		virtual void	Unk_01(void);	// 01 - { return 0; }
		virtual void	Unk_02(void);	// 02


		// members
		UInt64 unk08;	// 08
	};
	STATIC_ASSERT(sizeof(hkReferencedObject) == 0x10);
}
