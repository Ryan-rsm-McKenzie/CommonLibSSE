#pragma once

#include <type_traits>


namespace RE
{
	namespace BGSBodyPartDefs
	{
		enum class LIMB_ENUM : UInt32
		{
			kNone = static_cast<std::underlying_type_t<LIMB_ENUM>>(-1),
			kTorso = 0,
			kHead,
			kEye,
			kLookAt,
			kFlyGrab,
			kSaddle,

			kTotal
		};


		enum class LIMB_ENUM_8 : UInt8
		{
			kNone = static_cast<std::underlying_type_t<LIMB_ENUM_8>>(-1),
			kTorso = 0,
			kHead,
			kEye,
			kLookAt,
			kFlyGrab,
			kSaddle,

			kTotal
		};
	}
}
