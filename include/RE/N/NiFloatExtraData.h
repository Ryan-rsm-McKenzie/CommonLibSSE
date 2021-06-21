#pragma once

#include "RE/N/NiExtraData.h"

namespace RE
{
	class NiFloatExtraData : public NiExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiFloatExtraData;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiFloatExtraData;
		inline static constexpr auto VTABLE = VTABLE_NiFloatExtraData;

		virtual ~NiFloatExtraData();  // 00

		// override (NiExtraData)
		virtual const NiRTTI* GetRTTI() const override;                           // 02
		virtual NiObject*     CreateClone(NiCloningProcess& a_cloning) override;  // 17
		virtual void          LoadBinary(NiStream& a_stream) override;            // 18
		virtual void          LinkObject(NiStream& a_stream) override;            // 19 - { NiExtraData::LinkObject(a_stream); }
		virtual bool          RegisterStreamables(NiStream& a_stream) override;   // 1A - { return NiExtraData::RegisterStreamables(a_stream); }
		virtual void          SaveBinary(NiStream& a_stream) override;            // 1B
		virtual bool          IsEqual(NiObject* a_object) override;               // 1C

		static NiFloatExtraData* Create(const BSFixedString& a_name, float a_value);

		// members
		float data;  // 18
	};
	static_assert(sizeof(NiFloatExtraData) == 0x20);
}
