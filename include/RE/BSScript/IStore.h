#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSScript__IStore

#include "RE/BSStorage.h"  // BSStorage


namespace RE
{
	namespace BSScript
	{
		class IStore : public BSStorage
		{
		public:
			inline static const void* RTTI = RTTI_BSScript__IStore;


			virtual ~IStore();																					// 00

			// override (BSStorage)
			virtual BOOL					WriteFile(DWORD a_numberOfBytesToWrite, LPCVOID a_buffer) override;	// 05

			// add
			virtual bool					Open(const char* a_fileName) = 0;									// 06
			virtual void					Close(void) = 0;													// 07
			virtual const BSFixedString&	GetRelPath() = 0;													// 08
			virtual bool					HasOpenFile(void) = 0;												// 09
			virtual bool					FileIsGood(void) = 0;												// 0A
			virtual void					Unk_0B(void) = 0;													// 0B
		};
		STATIC_ASSERT(sizeof(IStore) == 0x20);
	}
}
