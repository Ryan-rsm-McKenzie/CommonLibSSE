#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class ExtraHotkey : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraHotkey;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kHotkey;

		enum class Hotkey
		{
			kUnbound = static_cast<std::underlying_type_t<Hotkey>>(-1),
			kSlot1 = 0,
			kSlot2 = 1,
			kSlot3 = 2,
			kSlot4 = 3,
			kSlot5 = 4,
			kSlot6 = 5,
			kSlot7 = 6,
			kSlot8 = 7
		};

		ExtraHotkey();
		explicit ExtraHotkey(Hotkey a_hotkey);
		~ExtraHotkey() override = default;  // 00

		// override (BSExtraData)
		ExtraDataType GetType() const override;                             // 01 - { return kHotkey }
		bool          IsNotEqual(const BSExtraData* a_rhs) const override;  // 02 - { hotkey != a_rhs->hotkey; }

		// members
		stl::enumeration<Hotkey, std::uint8_t> hotkey;  // 10
		std::uint8_t                           unk11;   // 11
		std::uint16_t                          unk12;   // 12
		std::uint32_t                          unk14;   // 14
	};
	static_assert(sizeof(ExtraHotkey) == 0x18);
}
