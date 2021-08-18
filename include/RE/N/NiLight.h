#pragma once

#include "RE/N/NiAVObject.h"

#include "RE/N/NiColor.h"

namespace RE
{
	class NiLight : public NiAVObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiLight;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiLight;

		virtual ~NiLight();  // 00

		// override (NiAVObject)
		virtual const NiRTTI* GetRTTI() const override;                 // 02
		virtual void          LoadBinary(NiStream& a_stream) override;  // 18
		virtual void          SaveBinary(NiStream& a_stream) override;  // 1B
		virtual bool          IsEqual(NiObject* a_object) override;     // 1C

		// members
		NiColor       ambient;   // 110
		NiColor       diffuse;   // 11C
		NiColor       specular;  // 128
		float         fade;      // 134
		std::uint32_t unk138;    // 138
	};
	static_assert(sizeof(NiLight) == 0x140);
}
