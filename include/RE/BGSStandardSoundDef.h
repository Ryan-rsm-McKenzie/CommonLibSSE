#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSStandardSoundDef, RTTI_BGSStandardSoundDef__SoundPlaybackCharacteristics

#include "RE/BGSSoundDescriptor.h"  // BGSSoundDescriptor
#include "RE/BSTArray.h"  // BSTArray
#include "RE/FileHash.h"  // FileHash
#include "RE/FormTypes.h"  // BGSSoundOutput


namespace RE
{
	class Condition;


	class BGSStandardSoundDef : public BGSSoundDescriptor
	{
	public:
		inline static const void* RTTI = RTTI_BGSStandardSoundDef;


		struct SoundPlaybackCharacteristics : public BSISoundDescriptor::BSIPlaybackCharacteristics	// BNAM
		{
		public:
			inline static const void* RTTI = RTTI_BGSStandardSoundDef__SoundPlaybackCharacteristics;


			// override (BSIPlaybackCharacteristics)
			virtual UInt8	GetFrequencyShift() override;		// 01 - { return frequencyShift; }
			virtual UInt8	GetFrequencyVariance() override;	// 02 - { return frequencyVariance; }
			virtual UInt8	GetPriority() override;				// 03 - { return priority; }
			virtual UInt16	GetStaticAttenuation() override;	// 04 - { return staticAttenuation; }
			virtual UInt8	GetDBVariance() override;			// 05 - { return dbVariance; }


			// members
			UInt8	frequencyShift;		// 08
			UInt8	frequencyVariance;	// 09
			UInt8	priority;			// 0A
			UInt8	dbVariance;			// 0B
			UInt16	staticAttenuation;	// 0C - CK Value * 100
			UInt16	pad0E;				// 0E
		};
		STATIC_ASSERT(sizeof(SoundPlaybackCharacteristics) == 0x10);


		struct LengthCharacteristics	// LNAM
		{
			enum class Looping : UInt8
			{
				kNone = 0,
				kLoop = 1 << 3,
				kEnvelopeFast = 1 << 4,
				kEnvelopeSlow = 1 << 5
			};


			UInt8	unk0;				// 0
			Looping	looping;			// 1
			UInt8	unk2;				// 2
			UInt8	rumbleSendValue;	// 3
		};
		STATIC_ASSERT(sizeof(LengthCharacteristics) == 0x4);


		virtual ~BGSStandardSoundDef();						// 00

		// override (BGSSoundDescriptor)
		virtual void	Unk_01(void) override;				// 01
		virtual void	Unk_02(void) override;				// 02
		virtual void	InitSound(TESForm* a_src) override;	// 03
		virtual bool	LoadSound(TESFile* a_mod) override;	// 04
		virtual UInt32	GetType() const override;			// 05 - "BGSStandardSoundDef"
		virtual void	Unk_06(void) override;				// 06


		// members
		BSTArray<FileHash>				soundFiles;				// 18 - ANAM
		SoundPlaybackCharacteristics	soundCharacteristics;	// 30 - BNAM
		Condition*						conditions;				// 40 - CTDA
		BGSSoundOutput*					outputModel;			// 48 - ONAM
		LengthCharacteristics			lengthCharacteristics;	// 50 - LNAM
		SInt32							unk54;					// 54
	};
	STATIC_ASSERT(sizeof(BGSStandardSoundDef) == 0x58);
}
