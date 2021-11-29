#include "RE/B/BSEffectShaderData.h"

#include "RE/N/NiTexture.h"

namespace RE
{
	BSEffectShaderData::BSEffectShaderData() :
		BSIntrusiveRefCounted(),
		pad04(0),
		nodeFilterFunction(nullptr),
		baseTexture(nullptr),
		paletteTexture(nullptr),
		blockOutTexture(nullptr),
		textureClampMode(BSGraphics::TextureAddressMode::kWrapSWrapT),
		fillColor(),
		rimColor(),
		baseFillScale(1.0),
		baseFillAlpha(1.0),
		baseRimAlpha(1.0),
		uOffset(0.0),
		vOffset(0.0),
		uScale(1.0),
		vScale(1.0),
		edgeExponent(1.0),
		boundDiameter(0.0),
		srcBlend(NiAlphaProperty::AlphaFunction::kSrcAlpha),
		destBlend(NiAlphaProperty::AlphaFunction::kInvSrcAlpha),
		zTestFunc(BSGraphics::DepthStencilDepthMode::kTest),
		alphaTestRef(0),
		grayscaleToColor(false),
		grayscaleToAlpha(false),
		ignoreTextureAlpha(false),
		baseTextureProjectedUVs(false),
		ignoreBaseGeomTexAlpha(false),
		lighting(false),
		alpha(false),
		pad84(0)
	{}

	BSEffectShaderData::~BSEffectShaderData()
	{}
}
