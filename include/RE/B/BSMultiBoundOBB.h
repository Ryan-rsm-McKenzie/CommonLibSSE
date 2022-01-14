#pragma once

#include "RE/B/BSMultiBoundAABB.h"
#include "RE/N/NiMatrix3.h"

namespace RE
{
	class BSMultiBoundOBB : public BSMultiBoundAABB
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSMultiBoundOBB;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSMultiBoundOBB;

		~BSMultiBoundOBB() override;  // 00

		// override (NiObject)
		const NiRTTI* GetRTTI() const override;                           // 02
		NiObject*     CreateClone(NiCloningProcess& a_cloning) override;  // 17
		void          LoadBinary(NiStream& a_stream) override;            // 18
		void          LinkObject(NiStream& a_stream) override;            // 19
		bool          RegisterStreamables(NiStream& a_stream) override;   // 1A
		void          SaveBinary(NiStream& a_stream) override;            // 1B
		bool          IsEqual(NiObject* a_object) override;               // 1C
		std::uint32_t GetType() override;                                 // 25 - { return 2; }
		bool          Unk_27() override;                                  // 27
		void          Unk_28() override;                                  // 28
		bool          Unk_29() override;                                  // 29
		void          Unk_2A() override;                                  // 2A
		void          Unk_2B() override;                                  // 2B
		bool          WithinPoint(const NiPoint3& a_pos) override;        // 2C
		void          Unk_2E() override;                                  // 2E

		// members
		NiMatrix3     rotation;  // 40
		bool          unk64;     // 64
		std::uint8_t  pad65;     // 65
		std::uint16_t pad66;     // 66
	};
	static_assert(sizeof(BSMultiBoundOBB) == 0x68);
}
