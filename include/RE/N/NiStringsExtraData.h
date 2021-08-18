#pragma once

#include "RE/N/NiExtraData.h"

namespace RE
{
	class NiStringsExtraData : public NiExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiStringsExtraData;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiStringsExtraData;
		inline static constexpr auto VTABLE = VTABLE_NiStringsExtraData;

		~NiStringsExtraData() override;  // 00

		// override (NiExtraData)
		const NiRTTI* GetRTTI() const override;                           // 02
		NiObject*     CreateClone(NiCloningProcess& a_cloning) override;  // 17
		void          LoadBinary(NiStream& a_stream) override;            // 18
		void          LinkObject(NiStream& a_stream) override;            // 19 - { NiExtraData::LinkObject(a_stream); }
		bool          RegisterStreamables(NiStream& a_stream) override;   // 1A - { return NiExtraData::RegisterStreamables(a_stream); }
		void          SaveBinary(NiStream& a_stream) override;            // 1B
		bool          IsEqual(NiObject* a_object) override;               // 1C

		static NiStringsExtraData*   Create(const BSFixedString& a_name, const std::vector<BSFixedString>& a_strings);
		std::optional<std::uint32_t> GetIndex(const BSFixedString& a_element) const;
		bool                         Insert(const BSFixedString& a_element);
		bool                         Remove(const BSFixedString& a_element);
		bool                         Replace(const BSFixedString& a_from, const BSFixedString& a_to);

		// members
		std::uint32_t size;   // 18
		std::uint32_t pad1C;  // 1C
		char**        value;  // 20
	};
	static_assert(sizeof(NiStringsExtraData) == 0x28);
}
