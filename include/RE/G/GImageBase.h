#pragma once

#include "RE/G/GArray.h"
#include "RE/G/GColor.h"

namespace RE
{
	class GImageBase
	{
	public:
		enum class ImageFormat
		{
			kNone = 0,
			kARGB_8888 = 1,
			kRGB_888 = 2,
			kL_8 = 8,
			kA_8 = 9,
			kDXT1 = 10,
			kDXT3 = 11,
			kDXT5 = 12,

			kP_8 = 100,

			kYUV_822 = 200,
			kYUVA_8228 = 201,
		};

		stl::enumeration<ImageFormat, std::uint32_t> format;       // 00
		std::uint32_t                                width;        // 04
		std::uint32_t                                height;       // 08
		std::uint32_t                                pitch;        // 0C
		std::uint8_t*                                data;         // 10
		std::uint32_t                                dataSize;     // 18
		std::uint32_t                                mipMapCount;  // 1C
		GArray<GColor>                               colorMap;     // 20
	};
	static_assert(sizeof(GImageBase) == 0x38);
}
