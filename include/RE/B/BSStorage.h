#pragma once

#include "RE/BSSystem/BSIntrusiveRefCounted.h"


namespace RE
{
	class BSStorage : public BSIntrusiveRefCounted
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSStorage;


		struct UnkData
		{
			std::uint64_t unk00;  // 00
			std::uint64_t unk08;  // 08
			std::uint64_t unk10;  // 10
		};
		static_assert(sizeof(UnkData) == 0x18);


		virtual ~BSStorage();  // 00

		// add
		virtual PLARGE_INTEGER GetFileSize() = 0;														// 01
		virtual PLARGE_INTEGER GetFilePointer() = 0;													// 02
		virtual BOOL		   SetFilePointer(LARGE_INTEGER a_distanceToMove, DWORD a_moveMethod) = 0;	// 03
		virtual BOOL		   ReadFile(DWORD a_numberOfBytesToRead, LPVOID a_buffer) = 0;				// 04
		virtual BOOL		   WriteFile(DWORD a_numberOfBytesToWrite, LPCVOID a_buffer) = 0;			// 05


		// members
		std::uint32_t unk0C;  // 0C
		UnkData*	  unk10;  // 10
		std::uint64_t unk18;  // 18
	};
	static_assert(sizeof(BSStorage) == 0x20);
}
