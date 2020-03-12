#pragma once

#include "RE/BGSPreloadable.h"
#include "RE/FormTypes.h"
#include "RE/TESBoundObject.h"
#include "RE/TESFullName.h"
#include "RE/TESImageSpaceModifiableForm.h"
#include "RE/TESModel.h"


namespace RE
{
	struct BGSHazardData  // DATA
	{
	public:
		enum class BGSHazardFlags : UInt32
		{
			kNone = 0,
			kPCOnly = 1 << 0,
			kInheritDuration = 1 << 1,
			kAlignToNormal = 1 << 2,
			kInheritRadius = 1 << 3,
			kDropToGround = 1 << 4
		};


		UInt32					limit;			   // 00
		float					radius;			   // 04
		float					lifetime;		   // 08
		float					imageSpaceRadius;  // 0C
		float					targetInterval;	   // 10
		BGSHazardFlags			flags;			   // 14
		SpellItem*				spell;			   // 18
		TESObjectLIGH*			light;			   // 20
		BGSImpactDataSet*		impactDataSet;	   // 28
		BGSSoundDescriptorForm* sound;			   // 30
	};
	STATIC_ASSERT(sizeof(BGSHazardData) == 0x38);


	class BGSHazard :
		public TESBoundObject,				// 00
		public TESFullName,					// 30
		public TESModel,					// 40
		public BGSPreloadable,				// 68
		public TESImageSpaceModifiableForm	// 70
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSHazard;
		inline static constexpr auto FORMTYPE = FormType::Hazard;


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSHazard();  // 00

		// override (TESBoundObject)
		virtual void InitializeData() override;		 // 04
		virtual bool Load(TESFile* a_mod) override;	 // 06
		virtual void InitItemImpl() override;		 // 13


		// members
		BGSHazardData data;	 // 80 - DATA
	};
	STATIC_ASSERT(sizeof(BGSHazard) == 0xB8);
}
