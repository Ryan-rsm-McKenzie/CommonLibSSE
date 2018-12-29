#pragma once

#include "RE/TESTexture.h"  // TESTexture


namespace RE
{
	class TESIcon : public TESTexture
	{
	public:
		virtual ~TESIcon();								// 00

		// override (TESTexture)
		virtual const char* GetSearchDir() override;	// 06 - { return "Textures"; }
	};
	STATIC_ASSERT(sizeof(TESIcon) == 0x10);
}
