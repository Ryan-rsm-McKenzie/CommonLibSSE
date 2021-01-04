#pragma once

#include "RE/T/TESTexture.h"

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
	static_assert(sizeof(TESIcon) == 0x10);
}
