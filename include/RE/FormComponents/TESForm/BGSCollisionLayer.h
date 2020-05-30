#pragma once

#include "RE/BSFixedString.h"
#include "RE/BSTArray.h"
#include "RE/Color.h"
#include "RE/FormTypes.h"
#include "RE/TESDescription.h"
#include "RE/TESForm.h"


namespace RE
{
	class BGSCollisionLayer :
		public TESForm,		   // 00
		public TESDescription  // 20
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSCollisionLayer;
		inline static constexpr auto FORMTYPE = FormType::CollisionLayer;


		enum class FLAG : UInt32  // GNAM
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


		virtual ~BGSCollisionLayer();  // 00

		// override (TESForm)
		virtual void ClearData() override;			  // 05
		virtual bool Load(TESFile* a_mod) override;	  // 06
		virtual void InitItemImpl() override;		  // 13
		virtual void SetDelete(bool a_set) override;  // 23 - { TESForm::SetDelete(a_set); }


		// members
		UInt32						 collisionIdx;	// 30 - BNAM
		Color						 debugColor;	// 34 - FNAM
		FLAG						 flags;			// 38 - GNAM
		UInt32						 pad3C;			// 3C
		BSFixedString				 name;			// 40 - MNAM
		BSTArray<BGSCollisionLayer*> collidesWith;	// 48 - CNAM
	};
	STATIC_ASSERT(sizeof(BGSCollisionLayer) == 0x60);
}
