#pragma once

#include "skse64/GameTypes.h"  // BSString

#include "RE/BGSSoundDescriptor.h"  // BGSSoundDescriptor
#include "RE/FormTypes.h"  // BGSSoundOutput


namespace RE
{
	class Condition;


	class BGSStandardSoundDef : public BGSSoundDescriptor
	{
	public:
		struct SoundPlaybackCharacteristics : public BSISoundDescriptor::BSIPlaybackCharacteristics	// BNAM
		{
		public:
			// override (BSIPlaybackCharacteristics)
			virtual UInt8	GetFrequencyShift() override;		// 01
			virtual UInt8	GetFrequencyVariance() override;	// 02
			virtual UInt8	GetPriority() override;				// 03
			virtual UInt16	GetStaticAttenuation() override;	// 04
			virtual UInt8	GetDBVariance() override;			// 05


			// members
			UInt8			frequencyShift;		// 08
			UInt8			frequencyVariance;	// 09
			UInt8			priority;			// 0A
			UInt8			dbVariance;			// 0B
			UInt16			staticAttenuation;	// 0C - CK Value * 100
			UInt16			pad0E;				// 0E
		};
		STATIC_ASSERT(sizeof(SoundPlaybackCharacteristics) == 0x10);


		struct LengthCharacteristics	// LNAM
		{
			enum class Looping : UInt8
			{
				kNone = 0,
				kLoop = 8,
				kEnvelopeFast = 16,
				kEnvelopeSlow = 32
			};


			UInt8	unk0;				// 0
			Looping	looping;			// 1
			UInt8	unk2;				// 2
			UInt8	rumbleSendValue;	// 2
		};
		STATIC_ASSERT(sizeof(LengthCharacteristics) == 0x4);


		virtual ~BGSStandardSoundDef();	// 00


		// members
		BSString						fileNames;				// 18 - ANAM
		UInt32							numSoundFiles;			// 28
		UInt32							pad2C;					// 2C
		SoundPlaybackCharacteristics	soundCharacteristics;	// 30 - BNAM
		Condition*						conditions;				// 40 - CTDA
		BGSSoundOutput*					outputModel;			// 48 - ONAM
		LengthCharacteristics			lengthCharacteristics;	// 50 - LNAM
		SInt32							unk54;					// 54
	};
	STATIC_ASSERT(sizeof(BGSStandardSoundDef) == 0x58);
}
