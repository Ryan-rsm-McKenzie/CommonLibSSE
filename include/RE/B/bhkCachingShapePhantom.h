#pragma once

#include "RE/B/bhkShapePhantom.h"

namespace RE
{
	class bhkCachingShapePhantom : public bhkShapePhantom
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkCachingShapePhantom;
		inline static constexpr auto Ni_RTTI = NiRTTI_bhkCachingShapePhantom;

		virtual ~bhkCachingShapePhantom();	// 00

		// override (bhkShapePhantom)
		virtual const NiRTTI* GetRTTI() const override;							  // 02
		virtual NiObject*	  CreateClone(NiCloningProcess& a_cloning) override;  // 17
		virtual void		  Unk_2B(void) override;							  // 2B
		virtual void		  Unk_2C(void) override;							  // 2C - { return 112; }
		virtual void		  Unk_2E(void) override;							  // 2E
		virtual void		  Unk_2F(void) override;							  // 2F
	};
	static_assert(sizeof(bhkCachingShapePhantom) == 0x30);
}
