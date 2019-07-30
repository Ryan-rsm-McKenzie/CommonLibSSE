#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraResourcesPreload

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraResourcesPreload : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraResourcesPreload;


		enum { kExtraTypeID = ExtraDataType::kResourcesPreload };


		virtual ~ExtraResourcesPreload();				// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kResourcesPreload; }


		// members
		void* unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraResourcesPreload) == 0x18);
}
