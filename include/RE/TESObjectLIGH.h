#pragma once

#include "RE/BGSDestructibleObjectForm.h"
#include "RE/BGSEquipType.h"
#include "RE/BGSMessageIcon.h"
#include "RE/Color.h"
#include "RE/FormTypes.h"
#include "RE/NiColor.h"
#include "RE/TESBoundAnimObject.h"
#include "RE/TESFullName.h"
#include "RE/TESIcon.h"
#include "RE/TESModelTextureSwap.h"
#include "RE/TESValueForm.h"
#include "RE/TESWeightForm.h"


namespace RE
{
	enum class TES_LIGHT_FLAGS : UInt32
	{
		kNone = 0,
		kDynamic = 1 << 0,
		kCanCarry = 1 << 1,
		kNegative = 1 << 2,
		kFlicker = 1 << 3,
		kDeepCopy = 1 << 4,
		kOffByDefault = 1 << 5,
		kFlickerSlow = 1 << 6,
		kPulse = 1 << 7,
		kPulseSlow = 1 << 8,
		kSpotlight = 1 << 9,
		kSpotShadow = 1 << 10,
		kHemiShadow = 1 << 11,
		kOmniShadow = 1 << 12,
		kPortalStrict = 1 << 13
	};


	struct OBJ_LIGH	 // DATA
	{
		// members
		SInt32			time;						// 00
		UInt32			radius;						// 04
		Color			color;						// 08
		TES_LIGHT_FLAGS flags;						// 0C
		float			fallofExponent;				// 10
		float			fov;						// 14
		float			nearDistance;				// 18
		float			flickerPeriodRecip;			// 1C - CK value * 100
		float			flickerIntensityAmplitude;	// 20
		float			flickerMovementAmplitude;	// 24
	};
	STATIC_ASSERT(sizeof(OBJ_LIGH) == 0x28);


	class TESObjectLIGH :
		public TESBoundAnimObject,		   // 000
		public TESFullName,				   // 030
		public TESModelTextureSwap,		   // 040
		public TESIcon,					   // 078
		public BGSMessageIcon,			   // 088
		public TESWeightForm,			   // 0A0
		public TESValueForm,			   // 0B0
		public BGSDestructibleObjectForm,  // 0C0
		public BGSEquipType				   // 0D0
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESObjectLIGH;
		inline static constexpr auto FORMTYPE = FormType::Light;


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


		virtual ~TESObjectLIGH();  // 00

		// override (TESBoundAnimObject)
		virtual void		InitializeData() override;																													 // 04
		virtual bool		Load(TESFile* a_mod) override;																												 // 06
		virtual void		SaveGame(BGSSaveFormBuffer* a_buf) override;																								 // 0E
		virtual void		LoadGame(BGSLoadFormBuffer* a_buf) override;																								 // 0F
		virtual void		InitItemImpl() override;																													 // 13
		virtual bool		Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, UInt8 a_arg3, TESBoundObject* a_object, SInt32 a_targetCount) override;	 // 37
		virtual void		UnClone3D(TESObjectREFR* a_ref) override;																									 // 41
		virtual NiAVObject* LoadGraphics(TESObjectREFR* a_ref) override;																								 // 47
		virtual NiAVObject* Clone3D(TESObjectREFR* a_ref) override;																										 // 4A

		// override (BGSEquipType)
		virtual BGSEquipSlot* GetEquipSlot() const override;				// 04
		virtual void		  SetEquipSlot(BGSEquipSlot* a_slot) override;	// 05 - { return; }

		bool CanBeCarried() const;


		// members
		OBJ_LIGH				data;			 // 0E0 - DATA
		float					fade;			 // 108 - FNAM
		UInt32					pad10C;			 // 10C
		BGSSoundDescriptorForm* sound;			 // 110 - SNAM
		NiColor					emittanceColor;	 // 118
		UInt32					pad124;			 // 124
		BGSLensFlare*			lensFlare;		 // 128
	};
	STATIC_ASSERT(sizeof(TESObjectLIGH) == 0x130);
}
