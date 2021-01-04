#include "RE/N/NiTexture.h"

namespace RE
{
	NiTexture::FormatPrefs::FormatPrefs() :
		pixelLayout(PixelLayout::kDefault),
		alphaFormat(AlphaFormat::kDefault),
		mipMapped(MipFlag::kDefault),
		pad0C(0)
	{}
}
