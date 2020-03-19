#pragma once


namespace RE
{
	namespace BSResource
	{
		struct FileID
		{
		public:
			// members
			UInt32 file;	// 0
			char   ext[4];	// 0
		};
		STATIC_ASSERT(sizeof(FileID) == 0x8);
	}
}
