#pragma once

#include "RE/BSResource/Location.h"  // BSResource::Location


namespace RE
{
	namespace BSResource
	{
		class DevNull;
		class GlobalPaths;


		class LocationTree : public Location
		{
		public:
			virtual ~LocationTree();																							// 00

			// override (Location)
			virtual Result	LocateFile(const char* a_relPath, Stream*& a_stream, Location*& a_location, char a_delim) override;	// 03
			virtual void	Unk_04(void) override;																				// 04
			virtual Result	TraverseFiles(const char* a_relPath, LocationTraverser* a_traverser) override;						// 05
			virtual Result	LocateFileData(const char* a_relPath, FileData* a_fileData, Location*& a_location) override;		// 06
			virtual Result	GetFileData(const char* a_relPath, FileData* a_fileData) override;									// 07
			virtual void	Unk_08(void) override;																				// 08


			// members
			GlobalPaths*	globalPaths;	// 10
			DevNull*		devNull;		// 18
		};
		STATIC_ASSERT(sizeof(LocationTree) == 0x20);
	}
}
