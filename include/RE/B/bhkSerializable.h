#pragma once

#include "RE/B/bhkRefObject.h"

namespace RE
{
	class hkpWorld;

	class bhkSerializable : public bhkRefObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkSerializable;
		inline static constexpr auto Ni_RTTI = NiRTTI_bhkSerializable;

		~bhkSerializable() override;  // 00

		// override (bhkRefObject)
		const NiRTTI* GetRTTI() const override;                          // 02
		void          LoadBinary(NiStream& a_stream) override;           // 18
		void          LinkObject(NiStream& a_stream) override;           // 19
		bool          RegisterStreamables(NiStream& a_stream) override;  // 1A - { return NiObject::RegisterStreamables(a_stream); }
		void          SaveBinary(NiStream& a_stream) override;           // 1B
		void          Unk_25() override;                             // 25

		// add
		virtual hkpWorld* GetWorld();        // 27 - { return 0; }
		virtual void      Unk_28();      // 28 - { return 0; }
		virtual void      Unk_29();      // 29 - { return 0; }
		virtual void      Unk_2A();      // 2A - { return 0; }
		virtual void      Unk_2B();      // 2B
		virtual void      Unk_2C();      // 2C - { return 1; }
		virtual void      Unk_2D();      // 2D
		virtual void      Unk_2E() = 0;  // 2E
		virtual void      Unk_2F() = 0;  // 2F
		virtual void      Unk_30();      // 30
		virtual void      Unk_31();      // 31

		// members
		bhkSerializable* serializable;  // 18
	};
	static_assert(sizeof(bhkSerializable) == 0x20);
}
