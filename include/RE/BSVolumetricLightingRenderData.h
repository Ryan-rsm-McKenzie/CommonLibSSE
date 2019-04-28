#pragma once


namespace RE
{
	class BSVolumetricLightingRenderData
	{
	public:
		struct CustomColor
		{
			float contribution;	// DNAM
		};
		STATIC_ASSERT(sizeof(CustomColor) == 0x4);


		struct Density
		{
			float	contribution;	// HNAM
			float	size;			// INAM
			float	windSpeed;		// JNAM
			float	fallingSpeed;	// KNAM
		};
		STATIC_ASSERT(sizeof(Density) == 0x10);


		struct PhaseFunction
		{
			float	contribution;	// LNAM
			float	scattering;		// MNAM
		};
		STATIC_ASSERT(sizeof(PhaseFunction) == 0x8);


		struct SamplingRepartition
		{
			float rangeFactor;	// NNAM
		};
		STATIC_ASSERT(sizeof(SamplingRepartition) == 0x4);


		// members
		float				intensity;				// 00 - CNAM
		CustomColor			customColor;			// 04
		float				red;					// 08 - ENAM
		float				green;					// 0C - FNAM
		float				blue;					// 10 - GNAM
		Density				density;				// 14
		PhaseFunction		phaseFunction;			// 24
		SamplingRepartition	samplingRepartition;	// 2C
	};
	STATIC_ASSERT(sizeof(BSVolumetricLightingRenderData) == 0x30);
}
