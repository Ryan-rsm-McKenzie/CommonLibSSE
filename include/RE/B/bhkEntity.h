#pragma once

#include "RE/B/bhkWorldObject.h"

namespace RE
{
	class bhkEntity : public bhkWorldObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkEntity;
		inline static constexpr auto Ni_RTTI = NiRTTI_bhkEntity;

		~bhkEntity() override;  // 00

		// override (bhkEntity)
		const NiRTTI* GetRTTI() const override;                 // 02
		void          LoadBinary(NiStream& a_stream) override;  // 18
		void          SaveBinary(NiStream& a_stream) override;  // 1B
		void          Unk_2A(void) override;                    // 2A
		void          Unk_30(void) override;                    // 30
	};
	static_assert(sizeof(bhkEntity) == 0x28);
}
