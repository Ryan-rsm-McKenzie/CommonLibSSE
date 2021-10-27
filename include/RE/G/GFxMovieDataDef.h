#pragma once

#include "RE/G/GAtomic.h"
#include "RE/G/GFxLoadUpdateSync.h"
#include "RE/G/GFxResourceReport.h"
#include "RE/G/GFxTimelineDef.h"
#include "RE/G/GHashSet.h"
#include "RE/G/GHashUncached.h"
#include "RE/G/GRefCountBase.h"
#include "RE/G/GStringHash.h"

namespace RE
{
	class GFxLog;

	struct GFxMovieLoadInfo
	{
		std::uint32_t totalBytes;  // 00
		std::uint32_t version;     // 04
		GRectF        frameRect;   // 08
		float         frameRate;   // 18
		std::uint32_t frameCount;  // 1C
		std::uint32_t swfFlags;    // 20
		std::uint32_t unk24;       // 24
		std::uint64_t unk28;       // 28
		std::uint64_t unk30;       // 30
		std::uint64_t unk38;       // 38
		std::uint16_t unk40;       // 40
		std::uint16_t pad42;       // 42
		std::uint32_t unk44;       // 44
		GString       unk48;       // 48
		GString       unk50;       // 50
		void*         unk58;       // 58
		std::uint64_t unk60;       // 60
		std::uint64_t unk68;       // 68
	};
	static_assert(sizeof(GFxMovieLoadInfo) == 0x70);

	struct GFxResourceSource
	{
		enum SourceType : std::int32_t
		{
			kNormal,
			kImported,
		};

		struct ImportSource
		{
			std::uint32_t index;
			std::uint32_t unk04;
		};

		union ResourceUnion
		{
			GFxResource* resource;
			ImportSource importSource;
		};

		SourceType    type;   // 00
		std::uint32_t pad04;  // 04
		ResourceUnion data;   // 08
	};
	static_assert(sizeof(GFxResourceSource) == 0x10);

	struct GFxImportNode
	{
		struct ImportAssetInfo
		{
			GString       name;         // 00
			std::uint32_t id;           // 08
			std::uint32_t importIndex;  // 0C
		};
		static_assert(sizeof(ImportAssetInfo) == 0x10);

		GArray<ImportAssetInfo> assets;       // 00
		GString                 filename;     // 18
		std::uint32_t           frame;        // 20
		std::uint32_t           movieIndex;   // 24
		GFxImportNode*          nextInChain;  // 28
	};
	static_assert(sizeof(GFxImportNode) == 0x30);

