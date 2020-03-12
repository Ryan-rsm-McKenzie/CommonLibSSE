#pragma once

#include "RE/GRefCountImplCore.h"


namespace RE
{
	class GRefCountImpl : GRefCountImplCore
	{
	public:
		inline static constexpr auto RTTI = RTTI_GRefCountImpl;


		GRefCountImpl() = default;
		virtual ~GRefCountImpl() = default;	 // 00

		void AddRef();
		void Release();
	};
	STATIC_ASSERT(sizeof(GRefCountImpl) == 0x10);
}
