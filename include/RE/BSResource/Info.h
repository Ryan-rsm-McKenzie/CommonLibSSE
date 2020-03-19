#pragma once


namespace RE
{
	namespace BSResource
	{
		struct Info
		{
		public:
			// members
			FILETIME	  modifyTime;  // 00
			FILETIME	  createTime;  // 08
			LARGE_INTEGER fileSize;	   // 10
		};
		STATIC_ASSERT(sizeof(Info) == 0x18);
	}
}
