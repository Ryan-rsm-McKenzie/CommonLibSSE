#pragma once

#include "skse64/GameRTTI.h"  // RTTI_Precipitation


namespace RE
{
	class BSGeometryListCullingProcess;
	class BSShaderAccumulator;
	class NiCamera;


	class Precipitation
	{
	public:
		inline static const void* RTTI = RTTI_Precipitation;


		virtual ~Precipitation();	// 00


		// members
		UInt64							unk08;	// 08
		UInt64							unk10;	// 10
		UInt64							unk18;	// 18
		UInt64							unk20;	// 20
		UInt64							unk28;	// 28
		UInt64							unk30;	// 30
		UInt64							unk38;	// 38
		UInt64							unk40;	// 40
		UInt64							unk48;	// 48
		NiCamera*						unk50;	// 50
		BSShaderAccumulator*			unk58;	// 58
		BSGeometryListCullingProcess*	unk60;	// 60
		UInt64							unk68;	// 68
		UInt64							unk70;	// 70
		UInt64							unk78;	// 78
		float							unk80;	// 80
		float							unk84;	// 84
		float							unk88;	// 88
		UInt32							unk8C;	// 8C
	};
	STATIC_ASSERT(sizeof(Precipitation) == 0x90);
}
