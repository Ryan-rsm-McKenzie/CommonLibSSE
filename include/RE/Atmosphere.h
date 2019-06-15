#pragma once

#include "skse64/GameRTTI.h"  // RTTI_Atmosphere

#include "RE/SkyObject.h"  // SkyObject


namespace RE
{
	class BSFogProperty;
	class BSTriShape;


	class Atmosphere : public SkyObject
	{
	public:
		inline static const void* RTTI = RTTI_Atmosphere;


		virtual ~Atmosphere();					// 00

		// override (SkyObject)
		virtual void	Unk_03(void) override;	// 03

		// add
		virtual void	Unk_04(void);			// 04


		// members
		BSTriShape*		unk10;	// 10
		BSFogProperty*	unk18;	// 18
		UInt64			unk20;	// 20
		UInt64			unk28;	// 28
		UInt32			unk30;	// 30
		UInt32			unk34;	// 34
	};
	STATIC_ASSERT(sizeof(Atmosphere) == 0x38);
}
