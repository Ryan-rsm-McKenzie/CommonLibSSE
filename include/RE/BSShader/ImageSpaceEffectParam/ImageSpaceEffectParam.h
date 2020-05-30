#pragma once


namespace RE
{
	class ImageSpaceEffectParam
	{
	public:
		inline static constexpr auto RTTI = RTTI_ImageSpaceEffectParam;


		virtual ~ImageSpaceEffectParam();  // 00
	};
	STATIC_ASSERT(sizeof(ImageSpaceEffectParam) == 0x8);
}
