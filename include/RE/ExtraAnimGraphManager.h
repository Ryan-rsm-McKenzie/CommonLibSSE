#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraAnimGraphManager

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraAnimGraphManager : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraAnimGraphManager;


		enum { kExtraTypeID = ExtraDataType::kAnimGraphManager };


		virtual ~ExtraAnimGraphManager();				// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kAnimGraphManager; }


		// members
		void* unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraAnimGraphManager) == 0x18);
}
