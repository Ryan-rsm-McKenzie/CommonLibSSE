#pragma once

#include "RE/F/FileID.h"

namespace RE
{
	namespace BSResource
	{
		struct ID : public FileID
		{
		public:
			// members
			std::uint32_t dir;  // 0
		};
		static_assert(sizeof(ID) == 0xC);
	}
}
