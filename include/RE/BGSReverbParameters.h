#pragma once

#include "RE/BSIReverbType.h"
#include "RE/FormTypes.h"
#include "RE/TESForm.h"


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


		struct ReverbParams	// DATA
		{
			UInt16	decayTime;			// 00 - in ms
			UInt16	hfReference;		// 02 - in Hz
			SInt8	roomFilter;			// 04
			SInt8	roomHFFilter;		// 05
			SInt8	reflections;		// 06
			SInt8	reverb;				// 07
			UInt8	decayHFRatio;		// 08
			UInt8	reflectionDelay;	// 09 - in ms
			UInt8	reverbDelay;		// 0A - in ms
			UInt8	diffusionPct;		// 0B
			UInt8	densityPct;			// 0C
			UInt8	pad0D;				// 0D
		};
		STATIC_ASSERT(sizeof(ReverbParams) == 0xE);


		virtual ~BGSReverbParameters();					// 00

		// override (TESForm)
		virtual void	InitializeData() override;		// 04
		virtual bool	Load(TESFile* a_mod) override;	// 06

		// override (BSIReverbType)
		virtual UInt32	GetRoomFilter() const override;		// 00 - { return data.roomFilter * 100; }
		virtual UInt32	GetRoomHFFilter() const override;	// 01 - { return data.roomHFFilter * 100; }
		virtual float	GetDecayTime() const override;		// 02 - { return data.decayTime * 0.001; }
		virtual float	GetDecayHFRatio() const override;	// 03 - { return data.decayHFRatio * 0.0099999998; }
		virtual UInt32	GetReflections() const override;	// 04 - { return data.reflections * 100; }
		virtual float	GetReflectDelay() const override;	// 05 - { return data.reflectDelay * 0.0012000001; }
		virtual UInt32	GetReverbAmp() const override;		// 06 - { return data.reverb * 100; }
		virtual float	GetReverbDelay() const override;	// 07 - { return data.reverbDelay * 0.001; }
		virtual UInt32	GetDiffusionPct() const override;	// 08 - { return data.diffusionPct; }
		virtual UInt32	GetDensityPct() const override;		// 09 - { return data.densityPct; }
		virtual UInt32	GetHFReference() const override;	// 0A - { return data.hfReference; }


		// members
		ReverbParams	data;	// 28 - DATA
		UInt16			pad36;	// 36
	};
	STATIC_ASSERT(sizeof(BGSReverbParameters) == 0x38);
}
