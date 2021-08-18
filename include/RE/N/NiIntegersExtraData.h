#pragma once

#include "RE/N/NiExtraData.h"

namespace RE
{
	class NiIntegersExtraData : public NiExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiIntegersExtraData;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiIntegersExtraData;
		inline static constexpr auto VTABLE = VTABLE_NiIntegersExtraData;

		~NiIntegersExtraData() override;  // 00

		// override (NiExtraData)
		const NiRTTI* GetRTTI() const override;                           // 02
		NiObject*     CreateClone(NiCloningProcess& a_cloning) override;  // 17
		void          LoadBinary(NiStream& a_stream) override;            // 18
		void          LinkObject(NiStream& a_stream) override;            // 19 - { NiExtraData::LinkObject(a_stream); }
		bool          RegisterStreamables(NiStream& a_stream) override;   // 1A - { return NiExtraData::RegisterStreamables(a_stream); }
		void          SaveBinary(NiStream& a_stream) override;            // 1B
		bool          IsEqual(NiObject* a_object) override;               // 1C

		static NiIntegersExtraData* Create(const BSFixedString& a_name, const std::vector<std::int32_t>& a_integers);

		std::optional<std::uint32_t> GetIndex(std::int32_t a_element) const;
		bool                         Insert(std::int32_t a_element);
		bool                         Remove(std::int32_t a_element);

		// members
		std::uint32_t size;   // 18
		std::uint32_t pad;    // 1C
		std::int32_t* value;  // 20
	};
	static_assert(sizeof(NiIntegersExtraData) == 0x28);
}
