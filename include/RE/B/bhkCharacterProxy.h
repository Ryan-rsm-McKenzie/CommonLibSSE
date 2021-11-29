#pragma once

#include "RE/B/bhkCharacterPointCollector.h"
#include "RE/B/bhkSerializable.h"

namespace RE
{
	class bhkCharacterProxy : public bhkSerializable
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkCharacterProxy;
		inline static constexpr auto Ni_RTTI = NiRTTI_bhkCharacterProxy;

		~bhkCharacterProxy() override;  // 00

		// override (bhkSerializable)
		const NiRTTI* GetRTTI() const override;                           // 02
		NiObject*     CreateClone(NiCloningProcess& a_cloning) override;  // 17
		void          LoadBinary(NiStream& a_stream) override;            // 18
		void          LinkObject(NiStream& a_stream) override;            // 19
		bool          RegisterStreamables(NiStream& a_stream) override;   // 1A
		void          SaveBinary(NiStream& a_stream) override;            // 1B
		void          Unk_26(void) override;                              // 26 - "void AdjustRefCount(bool a_increment)"?
		hkpWorld*     GetWorld() override;                                // 27 - { auto proxy = (hkpCharacterProxy*)referencedObject.get(); if (proxy && proxy->shapePhantom) return proxy->world; else return 0; }
		void          Unk_28(void) override;                              // 28 - { return GetWorld(); }
		void          Unk_2B(void) override;                              // 2B
		void          Unk_2C(void) override;                              // 2C - { return 0x90; }
		void          Unk_2E(void) override;                              // 2E
		void          Unk_2F(void) override;                              // 2F

		// members
		bhkCharacterPointCollector ignoredCollisionStartCollector;  // 020
	};
	static_assert(sizeof(bhkCharacterProxy) == 0x260);
}
