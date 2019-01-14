#pragma once


namespace RE
{
	enum class GStatGroup : UInt32
	{
		kDefault = 0,

		kCore = 16,
		kRenderer = 1 << 6,
		kRenderGen = 2 << 6,

		kGFxFontCache = 3 << 6,
		kGFxMovieData = 4 << 6,
		kGFxMovieView = 5 << 6,
		kGFxRenderCache = 6 << 6,
		kGFxPlayer = 7 << 6,
		kGFxIME = 8 << 6,
	};
}
