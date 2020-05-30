#pragma once

#include "RE/BaseFormComponent.h"
#include "RE/FormTypes.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class QueuedFile;
	class TESModelTextureSwap;


	struct DestructibleObjectStage
	{
		enum class DESTRUCTIBLE_OBJECT_STAGE_FLAGS : UInt8
		{
			kNone = 0,
			kCapDamage = 1 << 0,
			kDisableObject = 1 << 1,
			kDestroyObject = 1 << 2,
			kIgnoreExternalDamage = 1 << 3,
			kBecomesDynamic = 1 << 4
		};
		using Flags = DESTRUCTIBLE_OBJECT_STAGE_FLAGS;


		// members
		SInt8				 modelDamageStage;	   // 00 - DSTD~
		SInt8				 healthPercentage;	   // 01
		Flags				 flags;				   // 02
		UInt8				 pad03;				   // 03
		UInt32				 selfDamagePerSecond;  // 04
		BGSExplosion*		 explosion;			   // 08
		BGSDebris*			 debris;			   // 10
		UInt32				 debrisCount;		   // 18 - ~DSTD
		UInt32				 pad1C;				   // 1C
		TESModelTextureSwap* replacementModel;	   // 20 - DMD*
	};
	STATIC_ASSERT(sizeof(DestructibleObjectStage) == 0x28);


	struct DestructibleObjectData
	{
		enum class Flag : UInt8
		{
			kNone = 0,
			kVatsTargetable = 1 << 0
		};


		// members
		UInt32					  health;					   // 00 - DEST~
		SInt8					  numStages;				   // 04
		Flag					  flags;					   // 05 - ~DEST
		UInt16					  pad06;					   // 06
		DestructibleObjectStage** stages;					   // 08
		volatile SInt32			  replacementModelRefCount;	   // 10
		UInt32					  pad14;					   // 14
		NiPointer<QueuedFile>	  preloadedReplacementModels;  // 18
	};
	STATIC_ASSERT(sizeof(DestructibleObjectData) == 0x20);


	class BGSDestructibleObjectForm : public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSDestructibleObjectForm;


		virtual ~BGSDestructibleObjectForm();  // 00

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;				// 01
		virtual void ClearDataComponent() override;						// 02
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;	// 03


		// members
		DestructibleObjectData* data;  // 08
	};
	STATIC_ASSERT(sizeof(BGSDestructibleObjectForm) == 0x10);
}
