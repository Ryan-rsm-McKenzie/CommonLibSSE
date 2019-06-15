#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESTexture1024

#include "RE/TESTexture.h"  // TESTexture


namespace RE
{
	class TESTexture1024 : public TESTexture
	{
	public:
		inline static const void* RTTI = RTTI_TESTexture1024;


		virtual ~TESTexture1024();			// 00

		// override (TESTexture)
		virtual UInt32	GetSize() override;	// 04 - { return 1024; }
	};
	STATIC_ASSERT(sizeof(TESTexture1024) == 0x10);
}
