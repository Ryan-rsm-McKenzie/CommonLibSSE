#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSResource__LooseFileLocation

#include <minwinbase.h>  // WIN32_FIND_DATAA
#include <minwindef.h>  // MAX_PATH
#include <winnt.h>  // HANDLE

#include "RE/BSResource/Location.h"  // BSResource::Location
#include "RE/BSFixedString.h"  // BSFixedString


namespace RE
{
	namespace BSResource
	{
		class LooseFileLocation : public Location
		{
		public:
			inline static const void* RTTI = RTTI_BSResource__LooseFileLocation;


			struct FindData
			{
				enum class State : UInt32
				{
					kSearching = 0,
					kFolderNameUnset = 4,
					kSearchFinished = 6
				};


				HANDLE				handle;					// 000
				WIN32_FIND_DATAA	findData;				// 008
				char				folderName[MAX_PATH];	// 148
				State				state;					// 24C
				UInt64				unk250;					// 250
			};
			STATIC_ASSERT(sizeof(FindData) == 0x258);


			struct FileData_Impl
			{
				FILETIME		lastAccessTime;	// 00
				FILETIME		lastWriteTime;	// 08
				FILETIME		creationTime;	// 10
				LARGE_INTEGER	fileSize;		// 18
			};
			STATIC_ASSERT(sizeof(FileData_Impl) == 0x20);


			virtual ~LooseFileLocation();																							// 00

			// override (Location)
			virtual Result		LocateFile(const char* a_relPath, Stream*& a_stream, Location*& a_location, char a_delim) override;	// 03
			virtual void		Unk_04(void) override;																				// 04
			virtual Result		TraverseFiles(const char* a_relPath, LocationTraverser* a_traverser) override;						// 05
			virtual Result		LocateFileData(const char* a_relPath, FileData* a_fileData, Location*& a_location) override;		// 06
			virtual Result		GetFileData(const char* a_relPath, FileData* a_fileData) override;									// 07
			virtual void		Unk_08(void) override;																				// 08
			virtual const char*	GetDirectory() const override;																		// 09 - { return directory.c_str(); }
			virtual void		Unk_0B(void) override;																				// 0B - { return *unk18; }


			// members
			BSFixedString	directory;	// 10
			UInt64			unk18;		// 18
		};
		STATIC_ASSERT(sizeof(LooseFileLocation) == 0x20);
	}
}
