#pragma once

#include "RE/B/bhkShapePhantom.h"

namespace RE
{
	class bhkCachingShapePhantom : public bhkShapePhantom
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkCachingShapePhantom;
		inline static constexpr auto Ni_RTTI = NiRTTI_bhkCachingShapePhantom;

		~bhkCachingShapePhantom() override;  // 00

		// override (bhkShapePhantom)
		const NiRTTI* GetRTTI() const override;                           // 02
		NiObject*     CreateClone(NiCloningProcess& a_cloning) override;  // 17
		void          Unk_2B(void) override;                              // 2B
		void          Unk_2C(void) override;                              // 2C - { return 112; }
		void          Unk_2E(void) override;                              // 2E
		void          Unk_2F(void) override;                              // 2F
	};
	static_assert(sizeof(bhkCachingShapePhantom) == 0x30);
}
