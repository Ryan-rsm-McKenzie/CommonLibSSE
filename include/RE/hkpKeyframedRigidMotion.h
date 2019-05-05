#pragma once

#include "RE/hkpMotion.h"  // hkpMotion


namespace RE
{
	class hkpKeyframedRigidMotion : public hkpMotion
	{
	public:
		virtual ~hkpKeyframedRigidMotion();		// 00

		// override (hkpMotion)
		virtual void	Unk_03(void) override;	// 03 - { return; }
		virtual void	Unk_04(void) override;	// 04 - { return; }
		virtual void	Unk_05(void) override;	// 05
		virtual void	Unk_06(void) override;	// 06
		virtual void	Unk_07(void) override;	// 07 - { return; }
		virtual void	Unk_08(void) override;	// 08 - { return; }
		virtual void	Unk_09(void) override;	// 09
		virtual void	Unk_0A(void) override;	// 0A
		virtual void	Unk_12(void) override;	// 12
		virtual void	Unk_13(void) override;	// 13 - { return; }
		virtual void	Unk_14(void) override;	// 14 - { return; }
		virtual void	Unk_15(void) override;	// 15 - { return; }
		virtual void	Unk_16(void) override;	// 16 - { return; }
		virtual void	Unk_17(void) override;	// 17 - { return; }
		virtual void	Unk_18(void) override;	// 18 - { return; }

		// add
		virtual void	Unk_1A(void);			// 1A - { return; }
		virtual void	Unk_1B(void);			// 1B
	};
	STATIC_ASSERT(sizeof(hkpKeyframedRigidMotion) == 0x140);
}
