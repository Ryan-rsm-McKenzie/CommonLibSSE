#pragma once

#include "RE/BSSystem/BSStorage/BSStorage.h"


namespace RE
{
	class BSSystemFileStorage : public BSStorage
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSSystemFileStorage;


		struct Attributes
		{
			enum class Error
			{
				kNone = 0,
				kFileNotFound = 2,
				kAlreadyExists = 3,
				kPathNotFound = 4,
				kWriteProtect = 5,
				kOther = 6,

				kErrorMask = 0x7FFFFFFF,

				kUnkFlag = 1 << 31	// top bit isn't part of the error, mask 0x7FFFFFFF to get the error
			};


			stl::enumeration<Error, std::uint32_t> lastError;  // 00
			std::uint32_t						   pad24;	   // 04
			HANDLE								   handle;	   // 08
		};
		static_assert(sizeof(Attributes) == 0x10);


		virtual ~BSSystemFileStorage();	 // 00

		// override (BSStorage)
		virtual PLARGE_INTEGER GetFileSize() override;														 // 01
		virtual PLARGE_INTEGER GetFilePointer() override;													 // 02
		virtual BOOL		   SetFilePointer(LARGE_INTEGER a_distanceToMove, DWORD a_moveMethod) override;	 // 03
		virtual BOOL		   ReadFile(DWORD a_numberOfBytesToRead, LPVOID a_buffer) override;				 // 04
		virtual BOOL		   WriteFile(DWORD a_numberOfBytesToWrite, LPCVOID a_buffer) override;			 // 05

		bool IsGoodForRead() const;


		// members
		Attributes	  attributes;	// 20
		bool		  unk30;		// 30
		bool		  unk31;		// 31
		bool		  goodForRead;	// 32
		std::uint8_t  pad33;		// 33
		std::uint32_t pad34;		// 34
	};
	static_assert(sizeof(BSSystemFileStorage) == 0x38);
}
