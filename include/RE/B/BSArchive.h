#pragma once

#include "RE/B/BSArchiveHeader.h"

namespace RE
{
	struct BSDirectoryEntry;

	class BSArchive : public BSArchiveHeader
	{
	public:
		// members
		std::uint32_t     pad24;        // 24
		BSDirectoryEntry* directories;  // 28
	};
	static_assert(sizeof(BSArchive) == 0x30);
}
