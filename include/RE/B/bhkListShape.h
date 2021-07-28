#pragma once

#include "RE/B/bhkShapeCollection.h"

namespace RE
{
	class bhkListShape : public bhkShapeCollection
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkListShape;
		inline static constexpr auto Ni_RTTI = NiRTTI_bhkListShape;

		~bhkListShape() override;  // 00

		// override (bhkShapeCollection)
		const NiRTTI* GetRTTI() const override;                           // 02
		NiObject*     CreateClone(NiCloningProcess& a_cloning) override;  // 17
		void          LoadBinary(NiStream& a_stream) override;            // 18
		void          LinkObject(NiStream& a_stream) override;            // 19
		bool          RegisterStreamables(NiStream& a_stream) override;   // 1A
		void          SaveBinary(NiStream& a_stream) override;            // 1B
		void          Unk_26() override;                              // 26
		void          Unk_2B() override;                              // 2B
		void          Unk_2C() override;                              // 2C - { return 40; }
		void          Unk_2D() override;                              // 2D
		void          Unk_2E() override;                              // 2E
		void          Unk_2F() override;                              // 2F
		void          Unk_32() override;                              // 32
		void          Unk_35() override;                              // 35
		void          Unk_36() override;                              // 36

		// members
		std::uint64_t unk28;  // 28
	};
	static_assert(sizeof(bhkListShape) == 0x30);
}
