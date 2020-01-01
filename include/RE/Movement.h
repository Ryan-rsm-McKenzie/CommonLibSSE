#pragma once

#include "RE/BSFixedString.h"


namespace RE
{
	namespace Movement
	{
		enum class SPEED_DIRECTION : UInt32
		{
			kLeft,
			kRight,
			kForward,
			kBack,
			kRotations,

			kTotal
		};


		struct MaxSpeeds
		{
			enum
			{
				kWalk,
				kRun,

				kTotal
			};


			float	speeds[to_underlying(SPEED_DIRECTION::kTotal)][kTotal];		// 00
			float	rotateWhileMovingRun;										// 28
		};
		STATIC_ASSERT(sizeof(MaxSpeeds) == 0x2C);


		struct TypeData
		{
			BSFixedString	typeName;		// 00 - MNAM
			MaxSpeeds		defaultData;	// 08 - SPED
			float			directional;	// 34 - INAM~
			float			movementSpeed;	// 38
			float			rotationSpeed;	// 3C - ~INAM
		};
		STATIC_ASSERT(sizeof(TypeData) == 0x40);
	}
}
