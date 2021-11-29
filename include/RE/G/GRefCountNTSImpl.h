#pragma once

#include "RE/G/GRefCountImplCore.h"

namespace RE
{
	class GRefCountNTSImpl : public GRefCountImplCore
	{
	public:
		void AddRef();
		void Release();
	};
	static_assert(sizeof(GRefCountNTSImpl) == 0x10);
}
