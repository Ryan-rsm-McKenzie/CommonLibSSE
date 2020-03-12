#pragma once

#include "RE/TESTexture.h"


namespace RE
{
	class TESTexture1024 : public TESTexture
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESTexture1024;


		virtual ~TESTexture1024();	// 00

		// override (TESTexture)
		virtual UInt32 GetMaxAllowedSize() override;  // 04 - { return 1024; }
	};
	STATIC_ASSERT(sizeof(TESTexture1024) == 0x10);
}
