#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSSoundOutput

#include "RE/BSISoundOutputModel.h"  // BSISoundOutputModel
#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	class BGSSoundOutput :
		public TESForm,				// 00
		public BSISoundOutputModel	// 20
	{
	public:
		inline static const void* RTTI = RTTI_BGSSoundOutput;


		enum { kTypeID = FormType::SoundOutputModel };


		enum class Type : UInt32	// MNAM
		{
			kUsesHRTF = 0,
			kDefinedSpeakerOutput = 1
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct Data	// NAM1
		{
			enum class Flag : UInt8
			{
				kNone = 0,
				kAttenuatesWithDistance = 1 << 0,
				kAllowsRumble = 1 << 1
			};


			Flag	flags;			// 0
			UInt8	unk1;			// 1
			UInt8	unk2;			// 2
			UInt8	reverbSendPct;	// 3
		};
		STATIC_ASSERT(sizeof(Data) == 0x4);


		struct DynamicAttenuationCharacteristics : public BSIAttenuationCharacteristics
		{
			virtual ~DynamicAttenuationCharacteristics();				// 00

			// override (BSIAttenuationCharacteristics)
			virtual float	GetMaxDistance() const override;			// 01 - { return maxDistance; }
			virtual float	GetMinDistance() const override;			// 02 - { return minDistance; }
			virtual UInt8	GetCurveValue(UInt32 a_idx) const override;	// 03 - { return a_idx >= 5 ? 0 : curve[a_idx]; }


			float	minDistance;	// 08
			float	maxDistance;	// 0C
			UInt8	curve[5];		// 10
			UInt8	pad15;			// 15
			UInt16	pad16;			// 16
		};
		STATIC_ASSERT(sizeof(DynamicAttenuationCharacteristics) == 0x18);


		struct OutputValues	// ONAM
		{
			struct Channel
			{
				UInt8	l;		// 0
				UInt8	r;		// 1
				UInt8	c;		// 2
				UInt8	lfe;	// 3
				UInt8	rl;		// 4
				UInt8	rr;		// 5
				UInt8	bl;		// 6
				UInt8	br;		// 7
			};
			STATIC_ASSERT(sizeof(Channel) == 0x8);


			Channel channels[3];
		};
		STATIC_ASSERT(sizeof(OutputValues) == 0x18);


		virtual ~BGSSoundOutput();																// 00

		// override (TESForm)
		virtual void							ReleaseManagedData() override;					// 05
		virtual bool							LoadForm(TESFile* a_mod) override;				// 06
		virtual void							InitItem() override;							// 13

		// override (BSISoundOutputModel)
		virtual bool							UsesHRTF() const override;						// 01 - { return type == kUsesHRTF; }
		virtual bool							DefinesSpeakerOutput() const override;			// 02 - { return type == kDefinedSpeakerOutput; }
		virtual bool							AttenuatesWithDistance(void) const override;	// 04 - { return data.flags & 1; }
		virtual bool							IsOutOfRange(float a_distance) const override;	// 05 - { float maxDistance = attenuationValues ? attenuationValues->GetMaxDistance() : 3.4028235e38; return a_distance > maxDistance; }
		virtual BSIAttenuationCharacteristics*	GetAttenuationValues() override;				// 07 - { return attenuationValues; }
		virtual float							GetReverbSend() const override;					// 08 - { return data.reverbSendPct * 0.0099999998; }


		// members
		Data								data;				// 28 - NAM1
		Type								type;				// 2C - MNAM
		DynamicAttenuationCharacteristics*	attenuationValues;	// 30 - ANAM
		OutputValues*						outputValues;		// 38 - ONAM
	};
	STATIC_ASSERT(sizeof(BGSSoundOutput) == 0x40);
}
