#pragma once

#include "RE/BGSDestructibleObjectForm.h"
#include "RE/BGSEquipType.h"
#include "RE/BGSMessageIcon.h"
#include "RE/Color.h"
#include "RE/FormTypes.h"
#include "RE/TESBoundAnimObject.h"
#include "RE/TESFullName.h"
#include "RE/TESIcon.h"
#include "RE/TESModelTextureSwap.h"
#include "RE/TESValueForm.h"
#include "RE/TESWeightForm.h"


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
		inline static const void* RTTI = RTTI_TESObjectLIGH;


		enum { kTypeID = FormType::Light };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12,
				kRandomAnimStart = 1 << 16,
				kPortalStrict = 1 << 17,
				kObstacle = 1 << 25
			};
		};


		struct Data	// DATA
		{
			enum class Flag : UInt32
			{
				kNone = 0,
				kDynamic = 1 << 0,
				kCanBeCarried = 1 << 1,
				kNegative = 1 << 2,
				kFlicker = 1 << 3,
				kOffByDefault = 1 << 5,
				kFlickerSlow = 1 << 6,
				kPulse = 1 << 7,
				kPulseSlow = 1 << 8,
				kSpotlight = 1 << 9,
				kShadowSpotlight = 1 << 10,
				kShadowHemisphere = 1 << 11,
				kShadowOmnidirectional = 1 << 12,
				kPortalStrict = 1 << 13
			};


			struct FlickerEffect
			{
				float GetPeriod() const;


				// members
				float	period;				// 0 - CK value * 100
				float	intensityAmplitude;	// 4
				float	movementAmplitude;	// 8
			};
			STATIC_ASSERT(sizeof(FlickerEffect) == 0xC);


			// members
			SInt32			time;			// 00
			UInt32			radius;			// 04
			Color			color;			// 08
			Flag			flags;			// 0C
			float			fallofExponent;	// 10
			float			fov;			// 14
			float			nearClip;		// 18
			FlickerEffect	flickerEffect;	// 1C
		};
		STATIC_ASSERT(sizeof(Data) == 0x28);


		virtual ~TESObjectLIGH();																															// 00

		// override (TESBoundAnimObject)
		virtual void	InitializeData() override;																											// 04
		virtual bool	Load(TESFile* a_mod) override;																										// 06
		virtual void	SaveGame(BGSSaveFormBuffer* a_buf) override;																						// 0E
		virtual void	LoadGame(BGSLoadFormBuffer* a_buf) override;																						// 0F
		virtual void	InitItemImpl() override;																											// 13
		virtual bool	Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, UInt8 a_arg3, UInt64 a_arg4, SInt32 a_targetCount) override;	// 37
		virtual void	Unk_41(void) override;																												// 41
		virtual void	Unk_47(void) override;																												// 47
		virtual void	Unk_4A(void) override;																												// 4A

		bool			CanBeCarried() const;


		// members
		Data					data;		// 0E0 - DATA
		float					fadeValue;	// 108 - FNAM
		UInt32					pad10C;		// 10C
		BGSSoundDescriptorForm*	sound;		// 110 - SNAM
		UInt64					unk118;		// 118
		UInt64					unk120;		// 120
		BGSLensFlare*			unk128;		// 128
	};
	STATIC_ASSERT(sizeof(TESObjectLIGH) == 0x130);
}
