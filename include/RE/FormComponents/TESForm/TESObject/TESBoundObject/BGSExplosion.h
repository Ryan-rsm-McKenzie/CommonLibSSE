#pragma once

#include "RE/FormComponents/BGSPreloadable.h"
#include "RE/FormComponents/Enums/FormTypes.h"
#include "RE/FormComponents/Enums/SoundLevels.h"
#include "RE/FormComponents/TESEnchantableForm.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESBoundObject.h"
#include "RE/FormComponents/TESFullName.h"
#include "RE/FormComponents/TESImageSpaceModifiableForm.h"
#include "RE/FormComponents/TESModel/TESModel.h"


namespace RE
{
	struct BGSExplosionData	 // DATA
	{
		enum class Flag : UInt32
		{
			kNone = 0,
			kAlwaysUsesWorldOrientation = 1 << 1,
			kKnockDown_Always = 1 << 2,
			kKnockDown_ByFormula = 1 << 3,
			kIgnoreLOSCheck = 1 << 4,
			kPushExplosionSourceRefOnly = 1 << 5,
			kIgnoreImageSpaceSwap = 1 << 6,
			kChain = 1 << 7,
			kNoControllerVibration = 1 << 8
		};


		TESObjectLIGH*			light;				 // 00
		BGSSoundDescriptorForm* sound1;				 // 08
		BGSSoundDescriptorForm* sound2;				 // 10
		BGSImpactDataSet*		impactDataSet;		 // 18
		TESObjectREFR*			impactPlacedObject;	 // 20
		BGSProjectile*			spawnProjectile;	 // 28
		float					force;				 // 30
		float					damage;				 // 34
		float					radius;				 // 38
		float					imageSpaceRadius;	 // 3C
		float					verticalOffsetMult;	 // 40
		Flag					flags;				 // 44
		SOUND_LEVEL				eSoundLevel;		 // 48
		UInt32					pad4C;				 // 4C
	};
	STATIC_ASSERT(sizeof(BGSExplosionData) == 0x50);


	class BGSExplosion :
		public TESBoundObject,				// 00
		public TESFullName,					// 30
		public TESModel,					// 40
		public TESEnchantableForm,			// 68
		public BGSPreloadable,				// 80
		public TESImageSpaceModifiableForm	// 88
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSExplosion;
		inline static constexpr auto FORMTYPE = FormType::Explosion;


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSExplosion();  // 00

		// override (TESBoundObject)
		virtual void		InitializeData() override;							  // 04
		virtual bool		Load(TESFile* a_mod) override;						  // 06
		virtual void		InitItemImpl() override;							  // 13
		virtual NiAVObject* Clone3D(TESObjectREFR* a_ref, bool a_arg3) override;  // 40
		virtual void		UnClone3D(TESObjectREFR* a_ref) override;			  // 41


		// members
		BGSExplosionData data;	// 98 - DATA
	};
	STATIC_ASSERT(sizeof(BGSExplosion) == 0xE8);
}
