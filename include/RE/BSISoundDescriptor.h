#pragma once

namespace RE
{
	class BSISoundDescriptor
	{
	public:
		class BSIPlaybackCharacteristics
		{
		public:
			virtual ~BSIPlaybackCharacteristics();			// 00

			// add
			virtual UInt8	GetFrequencyShift(void) = 0;	// 01
			virtual UInt8	GetFrequencyVariance(void) = 0;	// 02
			virtual UInt8	GetPriority(void) = 0;			// 03
			virtual UInt16	GetDBAttenuation(void) = 0;		// 04
			virtual UInt8	GetDBVariance(void) = 0;		// 05
		};
		STATIC_ASSERT(sizeof(BSIPlaybackCharacteristics) == 0x8);


		virtual ~BSISoundDescriptor();	// 00

		// add
		virtual void	Unk_01(void);	// 01 - pure
		virtual void	Unk_02(void);	// 02 - pure
	};
	STATIC_ASSERT(sizeof(BSISoundDescriptor) == 0x8);
}
