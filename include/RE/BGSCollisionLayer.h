#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSCollisionLayer

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSTArray.h"  // BSTArray
#include "RE/Color.h"  // Color
#include "RE/FormTypes.h"  // FormType
#include "RE/TESDescription.h"  // TESDescription
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	class BGSCollisionLayer :
		public TESForm,			// 00
		public TESDescription	// 20
	{
	public:
		inline static const void* RTTI = RTTI_BGSCollisionLayer;


		enum { kTypeID = FormType::CollisionLayer };


		enum class Flag : UInt32	// GNAM
		{
			kNone = 0,
			kTriggerVolume = 1 << 0,
			kSensor = 1 << 1,
			kNavmeshObstacle = 1 << 2
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSCollisionLayer();							// 00

		// override (TESForm)
		virtual void	ReleaseManagedData() override;			// 05
		virtual bool	LoadForm(TESFile* a_mod) override;		// 06
		virtual void	InitItem() override;					// 13
		virtual void	SetFlag00000020(bool a_set) override;	// 23 - { TESForm::SetFlag00000020(a_set); }


		// members
		UInt32							index;			// 30 - BNAM
		Color							debugColor;		// 34 - FNAM
		Flag							flags;			// 38
		UInt32							unk3C;			// 3C
		BSFixedString					name;			// 40 - MNAM
		BSTArray<BGSCollisionLayer*>	collidesWith;	// 48 - CNAM
	};
	STATIC_ASSERT(sizeof(BGSCollisionLayer) == 0x60);
}
