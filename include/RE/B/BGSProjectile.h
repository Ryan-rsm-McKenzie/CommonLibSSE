#pragma once

#include "RE/B/BGSDestructibleObjectForm.h"
#include "RE/B/BGSPreloadable.h"
#include "RE/F/FormTypes.h"
#include "RE/S/SoundLevels.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESModel.h"

namespace RE
{
	struct BGSProjectileData  // DATA
	{
	public:
		enum class BGSProjectileFlags
		{
			kNone = 0,
			kHitScan = 1 << 0,
			kExplosion = 1 << 1,
			kExplosionAltTrigger = 1 << 2,
			kMuzzleFlash = 1 << 3,
			kCanTurnOff = 1 << 5,
			kCanPickUp = 1 << 6,
			kSupersonic = 1 << 7,
			kPinsLimbs = 1 << 8,
			kPassSMTransparent = 1 << 9,
			kDisableCombatAimCorrection = 1 << 10,
			kContinuousUpdate = 1 << 11
		};

		enum class Type
		{
			kMissile = 1 << 0,
			kGrenade = 1 << 1,
			kBeam = 1 << 2,
			kFlamethrower = 1 << 3,
			kCone = 1 << 4,
			kBarrier = 1 << 5,
			kArrow = 1 << 6
		};

		// members
		stl::enumeration<BGSProjectileFlags, std::uint16_t> flags;				  // 00
		stl::enumeration<Type, std::uint16_t>				types;				  // 02
		float												gravity;			  // 04
		float												speed;				  // 08
		float												range;				  // 0C
		TESObjectLIGH*										light;				  // 10
		TESObjectLIGH*										muzzleFlashLight;	  // 18
		float												tracerChance;		  // 20
		float												explosionProximity;	  // 24
		float												explosionTimer;		  // 28
		std::uint32_t										pad2C;				  // 2C
		BGSExplosion*										explosionType;		  // 30
		BGSSoundDescriptorForm*								activeSoundLoop;	  // 38
		float												muzzleFlashDuration;  // 40
		float												fadeOutTime;		  // 44
		float												force;				  // 48
		std::uint32_t										pad4C;				  // 4C
		BGSSoundDescriptorForm*								countdownSound;		  // 50
		BGSSoundDescriptorForm*								deactivateSound;	  // 58
		TESObjectWEAP*										defaultWeaponSource;  // 60
		float												coneSpread;			  // 68
		float												collisionRadius;	  // 6C
		float												lifetime;			  // 70
		float												relaunchInterval;	  // 74
		BGSTextureSet*										decalData;			  // 78
		BGSCollisionLayer*									collisionLayer;		  // 80
	};
	static_assert(sizeof(BGSProjectileData) == 0x88);

	class BGSProjectile :
		public TESBoundObject,			  // 000
		public TESFullName,				  // 030
		public TESModel,				  // 040
		public BGSPreloadable,			  // 068
		public BGSDestructibleObjectForm  // 070
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSProjectile;
		inline static constexpr auto FORMTYPE = FormType::Projectile;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		virtual ~BGSProjectile();  // 00

		// override (TESBoundObject)
		virtual void		InitializeData() override;																																  // 04
		virtual void		ClearData() override;																																	  // 05
		virtual bool		Load(TESFile* a_mod) override;																															  // 06
		virtual void		InitItemImpl() override;																																  // 13
		virtual bool		Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, std::uint8_t a_arg3, TESBoundObject* a_object, std::int32_t a_targetCount) override;  // 37
		virtual NiAVObject* Clone3D(TESObjectREFR* a_ref, bool a_arg3) override;																									  // 40
		virtual void		UnClone3D(TESObjectREFR* a_ref) override;																												  // 41
		virtual bool		GetActivateText(TESObjectREFR* a_activator, BSString& a_dst) override;																					  // 4C

		// members
		BGSProjectileData data;				 // 080 - DATA
		TESModel		  muzzleFlashModel;	 // 108
		SOUND_LEVEL		  soundLevel;		 // 130 - VNAM
		std::uint32_t	  pad134;			 // 134
	};
	static_assert(sizeof(BGSProjectile) == 0x138);
}
