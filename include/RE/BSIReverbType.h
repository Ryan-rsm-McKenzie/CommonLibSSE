#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSIReverbType


namespace RE
{
	class BSIReverbType
	{
	public:
		inline static const void* RTTI = RTTI_BSIReverbType;


		// add
		virtual UInt32	GetRoomFilter() const = 0;		// 00
		virtual UInt32	GetRoomHFFilter() const = 0;	// 01
		virtual float	GetDecayTime() const = 0;		// 02 - in seconds
		virtual float	GetDecayHFRatio() const = 0;	// 03
		virtual UInt32	GetReflections() const = 0;		// 04
		virtual float	GetReflectDelay() const = 0;	// 05 - in seconds
		virtual UInt32	GetReverbAmp() const = 0;		// 06
		virtual float	GetReverbDelay() const = 0;		// 07 - in seconds
		virtual UInt32	GetDiffusionPct() const = 0;	// 08
		virtual UInt32	GetDensityPct() const = 0;		// 09
		virtual UInt32	GetHFReference() const = 0;		// 0A
	};
	STATIC_ASSERT(sizeof(BSIReverbType) == 0x8);
}
