#pragma once

#include "RE/IAIWorldLocationHandle.h"
#include "RE/IPackageData.h"


namespace RE
{
	class IPackageDataAIWorldLocationHandle :
		public IAIWorldLocationHandle,	// 00
		public IPackageData				// 08
	{
	public:
		inline static constexpr auto RTTI = RTTI_IPackageDataAIWorldLocationHandle;


		virtual ~IPackageDataAIWorldLocationHandle();  // 00
	};
	STATIC_ASSERT(sizeof(IPackageDataAIWorldLocationHandle) == 0x10);
}
