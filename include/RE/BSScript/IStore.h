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


			virtual ~IStore();																	// 00

			// override (BSStorage)
			virtual BOOL	WriteFile(DWORD a_numberOfBytesToWrite, LPCVOID a_buffer) override;	// 05

			// add
			virtual void	Unk_06(void) = 0;													// 06
			virtual void	Unk_07(void) = 0;													// 07
			virtual void	Unk_08(void) = 0;													// 08
			virtual void	Unk_09(void) = 0;													// 09
			virtual void	Unk_0A(void) = 0;													// 0A
			virtual void	Unk_0B(void) = 0;													// 0B
		};
		STATIC_ASSERT(sizeof(IStore) == 0x20);
	}
}
