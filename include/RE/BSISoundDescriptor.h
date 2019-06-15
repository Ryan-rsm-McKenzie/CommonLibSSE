#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSISoundDescriptor, RTTI_BSISoundDescriptor__BSIPlaybackCharacteristics


namespace RE
{
	class BSISoundDescriptor
	{
	public:
		inline static const void* RTTI = RTTI_BSISoundDescriptor;


		class BSIPlaybackCharacteristics
		{
		public:
			inline static const void* RTTI = RTTI_BSISoundDescriptor__BSIPlaybackCharacteristics;


			virtual ~BSIPlaybackCharacteristics();		// 00

			// add
			virtual UInt8	GetFrequencyShift() = 0;	// 01
			virtual UInt8	GetFrequencyVariance() = 0;	// 02
			virtual UInt8	GetPriority() = 0;			// 03
			virtual UInt16	GetStaticAttenuation() = 0;	// 04
			virtual UInt8	GetDBVariance() = 0;		// 05
		};
		STATIC_ASSERT(sizeof(BSIPlaybackCharacteristics) == 0x8);


		virtual ~BSISoundDescriptor();		// 00

		// add
		virtual void	Unk_01(void) = 0;	// 01
		virtual void	Unk_02(void) = 0;	// 02
	};
	STATIC_ASSERT(sizeof(BSISoundDescriptor) == 0x8);
}
