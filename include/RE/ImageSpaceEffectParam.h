#pragma once


namespace RE
{
	class ImageSpaceEffectParam
	{
	public:
		inline static const void* RTTI = RTTI_ImageSpaceEffectParam;


		virtual ~ImageSpaceEffectParam();	// 00
	};
	STATIC_ASSERT(sizeof(ImageSpaceEffectParam) == 0x8);
}
