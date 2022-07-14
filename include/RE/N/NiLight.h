#pragma once

#include "RE/N/NiAVObject.h"
#include "RE/N/NiColor.h"
#include "RE/N/NiPoint3.h"

namespace RE
{
	class NiLight : public NiAVObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiLight;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiLight;

		~NiLight() override;  // 00

		// override (NiAVObject)
		const NiRTTI* GetRTTI() const override;                 // 02
		void          LoadBinary(NiStream& a_stream) override;  // 18
		void          SaveBinary(NiStream& a_stream) override;  // 1B
		bool          IsEqual(NiObject* a_object) override;     // 1C

		// members
		NiColor       ambient;  // 110
		NiColor       diffuse;  // 11C
		NiPoint3      radius;   // 128
		float         fade;     // 134
		std::uint32_t unk138;   // 138
	};
	static_assert(sizeof(NiLight) == 0x140);
}
