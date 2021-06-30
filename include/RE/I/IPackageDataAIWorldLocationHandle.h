#pragma once

#include "RE/I/IAIWorldLocationHandle.h"
#include "RE/I/IPackageData.h"

namespace RE
{
	class IPackageDataAIWorldLocationHandle :
		public IAIWorldLocationHandle,  // 00
		public IPackageData             // 08
	{
	public:
		inline static constexpr auto RTTI = RTTI_IPackageDataAIWorldLocationHandle;

		~IPackageDataAIWorldLocationHandle() override;  // 00
	};
	static_assert(sizeof(IPackageDataAIWorldLocationHandle) == 0x10);
}
