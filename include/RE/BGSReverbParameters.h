#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSReverbParameters

#include "RE/BSIReverbType.h"  // BSIReverbType
#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	class BGSReverbParameters :
		public TESForm,			// 00
		public BSIReverbType	// 20
	{
	public:
		inline static const void* RTTI = RTTI_BGSReverbParameters;


		enum { kTypeID = FormType::ReverbParam };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct Data	// DATA
		{
			UInt16	decayTime;		// 00 - in ms
			UInt16	hfReference;	// 02 - in Hz
			SInt8	roomFilter;		// 04
			SInt8	roomHFFilter;	// 05
			SInt8	reflections;	// 06
			SInt8	reverbAmp;		// 07
			UInt8	decayHFRatio;	// 08
			UInt8	reflectDelay;	// 09 - in ms
			UInt8	reverbDelay;	// 0A - in ms
			UInt8	diffusionPct;	// 0B
			UInt8	densityPct;		// 0C
			UInt8	unk0D;			// 0D
			UInt16	unk0E;			// 0E
		};
		STATIC_ASSERT(sizeof(Data) == 0x10);


		virtual ~BGSReverbParameters();						// 00

		// override (TESForm)
		virtual void	InitDefaults() override;			// 04
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06

		// override (BSIReverbType)
		virtual UInt32	GetRoomFilter() const override;		// 00 - { return data.roomFilter * 100; }
		virtual UInt32	GetRoomHFFilter() const override;	// 01 - { return data.roomHFFilter * 100; }
		virtual float	GetDecayTime() const override;		// 02 - { return data.decayTime * 0.001; }
		virtual float	GetDecayHFRatio() const override;	// 03 - { return data.decayHFRatio * 0.0099999998; }
		virtual UInt32	GetReflections() const override;	// 04 - { return data.reflections * 100; }
		virtual float	GetReflectDelay() const override;	// 05 - { return data.reflectDelay * 0.0012000001; }
		virtual UInt32	GetReverbAmp() const override;		// 06 - { return data.reverbAmp * 100; }
		virtual float	GetReverbDelay() const override;	// 07 - { return data.reverbDelay * 0.001; }
		virtual UInt32	GetDiffusionPct() const override;	// 08 - { return data.diffusionPct; }
		virtual UInt32	GetDensityPct() const override;		// 09 - { return data.densityPct; }
		virtual UInt32	GetHFReference() const override;	// 0A - { return data.hfReference; }


		// members
		Data data;	// 28 - DATA
	};
	STATIC_ASSERT(sizeof(BGSReverbParameters) == 0x38);
}
