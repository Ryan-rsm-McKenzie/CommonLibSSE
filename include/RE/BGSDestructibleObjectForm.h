#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSDestructibleObjectForm

#include "RE/BaseFormComponent.h"  // BaseFormComponent
#include "RE/FormTypes.h"  // BGSExplosion, BGSDebris


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
				UInt32	health;			// 00
				UInt8	count;			// 04
				bool	vatsTargetable;	// 05
				UInt16	unk06;			// 06
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
						kDisable = 1 << 1,
						kDestroy = 1 << 2,
						kIgnoreExternalDamage = 1 << 3
					};


					UInt8			modelDamageStage;		// 00
					UInt8			healthPct;				// 01
					Flag			flags;					// 02
					UInt8			unk03;					// 03
					UInt32			selfDamagePerSecond;	// 04
					BGSExplosion*	explosion;				// 08
					BGSDebris*		debris;					// 10
					UInt32			debrisCount;			// 18
					UInt32			pad1C;					// 1C
				};
				STATIC_ASSERT(sizeof(DestructionStageData) == 0x20);


				DestructionStageData	destructionStageData;	// 00 - DSTD
				TESModelTextureSwap*	model;					// 20 - DMD*
			};
			STATIC_ASSERT(sizeof(Stage) == 0x28);


			Header	header;	// 00 - DEST
			Stage**	stages;	// 08
		};
		STATIC_ASSERT(sizeof(Destructible) == 0x10);


		virtual ~BGSDestructibleObjectForm();								// 00

		// override (BaseFormComponent)
		virtual void	Init() override;									// 01
		virtual void	ReleaseRefs() override;								// 02
		virtual void	CopyFromBase(BaseFormComponent* a_rhs) override;	// 03


		// members
		Destructible* destructible;	// 08
	};
	STATIC_ASSERT(sizeof(BGSDestructibleObjectForm) == 0x10);
}
