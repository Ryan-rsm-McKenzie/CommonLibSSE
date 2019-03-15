#pragma once

#include "RE/BSExtraData.h"  // BSExtraData


namespace RE
{
	class InventoryChanges;


	class ExtraContainerChanges : public BSExtraData
	{
	public:
		enum { kExtraTypeID = ExtraDataType::kContainerChanges };


		virtual	~ExtraContainerChanges();				// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kContainerChanges; }


		// members
		InventoryChanges* changes;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraContainerChanges) == 0x18);
}
