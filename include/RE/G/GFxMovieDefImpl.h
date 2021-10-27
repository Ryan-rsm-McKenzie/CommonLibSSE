#pragma once

#include "RE/G/GAtomic.h"
#include "RE/G/GFxLoadUpdateSync.h"
#include "RE/G/GFxMovieDef.h"
#include "RE/G/GFxResource.h"
#include "RE/G/GFxResourceKey.h"
#include "RE/G/GFxResourceLib.h"
#include "RE/G/GPtr.h"
#include "RE/G/GRefCountBase.h"
#include "RE/G/GStats.h"

namespace RE
{
	class GFxMovieDefImpl : public GFxMovieDef
	{
	public:
		struct ImportData;

		struct ImportedResource
		{
			GPtr<GFxResource> resource;    // 00
			ImportData*       importData;  // 08
		};

		struct ImportData
		{
			GMemoryHeap*      heap;           // 00
			std::uint32_t     importCount;    // 08
			std::uint32_t     pad0C;          // 0C
			ImportedResource* resourceArray;  // 10
			GLock             lock;           // 18
			bool              hasImports;     // 40
			std::uint8_t      pad41;          // 41
			std::uint16_t     pad42;          // 42
			std::uint32_t     pad44;          // 44
			GFxMovieDef*      movieDef;       // 48
		};
		static_assert(sizeof(ImportData) == 0x50);

		class BindTaskData : public GRefCountBase<BindTaskData, GStatGroups::kGStat_Default_Mem>
		{
		public:
			virtual ~BindTaskData();  // 00

			// members
			GMemoryHeap*            bindDataHeap;       // 10
			GFxMovieDataDef*        movieDataResource;  // 18
			GFxMovieDefImpl*        unk20;              // 20
			std::uint32_t           unk28;              // 28
			std::uint32_t           pad2C;              // 2C
			ImportData              importData;         // 30
			GArray<GFxMovieDef*>    importedMovies;     // 80
			GLock                   lock;               // 98
			std::uint64_t           unkC0;              // C0
			std::uint64_t           unkC8;              // C8
			std::uint64_t           unkD0;              // D0
			std::uint32_t           taskState;          // D8
			std::uint32_t           padDC;              // DC
			GPtr<GFxLoadUpdateSync> updateSync;         // E0
			std::uint32_t           loadingFrame;       // E8
			std::uint32_t           bytesLoaded;        // EC
			bool                    hasError;           // F0
			std::uint8_t            padF1;              // F1
			std::uint16_t           padF2;              // F2
			std::uint32_t           padF4;              // F4
		};
		static_assert(sizeof(BindTaskData) == 0xF8);

		virtual ~GFxMovieDefImpl();  // 00

		// add
		virtual GFxResource* GetFont(const char* a_name, std::uint32_t a_fontFlags, std::int32_t& a_arg3);  // 1C

		// members
		GPtr<GFxStateBagImpl>       stateBagImpl;     // 20
		void*                       unk28;            // 28
		GPtr<GFxMovieDefBindStates> movieBindStates;  // 30
		GPtr<BindTaskData>          bindTaskData;     // 38
	};
	static_assert(sizeof(GFxMovieDefImpl) == 0x40);
}
