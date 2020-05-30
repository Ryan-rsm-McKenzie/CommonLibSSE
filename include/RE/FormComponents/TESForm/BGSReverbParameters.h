#pragma once

#include "RE/BSIReverbType.h"
#include "RE/FormTypes.h"
#include "RE/TESForm.h"


namespace RE
{
	class BGSReverbParameters :
		public TESForm,		  // 00
		public BSIReverbType  // 20
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSReverbParameters;
		inline static constexpr auto FORMTYPE = FormType::ReverbParam;


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct ReverbParams	 // DATA
		{
			UInt16 decayTime;		 // 00 - in ms
			UInt16 hfReference;		 // 02 - in Hz
			SInt8  roomFilter;		 // 04
			SInt8  roomHFFilter;	 // 05
			SInt8  reflections;		 // 06
			SInt8  reverb;			 // 07
			SInt8  decayHFRatio;	 // 08
			SInt8  reflectionDelay;	 // 09 - in ms
			SInt8  reverbDelay;		 // 0A - in ms
			SInt8  diffusionPct;	 // 0B
			SInt8  densityPct;		 // 0C
			UInt8  pad0D;			 // 0D
		};
		STATIC_ASSERT(sizeof(ReverbParams) == 0xE);


		virtual ~BGSReverbParameters();	 // 00

		// override (TESForm)
		virtual void InitializeData() override;		 // 04
		virtual bool Load(TESFile* a_mod) override;	 // 06

		// override (BSIReverbType)
		virtual SInt32 DoGetRoomLevel() const override;		   // 00 - { return data.roomFilter * 100; }
		virtual SInt32 DoGetRoomHFLevel() const override;	   // 01 - { return data.roomHFFilter * 100; }
		virtual float  DoGetDecayTime() const override;		   // 02 - { return data.decayTime * 0.001; }
		virtual float  DoGetDecayHFRatio() const override;	   // 03 - { return data.decayHFRatio * 0.0099999998; }
		virtual SInt32 DoGetReflectionLevel() const override;  // 04 - { return data.reflections * 100; }
		virtual float  DoGetReflectionDelay() const override;  // 05 - { return data.reflectDelay * 0.0012000001; }
		virtual SInt32 DoGetReverbLevel() const override;	   // 06 - { return data.reverb * 100; }
		virtual float  DoGetReverbDelay() const override;	   // 07 - { return data.reverbDelay * 0.001; }
		virtual float  DoGetDiffusion() const override;		   // 08 - { return data.diffusionPct; }
		virtual float  DoGetDensity() const override;		   // 09 - { return data.densityPct; }
		virtual float  DoGetHFReference() const override;	   // 0A - { return data.hfReference; }


		// members
		ReverbParams data;	 // 28 - DATA
		UInt16		 pad36;	 // 36
	};
	STATIC_ASSERT(sizeof(BGSReverbParameters) == 0x38);
}
