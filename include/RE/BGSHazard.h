#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSHazard

#include "RE/BGSPreloadable.h"  // BGSPreloadable
#include "RE/FormTypes.h"  // FormType
#include "RE/TESBoundObject.h"  // TESBoundObject
#include "RE/TESFullName.h"  // TESFullName
#include "RE/TESImageSpaceModifiableForm.h"  // TESImageSpaceModifiableForm
#include "RE/TESModel.h"  // TESModel


namespace RE
{
	class BGSHazard :
		public TESBoundObject,				// 00
		public TESFullName,					// 30
		public TESModel,					// 40
		public BGSPreloadable,				// 68
		public TESImageSpaceModifiableForm	// 70
	{
	public:
		inline static const void* RTTI = RTTI_BGSHazard;


		enum { kTypeID = FormType::Hazard };


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
		public:
			enum class Flag : UInt32
			{
				kNone = 0,
				kAffectsPlayerOnly = 1 << 0,
				kInheritDurationFromSpawnCell = 1 << 1,
				kAlignToImpactNormal = 1 << 2,
				kInheritRadiusFromSpawnCell = 1 << 3,
				kDropToGround = 1 << 4
			};


			UInt32					limit;				// 00
			float					radius;				// 04
			float					lifetime;			// 08
			float					imageSpaceRadius;	// 0C
			float					targetInterval;		// 10
			Flag					flags;				// 14
			SpellItem*				spell;				// 18
			TESObjectLIGH*			light;				// 20
			BGSImpactDataSet*		impactDataSet;		// 28
			BGSSoundDescriptorForm*	sound;				// 30
		};
		STATIC_ASSERT(sizeof(Data) == 0x38);


		virtual ~BGSHazard();								// 00

		// override (TESBoundObject)
		virtual void	InitDefaults() override;			// 04
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06
		virtual void	InitItem() override;				// 13


		// members
		Data data;	// 80 - DATA
	};
	STATIC_ASSERT(sizeof(BGSHazard) == 0xB8);
}
