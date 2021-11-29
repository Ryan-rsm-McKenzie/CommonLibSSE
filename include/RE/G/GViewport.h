#pragma once

namespace RE
{
	class GViewport
	{
	public:
		enum Flag
		{
			kNone = 0,
			kIsRenderTexture = 1,
			kAlphaComposite = 2,
			kUseScissorRect = 4,
			kNoSetState = 8,
			kRenderTextureAlpha = kIsRenderTexture | kAlphaComposite
		};

		GViewport();
		GViewport(const GViewport& a_rhs);
		GViewport(std::int32_t a_bufW, std::int32_t a_bufH, std::int32_t a_left, std::int32_t a_top, std::int32_t a_width, std::int32_t a_height, std::int32_t a_scLeft, std::int32_t a_scTop, std::int32_t a_scW, std::int32_t a_scH, Flag a_flags = Flag::kNone);
		GViewport(std::int32_t a_bufW, std::int32_t a_bufH, std::int32_t a_left, std::int32_t a_top, std::int32_t a_width, std::int32_t a_height, std::int32_t a_scLeft, std::int32_t a_scTop, std::int32_t a_scW, std::int32_t a_scH, float a_scale, float a_ratio, Flag a_flags = Flag::kNone);
		GViewport(std::int32_t a_bufW, std::int32_t a_bufH, std::int32_t a_left, std::int32_t a_top, std::int32_t a_width, std::int32_t a_height, Flag a_flags = Flag::kNone);

		void SetViewport(std::int32_t a_bufW, std::int32_t a_bufH, std::int32_t a_left, std::int32_t a_top, std::int32_t a_width, std::int32_t a_height, Flag a_flags = Flag::kNone);
		void SetScissorRect(std::int32_t a_scLeft, std::int32_t a_scTop, std::int32_t a_scW, std::int32_t a_scH);

		// members
		std::int32_t                          bufferWidth;    // 00
		std::int32_t                          bufferHeight;   // 04
		std::int32_t                          left;           // 08
		std::int32_t                          top;            // 0C
		std::int32_t                          width;          // 10
		std::int32_t                          height;         // 14
		std::int32_t                          scissorLeft;    // 18
		std::int32_t                          scissorTop;     // 1C
		std::int32_t                          scissorWidth;   // 20
		std::int32_t                          scissorHeight;  // 24
		float                                 scale;          // 28
		float                                 aspectRatio;    // 2C
		stl::enumeration<Flag, std::uint32_t> flags;          // 30
		std::uint32_t                         pad34;          // 34
	};
	static_assert(sizeof(GViewport) == 0x38);
}
