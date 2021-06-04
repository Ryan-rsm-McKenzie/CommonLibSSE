#pragma once

namespace RE
{
	class BSVolumetricLightingRenderData
	{
	public:
		struct CustomColor
		{
		public:
			// members
			float contribution;  // DNAM
		};
		static_assert(sizeof(CustomColor) == 0x4);

		struct Density
		{
		public:
			// members
			float contribution;  // HNAM
			float size;          // INAM
			float windSpeed;     // JNAM
			float fallingSpeed;  // KNAM
		};
		static_assert(sizeof(Density) == 0x10);

		struct PhaseFunction
		{
		public:
			// members
			float contribution;  // LNAM
			float scattering;    // MNAM
		};
		static_assert(sizeof(PhaseFunction) == 0x8);

		struct SamplingRepartition
		{
		public:
			// members
			float rangeFactor;  // NNAM
		};
		static_assert(sizeof(SamplingRepartition) == 0x4);

		// members
		float               intensity;            // 00 - CNAM
		CustomColor         customColor;          // 04
		float               red;                  // 08 - ENAM
		float               green;                // 0C - FNAM
		float               blue;                 // 10 - GNAM
		Density             density;              // 14
		PhaseFunction       phaseFunction;        // 24
		SamplingRepartition samplingRepartition;  // 2C
	};
	static_assert(sizeof(BSVolumetricLightingRenderData) == 0x30);
}
