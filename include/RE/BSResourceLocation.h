#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSResource__Location


namespace RE
{
	namespace BSResource
	{
		class LocationTraverser;
		class Stream;


		class Location
		{
		public:
			inline static const void* RTTI = RTTI_BSResource__Location;


			virtual ~Location();																																		// 00

			// add
			virtual void		Unk_01(void);																															// 01 - { return 0; }
			virtual void		Unk_02(void);																															// 02 - { return; }
			virtual BOOL		QueryFileAttributes(const char* a_relPath, RE::BSResource::Stream*& a_stream, RE::BSResource::Location*& a_location, char a_arg4) = 0;	// 03
			virtual void		Unk_04(void);																															// 04 - { return 8; }
			virtual BOOL		FindFiles(const char* a_relPath, LocationTraverser* a_traverser) = 0;																	// 05
			virtual void		Unk_06(void);																															// 06 - { return 8; }
			virtual void		Unk_07(void);																															// 07 - { return 8; }
			virtual void		Unk_08(void);																															// 08 - { return 8; }
			virtual const char*	GetFilePath() const;																													// 09 - { return 0; }
			virtual void		Unk_0A(void);																															// 0A - { return 0x80000; }
			virtual void		Unk_0B(void);																															// 0B - { return 0x80000; }


			// members
			bool	unk08;	// 08
			UInt8	pad09;	// 09
			UInt16	pad0A;	// 0A
			UInt32	pad0C;	// 0C
		};
		STATIC_ASSERT(sizeof(Location) == 0x10);
	}
}
