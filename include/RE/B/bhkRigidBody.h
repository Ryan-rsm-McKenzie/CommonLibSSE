#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/bhkEntity.h"

namespace RE
{
	class bhkRigidBody : public bhkEntity
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkRigidBody;
		inline static constexpr auto Ni_RTTI = NiRTTI_bhkRigidBody;

		~bhkRigidBody() override;  // 00

		// override (bhkEntity)
		const NiRTTI* GetRTTI() const override;                           // 02
		bhkRigidBody* AsBhkRigidBody() override;                          // 15 - { return this; }
		NiObject*     CreateClone(NiCloningProcess& a_cloning) override;  // 17
		void          LoadBinary(NiStream& a_stream) override;            // 18
		void          LinkObject(NiStream& a_stream) override;            // 19
		bool          RegisterStreamables(NiStream& a_stream) override;   // 1A
		void          SaveBinary(NiStream& a_stream) override;            // 1B
		bool          IsEqual(NiObject* a_object) override;               // 1C
		void          Unk_29(void) override;                              // 29
		void          Unk_2A(void) override;                              // 2A
		void          Unk_2B(void) override;                              // 2B
		void          Unk_2C(void) override;                              // 2C - { return 0x110; }
		void          Unk_2D(void) override;                              // 2D
		void          Unk_2E(void) override;                              // 2E
		void          Unk_2F(void) override;                              // 2F
		void          Unk_30(void) override;                              // 30
		void          Unk_32(void) override;                              // 32

		// add
		virtual void Unk_33(void);  // 33
		virtual void Unk_34(void);  // 34
		virtual void Unk_35(void);  // 35
		virtual void Unk_36(void);  // 36
		virtual void Unk_37(void);  // 37
		virtual void Unk_38(void);  // 38
		virtual void Unk_39(void);  // 39
		virtual void Unk_3A(void);  // 3A
		virtual void Unk_3B(void);  // 3B
		virtual void Unk_3C(void);  // 3C

		// members
		BSTArray<void*> unk28;  // 28 - array of smart ptrs
	};
	static_assert(sizeof(bhkRigidBody) == 0x40);
}
