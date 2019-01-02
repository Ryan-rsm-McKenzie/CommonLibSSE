#pragma once

#include "RE/hkpWorldObject.h"  // hkpWorldObject


namespace RE
{
	class hkpPhantom : public hkpWorldObject
	{
	public:
		virtual ~hkpPhantom();			// 00

		// add
		virtual void	Unk_06(void);	// 06 - pure
		virtual void	Unk_07(void);	// 07 - pure
		virtual void	Unk_08(void);	// 08 - pure
		virtual void	Unk_09(void);	// 09 - pure
		virtual void	Unk_0A(void);	// 0A - pure
		virtual void	Unk_0B(void);	// 0B - pure
		virtual void	Unk_0C(void);	// 0C - pure
		virtual void	Unk_0D(void);	// 0D - {}
		virtual void	Unk_0E(void);	// 0E - { return 0; }


		// members
		UInt64	unkD0;	// D0
		UInt64	unkD8;	// D8
		UInt64	unkE0;	// E0
		UInt64	unkE8;	// E8
	};
	STATIC_ASSERT(sizeof(hkpPhantom) == 0xF0);
}
