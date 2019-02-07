#pragma once

#include "RE/BGSDestructibleObjectForm.h"  // BGSDestructibleObjectForm
#include "RE/BGSEquipType.h"  // BGSEquipType
#include "RE/BGSMessageIcon.h"  // BGSMessageIcon
#include "RE/Color.h"  // Color
#include "RE/FormTypes.h"  // FormType
#include "RE/TESBoundAnimObject.h"  // TESBoundAnimObject
#include "RE/TESFullName.h"  // TESFullName
#include "RE/TESIcon.h"  // TESIcon
#include "RE/TESModelTextureSwap.h"  // TESModelTextureSwap
#include "RE/TESValueForm.h"  // TESValueForm
#include "RE/TESWeightForm.h"  // TESWeightForm


namespace RE
{
	class TESObjectLIGH :
		public TESBoundAnimObject,			// 000
		public TESFullName,					// 030
		public TESModelTextureSwap,			// 040
		public TESIcon,						// 078
		public BGSMessageIcon,				// 088
		public TESWeightForm,				// 0A0
		public TESValueForm,				// 0B0
		public BGSDestructibleObjectForm,	// 0C0
		public BGSEquipType					// 0D0
	{
	public:
		enum { kTypeID = FormType::Light };


		enum class Flag : UInt32
		{
			kTypeOmni = 0,
			kDynamic = 1 << 0,
			kCarryable = 1 << 1,
			kNegative = 1 << 2,
			kFlicker = 1 << 3,
			kUnk00000010 = 1 << 4,
			kOffByDefault = 1 << 5,
			kFlickerSlow = 1 << 6,
			kPulse = 1 << 7,
			kPulseSlow = 1 << 8,
			kTypeSpot = 1 << 9,
			kTypeSpotShadow = 1 << 10,
			kTypeHemiShadow = 1 << 11,
			kTypeOmniShadow = 1 << 12,
			kPortalStrict = 1 << 13,

			kType = kTypeSpot | kTypeSpotShadow | kTypeHemiShadow | kTypeOmniShadow
		};


		struct DataE0
		{
			struct FlickerEffect
			{
				UInt32	period;				// 0
				UInt32	intensityAmplitude;	// 4
				UInt32	movementAmplitude;	// 8
			};
			STATIC_ASSERT(sizeof(FlickerEffect) == 0xC);


			SInt32			time;			// 00
			UInt32			radius;			// 04
			Color			color;			// 08
			Flag			flags;			// 0C
			UInt32			fallofExponent;	// 10
			float			FOV;			// 14 - 90
			float			nearClip;		// 18 - .001
			FlickerEffect	flickerEffect;	// 1C
		};
		STATIC_ASSERT(sizeof(DataE0) == 0x28);


		struct Data118
		{
			UInt64	unk0;	// 00
			UInt32	unk4;	// 08
			UInt32	padC;	// 0C
			UInt64	unk8;	// 10
		};
		STATIC_ASSERT(sizeof(Data118) == 0x18);


		virtual ~TESObjectLIGH();																															// 00

		// override (TESBoundAnimObject)
		virtual bool	LoadForm(TESFile* a_mod) override;																									// 06
		virtual void	SaveBuffer(BGSSaveFormBuffer* a_buf) override;																						// 0E
		virtual void	LoadBuffer(BGSLoadFormBuffer* a_buf) override;																						// 0F
		virtual void	InitItem() override;																												// 13
		virtual bool	ActivateReference(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, UInt8 a_arg3, UInt64 a_arg4, UInt32 a_arg5) override;	// 37

		bool			CanBeCarried() const;


		DataE0	unkE0;		// 0E0 - DATA
		float	fadeValue;	// 108 - FNAM
		UInt32	pad10C;		// 10C - SNAM
		UInt64	unk110;		// 110
		Data118	unk118;		// 118
	};
	STATIC_ASSERT(sizeof(TESObjectLIGH) == 0x130);
}
