#pragma once

#include "RE/BaseFormComponent.h"
#include "RE/FormTypes.h"


namespace RE
{
	class TESModelTextureSwap;


	class BGSDestructibleObjectForm : public BaseFormComponent
	{
	public:
		inline static const void* RTTI = RTTI_BGSDestructibleObjectForm;


		struct Destructible
		{
			struct Header	// DEST
			{
				enum class Flag : UInt8
				{
					kNone = 0,
					kVatsTargetable = 1 << 0
				};


				UInt32	health;		// 00
				SInt8	numStages;	// 04
				Flag	flags;		// 05
				UInt16	pad06;		// 06
			};
			STATIC_ASSERT(sizeof(Header) == 0x8);


			struct Stage
			{
				struct DestructionStageData	// DSTD
				{
					enum class Flag : UInt8
					{
						kNone = 0,
						kCapDamage = 1 << 0,
						kDisableObject = 1 << 1,
						kDestroyObject = 1 << 2,
						kIgnoreExternalDamage = 1 << 3,
						kBecomesDynamic = 1 << 4
					};


					SInt8			modelDamageStage;		// 00
					SInt8			healthPercentage;		// 01
					Flag			flags;					// 02
					UInt8			pad03;					// 03
					UInt32			selfDamagePerSecond;	// 04
					BGSExplosion*	explosion;				// 08
					BGSDebris*		debris;					// 10
					UInt32			debrisCount;			// 18
					UInt32			pad1C;					// 1C
				};
				STATIC_ASSERT(sizeof(DestructionStageData) == 0x20);


				DestructionStageData	destructionStageData;	// 00 - DSTD
				TESModelTextureSwap*	replacementModel;		// 20 - DMD*
			};
			STATIC_ASSERT(sizeof(Stage) == 0x28);


			Header	header;	// 00 - DEST
			Stage**	stages;	// 08
		};
		STATIC_ASSERT(sizeof(Destructible) == 0x10);


		virtual ~BGSDestructibleObjectForm();								// 00

		// override (BaseFormComponent)
		virtual void	InitializeDataComponent() override;					// 01
		virtual void	ClearDataComponent() override;						// 02
		virtual void	CopyComponent(BaseFormComponent* a_rhs) override;	// 03


		// members
		Destructible* destructible;	// 08
	};
	STATIC_ASSERT(sizeof(BGSDestructibleObjectForm) == 0x10);
}
