#pragma once

#include "RE/N/NiCollisionObject.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class bhkWorldObject;

	class bhkNiCollisionObject : public NiCollisionObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkNiCollisionObject;
		inline static constexpr auto Ni_RTTI = NiRTTI_bhkNiCollisionObject;

		enum class Flag
		{
			kNone = 0,
			kActive = 1 << 0,
			kNotify = 1 << 2,
			kSetLocal = 1 << 3,
			kDebugDisplay = 1 << 4,
			kUseVelocity = 1 << 5,
			kReset = 1 << 6,
			kSyncOnUpdate = 1 << 7,
			kAnimTargeted = 1 << 10,
			kDismemberLimb = 1 << 11
		};

		~bhkNiCollisionObject() override;  // 00

		// override (NiCollisionObject)
		const NiRTTI*         GetRTTI() const override;                          // 02
		bhkNiCollisionObject* AsBhkNiCollisionObject() override;                 // 12 - { return this; }
		void                  LoadBinary(NiStream& a_stream) override;           // 18
		void                  LinkObject(NiStream& a_stream) override;           // 19
		bool                  RegisterStreamables(NiStream& a_stream) override;  // 1A
		void                  SaveBinary(NiStream& a_stream) override;           // 1B
		bool                  IsEqual(NiObject* a_object) override;              // 1C
		void                  Unk_25() override;                             // 25
		void                  Unk_26() override;                             // 26
		void                  Unk_27() override;                             // 27 - { return; }

		// add
		virtual void Unk_2A();      // 2A
		virtual void Unk_2B() = 0;  // 2B
		virtual void Unk_2C() = 0;  // 2C
		virtual void Unk_2D() = 0;  // 2D
		virtual void Unk_2E() = 0;  // 2E
		virtual void Unk_2F();      // 2F
		virtual void Unk_30();      // 30 - { return 1; }

		// members
		stl::enumeration<Flag, std::uint32_t> flags;  // 18
		std::uint32_t                         pad1C;  // 1C
		NiPointer<bhkWorldObject>             body;   // 20
	};
	static_assert(sizeof(bhkNiCollisionObject) == 0x28);
}
