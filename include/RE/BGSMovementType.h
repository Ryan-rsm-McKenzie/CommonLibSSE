#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSMovementType

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	class BGSMovementType : public TESForm
	{
	public:
		inline static const void* RTTI = RTTI_BGSMovementType;


		enum { kTypeID = FormType::MovementType };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct DefaultData	// SPED
		{
			float	leftWalk;				// 00
			float	leftRun;				// 04
			float	rightWalk;				// 08
			float	rightRun;				// 0C
			float	forwardWalk;			// 10
			float	forwardRun;				// 14
			float	backWalk;				// 18
			float	backRun;				// 1C
			float	rotateInPlaceWalk;		// 20 - ck value in rads
			float	rotateInPlaceRun;		// 24 - ck value in rads
			float	rotateWhileMovingRun;	// 28 - ck value in rads
		};
		STATIC_ASSERT(sizeof(DefaultData) == 0x2C);


		struct AnimChangeThresholds	// INAM
		{
			struct Threshold
			{
				constexpr operator float&() { return val; }
				constexpr bool IsDefault() const { return val == 0x7F7FFFFF; }


				float val;
			};
			STATIC_ASSERT(sizeof(Threshold) == 0x4);


			Threshold	directional;	// 0
			Threshold	movementSpeed;	// 4
			Threshold	rotationSpeed;	// 8
		};
		STATIC_ASSERT(sizeof(AnimChangeThresholds) == 0xC);


		virtual ~BGSMovementType();							// 00

		// override (TESForm)
		virtual void	InitDefaults() override;			// 04
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06
		virtual void	InitItem() override;				// 13


		// members
		BSFixedString			name;					// 20 - MNAM
		DefaultData				defaultData;			// 28 - SPED
		AnimChangeThresholds	animChangeThresholds;	// 54 - INAM
	};
	STATIC_ASSERT(sizeof(BGSMovementType) == 0x60);
}
