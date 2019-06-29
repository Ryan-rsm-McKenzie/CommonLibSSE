#pragma once

#include "skse64/GameRTTI.h"  // RTTI_SkyrimScript__Store

#include "RE/BSScript/IStore.h"  // BSScript::IStore


namespace RE
{
	namespace SkyrimScript
	{
		class Store : public BSScript::IStore
		{
		public:
			inline static const void* RTTI = RTTI_SkyrimScript__Store;


			virtual ~Store();	// 00

			// override (BSScript::IStore)
			virtual PLARGE_INTEGER 	GetFileSize() override;															// 01
			virtual PLARGE_INTEGER	GetFilePointer() override;														// 02
			virtual BOOL			SetFilePointer(LARGE_INTEGER a_distanceToMove, DWORD a_moveMethod) override;	// 03
			virtual BOOL			ReadFile(DWORD a_numberOfBytesToRead, LPVOID a_buffer) override;				// 04
			virtual void			Unk_06(void) override;															// 06
			virtual void			Unk_07(void) override;															// 07
			virtual void			Unk_08(void) override;															// 08
			virtual void			Unk_09(void) override;															// 09
			virtual void			Unk_0A(void) override;															// 0A
			virtual void			Unk_0B(void) override;															// 0B


			// members
			UInt64	unk20;	// 20
			UInt64	unk28;	// 28
			UInt64	unk30;	// 30
			UInt64	unk38;	// 38
		};
		STATIC_ASSERT(sizeof(Store) == 0x40);
	}
}
