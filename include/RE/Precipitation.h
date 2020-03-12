#pragma once

#include <DirectXMath.h>

#include "RE/NiSmartPointer.h"


namespace RE
{
	class BSCullingProcess;
	class BSGeometry;
	class BSShaderAccumulator;
	class NiCamera;


	class Precipitation
	{
	public:
		inline static constexpr auto RTTI = RTTI_Precipitation;


		class OcclusionMapData
		{
			DirectX::XMFLOAT4X4A		   projection;		// 00
			NiPointer<NiCamera>			   camera;			// 40
			NiPointer<BSShaderAccumulator> accumulator;		// 48
			BSCullingProcess*			   cullingProcess;	// 50
			UInt64						   pad58;			// 58
		};
		STATIC_ASSERT(sizeof(OcclusionMapData) == 0x60);


		virtual ~Precipitation();  // 00


		// members
		//UInt64						pad08;					// 08
		OcclusionMapData	  occlusionData;		   // 10
		NiPointer<BSGeometry> currentPrecip;		   // 70
		NiPointer<BSGeometry> lastPrecip;			   // 78
		float				  lastCubeSize;			   // 80
		float				  currentParticleDensity;  // 84
		float				  lastParticleDensity;	   // 88
		UInt32				  pad8C;				   // 8C
	};
	STATIC_ASSERT(sizeof(Precipitation) == 0x90);
}
