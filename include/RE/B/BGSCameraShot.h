#pragma once

#include "RE/F/FormTypes.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESImageSpaceModifiableForm.h"
#include "RE/T/TESModel.h"

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

		enum class CAM_ACTION
		{
			kShoot = 0,
			kFly = 1,
			kHit = 2,
			kZoom = 3
		};

		enum class CAM_OBJECT
		{
			kAttacker = 0,
			kProjectile = 1,
			kTarget = 2,
			kLeadActor = 3
		};

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		struct CAMERA_SHOT_DATA	 // DATA
		{
		public:
			enum class Flag
			{
				kNone = 0,
				kPositionFollowsLocation = 1 << 0,
				kRotationFollowsTarget = 1 << 1,
				kDontFollowBone = 1 << 2,
				kFirstPersonCamera = 1 << 3,
				kNoTracer = 1 << 4,
				kStartAtTimeZero = 1 << 5
			};

			// members
			stl::enumeration<CAM_ACTION, std::uint32_t> cameraAction;				 // 00
			stl::enumeration<CAM_OBJECT, std::uint32_t> location;					 // 04
			stl::enumeration<CAM_OBJECT, std::uint32_t> target;						 // 08
			stl::enumeration<Flag, std::uint32_t>		flags;						 // 0C
			float										playerTimeMult;				 // 10
			float										targetTimeMult;				 // 14
			float										globalTimeMult;				 // 18
			float										maxTime;					 // 1C
			float										minTime;					 // 20
			float										targetPercentBetweenActors;	 // 24
			float										nearTargetDistance;			 // 28
		};
		static_assert(sizeof(CAMERA_SHOT_DATA) == 0x2C);

		virtual ~BGSCameraShot();  // 00

		// override (TESForm)
		virtual void InitializeData() override;		 // 04
		virtual bool Load(TESFile* a_mod) override;	 // 06
		virtual void InitItemImpl() override;		 // 13

		// members
		CAMERA_SHOT_DATA data;	 // 58 - DATA
		std::uint32_t	 pad84;	 // 84
		void*			 unk88;	 // 88 - smart ptr
		void*			 unk90;	 // 90 - smart ptr
		RefHandle		 unk98;	 // 98
		std::uint32_t	 unk9C;	 // 9C
		void*			 unkA0;	 // A0 - smart ptr
		void*			 unkA8;	 // A8 - smart ptr
		std::uint64_t	 unkB0;	 // B0
		void*			 unkB8;	 // B8
	};
	static_assert(sizeof(BGSCameraShot) == 0xC0);
}
