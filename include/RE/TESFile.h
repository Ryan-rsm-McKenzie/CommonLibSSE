#pragma once

#include "RE/BSString.h"  // BSString
#include "RE/BSTList.h"  // BSSimpleList
#include "RE/FormTypes.h"  // FormType


namespace RE
{
	class BSFile;


	struct FormRecordData
	{
		FormType	typeID;		// 0
		UInt8		pad1;		// 1
		UInt16		pad2;		// 2
		UInt32		typeCode;	// 4 - i.e. 'GMST', 'FACT'
		UInt32		unk8;		// 8 - only seen zero
	};
	STATIC_ASSERT(sizeof(FormRecordData) == 0xC);


	struct ChunkHeader
	{
		UInt32	type;	// 0 - i.e. 'XGRD', 'DATA'
		UInt16	size;	// 4
		UInt16	pad6;	// 6
	};
	STATIC_ASSERT(sizeof(ChunkHeader) == 0x8);


	// 4C8
	class TESFile
	{
	public:
		enum class RecordFlag : UInt32
		{
			kNone = 0,
			kESM = 1 << 0,
			kActive = 1 << 3,
			kLocalized = 1 << 7,
			kESL = 1 << 9
		};


		// 18 info about currently loading form
		struct FormInfo
		{
			UInt32	recordType;	// 00 i.e. 'FACT', 'GMST'
			UInt32	unk04;		// 04 looks like size of entire record
			UInt32	formFlags;	// 08 copied to TESForm->flags
			UInt32	formID;		// 0C
			UInt32	unk10;		// 10
			UInt16	unk14;		// 14 always initialized to 0F on SaveForm.
			UInt16	unk16;		// 16
		};
		STATIC_ASSERT(sizeof(FormInfo) == 0x18);


		struct FileSize
		{
			DWORD	fileSizeHigh;	// 0
			DWORD	fileSizeLow;	// 4
		};
		STATIC_ASSERT(sizeof(FormInfo) >= 0x8);


		TESFile*	Duplicate(UInt32 a_cacheSize = 0x4000);
		UInt32		GetCurrentSubRecordType();
		UInt32		GetCurrentSubRecordSize() const;
		FormType	GetFormType();
		bool		IsLoaded() const;
		bool		IsLocalized() const;
		void		ReadData(void* a_buf, UInt32 a_size);
		bool		Seek(UInt32 a_offset);
		bool		SeekNextSubrecord();


		// members
		UInt32						unk000;					// 000
		UInt8						unk004[0xC];			// 004
		void*						pointerMap;				// 010 - NiTPointerMap<UInt32, TESFile*>* - size == 0x20
		UInt64						unk018[2];				// 018
		UInt8						unk028;					// 028
		UInt8						unk029;					// 029
		UInt8						pad02A[6];				// 02A
		UInt64						unk030;					// 030
		BSFile*						unkFile;				// 038
		UInt64						unk040[3];				// 040
		char						name[MAX_PATH];			// 058
		char						filepath[MAX_PATH];		// 15C
		void*						unk260;					// 260
		UInt32						unk268;					// 268 - init'd to ctor arg(0x800) or 0x10000 if arg is 0
		UInt32						unk26C;					// 26C
		UInt32						unk270;					// 270
		UInt32						unk274;					// 274 - pad?
		UInt64						unk278;					// 278
		UInt32						unk280;					// 280
		FormInfo					formInfo;				// 284
		ChunkHeader					subRecord;				// 29C
		UInt32						unk2A4;					// 2A4
		UInt32						fileOffset;				// 2A8
		UInt32						dataOffset;				// 2AC - index into dataBuf
		UInt32						subrecordBytesRead;		// 2B0 - generates error on Read if != expected length
		UInt32						unk2B4;					// 2B4
		UInt64						unk2B8;					// 2B8
		UInt64						unk2C0;					// 2C0
		UInt64						unk2C8;					// 2C8
		UInt64						unk2D0;					// 2D0
		UInt64						unk2D8;					// 2D8
		UInt64						unk2E0;					// 2E0
		UInt8						unk2E8;					// 2E8
		bool						isBigEndian;			// 2E9
		UInt8						unk2EA;					// 2EA
		UInt8						pad2EB;					// 2EB
		WIN32_FIND_DATA				fileData;				// 2EC
		float						unk42C;					// 42C - init'd to 0.94
		UInt32						unk430;					// 430
		UInt32						flags;					// 434 - init'd to 0x00000800. 4000 and 40000 do stuff
		RecordFlag					recordFlags;			// 438
		BSSimpleList<const char*>	masterNames;			// 440
		BSSimpleList<FileSize*>		masterFileSizes;		// 450
		UInt32						numRefMods;				// 460 - related to modindex; see 4472D0
															// formIDs in mod are as saved in GECK, must fix up at runtime
		UInt32						pad464;					// 464
		TESFile**					refModInfo;				// 468 - used to look up modInfo based on fixed mod index, double-check
		UInt32						unk470;					// 470
		UInt32						unk474;					// 474
		UInt8						modIndex;				// 478 - init to 0xFF
		UInt8						pad479;					// 479
		UInt16						lightIndex;				// 47A
		UInt32						pad47C;					// 47C
		BSString					author;					// 480
		BSString					description;			// 490
		void*						dataBuf;				// 4A0
		UInt32						unk4A8;					// 4A8 - looks like size of entire record
		UInt32						pad4AC;					// 4AC
		void*						unk4B0;					// 4B0
		UInt32						unk4B8;					// 4B8
		UInt32						pad4BC;					// 4BC
		void*						unk4C0;					// 4C0
	};
	STATIC_ASSERT(offsetof(TESFile, formInfo) == 0x284);
	STATIC_ASSERT(offsetof(TESFile, subRecord) == 0x29C);
	STATIC_ASSERT(offsetof(TESFile, fileOffset) == 0x2A8);
	STATIC_ASSERT(offsetof(TESFile, fileData) == 0x2EC);
	STATIC_ASSERT(offsetof(TESFile, numRefMods) == 0x460);
	STATIC_ASSERT(offsetof(TESFile, author) == 0x480);
	STATIC_ASSERT(sizeof(TESFile) == 0x4C8);
}
