#pragma once


namespace RE
{
	class BSArchiveHeader
	{
	public:
		struct ArchiveFlag
		{
		public:
			// members
			UInt32 flag;  // 0
		};
		STATIC_ASSERT(sizeof(ArchiveFlag) == 0x4);


		// members
		UInt32		tag;				   // 00
		UInt32		version;			   // 04
		UInt32		headerSize;			   // 08
		ArchiveFlag flags;				   // 0C
		UInt32		directories;		   // 10
		UInt32		files;				   // 14
		UInt32		directoryNamesLength;  // 18
		UInt32		fileNamesLength;	   // 1C
		UInt16		archiveType;		   // 20
		UInt16		pad22;				   // 22
	};
	STATIC_ASSERT(sizeof(BSArchiveHeader) == 0x24);
}
