#pragma once

#include "RE/hkpKeyframedRigidMotion.h"  // hkpKeyframedRigidMotion


namespace RE
{
	class hkpFixedRigidMotion : public hkpKeyframedRigidMotion
	{
	public:
		virtual ~hkpFixedRigidMotion();	// 00

		// add
		virtual void Unk_1C(void);		// 1C
	};
	STATIC_ASSERT(sizeof(hkpFixedRigidMotion) == 0x140);
}
