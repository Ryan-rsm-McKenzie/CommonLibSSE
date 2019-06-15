#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESTexture

#include "RE/TESTexture.h"  // TESTexture


namespace RE
{
	class TESIcon : public TESTexture
	{
	public:
		inline static const void* RTTI = RTTI_TESTexture;


		virtual ~TESIcon();								// 00

		// override (TESTexture)
		virtual const char* GetSearchDir() override;	// 06 - { return "Textures"; }
	};
	STATIC_ASSERT(sizeof(TESIcon) == 0x10);
}
