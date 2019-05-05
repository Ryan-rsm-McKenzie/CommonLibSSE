#pragma once

#include "RE/hkpKeyframedRigidMotion.h"  // hkpKeyframedRigidMotion


namespace RE
{
	class hkpFixedRigidMotion : public hkpKeyframedRigidMotion
	{
	public:
		virtual ~hkpFixedRigidMotion();			// 00

		// override (hkpKeyframedRigidMotion)
		virtual void	Unk_10(void) override;	// 10 - { return; }
		virtual void	Unk_11(void) override;	// 11 - { return; }
		virtual void	Unk_1A(void) override;	// 1A - { return; }

		// add
		virtual void	Unk_1C(void);			// 1C
	};
	STATIC_ASSERT(sizeof(hkpFixedRigidMotion) == 0x140);
}
