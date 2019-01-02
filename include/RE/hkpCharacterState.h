#pragma once

#include "RE/hkReferencedObject.h"  // hkReferencedObject


namespace RE
{
	class hkpCharacterState : public hkReferencedObject
	{
	public:
		virtual ~hkpCharacterState();	// 00

		// add
		virtual void	Unk_03(void);	// 03 - pure
		virtual void	Unk_04(void);	// 04 - { return 0; }
		virtual void	Unk_05(void);	// 05 - { return 0; }
		virtual void	Unk_06(void);	// 06 - pure
		virtual void	Unk_07(void);	// 07 - pure
	};
	STATIC_ASSERT(sizeof(hkpCharacterState) == 0x10);
}
