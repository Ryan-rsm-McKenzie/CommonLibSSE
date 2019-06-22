#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSResource__LooseFileLocation

#include <minwinbase.h>  // WIN32_FIND_DATAA
#include <minwindef.h>  // MAX_PATH
#include <winnt.h>  // HANDLE

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSResourceLocation.h"  // BSResource::Location


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


			virtual ~LooseFileLocation();																																	// 00

			// override (Location)
			virtual BOOL		QueryFileAttributes(const char* a_relPath, RE::BSResource::Stream*& a_stream, RE::BSResource::Location*& a_location, char a_arg4) override;	// 03
			virtual void		Unk_04(void) override;																														// 04
			virtual BOOL		FindFiles(const char* a_relPath, LocationTraverser* a_traverser) override;																	// 05
			virtual void		Unk_06(void) override;																														// 06
			virtual void		Unk_07(void) override;																														// 07
			virtual void		Unk_08(void) override;																														// 08
			virtual const char*	GetFilePath() const override;																												// 09 - { return filePath.c_str(); }
			virtual void		Unk_0B(void) override;																														// 0B - { return *unk18; }


			// members
			BSFixedString	currentLocation;	// 10
			UInt64			unk18;				// 18
		};
		STATIC_ASSERT(sizeof(LooseFileLocation) == 0x20);
	}
}
