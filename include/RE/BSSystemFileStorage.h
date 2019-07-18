#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSSystemFileStorage

#include "RE/BSStorage.h"  // BSStorage


namespace RE
{
	class BSSystemFileStorage : public BSStorage
	{
	public:
		inline static const void* RTTI = RTTI_BSSystemFileStorage;


		struct Attributes
		{
			enum class Error : UInt32
			{
				kNone = 0,
				kFileNotFound = 2,
				kAlreadyExists = 3,
				kPathNotFound = 4,
				kWriteProtect = 5,
				kOther = 6,

				kErrorMask = 0x7FFFFFFF,

				kUnkFlag = (UInt32)1 << 31	// top bit isn't part of the error, mask 0x7FFFFFFF to get the error
			};


			Error	lastError;	// 00
			UInt32	pad24;		// 04
			HANDLE	handle;		// 08
		};
		STATIC_ASSERT(sizeof(Attributes) == 0x10);


		virtual ~BSSystemFileStorage();																			// 00

		// override (BSStorage)
		virtual PLARGE_INTEGER 	GetFileSize() override;															// 01
		virtual PLARGE_INTEGER	GetFilePointer() override;														// 02
		virtual BOOL			SetFilePointer(LARGE_INTEGER a_distanceToMove, DWORD a_moveMethod) override;	// 03
		virtual BOOL			ReadFile(DWORD a_numberOfBytesToRead, LPVOID a_buffer) override;				// 04
		virtual BOOL			WriteFile(DWORD a_numberOfBytesToWrite, LPCVOID a_buffer) override;				// 05

		bool IsGoodForRead() const;


		// members
		Attributes	attributes;		// 20
		bool		unk30;			// 30
		bool		unk31;			// 31
		bool		goodForRead;	// 32
		UInt8		pad33;			// 33
		UInt32		pad34;			// 34
	};
	STATIC_ASSERT(sizeof(BSSystemFileStorage) == 0x38);
}
