#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSISoundOutputModel, RTTI_BSISoundOutputModel__BSIAttenuationCharacteristics


namespace RE
{
	class BSISoundOutputModel
	{
	public:
		inline static const void* RTTI = RTTI_BSISoundOutputModel;


		struct BSIAttenuationCharacteristics
		{
			inline static const void* RTTI = RTTI_BSISoundOutputModel__BSIAttenuationCharacteristics;


			virtual ~BSIAttenuationCharacteristics();				// 00

			// add
			virtual float	GetMaxDistance() const = 0;				// 01
			virtual float	GetMinDistance() const = 0;				// 02
			virtual UInt8	GetCurveValue(UInt32 a_idx) const = 0;	// 03
		};
		STATIC_ASSERT(sizeof(BSIAttenuationCharacteristics) == 0x8);


		virtual ~BSISoundOutputModel();														// 00

		// add
		virtual bool							UsesHRTF() const = 0;						// 01
		virtual bool							DefinesSpeakerOutput() const = 0;			// 02
		virtual void							Unk_03(void) = 0;							// 03
		virtual bool							AttenuatesWithDistance(void) const = 0;		// 04
		virtual bool							IsOutOfRange(float a_distance) const = 0;	// 05
		virtual void							Unk_06(void) = 0;							// 06
		virtual BSIAttenuationCharacteristics*	GetAttenuationValues() = 0;					// 07
		virtual float							GetReverbSend() const = 0;					// 08
		virtual void							Unk_09(void) = 0;							// 09
	};
	STATIC_ASSERT(sizeof(BSISoundOutputModel) == 0x8);
}
