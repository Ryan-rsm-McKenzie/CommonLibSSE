#pragma once

#include "RE/B/bhkShape.h"

namespace RE
{
	class bhkShapeCollection : public bhkShape
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkShapeCollection;
		inline static constexpr auto Ni_RTTI = NiRTTI_bhkShapeCollection;

		~bhkShapeCollection() override;  // 00

		// override (bhkShape)
		const NiRTTI* GetRTTI() const override;  // 02
		void          Unk_34(void) override;     // 34 - { return this; }
		void          Unk_35(void) override;     // 35

		// add
		virtual void Unk_36(void) = 0;  // 36
	};
	static_assert(sizeof(bhkShapeCollection) == 0x28);
}
