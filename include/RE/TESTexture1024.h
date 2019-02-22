#pragma once

#include "RE/TESTexture.h"  // TESTexture


namespace RE
{
	class TESTexture1024 : public TESTexture
	{
	public:
		virtual ~TESTexture1024();	// 00

		// override (TESTexture)
		virtual UInt32	GetSize();	// 04 - { return 1024; }
	};
	STATIC_ASSERT(sizeof(TESTexture1024) == 0x10);
}
