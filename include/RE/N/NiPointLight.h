#pragma once

#include "RE/N/NiLight.h"

namespace RE
{
	class NiPointLight : public NiLight
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiPointLight;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiPointLight;

		virtual ~NiPointLight();  // 00

		// override (NiLight)
		virtual const NiRTTI* GetRTTI() const override;                  // 02
		virtual NiObject*     CreateClone(NiCloningProcess& a_cloning);  // 17
		virtual void          LoadBinary(NiStream& a_stream) override;   // 18
		virtual void          SaveBinary(NiStream& a_stream) override;   // 1B
		virtual bool          IsEqual(NiObject* a_object) override;      // 1C

		// members
		float constAttenuation;      // 140
		float linearAttenuation;     // 144
		float quadraticAttenuation;  // 148
	};
	static_assert(sizeof(NiPointLight) == 0x150);
}
