#pragma once

#include "RE/NiPoint3.h"
#include "RE/NiRefObject.h"


namespace RE
{
	class DetectionState : public NiRefObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_DetectionState;


		virtual ~DetectionState();	// 00


		// members
		SInt32	 level;	 // 10
		UInt8	 unk14;	 // 14
		UInt8	 unk15;	 // 15
		UInt8	 unk16;	 // 16
		UInt8	 pad17;	 // 17
		float	 unk18;	 // 18
		NiPoint3 unk1C;	 // 1C
		float	 unk28;	 // 28
		NiPoint3 unk2C;	 // 2C
		float	 unk38;	 // 38
		NiPoint3 unk3C;	 // 3C
	};
	STATIC_ASSERT(sizeof(DetectionState) == 0x48);
}
