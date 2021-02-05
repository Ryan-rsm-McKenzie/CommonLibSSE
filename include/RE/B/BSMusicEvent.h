#pragma once

namespace RE
{
	class BSIMusicType;

	struct BSMusicEvent
	{
	public:
		BSIMusicType* musicType;  // 00
		std::uint32_t unk08;	  // 08 - some kind of enum
		std::uint32_t pad0C;	  // 0C
	};
	static_assert(sizeof(BSMusicEvent) == 0x10);
}
