#pragma once

#include "RE/N/NiObject.h"

namespace RE
{
	class NiAVObject;

	class NiCollisionObject : public NiObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiCollisionObject;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiCollisionObject;

		~NiCollisionObject() override = 0;  // 00

		// override (NiObject)
		const NiRTTI* GetRTTI() const override;                          // 02
		void          LoadBinary(NiStream& a_stream) override;           // 18
		void          LinkObject(NiStream& a_stream) override;           // 19
		bool          RegisterStreamables(NiStream& a_stream) override;  // 1A
		void          SaveBinary(NiStream& a_stream) override;           // 1B
		bool          IsEqual(NiObject* a_object) override;              // 1C

		// add
		virtual void Unk_25(void);      // 25
		virtual void Unk_26(void) = 0;  // 26
		virtual void Unk_27(void) = 0;  // 27
		virtual void Unk_28(void);      // 28 - { return; }
		virtual void Unk_29(void);      // 29 - { return; }

		// members
		NiAVObject* sceneObject;  // 10
	};
	static_assert(sizeof(NiCollisionObject) == 0x18);
}
