#pragma once


namespace RE
{
	class BSISoundOutputModel
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSISoundOutputModel;


		struct BSIAttenuationCharacteristics
		{
			inline static constexpr auto RTTI = RTTI_BSISoundOutputModel__BSIAttenuationCharacteristics;


			virtual ~BSIAttenuationCharacteristics();  // 00

			// add
			virtual float GetMaxDistance() const = 0;			  // 01
			virtual float GetMinDistance() const = 0;			  // 02
			virtual UInt8 GetCurveValue(UInt32 a_idx) const = 0;  // 03
		};
		STATIC_ASSERT(sizeof(BSIAttenuationCharacteristics) == 0x8);


		virtual ~BSISoundOutputModel();	 // 00

		// add
		virtual bool								 DoGetUsesHRTF() const = 0;														// 01
		virtual bool								 DoGetHasSpeakerBias() const = 0;												// 02
		virtual bool								 DoGetSpeakerBias(UInt32 a_arg1, UInt32 a_arg2, float (&a_arg3)[8]) const = 0;	// 03
		virtual bool								 DoGetAttenuatesWithDistance() const = 0;										// 04
		virtual bool								 DoGetAudibility(float a_distance) const = 0;									// 05
		virtual UInt32								 DoGetSupportedInputChannels() const = 0;										// 06
		virtual const BSIAttenuationCharacteristics* DoGetAttenuation() const = 0;													// 07
		virtual float								 DoGetReverbSendLevel() const = 0;												// 08
		virtual bool								 DoGetSupportsMonitor(UInt32 a_arg1) const = 0;									// 09
	};
	STATIC_ASSERT(sizeof(BSISoundOutputModel) == 0x8);
}
