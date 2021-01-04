#pragma once

#include "RE/N/NiSmartPointer.h"

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
		public:
			// members
			alignas(0x10) DirectX::XMFLOAT4X4 projection;	// 00
			NiPointer<NiCamera>			   camera;			// 40
			NiPointer<BSShaderAccumulator> accumulator;		// 48
			BSCullingProcess*			   cullingProcess;	// 50
			std::uint64_t				   pad58;			// 58
		};
		static_assert(sizeof(OcclusionMapData) == 0x60);

		virtual ~Precipitation();  // 00

		// members
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
