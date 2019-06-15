#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSCameraShot

#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm
#include "RE/TESImageSpaceModifiableForm.h"  // TESImageSpaceModifiableForm
#include "RE/TESModel.h"  // TESModel


namespace RE
{
	class BGSCameraShot :
		public TESForm,						// 00
		public TESModel,					// 20
		public TESImageSpaceModifiableForm	// 48
	{
	public:
		inline static const void* RTTI = RTTI_BGSCameraShot;


		enum { kTypeID = FormType::CameraShot };


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
			enum class Action : UInt32
			{
				kShoot = 0,
				kFly = 1,
				kHit = 2,
				kZoom = 4
			};


			enum class Target : UInt32
			{
				kAttacker = 0,
				kProjectile = 1,
				kTarget = 2,
				kLeadActor = 3
			};


			enum class Flag : UInt32
			{
				kNone = 0,
				kPositionFollowsLocation = 1 << 0,
				kRotationFollowsTarget = 1 << 1,
				kDontFollowBone = 1 << 2,
				kFirstPersonCamera = 1 << 3,
				kNoTracer = 1 << 4,
				kStartAtTimeZero = 1 << 5
			};


			struct TimeMultipliers
			{
				float	player;	// 0
				float	target;	// 4
				float	global;	// 8
			};
			STATIC_ASSERT(sizeof(TimeMultipliers) == 0xC);


			Action			action;					// 00
			Target			location;				// 04
			Target			target;					// 08
			Flag			flags;					// 0C
			TimeMultipliers	timeMultipliers;		// 10
			float			maxTime;				// 1C
			float			minTime;				// 20
			float			targetPctBetweenActors;	// 24
			float			nearTargetDistance;		// 28
			UInt32			unk2C;					// 2C
		};
		STATIC_ASSERT(sizeof(Data) == 0x30);


		virtual ~BGSCameraShot();							// 00

		// override (TESForm)
		virtual void	InitDefaults() override;			// 04
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06
		virtual void	InitItem() override;				// 13


		// members
		Data		data;	// 58 - DATA
		void*		unk88;	// 88
		void*		unk90;	// 90
		RefHandle	unk98;	// 98
		UInt32		unk9C;	// 9C
		void*		unkA0;	// A0
		void*		unkA8;	// A8
		UInt64		unkB0;	// B0
		void*		unkB8;	// B8
	};
	STATIC_ASSERT(sizeof(BGSCameraShot) == 0xC0);
}
