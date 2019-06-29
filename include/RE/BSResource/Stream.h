#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSResource__Stream

#include "RE/BSResource/StreamBase.h"  // BSResource::StreamBase


namespace RE
{
	namespace BSResource
	{
		class Stream : public StreamBase
		{
		public:
			inline static const void* RTTI = RTTI_BSResource__Stream;


			virtual ~Stream();									// 00

			// add
			virtual void	Unk_05(void) = 0;					// 05
			virtual void	Unk_06(void) = 0;					// 06
			virtual void	Unk_07(void) = 0;					// 07
			virtual void	Unk_08(void) = 0;					// 08
			virtual void	Unk_09(void);						// 09 - { return 8; }
			virtual bool	GetRelPath(BSFixedString& a_dst);	// 0A - { a_dst = ""; }
			virtual void	Unk_0B(void);						// 0B - { return 8; }
		};
		STATIC_ASSERT(sizeof(Stream) == 0x10);
	}
}