	class GFxMovieDataDef :
		public GFxTimelineDef,    // 00
		public GFxResourceReport  // 20
	{
	public:
		class Allocator
		{
		public:
			void* Alloc(UPInt a_size)
			{
				if (a_size > 0xFF8) {
					auto newBlock = static_cast<void**>(heap->Alloc(a_size + 8, 0));
					if (!newBlock) {
						return nullptr;
					}

					newBlock[0] = lastBlock;
					lastBlock = newBlock;

					return &newBlock[1];
				}

				if (a_size > memAvailable) {
					auto newBlock = static_cast<void**>(heap->Alloc(0x1FF8, 0));
					if (!newBlock) {
						return nullptr;
					}

					newBlock[0] = lastBlock;
					lastBlock = newBlock;

					allocPtr = &newBlock[1];
					memAvailable = 0x1FF0;
				}

				auto memPtr = allocPtr;

				memAvailable -= a_size;
				allocPtr = static_cast<char*>(allocPtr) + a_size;

				return memPtr;
			}

			template <class T>
			T* Alloc()
			{
				return static_cast<T*>(Alloc(sizeof(T)));
			}

			void Free()
			{
				const auto globalHeap = GMemory::GetGlobalHeap();
				void*      block = lastBlock;
				while (block) {
					globalHeap->Free(block);
					block = static_cast<void**>(block)[0];
				}
			}

			// members
			void*         allocPtr;      // 00
			std::uint64_t memAvailable;  // 08
			void*         lastBlock;     // 10
			GMemoryHeap*  heap;          // 18
		};

		class LoadTaskDataBase : public GRefCountBase<LoadTaskDataBase, GFxStatMovieData::kGFxStatMD_Other_Mem>
		{
		public:
			// members
			Allocator allocator;  // 10
			void*     unk30;      // 30
		};
		static_assert(sizeof(LoadTaskDataBase) == 0x38);

		class LoadTaskData : public LoadTaskDataBase
		{
		public:
			using ResourceHash = GHashUncached<GFxResourceID, GFxResourceSource, GFxResourceID::HashOp>;

			~LoadTaskData() override;  // 00

			// add
			virtual void AddFrameName(GString* a_label, GFxLog* a_log);  // 01
			virtual void SetMovieTagArray(ExecuteTagList* a_data);       // 02
			virtual void SetImportTagArray(ExecuteTagList* a_data);      // 03

			// members
			GMemoryHeap*              loadDataHeap;           // 038
			GMemoryHeap*              imageHeap;              // 040
			GString                   fileURL;                // 048
			GFxMovieLoadInfo          movieInfo;              // 050
			std::uint32_t             fileAttributes;         // 0C0
			std::uint32_t             padC4;                  // 0C4
			void*                     metadata;               // 0C8
			std::uint32_t             metadataSize;           // 0D0
			std::uint32_t             loadStatus;             // 0D4 - 1 when file loaded, 2 when loading finished, 4 if error?
			std::int32_t              frameLoading;           // 0D8
			std::uint8_t              unkDC;                  // 0DC
			std::uint8_t              padDD;                  // 0DD
			std::uint16_t             padDE;                  // 0DE
			std::uint32_t             unkE0;                  // 0E0
			std::uint32_t             padE4;                  // 0E4
			GPtr<GFxLoadUpdateSync>   updateSync;             // 0E8
			std::uint64_t             unkF0;                  // 0F0
			std::uint64_t             unkF8;                  // 0F8
			GFxImportNode*            importInfoBegin;        // 100
			GFxImportNode*            importInfoEnd;          // 108
			std::uint64_t             unk110;                 // 110
			std::uint64_t             unk118;                 // 118
			std::uint64_t             unk120;                 // 120
			std::uint64_t             unk128;                 // 128
			std::uint32_t             importedResourceCount;  // 130
			std::uint32_t             pad134;                 // 134
			GLock                     resourceLock;           // 138
			ResourceHash              resources;              // 160
			std::uint64_t             unk168;                 // 168
			std::uint64_t             unk170;                 // 170
			GLock                     frameLock;              // 178
			GArrayLH<ExecuteTagList>  movieFrames;            // 1A0
			GArrayLH<ExecuteTagList>  importFrames;           // 1B8
			std::int32_t              importFrameCount;       // 1D0
			std::uint32_t             pad1D4;                 // 1D4
			GStringHash<std::int32_t> frameLabels;            // 1D8
			std::uint64_t             unk1E0;                 // 1E0
		};
		static_assert(sizeof(LoadTaskData) == 0x1E8);

		~GFxMovieDataDef() override;  // 00

		// override (GFxResource)
		GFxResourceKey     GetKey() override;                     // 01
		std::uint32_t      GetResourceTypeCode() const override;  // 02
		GFxResourceReport* GetResourceReport() override;          // 03

		// override (GFxCharacterDef)
		std::uint32_t GetVersion() override;  // 08

		// override (GFxTimelineDef)
		std::uint32_t   GetFrameCount() override;                                                                 // 0A
		ExecuteTagList* GetMovieTagArray(ExecuteTagList& a_data, std::int32_t a_frameNumber) override;            // 0B
		ExecuteTagList* GetImportTagArray(ExecuteTagList& a_data, std::int32_t a_frameNumber) override;           // 0C
		bool            GetLabeledFrame(const char* a_label, std::int32_t& a_frameNumber, bool a_arg3) override;  // 0D

		// add
		virtual void          Unk_0E(void);   // 0E
		virtual std::uint32_t GetSWFFlags();  // 0F

		// members
		GFxResourceKey*    resourceKey;   // 28
		void*              unk30;         // 30
		std::uint32_t      fileFormat;    // 38
		std::uint32_t      pad3C;         // 3C
		GPtr<LoadTaskData> loadTaskData;  // 40
	};
	static_assert(sizeof(GFxMovieDataDef) == 0x48);
}
