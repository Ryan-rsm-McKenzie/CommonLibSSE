#pragma once

#include "RE/BSISoundOutputModel.h"
#include "RE/FormTypes.h"
#include "RE/TESForm.h"


namespace RE
{
	class BGSSoundOutput :
		public TESForm,				// 00
		public BSISoundOutputModel	// 20
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSSoundOutput;
		inline static constexpr auto FORMTYPE = FormType::SoundOutputModel;


		enum class Type : UInt32  // MNAM
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


		struct Data	 // NAM1
		{
			enum class Flag : UInt8
			{
				kNone = 0,
				kAttenuatesWithDistance = 1 << 0,
				kAllowsRumble = 1 << 1
			};


			Flag  flags;		  // 0
			UInt8 unk1;			  // 1
			UInt8 unk2;			  // 2
			UInt8 reverbSendPct;  // 3
		};
		STATIC_ASSERT(sizeof(Data) == 0x4);


		struct DynamicAttenuationCharacteristics : public BSIAttenuationCharacteristics
		{
			struct DataType
			{
				float  minDistance;	 // 00
				float  maxDistance;	 // 04
				UInt8  curve[5];	 // 08
				UInt8  pad15;		 // 0D
				UInt16 pad16;		 // 0E
			};
			STATIC_ASSERT(sizeof(DataType) == 0x10);


			virtual ~DynamicAttenuationCharacteristics();  // 00

			// override (BSIAttenuationCharacteristics)
			virtual float GetMaxDistance() const override;			   // 01 - { return data.maxDistance; }
			virtual float GetMinDistance() const override;			   // 02 - { return data.minDistance; }
			virtual UInt8 GetCurveValue(UInt32 a_idx) const override;  // 03 - { return a_idx >= 5 ? 0 : data.curve[a_idx]; }


			// members
			DataType data;	// 00
		};
		STATIC_ASSERT(sizeof(DynamicAttenuationCharacteristics) == 0x18);


		struct SpeakerArrays  // ONAM
		{
			struct Channel
			{
				UInt8 l;	// 0
				UInt8 r;	// 1
				UInt8 c;	// 2
				UInt8 lfe;	// 3
				UInt8 rl;	// 4
				UInt8 rr;	// 5
				UInt8 bl;	// 6
				UInt8 br;	// 7
			};
			STATIC_ASSERT(sizeof(Channel) == 0x8);


			Channel channels[3];
		};
		STATIC_ASSERT(sizeof(SpeakerArrays) == 0x18);


		virtual ~BGSSoundOutput();	// 00

		// override (TESForm)
		virtual void ClearData() override;			 // 05
		virtual bool Load(TESFile* a_mod) override;	 // 06
		virtual void InitItemImpl() override;		 // 13

		// override (BSISoundOutputModel)
		virtual bool								 DoGetUsesHRTF() const override;													 // 01 - { return type == kUsesHRTF; }
		virtual bool								 DoGetHasSpeakerBias() const override;												 // 02 - { return type == kDefinedSpeakerOutput; }
		virtual bool								 DoGetSpeakerBias(UInt32 a_arg1, UInt32 a_arg2, float (&a_arg3)[8]) const override;	 // 03
		virtual bool								 DoGetAttenuatesWithDistance() const override;										 // 04 - { return data.flags & 1; }
		virtual bool								 DoGetAudibility(float a_distance) const override;									 // 05 - { float maxDistance = attenuationValues ? attenuationValues->GetMaxDistance() : 3.4028235e38; return a_distance > maxDistance; }
		virtual UInt32								 DoGetSupportedInputChannels() const override;										 // 06 - { return 2; }
		virtual const BSIAttenuationCharacteristics* DoGetAttenuation() const override;													 // 07 - { return attenuationValues; }
		virtual float								 DoGetReverbSendLevel() const override;												 // 08 - { return data.reverbSendPct * 0.0099999998; }
		virtual bool								 DoGetSupportsMonitor(UInt32 a_arg1) const override;								 // 09


		// members
		Data							   data;			// 28 - NAM1
		Type							   type;			// 2C - MNAM
		DynamicAttenuationCharacteristics* attenuation;		// 30 - ANAM
		SpeakerArrays*					   speakerOutputs;	// 38 - ONAM
	};
	STATIC_ASSERT(sizeof(BGSSoundOutput) == 0x40);
}
