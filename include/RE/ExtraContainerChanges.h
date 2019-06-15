#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraContainerChanges

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class InventoryChanges;


	class ExtraContainerChanges : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraContainerChanges;


		enum { kExtraTypeID = ExtraDataType::kContainerChanges };


		virtual	~ExtraContainerChanges();				// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kContainerChanges; }


		// members
		InventoryChanges* changes;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraContainerChanges) == 0x18);
}
