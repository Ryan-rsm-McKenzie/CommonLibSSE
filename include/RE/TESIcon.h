#pragma once

#include "RE/TESTexture.h"


namespace RE
{
	class TESIcon : public TESTexture
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESTexture;


		virtual ~TESIcon();	 // 00

		// override (TESTexture)
		virtual const char* GetDefaultPath() const override;  // 06 - { return "Textures"; }
	};
	STATIC_ASSERT(sizeof(TESIcon) == 0x10);
}
