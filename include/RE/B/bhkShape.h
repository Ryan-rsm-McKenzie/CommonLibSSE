#pragma once

#include "RE/B/bhkSerializable.h"

namespace RE
{
	class bhkShape : public bhkSerializable
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkShape;
		inline static constexpr auto Ni_RTTI = NiRTTI_bhkShape;

		~bhkShape() override;  // 00

		// override (bhkSerializable)
		const NiRTTI* GetRTTI() const override;                          // 02
		void          LoadBinary(NiStream& a_stream) override;           // 18
		void          LinkObject(NiStream& a_stream) override;           // 19 - { bhkSerializable::LinkObject(a_stream); }
		bool          RegisterStreamables(NiStream& a_stream) override;  // 1A - { return bhkSerializable::RegisterStreamables(a_stream); }
		void          SaveBinary(NiStream& a_stream) override;           // 1B
		bool          IsEqual(NiObject* a_object) override;              // 1C
		void          Unk_26(void) override;                             // 26

		// add
		virtual void Unk_32(void);  // 32
		virtual void Unk_33(void);  // 33
		virtual void Unk_34(void);  // 34 - { return 0; }
		virtual void Unk_35(void);  // 35

		// members
		std::uint64_t unk20;  // 20
	};
	static_assert(sizeof(bhkShape) == 0x28);
}
