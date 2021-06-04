#pragma once

namespace RE
{
	struct DECAL_DATA_DATA
	{
	public:
		enum Flag : std::uint8_t
		{
			kNone = 0,
			kParallax = 1 << 0,
			kAlphaBlending = 1 << 1,
			kAlphaTesting = 1 << 2,
			kNoSubtextures = 1 << 3
		};

		// members
		float         decalMinWidth;   // 00
		float         decalMaxWidth;   // 04
		float         decalMinHeight;  // 08
		float         decalMaxHeight;  // 0C
		float         depth;           // 10
		float         shininess;       // 14
		float         parallaxScale;   // 18
		std::int8_t   parallaxPasses;  // 1C
		Flag          flags;           // 1D
		std::uint16_t pad1E;           // 1E
		Color         color;           // 20
	};
	static_assert(sizeof(DECAL_DATA_DATA) == 0x24);

	struct DecalData
	{
	public:
		// members
		DECAL_DATA_DATA data;  // 00
	};
	static_assert(sizeof(DecalData) == 0x24);
}
