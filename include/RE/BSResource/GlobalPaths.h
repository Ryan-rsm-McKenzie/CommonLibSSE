#pragma once

#include "RE/BSResource/Location.h"  // BSResource::Location
#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSTArray.h"  // BSTArray
#include "RE/BSTSingleton.h"  // BSTSingletonSDM


namespace RE
{
	namespace BSResource
	{
		class GlobalLocations;


		class GlobalPaths :
			public Location,					// 00
			public BSTSingletonSDM<GlobalPaths>	// 10
		{
		public:
			virtual ~GlobalPaths();																								// 00

			// override (Location)
			virtual Result	LocateFile(const char* a_relPath, Stream*& a_stream, Location*& a_location, char a_delim) override;	// 03
			virtual void	Unk_04(void) override;																				// 04
			virtual Result	TraverseFiles(const char* a_relPath, LocationTraverser* a_traverser) override;						// 05
			virtual Result	LocateFileData(const char* a_relPath, FileData* a_fileData, Location*& a_location) override;		// 06
			virtual Result	GetFileData(const char* a_relPath, FileData* a_fileData) override;									// 07
			virtual void	Unk_08(void) override;																				// 08


			// members
			UInt8					pad11;				// 11
			UInt16					pad12;				// 12
			UInt32					pad14;				// 14
			BSTArray<BSFixedString>	paths;				// 18
			GlobalLocations*		globalLocations;	// 30
		};
		STATIC_ASSERT(sizeof(GlobalPaths) == 0x38);
	}
}
