#pragma once

#include "RE/hkpMotion.h"  // hkpMotion


namespace RE
{
	class hkpKeyframedRigidMotion : public hkpMotion
	{
	public:
		virtual ~hkpKeyframedRigidMotion();	// 00

		// add
		virtual void	Unk_1A(void);		// 1A - { return 0; }
		virtual void	Unk_1B(void);		// 1B
	};
	STATIC_ASSERT(sizeof(hkpKeyframedRigidMotion) == 0x140);
}
