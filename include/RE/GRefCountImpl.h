#pragma once

#include "skse64/GameRTTI.h"  // RTTI_GRefCountImpl

#include "RE/GRefCountImplCore.h"  // GRefCountImplCore


namespace RE
{
	class GRefCountImpl : GRefCountImplCore
	{
	public:
		inline static const void* RTTI = RTTI_GRefCountImpl;


		GRefCountImpl() = default;
		virtual ~GRefCountImpl() = default;	// 00

		void	AddRef();
		void	Release();
	};
	STATIC_ASSERT(sizeof(GRefCountImpl) == 0x10);
}
