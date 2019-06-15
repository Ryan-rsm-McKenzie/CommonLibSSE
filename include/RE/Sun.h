#pragma once

#include "skse64/GameRTTI.h"  // RTTI_Sun

#include "RE/SkyObject.h"  // SkyObject


namespace RE
{
	class BSShaderAccumulator;
	class BSTriShape;
	class NiBillboardNode;
	class NiDirectionalLight;


	class Sun : public SkyObject
	{
	public:
		inline static const void* RTTI = RTTI_Sun;


		virtual ~Sun();							// 00

		// override (SkyObject)
		virtual void	Unk_02(void) override;	// 02
		virtual void	Unk_03(void) override;	// 03


		// members
		NiBillboardNode*		unk10;	// 10
		NiBillboardNode*		unk18;	// 18
		BSTriShape*				unk20;	// 20
		BSTriShape*				unk28;	// 28
		BSTriShape*				unk30;	// 30
		NiDirectionalLight*		unk38;	// 38
		NiDirectionalLight*		unk40;	// 40
		UInt64					unk48;	// 48
		BSShaderAccumulator*	unk50;	// 50
	};
	STATIC_ASSERT(sizeof(Sun) == 0x58);
}
