#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class InventoryChanges;


	class ExtraContainerChanges : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraContainerChanges;


		enum { kExtraTypeID = ExtraDataType::kContainerChanges };


		ExtraContainerChanges();
		explicit ExtraContainerChanges(InventoryChanges* a_changes);
		virtual	~ExtraContainerChanges();				// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kContainerChanges; }


		// members
		InventoryChanges* changes;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraContainerChanges) == 0x18);
}
