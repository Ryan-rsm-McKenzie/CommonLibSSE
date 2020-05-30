#pragma once

#include "RE/BSSystem/BSArchiveHeader/BSArchiveHeader.h"


namespace RE
{
	struct BSDirectoryEntry;


	class BSArchive : public BSArchiveHeader
	{
	public:
		// members
		UInt32			  pad24;		// 24
		BSDirectoryEntry* directories;	// 28
	};
	STATIC_ASSERT(sizeof(BSArchive) == 0x30);
}
