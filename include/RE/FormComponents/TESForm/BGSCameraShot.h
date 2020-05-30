#pragma once

#include "RE/FormTypes.h"
#include "RE/TESForm.h"
#include "RE/TESImageSpaceModifiableForm.h"
#include "RE/TESModel.h"


namespace RE
{
	class BGSCameraShot :
		public TESForm,						// 00
		public TESModel,					// 20
		public TESImageSpaceModifiableForm	// 48
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSCameraShot;
		inline static constexpr auto FORMTYPE = FormType::CameraShot;


		enum class CAM_ACTION : UInt32
		{
			kShoot = 0,
			kFly = 1,
			kHit = 2,
			kZoom = 3
		};


		enum class CAM_OBJECT : UInt32
		{
			kAttacker = 0,
			kProjectile = 1,
			kTarget = 2,
			kLeadActor = 3
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct CAMERA_SHOT_DATA	 // DATA
		{
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


			CAM_ACTION cameraAction;				// 00
			CAM_OBJECT location;					// 04
			CAM_OBJECT target;						// 08
			Flag	   flags;						// 0C
			float	   playerTimeMult;				// 10
			float	   targetTimeMult;				// 14
			float	   globalTimeMult;				// 18
			float	   maxTime;						// 1C
			float	   minTime;						// 20
			float	   targetPercentBetweenActors;	// 24
			float	   nearTargetDistance;			// 28
		};
		STATIC_ASSERT(sizeof(CAMERA_SHOT_DATA) == 0x2C);


		virtual ~BGSCameraShot();  // 00

		// override (TESForm)
		virtual void InitializeData() override;		 // 04
		virtual bool Load(TESFile* a_mod) override;	 // 06
		virtual void InitItemImpl() override;		 // 13


		// members
		CAMERA_SHOT_DATA data;	 // 58 - DATA
		UInt32			 pad84;	 // 84
		void*			 unk88;	 // 88 - smart ptr
		void*			 unk90;	 // 90 - smart ptr
		RefHandle		 unk98;	 // 98
		UInt32			 unk9C;	 // 9C
		void*			 unkA0;	 // A0 - smart ptr
		void*			 unkA8;	 // A8 - smart ptr
		UInt64			 unkB0;	 // B0
		void*			 unkB8;	 // B8
	};
	STATIC_ASSERT(sizeof(BGSCameraShot) == 0xC0);
}
