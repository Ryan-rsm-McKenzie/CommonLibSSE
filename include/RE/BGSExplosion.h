#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSExplosion

#include "RE/BGSPreloadable.h"  // BGSPreloadable
#include "RE/FormTypes.h"  // FormType
#include "RE/SoundLevels.h"  // SoundLevel
#include "RE/TESBoundObject.h"  // TESBoundObject
#include "RE/TESEnchantableForm.h"  // TESEnchantableForm
#include "RE/TESFullName.h"  // TESFullName
#include "RE/TESImageSpaceModifiableForm.h"  // TESImageSpaceModifiableForm
#include "RE/TESModel.h"  // TESModel


namespace RE
{
	class BGSExplosion :
		public TESBoundObject,				// 00
		public TESFullName,					// 30
		public TESModel,					// 40
		public TESEnchantableForm,			// 68
		public BGSPreloadable,				// 80
		public TESImageSpaceModifiableForm	// 88
	{
	public:
		inline static const void* RTTI = RTTI_BGSExplosion;


		enum { kTypeID = FormType::Explosion };


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


			TESObjectLIGH*			light;				// 00
			BGSSoundDescriptorForm* sound1;				// 08
			BGSSoundDescriptorForm* sound2;				// 10
			BGSImpactDataSet*		impactDataSet;		// 18
			TESObjectREFR*			placedObject;		// 20
			BGSProjectile*			spawnProjectile;	// 28
			float					force;				// 30
			float					damage;				// 34
			float					radius;				// 38
			float					isRadius;			// 3C
			float					verticalOffsetMult;	// 40
			Flag					flags;				// 44
			SoundLevel				soundLevels;		// 48
			UInt32					pad4C;				// 4C
		};
		STATIC_ASSERT(sizeof(Data) == 0x50);


		virtual ~BGSExplosion();							// 00

		// override (TESBoundObject)
		virtual void	InitDefaults() override;			// 04
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06
		virtual void	InitItem() override;				// 13
		virtual void	Unk_40(void) override;				// 40
		virtual void	Unk_41(void) override;				// 41


		// members
		Data data;	// 98 - DATA
	};
	STATIC_ASSERT(sizeof(BGSExplosion) == 0xE8);
}
