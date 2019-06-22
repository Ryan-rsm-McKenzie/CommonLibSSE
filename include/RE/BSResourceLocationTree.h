#pragma once

#include "RE/BSResourceLocation.h"  // BSResource::Location


namespace RE
{
	namespace BSResource
	{
		class LocationTree : public Location
		{
		public:
			virtual ~LocationTree();																																	// 00

			// override (Location)
			virtual BOOL	QueryFileAttributes(const char* a_relPath, RE::BSResource::Stream*& a_stream, RE::BSResource::Location*& a_location, char a_arg4) override;	// 03
			virtual void	Unk_04(void) override;																														// 04
			virtual BOOL	FindFiles(const char* a_relPath, LocationTraverser* a_traverser) override;																	// 05
			virtual void	Unk_06(void) override;																														// 06
			virtual void	Unk_07(void) override;																														// 07
			virtual void	Unk_08(void) override;																														// 08


			// members
			UInt64	unk10;	// 10
			UInt64	unk18;	// 18
		};
		STATIC_ASSERT(sizeof(LocationTree) == 0x20);
	}
}
