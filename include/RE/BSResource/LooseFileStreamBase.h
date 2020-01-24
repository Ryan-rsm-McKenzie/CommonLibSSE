#pragma once

#include "RE/BSFixedString.h"


namespace RE
{
	namespace BSResource
	{
		class BSSystemFile
		{
		public:
			struct Info
			{
			public:
				// members
				FILETIME		accessTime;	// 00
				FILETIME		modifyTime;	// 08
				FILETIME		createTime;	// 10
				LARGE_INTEGER	fileSize;	// 18
			};
			STATIC_ASSERT(sizeof(Info) == 0x20);


			UInt32	flags;	// 00
			UInt32	pad04;	// 04
			HANDLE	file;	// 08
		};
		STATIC_ASSERT(sizeof(BSSystemFile) == 0x10);


		struct LooseFileStreamBase
		{
		public:
			BSFixedString	prefix;		// 00
			BSFixedString	dirName;	// 08
			BSFixedString	fileName;	// 10
			BSSystemFile	file;		// 18
		};
		STATIC_ASSERT(sizeof(LooseFileStreamBase) == 0x28);
	}
}
