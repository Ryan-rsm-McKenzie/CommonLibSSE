#pragma once

#include "RE/NetImmerse/NiSmartPointer.h"


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
			std::uint64_t				   pad58;			// 58
		};
		static_assert(sizeof(OcclusionMapData) == 0x60);


		virtual ~Precipitation();  // 00


		// members
		//std::uint64_t						pad08;					// 08
		OcclusionMapData	  occlusionData;		   // 10
		NiPointer<BSGeometry> currentPrecip;		   // 70
		NiPointer<BSGeometry> lastPrecip;			   // 78
		float				  lastCubeSize;			   // 80
		float				  currentParticleDensity;  // 84
		float				  lastParticleDensity;	   // 88
		std::uint32_t		  pad8C;				   // 8C
	};
	static_assert(sizeof(Precipitation) == 0x90);
}
