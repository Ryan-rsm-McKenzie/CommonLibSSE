#pragma once

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSResourceLocation.h"  // BSResource::Location
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
			virtual ~GlobalPaths();																																		// 00

			// override (Location)
			virtual BOOL	QueryFileAttributes(const char* a_relPath, RE::BSResource::Stream*& a_stream, RE::BSResource::Location*& a_location, char a_arg4) override;	// 03
			virtual void	Unk_04(void) override;																														// 04
			virtual BOOL	FindFiles(const char* a_relPath, LocationTraverser* a_traverser) override;																	// 05
			virtual void	Unk_06(void) override;																														// 06
			virtual void	Unk_07(void) override;																														// 07
			virtual void	Unk_08(void) override;																														// 08


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
