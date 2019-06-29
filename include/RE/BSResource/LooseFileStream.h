#pragma once

#include "RE/BSResource/LooseFileStreamBase.h"  // BSResource::LooseFileStreamBase
#include "RE/BSResource/Stream.h"  // BSResource::Stream


namespace RE
{
	namespace BSResource
	{
		class LooseFileLocation;


		class LooseFileStream :
			public LooseFileStreamBase,	// 10
			public Stream				// 00
		{
		public:
			virtual ~LooseFileStream();									// 00

			// override (Stream)
			virtual void	Unk_01(void) override;						// 01
			virtual void	Unk_02(void) override;						// 02
			virtual void	Unk_04(void) override;						// 04
			virtual void	Unk_05(void) override;						// 05
			virtual void	Unk_06(void) override;						// 06
			virtual void	Unk_07(void) override;						// 07
			virtual void	Unk_08(void) override;						// 08
			virtual void	Unk_09(void) override;						// 09
			virtual bool	GetRelPath(BSFixedString& a_dst) override;	// 0A
			virtual void	Unk_0B(void) override;						// 0B


			// members
			LooseFileLocation*	location;	// 38
			UInt64				unk40;		// 40
			void*				unk48;		// 48
		};
		STATIC_ASSERT(sizeof(LooseFileStream) == 0x50);
	}
}
