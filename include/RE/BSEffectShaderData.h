#pragma once

#include "RE/BSGraphics/DepthStencilDepthModes.h"
#include "RE/BSGraphics/TextureAddressModes.h"
#include "RE/BSIntrusiveRefCounted.h"
#include "RE/NiAlphaProperty.h"
#include "RE/NiColor.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class BSFixedString;
	class NiTexture;


	class BSEffectShaderData : public BSIntrusiveRefCounted
	{
	public:
		using NodeFilterFunction_t = bool(const BSFixedString*);


		BSEffectShaderData();
		~BSEffectShaderData();


		// members
		UInt32							  pad04;					// 04
		NodeFilterFunction_t*			  nodeFilterFunction;		// 08
		NiPointer<NiTexture>			  baseTexture;				// 10
		NiPointer<NiTexture>			  paletteTexture;			// 18
		NiPointer<NiTexture>			  blockOutTexture;			// 20
		BSGraphics::TextureAddressMode	  textureClampMode;			// 28
		NiColorA						  fillColor;				// 2C
		NiColorA						  rimColor;					// 3C
		float							  baseFillScale;			// 4C
		float							  baseFillAlpha;			// 50
		float							  baseRimAlpha;				// 54
		float							  uOffset;					// 58
		float							  vOffset;					// 5C
		float							  uScale;					// 60
		float							  vScale;					// 64
		float							  edgeExponent;				// 68
		float							  boundDiameter;			// 6C
		NiAlphaProperty::AlphaFunction	  srcBlend;					// 70
		NiAlphaProperty::AlphaFunction	  destBlend;				// 74
		BSGraphics::DepthStencilDepthMode zTestFunc;				// 78
		SInt8							  alphaTestRef;				// 7C
		bool							  grayscaleToColor;			// 7D
		bool							  grayscaleToAlpha;			// 7E
		bool							  ignoreTextureAlpha;		// 7F
		bool							  baseTextureProjectedUVs;	// 80
		bool							  ignoreBaseGeomTexAlpha;	// 81
		bool							  lighting;					// 82
		bool							  alpha;					// 83
		UInt32							  pad84;					// 84
	};
	STATIC_ASSERT(sizeof(BSEffectShaderData) == 0x88);
}
