#pragma once


namespace RE
{
	class GViewport
	{
	public:
		enum Flag : UInt32
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
		GViewport(SInt32 a_bufW, SInt32 a_bufH, SInt32 a_left, SInt32 a_top, SInt32 a_width, SInt32 a_height, SInt32 a_scLeft, SInt32 a_scTop, SInt32 a_scW, SInt32 a_scH, Flag a_flags = Flag::kNone);
		GViewport(SInt32 a_bufW, SInt32 a_bufH, SInt32 a_left, SInt32 a_top, SInt32 a_width, SInt32 a_height, SInt32 a_scLeft, SInt32 a_scTop, SInt32 a_scW, SInt32 a_scH, float a_scale, float a_ratio, Flag a_flags = Flag::kNone);
		GViewport(SInt32 a_bufW, SInt32 a_bufH, SInt32 a_left, SInt32 a_top, SInt32 a_width, SInt32 a_height, Flag a_flags = Flag::kNone);

		void	SetViewport(SInt32 a_bufW, SInt32 a_bufH, SInt32 a_left, SInt32 a_top, SInt32 a_width, SInt32 a_height, Flag a_flags = Flag::kNone);
		void	SetScissorRect(SInt32 a_scLeft, SInt32 a_scTop, SInt32 a_scW, SInt32 a_scH);


		// members
		SInt32	bufferWidth;	// 00
		SInt32	bufferHeight;	// 04
		SInt32	left;			// 08
		SInt32	top;			// 0C
		SInt32	width;			// 10
		SInt32	height;			// 14
		SInt32	scissorLeft;	// 18
		SInt32	scissorTop;		// 1C
		SInt32	scissorWidth;	// 20
		SInt32	scissorHeight;	// 24
		float	scale;			// 28
		float	aspectRatio;	// 2C
		Flag	flags;			// 30
		UInt32	pad34;			// 34
	};
	STATIC_ASSERT(sizeof(GViewport) == 0x38);
}
