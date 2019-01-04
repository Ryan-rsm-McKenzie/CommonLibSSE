#pragma once

#include "skse64/GameFormComponents.h"  // BaseFormComponent

#include "RE/FormTypes.h"  // BGSExplosion, BGSDebris


namespace RE
{
	class BGSDestructibleObjectForm : public BaseFormComponent
	{
	public:
		struct Data
		{
			struct Header	// DEST
			{
				UInt32	health;			// 00
				UInt8	destCount;		// 04
				bool	vatsTargetable;	// 05
				UInt16	unk06;			// 06
			};


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


				UInt8			healthPct;				// 00
				UInt8			index;					// 01
				UInt8			modelDamageStage;		// 02
				Flag			flags;					// 03
				UInt8			selfDamagePerSecond;	// 04
				UInt8			pad05;					// 05
				UInt16			pad06;					// 06
				BGSExplosion*	explosion;				// 08
				BGSDebris*		debris;					// 10
				UInt8			debrisCount;			// 18
				UInt8			pad19;					// 19
				UInt16			pad1A;					// 1A
				UInt32			pad1C;					// 1C
			};


			Header*					header;					// 00 - DEST
			DestructionStageData*	destructionStageData;	// 08 - DSTD
		};


		virtual ~BGSDestructibleObjectForm();								// 00

		// override (BaseFormComponent)
		virtual void	Init() override;									// 01
		virtual void	ReleaseRefs() override;								// 02
		virtual void	CopyFromBase(BaseFormComponent* a_rhs) override;	// 03


		// members
		Data* data;	// 08
	};
	STATIC_ASSERT(sizeof(BGSDestructibleObjectForm) == 0x10);
}
