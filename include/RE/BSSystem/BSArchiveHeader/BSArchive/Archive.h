#pragma once

#include "RE/BSArchive.h"
#include "RE/BSFile.h"
#include "RE/NiRefObject.h"


namespace RE
{
	class Archive :
		public BSArchive,	// 190
		public BSFile,		// 000
		public NiRefObject	// 180
	{
	public:
		inline static constexpr auto RTTI = RTTI_Archive;


		virtual ~Archive();	 // 00


		// members
		UInt64 unk1C0;	// 1C0
		UInt64 unk1C8;	// 1C8
		UInt64 unk1D0;	// 1D0
		UInt64 unk1D8;	// 1D8
		UInt64 unk1E0;	// 1E0
		UInt64 unk1E8;	// 1E8
		UInt64 unk1F0;	// 1F0
		UInt64 unk1F8;	// 1F8
		UInt64 unk200;	// 200
		UInt64 unk208;	// 208
		UInt64 unk210;	// 210
		UInt64 unk218;	// 218
		UInt64 unk220;	// 220
		UInt64 unk228;	// 228
	};
	STATIC_ASSERT(sizeof(Archive) == 0x230);
}
