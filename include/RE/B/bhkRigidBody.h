#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/bhkEntity.h"
#include "RE/H/hkQuaternion.h"

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
		virtual hkVector4&   getPosition(hkVector4& position);                           // 33
		virtual hkVector4&   getRotation(hkQuaternion& rotation);                        // 34
		virtual void         setPosition(hkVector4& position);                           // 35
		virtual void         setRotation(hkQuaternion& rotation);                        // 36
		virtual void         setPositionAndRotation(hkVector4& pos, hkQuaternion& rot);  // 37
		virtual hkVector4&   getCenterOfMassLocal(hkVector4& centerOfMassLocal);         // 38
		virtual hkVector4&   getCenterOfMassInWorld(hkVector4& centerOfMassWorld);       // 39
		virtual hkTransform& getTransform(hkTransform& transform);                       // 3A
		virtual void         getAabbWorldspace(hkAabb& aabb);                            // 3B
		virtual void         Unk_3C(void);                                               // 3C

		// members
		BSTArray<void*> unk28;  // 28 - array of smart ptrs
	};
	static_assert(sizeof(bhkRigidBody) == 0x40);


	class bhkRigidBodyT : bhkRigidBody
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkRigidBodyT;
		inline static constexpr auto Ni_RTTI = NiRTTI_bhkRigidBodyT;

		hkQuaternion rotation;     // 40
		hkVector4    translation;  // 50
	};
}
