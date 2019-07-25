#pragma once

#include "RE/BSLock.h"  // BSUniqueLock
#include "RE/BSResource/Location.h"  // BSResource::Location
#include "RE/BSTSingleton.h"  // BSTSingletonSDM


namespace RE
{
	namespace BSResource
	{
		class GlobalLocations :
			public Location,						// 00
			public BSTSingletonSDM<GlobalLocations>	// 10
		{
		public:
			template <class T>
			struct List
			{
				List*	next;		// 00
				T		current;	// 08
				UInt64	unk10;		// ??
			};
			STATIC_ASSERT(sizeof(List<void*>) == 0x18);


			virtual ~GlobalLocations();																							// 00

			// override (Location)
			virtual void	Unk_01(void) override;																				// 01
			virtual void	Unk_02(void) override;																				// 02
			virtual Result	LocateFile(const char* a_relPath, Stream*& a_stream, Location*& a_location, char a_delim) override;	// 03
			virtual void	Unk_04(void) override;																				// 04
			virtual	Result	TraverseFiles(const char* a_relPath, LocationTraverser* a_traverser) override;						// 05
			virtual Result	LocateFileData(const char* a_relPath, FileData* a_fileData, Location*& a_location) override;		// 06
			virtual Result	GetFileData(const char* a_relPath, FileData* a_fileData) override;									// 07
			virtual void	Unk_08(void) override;																				// 08


			// members
			UInt8					pad11;		// 11
			UInt16					pad12;		// 12
			mutable BSUniqueLock	lock;		// 14
			UInt32					unk1C;		// 1C
			List<Location*>*		locations;	// 20
			List<void*>*			unk28;		// 28
			List<void*>*			unk30;		// 30
		};
		STATIC_ASSERT(sizeof(GlobalLocations) == 0x38);
	}
}
