#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/N/NiPoint3.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class bhkRigidBody;
	class bhkSimpleShapePhantom;

	class CrosshairPickData
	{
	public:
		static CrosshairPickData* GetSingleton()
		{
			REL::Relocation<CrosshairPickData**> singleton{ REL::ID(515446) };
			return *singleton;
		}

		// members
		std::uint32_t                    pad00;           // 00
		ObjectRefHandle                  target;          // 04
		ObjectRefHandle                  targetActor;     // 08
		ObjectRefHandle                  unk0C;           // 0C
		NiPoint3                         collisionPoint;  // 10
		std::uint32_t                    pad1C;           // 1C
		bhkRigidBody*                    targetCollider;  // 20
		NiPointer<bhkSimpleShapePhantom> pickCollider;    // 28
		std::uint32_t                    collisionInfo;   // 30
		std::uint8_t                     unk34;           // 34
		std::uint8_t                     unk35;           // 35
		std::uint16_t                    unk36;           // 36
	};
	static_assert(sizeof(CrosshairPickData) == 0x38);
}
