#pragma once

#include "skse64/GameRTTI.h"  // RTTI_IPackageDataAIWorldLocationHandle

#include "RE/IAIWorldLocationHandle.h"  // IAIWorldLocationHandle
#include "RE/IPackageData.h"  // IPackageData


namespace RE
{
	class IPackageDataAIWorldLocationHandle :
		public IAIWorldLocationHandle,	// 00
		public IPackageData				// 08
	{
	public:
		inline static const void* RTTI = RTTI_IPackageDataAIWorldLocationHandle;


		virtual ~IPackageDataAIWorldLocationHandle();	// 00
	};
	STATIC_ASSERT(sizeof(IPackageDataAIWorldLocationHandle) == 0x10);
}
