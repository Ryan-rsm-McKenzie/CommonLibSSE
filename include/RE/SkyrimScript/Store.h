#pragma once

#include "skse64/GameRTTI.h"  // RTTI_SkyrimScript__Store

#include "RE/BSScript/IStore.h"  // BSScript::IStore


namespace RE
{
	namespace BSResource
	{
		class Stream;
	}


	namespace SkyrimScript
	{
		class Store : public BSScript::IStore
		{
		public:
			inline static const void* RTTI = RTTI_SkyrimScript__Store;


			virtual ~Store();																						// 00

			// override (BSScript::IStore)
			virtual PLARGE_INTEGER			GetFileSize() override;															// 01
			virtual PLARGE_INTEGER			GetFilePointer() override;														// 02
			virtual BOOL					SetFilePointer(LARGE_INTEGER a_distanceToMove, DWORD a_moveMethod) override;	// 03
			virtual BOOL					ReadFile(DWORD a_numberOfBytesToRead, LPVOID a_buffer) override;				// 04
			virtual bool					Open(const char* a_fileName) override;											// 06
			virtual void					Close(void) override;															// 07
			virtual const BSFixedString&	GetRelPath() override;															// 08 - { return relPath; }
			virtual bool					HasOpenFile() override;															// 09 - { return hasOpenFile; }
			virtual bool					FileIsGood() override;															// 0A - { return fileIsGood; }
			virtual void					Unk_0B(void) override;															// 0B


			// members
			UInt64				unk20;			// 20
			BSResource::Stream*	stream;			// 28
			BSFixedString		relPath;		// 30
			bool				hasOpenFile;	// 38
			bool				fileIsGood;		// 39
			UInt16				pad3A;			// 3A
			UInt32				pad3C;			// 3C
		};
		STATIC_ASSERT(sizeof(Store) == 0x40);
	}
}
