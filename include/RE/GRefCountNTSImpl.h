#pragma once

#include "RE/GRefCountImplCore.h"  // GRefCountImplCore


namespace RE
{
	class GRefCountNTSImpl : public GRefCountImplCore
	{
	public:
		void	AddRef();
		void	Release();
	};
	STATIC_ASSERT(sizeof(GRefCountNTSImpl) == 0x10);
}
