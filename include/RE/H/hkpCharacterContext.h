#pragma once

#include "RE/H/hkReferencedObject.h"
#include "RE/H/hkStepInfo.h"
#include "RE/H/hkVector4.h"
#include "RE/H/hkpCharacterControl.h"
#include "RE/H/hkpCharacterState.h"

namespace RE
{
	class hkpCharacterStateManager;

	struct hkpCharacterInput
	{
		float          inputLR;           // 00
		float          inputUD;           // 04
		bool           wantJump;          // 08
		std::uint8_t   pad09;             // 09
		std::uint16_t  pad0A;             // 0A
		std::uint32_t  pad0C;             // 0C
		hkVector4      up;                // 10
		hkVector4      forward;           // 20
		bool           atLadder;          // 30
		hkpSurfaceInfo surfaceInfo;       // 40
		hkStepInfo     stepInfo;          // 80
		hkVector4      position;          // 90
		hkVector4      velocity;          // A0
		hkVector4      characterGravity;  // B0
		std::uint64_t  userData;          // C0
		std::uint64_t  padC8;             // C8
	};
	static_assert(sizeof(hkpCharacterInput) == 0xD0);

	struct hkpCharacterOutput
	{
		hkVector4 velocity;  // 00
	};
	static_assert(sizeof(hkpCharacterOutput) == 0x10);

	class hkpCharacterContext : public hkReferencedObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpCharacterContext;

		enum class CharacterType
		{
			kProxy = 0,
			kRigidBody = 1
		};

		~hkpCharacterContext() override;  // 00

		stl::enumeration<CharacterType, std::uint32_t> characterType;          // 10
		std::uint32_t                                  pad14;                  // 14
		const hkpCharacterStateManager*                stateManager;           // 18
		hkpCharacterStateType                          currentState;           // 20
		hkpCharacterStateType                          previousState;          // 24
		bool                                           filterEnable;           // 28
		std::uint8_t                                   pad29;                  // 29
		std::uint16_t                                  pad2A;                  // 2A
		float                                          maxLinearAcceleration;  // 2C
		float                                          maxLinearVelocity;      // 30
		float                                          gain;                   // 34
	};
	static_assert(sizeof(hkpCharacterContext) == 0x38);
}
