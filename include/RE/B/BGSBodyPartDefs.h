#pragma once

namespace RE
{
	namespace BGSBodyPartDefs
	{
		struct LIMB_ENUMS
		{
			enum LIMB_ENUM
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
		};
		using LIMB_ENUM = LIMB_ENUMS::LIMB_ENUM;
	}
}
