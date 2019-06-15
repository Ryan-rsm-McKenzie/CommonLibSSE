#pragma once

#include "skse64/GameRTTI.h"  // RTTI_Moon

#include "RE/BSString.h"  // BSString
#include "RE/SkyObject.h"  // SkyObject


namespace RE
{
	class NiNode;
	class BSTriShape;


	class Moon : public SkyObject
	{
	public:
		inline static const void* RTTI = RTTI_Moon;


		struct States
		{
			enum
			{
				kFull = 0,
				kWaningGibbous,
				kWaningQuarter,
				kWaningCrescent,
				kNewMoon,
				kWaxingCrescent,
				kWaxingQuarter,
				kWaxingGibbous,

				kTotal
			};
		};


		virtual ~Moon();						// 00

		// override (SkyObject)
		virtual void	Unk_02(void) override;	// 02
		virtual void	Unk_03(void) override;	// 03


		// members
		NiNode*		unk10;							// 10
		NiNode*		unk18;							// 18
		BSTriShape*	unk20;							// 20
		BSTriShape*	unk28;							// 28
		BSString	stateTextures[States::kTotal];	// 30
		float		unkB0;							// B0 - lunar cycle related
		float		unkB4;							// B4
		float		unkB8;							// B8
		float		unkBC;							// BC
		float		unkC0;							// C0
		float		unkC4;							// C4
		float		unkC8;							// C8
		float		unkCC;							// CC
		float		unkD0;							// D0
		UInt32		padD4;							// D4
	};
	STATIC_ASSERT(sizeof(Moon) == 0xD8);
}
