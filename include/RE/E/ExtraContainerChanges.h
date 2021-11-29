#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class ExtraDataList;
	class InventoryChanges;
	class TESBoundObject;
	class TESForm;
	class TESObjectREFR;

	class ExtraContainerChanges : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraContainerChanges;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kContainerChanges;

		ExtraContainerChanges();
		explicit ExtraContainerChanges(InventoryChanges* a_changes);
		~ExtraContainerChanges() override;  // 00

		// override (BSExtraData)
		[[nodiscard]] ExtraDataType GetType() const override;  // 01 - { return kContainerChanges; }

		void* AddInventoryItem(TESBoundObject* a_object, void* a_arg2, std::int32_t a_count, void* a_arg4);

		// members
		InventoryChanges* changes;  // 10
	};
	static_assert(sizeof(ExtraContainerChanges) == 0x18);
}
