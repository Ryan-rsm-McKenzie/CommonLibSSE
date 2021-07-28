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
		void          Unk_29() override;                              // 29
		void          Unk_2A() override;                              // 2A
		void          Unk_2B() override;                              // 2B
		void          Unk_2C() override;                              // 2C - { return 0x110; }
		void          Unk_2D() override;                              // 2D
		void          Unk_2E() override;                              // 2E
		void          Unk_2F() override;                              // 2F
		void          Unk_30() override;                              // 30
		void          Unk_32() override;                              // 32

		// add
		virtual void Unk_33();  // 33
		virtual void Unk_34();  // 34
		virtual void Unk_35();  // 35
		virtual void Unk_36();  // 36
		virtual void Unk_37();  // 37
		virtual void Unk_38();  // 38
		virtual void Unk_39();  // 39
		virtual void Unk_3A();  // 3A
		virtual void Unk_3B();  // 3B
		virtual void Unk_3C();  // 3C

		// members
		BSTArray<void*> unk28;  // 28 - array of smart ptrs
	};
	static_assert(sizeof(bhkRigidBody) == 0x40);
}
