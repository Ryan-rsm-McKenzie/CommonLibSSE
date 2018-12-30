#pragma once


namespace RE
{
	class ImageSpaceEffectParam
	{
	public:
		virtual ~ImageSpaceEffectParam();	// 00
	};
	STATIC_ASSERT(sizeof(ImageSpaceEffectParam) == 0x8);
}
