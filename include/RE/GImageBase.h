#pragma once

#include "RE/GArray.h"
#include "RE/GColor.h"


namespace RE
{
	class GImageBase
	{
	public:
		enum class ImageFormat : UInt32
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


		ImageFormat	   format;		 // 00
		UInt32		   width;		 // 04
		UInt32		   height;		 // 08
		UInt32		   pitch;		 // 0C
		UInt8*		   data;		 // 10
		UInt32		   dataSize;	 // 18
		UInt32		   mipMapCount;	 // 1C
		GArray<GColor> colorMap;	 // 20
	};
	STATIC_ASSERT(sizeof(GImageBase) == 0x38);
}
