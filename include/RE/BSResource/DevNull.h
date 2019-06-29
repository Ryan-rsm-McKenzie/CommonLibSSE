#pragma once

#include "RE/BSResource/Location.h"  // BSResource::Location
#include "RE/BSResource/Stream.h"  // BSResource::Stream
#include "RE/BSTSingleton.h"  // BSTSingletonSDM


namespace RE
{
	namespace BSResource
	{
		class DevNull :
			public Location,				// 00
			public BSTSingletonSDM<DevNull>	// 10
		{
		public:
			struct NullStream : public Stream
			{
			public:
				virtual ~NullStream();					// 00

				// override (Stream)
				virtual void	Unk_01(void) override;	// 01 - { return 0; }
				virtual void	Unk_02(void) override;	// 02 - { return; }
				virtual void	Unk_05(void) override;	// 05
				virtual void	Unk_06(void) override;	// 06
				virtual void	Unk_07(void) override;	// 07
				virtual void	Unk_08(void) override;	// 08
			};
			STATIC_ASSERT(sizeof(NullStream) == 0x10);


			virtual ~DevNull();																									// 00

			// override (Location)
			virtual void	Unk_01(void) override;																				// 01 - { return 0; }
			virtual void	Unk_02(void) override;																				// 02 - { return; }
			virtual Result	LocateFile(const char* a_relPath, Stream*& a_stream, Location*& a_location, char a_delim) override;	// 03
			virtual Result	TraverseFiles(const char* a_relPath, LocationTraverser* a_traverser) override;						// 05 - { return 1; }


			// members
			UInt8		pad11;	// 11
			UInt16		pad12;	// 12
			UInt32		pad14;	// 14
			NullStream*	unk18;	// 18
			NullStream*	unk20;	// 20
		};
		STATIC_ASSERT(sizeof(DevNull) == 0x28);
	}
}
