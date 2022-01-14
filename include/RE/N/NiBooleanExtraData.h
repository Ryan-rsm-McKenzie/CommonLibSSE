#pragma once

#include "RE/N/NiExtraData.h"

namespace RE
{
	class NiBooleanExtraData : public NiExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiBooleanExtraData;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiBooleanExtraData;
		inline static constexpr auto VTABLE = VTABLE_NiBooleanExtraData;

		~NiBooleanExtraData() override;  // 00

		// override (NiExtraData)
		const NiRTTI* GetRTTI() const override;                           // 02
		NiObject*     CreateClone(NiCloningProcess& a_cloning) override;  // 17
		void          LoadBinary(NiStream& a_stream) override;            // 18
		void          LinkObject(NiStream& a_stream) override;            // 19 - { NiExtraData::LinkObject(a_stream); }
		bool          RegisterStreamables(NiStream& a_stream) override;   // 1A - { return NiExtraData::RegisterStreamables(a_stream); }
		void          SaveBinary(NiStream& a_stream) override;            // 1B
		bool          IsEqual(NiObject* a_object) override;               // 1C

		static NiBooleanExtraData* Create(const BSFixedString& a_name, bool a_value);

		// members
		bool data;  // 18
	};
	static_assert(sizeof(NiBooleanExtraData) == 0x20);
}
