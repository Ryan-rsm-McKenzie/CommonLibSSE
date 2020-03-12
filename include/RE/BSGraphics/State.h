#pragma once

#include "RE/NiSmartPointer.h"
#include "RE/NiTexture.h"


namespace RE
{
	namespace BSGraphics
	{
		class State
		{
		public:
			static State* GetSingleton();


			// members
			UInt64				 unk00;						// 000
			UInt64				 unk08;						// 008
			UInt64				 unk10;						// 010
			UInt64				 unk18;						// 018
			UInt32				 unk20;						// 020
			UInt32				 screenWidth;				// 024
			UInt32				 screenHeight;				// 028
			UInt32				 frameBufferViewport[2];	// 02C
			UInt32				 unk34;						// 034
			UInt64				 unk38;						// 038
			UInt64				 unk40;						// 040
			UInt64				 unk48;						// 048
			bool				 insideFrame;				// 050
			bool				 letterbox;					// 051
			UInt16				 unk52;						// 052
			UInt32				 unk54;						// 054
			NiPointer<NiTexture> unk058;					// 058 - black?
			NiPointer<NiTexture> defaultTextureWhite;		// 060
			NiPointer<NiTexture> defaultTextureGrey;		// 068
			NiPointer<NiTexture> defaultHeightMap;			// 070
			NiPointer<NiTexture> defaultReflectionCubeMap;	// 078
			NiPointer<NiTexture> defaultFaceDetailMap;		// 080
			NiPointer<NiTexture> defaultTexEffectMap;		// 088
			NiPointer<NiTexture> defaultTextureNormalMap;	// 090
		};
		STATIC_ASSERT(offsetof(State, screenWidth) == 0x24);
		STATIC_ASSERT(offsetof(State, frameBufferViewport) == 0x2C);
		STATIC_ASSERT(offsetof(State, letterbox) == 0x51);
	}
}
