#pragma once

#include "RE/FormComponents/Components/IAIWorldLocationHandle/IAIWorldLocationHandle.h"
#include "RE/FormComponents/Components/IPackageData/IPackageData.h"


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
	static_assert(sizeof(IPackageDataAIWorldLocationHandle) == 0x10);
}
