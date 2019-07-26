#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSProjectile

#include "RE/BGSDestructibleObjectForm.h"  // BGSDestructibleObjectForm
#include "RE/BGSPreloadable.h"  // BGSPreloadable
#include "RE/FormTypes.h"  // FormType
#include "RE/SoundLevels.h"  // SoundLevel
#include "RE/TESBoundObject.h"  // TESBoundObject
#include "RE/TESFullName.h"  // TESFullName
#include "RE/TESModel.h"  // TESModel


namespace RE
{
	class BGSProjectile :
		public TESBoundObject,				// 000
		public TESFullName,					// 030
		public TESModel,					// 040
		public BGSPreloadable,				// 068
		public BGSDestructibleObjectForm	// 070
	{
	public:
		inline static const void* RTTI = RTTI_BGSProjectile;


		enum { kTypeID = FormType::Projectile };


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
			enum class Flag : UInt16
			{
				kNone = 0,
				kHitScan = 1 << 0,
				kExplosion = 1 << 1,
				kAltTrigger = 1 << 2,
				kMuzzleFlash = 1 << 3,
				kCanBeDisabled = 1 << 5,
				kCanBePickedUp = 1 << 6,
				kSupersonic = 1 << 7,
				kPinsLimbs = 1 << 8,
				kPassThroughSmallTransparentObjects = 1 << 9,
				kDisableCombatAimCorrection = 1 << 10,
				kRotation = 1 << 11
			};


			enum class Type : UInt16
			{
				kMissile = 1 << 0,
				kLobber = 1 << 1,
				kBeam = 1 << 2,
				kFlame = 1 << 3,
				kCone = 1 << 4,
				kBarrier = 1 << 5,
				kArrow = 1 << 6
			};


			Flag					flags;							// 00
			Type					types;							// 02
			float					gravity;						// 04
			float					speed;							// 08
			float					range;							// 0C
			TESObjectLIGH*			light;							// 10
			TESObjectLIGH*			muzzleFlash;					// 18
			float					tracerChance;					// 20
			float					explosionAltTriggerProximity;	// 24
			float					explosionAltTriggerTimer;		// 28
			UInt32					unk2C;							// 2C
			BGSExplosion*			explosion;						// 30
			BGSSoundDescriptorForm*	sound;							// 38
			float					muzzleFlashDuration;			// 40
			float					fadeDuration;					// 44
			float					impactForce;					// 48
			UInt32					unk4C;							// 4C
			BGSSoundDescriptorForm*	soundCountdown;					// 50
			BGSSoundDescriptorForm*	soundDisable;					// 58
			TESObjectWEAP*			defaultWeaponSource;			// 60
			float					coneSpread;						// 68
			float					collisionRadius;				// 6C
			float					lifetime;						// 70
			float					relaunchInterval;				// 74
			BGSTextureSet*			decalData;						// 78
			BGSCollisionLayer*		collisionLayer;					// 80
		};
		STATIC_ASSERT(sizeof(Data) == 0x88);


		virtual ~BGSProjectile();																																	// 00

		// override (TESBoundObject)
		virtual void	InitDefaults() override;																													// 04
		virtual void	ReleaseManagedData() override;																												// 05
		virtual bool	LoadForm(TESFile* a_mod) override;																											// 06
		virtual void	InitItem() override;																														// 13
		virtual bool	ActivateReference(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, UInt8 a_arg3, UInt64 a_arg4, SInt32 a_targetCount) override;	// 37
		virtual void	Unk_40(void) override;																														// 40
		virtual void	Unk_41(void) override;																														// 41
		virtual bool	GetCrosshairText(TESObjectREFR* a_ref, BSString* a_dst) override;																			// 4C


		// members
		Data		data;				// 080 - DATA
		TESModel	muzzleFlashModel;	// 108
		SoundLevel	soundLevel;			// 130 - VNAM
		UInt32		unk134;				// 134
	};
	STATIC_ASSERT(sizeof(BGSProjectile) == 0x138);
}
