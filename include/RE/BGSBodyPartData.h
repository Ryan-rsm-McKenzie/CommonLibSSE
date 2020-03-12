#pragma once

#include "RE/ActorValues.h"
#include "RE/BGSBodyPartDefs.h"
#include "RE/BGSPreloadable.h"
#include "RE/BSFixedString.h"
#include "RE/FormTypes.h"
#include "RE/NiPoint3.h"
#include "RE/TESForm.h"
#include "RE/TESModel.h"
#include "RE/TESModelPSA.h"


namespace RE
{
	struct PART_DATA  // BPND
	{
	public:
		using Type = BGSBodyPartDefs::LIMB_ENUM_8;


		enum class Flag : UInt8
		{
			kNone = 0,
			kSeverable = 1 << 0,
			kIKData = 1 << 1,
			kIKData_BipedData = 1 << 2,
			kExplodable = 1 << 3,
			kIKData_IsHead = 1 << 4,
			kIKData_HeadTracking = 1 << 5,
			kToHitChance_Absolute = 1 << 6
		};


		// members
		float			  damageMult;					// 00
		Flag			  flags;						// 04
		Type			  type;							// 05
		SInt8			  healthPercent;				// 06
		ActorValue8		  actorValue;					// 07
		SInt8			  toHitChance;					// 08
		SInt8			  explosionChance;				// 09
		SInt8			  explosionGenericDebrisCount;	// 0A
		UInt8			  pad0B;						// 0B
		UInt32			  pad0C;						// 0C
		BGSDebris*		  explosionGenericDebris;		// 10
		BGSExplosion*	  explosion;					// 18
		float			  trackingMaxAngle;				// 20
		float			  explosionGenericDebrisScale;	// 24
		SInt8			  dismemberGenericDebrisCount;	// 28
		SInt8			  unk29;						// 29
		UInt16			  unk2A;						// 2A
		UInt32			  unk2C;						// 2C
		BGSDebris*		  dismemberGenericDebris;		// 30
		BGSExplosion*	  dismemberExplosion;			// 38
		float			  dismemberGenericDebrisScale;	// 40
		NiPoint3		  goreTranslate;				// 44
		NiPoint3		  goreRotate;					// 50
		UInt32			  pad5C;						// 5C
		BGSImpactDataSet* dismemberImpactDataSet;		// 60
		BGSImpactDataSet* explosionImpactDataSet;		// 68
		SInt8			  dismemberDecalCount;			// 70
		SInt8			  explosionDecalCount;			// 71
		UInt16			  pad72;						// 72
		float			  explosionSpecialDebrisScale;	// 74
	};
	STATIC_ASSERT(sizeof(PART_DATA) == 0x78);


	class BGSBodyPart
	{
	public:
		// members
		BSFixedString nodeName;					  // 00 - BPNN
		BSFixedString targetName;				  // 08 - BPNT
		BSFixedString hitReactionVariablePrefix;  // 10 - BPNI
		BSFixedString partName;					  // 18 - BPTN
		BSFixedString goreObjectName;			  // 20 - NAM4
		TESModel	  explosionSpecialDebris;	  // 28 - NAM1
		TESModelPSA	  poseMatching;				  // 50 - PNAM
		PART_DATA	  data;						  // 78 - BPND
	};
	STATIC_ASSERT(sizeof(BGSBodyPart) == 0xF0);


	class BGSBodyPartData :
		public TESForm,		   // 00
		public TESModel,	   // 20
		public BGSPreloadable  // 48
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSBodyPartData;
		inline static constexpr auto FORMTYPE = FormType::BodyPartData;


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSBodyPartData();	 // 00

		// override (TESForm)
		virtual void InitializeData() override;		 // 04
		virtual void ClearData() override;			 // 05
		virtual bool Load(TESFile* a_mod) override;	 // 06
		virtual void InitItemImpl() override;		 // 13


		// members
		BGSBodyPart* parts[BGSBodyPartDefs::LIMB_ENUM::kTotal];	 // 50
		BGSRagdoll*	 ragdoll;									 // 80
	};
	STATIC_ASSERT(sizeof(BGSBodyPartData) == 0x88);
}
