#pragma once

#include "RE/B/bhkNiCollisionObject.h"

namespace RE
{
	class bhkCollisionObject : public bhkNiCollisionObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkCollisionObject;
		inline static constexpr auto Ni_RTTI = NiRTTI_bhkCollisionObject;

		~bhkCollisionObject() override;  // 00

		// override (bhkNiCollisionObject)
		const NiRTTI* GetRTTI() const override;                           // 02
		NiObject*     CreateClone(NiCloningProcess& a_cloning) override;  // 17
		void          LoadBinary(NiStream& a_stream) override;            // 18 - { bhkNiCollisionObject::LoadBinary(a_stream); }
		void          LinkObject(NiStream& a_stream) override;            // 19 - { bhkNiCollisionObject::LinkObject(a_stream); }
		bool          RegisterStreamables(NiStream& a_stream) override;   // 1A - { return bhkNiCollisionObject::RegisterStreamables(a_stream); }
		void          SaveBinary(NiStream& a_stream) override;            // 1B - { bhkNiCollisionObject::SaveBinary(a_stream); }
		void          Unk_26(void) override;                              // 26
		void          Unk_2A(void) override;                              // 2A
		void          Unk_2B(void) override;                              // 2B
		void          Unk_2C(void) override;                              // 2C
		void          Unk_2D(void) override;                              // 2D
		void          Unk_2E(void) override;                              // 2E
		void          Unk_2F(void) override;                              // 2F
	};
	static_assert(sizeof(bhkCollisionObject) == 0x28);
}
