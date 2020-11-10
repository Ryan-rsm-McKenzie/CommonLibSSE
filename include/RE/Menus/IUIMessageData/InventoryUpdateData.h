#pragma once

#include "RE/Menus/IUIMessageData/IUIMessageData.h"

namespace RE
{
	class InventoryUpdateData : public IUIMessageData
	{
	public:

		inline static constexpr auto RTTI = RTTI_InventoryUpdateData;

		virtual ~InventoryUpdateData() = default;  // 00

		RefHandle		unk10;	// 10
		std::uint32_t	pad14;	// 14
		TESForm*		unk18;	// 18
	};
	static_assert(sizeof(InventoryUpdateData) == 0x20);
}
