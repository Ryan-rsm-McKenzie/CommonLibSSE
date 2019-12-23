#pragma once

#include "RE/ActorValues.h"
#include "RE/BGSPreloadable.h"
#include "RE/BSFixedString.h"
#include "RE/FormTypes.h"
#include "RE/NiPoint3.h"
#include "RE/TESForm.h"
#include "RE/TESModel.h"
#include "RE/TESModelPSA.h"


namespace RE
{
	class BGSBodyPartData :
		public TESForm,			// 00
		public TESModel,		// 20
		public BGSPreloadable	// 48
	{
	public:
		inline static const void* RTTI = RTTI_BGSBodyPartData;


		enum { kTypeID = FormType::BodyPartData };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct PartTypes
		{
			enum PartType : UInt8
			{
				kTorso = 0,
				kHead,
				kEye,
				kLookAt,
				kFlyGrab,
				kSaddle,

				kTotal
			};
		};


		struct BodyPart
		{
			struct NumericData	// BPND
			{
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


#pragma pack(push, 1)
				struct Explodable
				{
					UInt8			explosionChance;	// 00
					UInt8			debrisCount;		// 01
					UInt8			pad02;				// 02
					UInt32			pad03;				// 03
					BGSDebris*		debris;				// 07
					BGSExplosion*	explosion;			// 0F
				};
				STATIC_ASSERT(sizeof(Explodable) == 0x17);
#pragma pack(pop)


				struct GoreEffectsPositioning
				{
					NiPoint3	translate;	// 00
					NiPoint3	rotation;	// 0C
				};
				STATIC_ASSERT(sizeof(GoreEffectsPositioning) == 0x18);


				float					damageMult;					// 00
				Flag					flags;						// 04
				PartTypes::PartType		partType;					// 05
				UInt8					healthPct;					// 06
				ActorValue8				actorValue;					// 07
				UInt8					toHitChance;				// 08
				Explodable				explodable;					// 09
				float					trackingMaxAngle;			// 20
				float					explodableDebrisScale;		// 24
				UInt8					severableDebrisCount;		// 28
				UInt8					unk29;						// 29
				UInt16					unk2A;						// 2A
				UInt32					unk2C;						// 2C
				BGSDebris*				severableDebris;			// 30
				BGSExplosion*			severableExplosion;			// 38
				float					severableDebrisScale;		// 40
				GoreEffectsPositioning	goreEffectsPositioning;		// 44
				UInt32					pad5C;						// 5C
				BGSImpactDataSet*		severableImpactDataSet;		// 60
				BGSImpactDataSet*		explodableImpactDataSet;	// 68
				UInt8					severableDecalCount;		// 70
				UInt8					explodableDecalCount;		// 71
				UInt16					pad72;						// 72
				float					limbReplacementScale;		// 74
			};
			STATIC_ASSERT(sizeof(NumericData) == 0x78);


			BSFixedString	partNode;				// 00 - BPNN
			BSFixedString	vatsTarget;				// 08 - BPNT
			BSFixedString	ikDataStartNode;		// 10 - BPNI
			BSFixedString	partName;				// 18 - BPTN
			BSFixedString	goreEffectsTargetBone;	// 20 - NAM4
			TESModel		limbReplacementModel;	// 28 - NAM1
			TESModelPSA		poseMatching;			// 50 - PNAM
			NumericData		numericData;			// 78 - BPND
		};
		STATIC_ASSERT(sizeof(BodyPart) == 0xF0);


		virtual ~BGSBodyPartData();							// 00

		// override (TESForm)
		virtual void	InitializeData() override;			// 04
		virtual void	ClearData() override;				// 05
		virtual bool	Load(TESFile* a_mod) override;		// 06
		virtual void	InitItemImpl() override;			// 13


		// members
		BodyPart*	bodyParts[PartTypes::kTotal];	// 50
		BGSRagdoll*	ragdoll;						// 80
	};
	STATIC_ASSERT(sizeof(BGSBodyPartData) == 0x88);
}
