#pragma once

namespace RE
{
	class IUIMessageData
	{
	public:
		inline static constexpr auto RTTI = RTTI_IUIMessageData;

		virtual ~IUIMessageData() = default;  // 00

		// members
		std::uint16_t unk08;  // 08
		std::uint16_t pad0A;  // 0A
		std::uint32_t pad0C;  // 0C
	};
	static_assert(sizeof(IUIMessageData) == 0x10);
}
