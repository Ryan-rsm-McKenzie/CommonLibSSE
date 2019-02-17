#pragma once

#include "RE/GRefCountImplCore.h"  // GRefCountImplCore


namespace RE
{
	class GRefCountImpl : GRefCountImplCore
	{
	public:
		void	AddRef();
		void	Release();
	};
	STATIC_ASSERT(sizeof(GRefCountImpl) == 0x10);
}
