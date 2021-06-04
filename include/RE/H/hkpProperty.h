#pragma once

namespace RE
{
	struct hkpPropertyValue
	{
		std::uint64_t data;  // 0
	};
	static_assert(sizeof(hkpPropertyValue) == 0x8);

	class hkpProperty
	{
	public:
		std::uint32_t    key;               // 00
		std::uint32_t    alignmentPadding;  // 04
		hkpPropertyValue value;             // 08
	};
	static_assert(sizeof(hkpProperty) == 0x10);
}
