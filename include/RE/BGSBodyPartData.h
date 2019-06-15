#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSBodyPartData

#include "RE/ActorValues.h"  // ActorValue8
#include "RE/BGSPreloadable.h"  // BGSPreloadable
#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm
#include "RE/TESModel.h"  // TESModel
#include "RE/TESModelPSA.h"  // TESModelPSA


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


			struct GoreEffectsPositioning
			{
				struct XYZ
				{
					float	x;	// 0
					float	y;	// 4
					float	z;	// 8
				};
				STATIC_ASSERT(sizeof(XYZ) == 0xC);


				XYZ	translate;	// 00
				XYZ	rotation;	// 0C
			};
			STATIC_ASSERT(sizeof(GoreEffectsPositioning) == 0x18);


			BSFixedString			partNode;					// 00 - BPNN
			BSFixedString			vatsTarget;					// 08 - BPNT
			BSFixedString			ikDataStartNode;			// 10 - BPNI
			BSFixedString			partName;					// 18 - BPTN
			BSFixedString			goreEffectsTargetBone;		// 20 - NAM4
			TESModel				limbReplacementModel;		// 28 - NAM1
			TESModelPSA				poseMatching;				// 50 - PNAM
			float					damageMult;					// 78
			Flag					flags;						// 7C
			PartTypes::PartType		partType;					// 7D
			UInt8					healthPct;					// 7E
			ActorValue8				actorValue;					// 7F
			UInt8					toHitChance;				// 80
			UInt8					explodableExplosionChance;	// 81
			UInt8					explodableDebrisCount;		// 82
			UInt8					unk83;						// 83
			UInt32					unk84;						// 84
			BGSDebris*				explodableDebris;			// 88
			BGSExplosion*			explodableExplosion;		// 90
			float					trackingMaxAngle;			// 98
			float					explodableDebrisScale;		// 9C
			UInt8					severableDebrisCount;		// A0
			UInt8					unkA1;						// A1
			UInt16					unkA2;						// A2
			UInt32					unkA4;						// A4
			BGSDebris*				severableDebris;			// A8
			BGSExplosion*			severableExplosion;			// B0
			float					severableDebrisScale;		// B8
			GoreEffectsPositioning	goreEffectsPositioning;		// BC
			UInt32					unkD4;						// D4
			BGSImpactDataSet*		severableImpactDataSet;		// D8
			BGSImpactDataSet*		explodableImpactDataSet;	// E0
			UInt8					severableDecalCount;		// E8
			UInt8					explodableDecalCount;		// E9
			UInt16					unkEA;						// EA
			float					limbReplacementScale;		// EC
		};
		STATIC_ASSERT(sizeof(BodyPart) == 0xF0);


		virtual ~BGSBodyPartData();							// 00

		// override (TESForm)
		virtual void	InitDefaults() override;			// 04
		virtual void	ReleaseManagedData() override;		// 05
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06
		virtual void	InitItem() override;				// 13


		// members
		BodyPart*	bodyParts[PartTypes::kTotal];	// 50
		UInt64		unk80;							// 80
	};
	STATIC_ASSERT(sizeof(BGSBodyPartData) == 0x88);
}
