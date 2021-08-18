#pragma once

#include "RE/N/NiLight.h"

namespace RE
{
	class NiPointLight : public NiLight
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiPointLight;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiPointLight;

		~NiPointLight() override;  // 00

		// override (NiLight)
		const NiRTTI* GetRTTI() const override;                  // 02
		NiObject*     CreateClone(NiCloningProcess& a_cloning);  // 17
		void          LoadBinary(NiStream& a_stream) override;   // 18
		void          SaveBinary(NiStream& a_stream) override;   // 1B
		bool          IsEqual(NiObject* a_object) override;      // 1C

		// members
		float constAttenuation;      // 140
		float linearAttenuation;     // 144
		float quadraticAttenuation;  // 148
	};
	static_assert(sizeof(NiPointLight) == 0x150);
}
