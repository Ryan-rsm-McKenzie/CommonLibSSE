#pragma once

#include "RE/BSResource/FileID.h"


namespace RE
{
	namespace BSResource
	{
		struct ID : public FileID
		{
		public:
			// members
			UInt32 dir;	 // 0
		};
		STATIC_ASSERT(sizeof(ID) == 0xC);
	}
}
